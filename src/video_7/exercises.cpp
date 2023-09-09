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

class Elementalist : public Wizard
{
public:
    static enum TElements {
        earth,
        wind,
        fire,
        water
    };

private:
    TElements specialism;

public:
    Elementalist() : Wizard("Aang", 88, 70, 4)
    {
        this->specialism = wind;
    }
    Elementalist(string name, int knowledge, int skill, int maxMagic, TElements specialism) : Wizard(name, knowledge, skill, maxMagic)
    {
        this->specialism = specialism;
    }
    string Display()
    {
        string parentDisplay = Wizard::Display();
        string ownDisplay;

        switch (specialism)
        {
        case earth:
            ownDisplay = "\t\tEarth specialist";
            break;
        case wind:
            ownDisplay = "\t\tWind specialist";
            break;
        case fire:
            ownDisplay = "\t\tFire specialist";
            break;
        case water:
            ownDisplay = "\t\tWater specialist";
            break;
        default:
            break;
        }

        return parentDisplay + ownDisplay;
    }
};

void runTests()
{
    Spell *fireball = new Spell("fireball");
    Spell *frostbolt = new Spell("frostbolt");
    Wizard *gandalf = new Wizard("Gandalf Greyhame", 99, 85, 5);
    gandalf->AddMagic(fireball);
    gandalf->AddMagic(frostbolt);
    Elementalist *aang = new Elementalist("Aang", 88, 70, 4, Elementalist::wind);

    expect("Test1", gandalf->Display(), "Gandalf Greyhame, 99, 85, 2\n\tInventory:\n\t\t- Spell Words fireball\n\t\t- Spell Words frostbolt\n");
    expect("Test2", aang->Display(), "Aang, 88, 70, 0\n\tInventory:\n\t\tWind specialist");
}

int main()
{
    runTests();

    return 0;
}