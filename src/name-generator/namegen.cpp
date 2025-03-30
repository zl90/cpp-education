#include <sqlite3.h>

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MAX_SYLLABLES = 4;
int MAX_CONSECUTIVE_VOWELS = 2;

vector<string> vowels = {"a", "e", "i", "o", "u"};
vector<string> consonants = {"b", "c", "d", "f", "g", "h", "j",
                             "k", "l", "m", "n", "p", "q", "r",
                             "s", "t", "v", "w", "x", "y", "z"};

string getRandomConsonant() { return consonants[rand() % consonants.size()]; }
string getRandomVowel() { return vowels[rand() % vowels.size()]; }

string generateRandomName() {
  int numSyllables = (rand() % MAX_SYLLABLES) + 1;
  string name = "";
  int runningVowelCount = 0;  // Used to prevent many consecutive vowels.

  for (int j = 0; j < numSyllables; j++) {
    bool shouldAddLetterInFront = rand() % 2;
    bool shouldAddLetterBehind = rand() % 2;

    if (shouldAddLetterInFront) {
      name += getRandomConsonant();
      runningVowelCount = 0;
    }

    if (runningVowelCount < MAX_CONSECUTIVE_VOWELS) {
      name += getRandomVowel();
      runningVowelCount++;
    }

    if (shouldAddLetterBehind) {
      name += getRandomConsonant();
      runningVowelCount = 0;
    }
  }

  // Prevent single digit names.
  if (name.length() == 1) {
    bool shouldAddConsonant = rand() % 2;
    name += shouldAddConsonant ? getRandomConsonant() : getRandomVowel();
  }

  name[0] = toupper(name[0]);
  return name;
}

void updateFrequency(sqlite3 *db, const std::string &name) {
  const char *sql =
      "INSERT INTO names (name, frequency) VALUES (?1, 1) "
      "ON CONFLICT(name) DO UPDATE SET frequency = frequency + 1;";

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
    std::cerr << "Error preparing statement: " << sqlite3_errmsg(db)
              << std::endl;
    return;
  }

  // Bind name parameter
  sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

  // Execute
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "Error executing statement: " << sqlite3_errmsg(db)
              << std::endl;
  }

  // Clean up
  sqlite3_finalize(stmt);
}

void batchUpdateFrequency(sqlite3 *db, const vector<string> &names) {
  const char *sql =
      "INSERT INTO names (name, frequency) VALUES (?1, 1) "
      "ON CONFLICT(name) DO UPDATE SET frequency = frequency + 1;";

  sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
    std::cerr << "Error preparing statement: " << sqlite3_errmsg(db)
              << std::endl;
    return;
  }

  for (const auto &name : names) {
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
      std::cerr << "Error executing statement: " << sqlite3_errmsg(db)
                << std::endl;
    }

    sqlite3_reset(stmt);  // Reset statement for next iteration
  }

  sqlite3_finalize(stmt);
  sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);
}

int main() {
  sqlite3 *db;
  int exit = sqlite3_open("names.db", &db);  // Open (or create) a database

  if (exit) {
    std::cerr << "Error opening DB: " << sqlite3_errmsg(db) << std::endl;
    return 1;
  } else {
    std::cout << "Database opened successfully!" << std::endl;
  }

  const char *sql =
      "CREATE TABLE IF NOT EXISTS names (name TEXT UNIQUE, "
      "frequency INTEGER);";
  sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

  srand(time(0));

  vector<string> names = {};

  for (int i = 0; i < 300000; i++) {
    string name = generateRandomName();
    names.push_back(name);
    cout << generateRandomName() << ".\n";
  }

  batchUpdateFrequency(db, names);

  sqlite3_close(db);

  return 0;
}
