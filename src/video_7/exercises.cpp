#include <iostream>
#include <string>
#include "../test_utils.h"

class Magic
{
public:
    Magic() {}
    virtual string Display() = 0;
};

class Spell final : public Magic
{
private:
    string words;

public:
    Spell() {}
    Spell(string words) : words(words) {}
    string Display()
    {
        return "Spell Words " + words;
    }
};

class Transformation final : public Magic
{
private:
    string creature;

public:
    Transformation() {}
    Transformation(string creature) : creature(creature) {}
    string Display()
    {
        return "Transformation creature " + creature;
    }
};

class Potion final : public Magic
{
private:
    int dose;

public:
    Potion() {}
    Potion(int dose) : dose(dose) {}
    string Display()
    {
        return "Potion dose " + to_string(dose);
    }
};

class Wizard
{
private:
    int knowledge;
    int magicCount;
    Magic **magicInventory;
    string name;
    int skill;

public:
    Wizard()
    {
        magicCount = 0;
        name = "Gandalf";
        knowledge = 99;
        skill = 75;
        magicInventory = new Magic *[20];
    }
    Wizard(string name, int knowledge, int skill, int maxMagic) : name(name), knowledge(knowledge), skill(skill)
    {
        magicCount = 0;
        magicInventory = new Magic *[maxMagic];
    }
    string Display()
    {
        string stats = name + ", " + to_string(knowledge) + ", " + to_string(skill) + ", " + to_string(magicCount) + "\n";
        string inventory = "\tInventory:\n";
        for (int i = 0; i < magicCount; i++)
        {
            inventory += "\t\t- " + magicInventory[i]->Display() + "\n";
        }

        return stats + inventory;
    }
    void AddMagic(Magic *magic)
    {
        magicInventory[magicCount] = magic;
        magicCount++;
    }
};

void runTests()
{
    Spell *fireball = new Spell("fireball");
    Spell *frostbolt = new Spell("frostbolt");
    Wizard *gandalf = new Wizard("Gandalf Greyhame", 99, 85, 5);
    gandalf->AddMagic(fireball);
    gandalf->AddMagic(frostbolt);

    expect("Test1", gandalf->Display(), "Gandalf Greyhame, 99, 85, 2\n\tInventory:\n\t\t- Spell Words fireball\n\t\t- Spell Words frostbolt\n");
}

int main()
{
    runTests();

    return 0;
}