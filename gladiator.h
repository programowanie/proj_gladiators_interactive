#include <iostream>

using namespace std;

class Gladiator
{
    public:
    string Name;
    int Strength;
    int Agility;
    int Defense;
    int HP;
    int dmg_chance;
    int hit_chance;
    int def_chance;

    int gladiator_number; // wczytywanie z pliku

    void LoadGladiators(int n);
    void ViewGladiators(int n);
    void Stats();
};

class Hero
{
    public:
    string Name;
    int Strength;
    int Agility;
    int Defense;
    int HP;
    int base_hp;
    int dmg_chance;
    int hit_chance;
    int def_chance;
    int gold;


    void AddHero();
    void heal();
    void Stats();
};