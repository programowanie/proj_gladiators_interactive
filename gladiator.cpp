#include <iostream>
//#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include "gladiator.h"

using namespace std;

void Hero::AddHero()
{
    int sleep=1000000; 

    cout << "What is your name?" << endl;
    cout << "\nPeople used to call me: ";
    cin >> Hero::Name;
    cout << "\nGreatings " << Hero::Name << "! I hope you are a great warrior, so maybe you won't die in the first fight!" << endl; usleep(2*sleep);
    cout << "My apologize... I did not mean to scare you."<<endl;  usleep(sleep);
    cout << "Honestly you look pretty miserable, but I guess it is not the main thing that count in the arena..."<<endl; usleep(3*sleep);
    cout << "Anyways - let's talk about your attributes and your talents, huh?"<<endl; usleep(2*sleep);
    cout << "\n(Now - you may distribute 25 points among all the attributes\nYou have to spend atleast 1 point in each attribute)\n"<<endl;

    int allAtr=(Hero::Strength+Hero::Agility+Hero::Defense);
    allAtr = 50;
    while(allAtr!=25){
    cout << "How strong are you?"<<endl;
    cin >> Hero::Strength;
        while (Hero::Strength<1)
            {cout << "Wrong! Please, tell me again - how strong are you?" << endl; cin >> Hero::Strength;}
            allAtr=Hero::Strength;
    cout << "Wow! I did not expect that... But how fast are you?"<<endl;
    cin >> Hero::Agility;
        while (Hero::Agility<1)
            {cout << "Wrong! Please, tell me again - how fast are you?" << endl; cin >> Hero::Agility;}
            allAtr=allAtr+Hero::Agility;
    cout << "And what about self-defense skills?"<<endl;
    cin >> Hero::Defense;
        while (Hero::Defense<1)
            {cout << "Wrong! Please, tell me again about self-defense skills?" << endl; cin >> Hero::Defense;}
            allAtr=allAtr+Hero::Defense;
    if (allAtr>25) cout << "You have spent too many points! Let's do this again.\n" << endl;
    if (allAtr<25) cout << "You have not spent all points! Let's do this again.\n" << endl;
    }
    cout << "\nSo... Your are " << Hero::Name << " borned only gods know where. You got kidnapped by our Lords and now you are\n"
    "supposed to fight for your life in the arena. \nYour statistics: " << endl;
    cout << "Strength: " << Hero::Strength << endl;
    cout << "Agility: " << Hero::Agility << endl;
    cout << "Defense: " << Hero::Defense << endl;

    cout << "\nThat's all from me. Try to not die in the first fight, huh?"
    "\nI bet gold on you. Good luck, may the gods be with you, always!" << endl;
}

void Hero::Stats()
{
    cout << Name << ", Str: " << Strength << ", Agi: " << Agility << ", Def: " << Defense << ", HP: " << HP;
}

void Gladiator::LoadGladiators(int n)
{
    fstream plik;
    switch(n)
    {
        case 0: {plik.open("Gladiators1.dat",ios::in);
                break;};
        case 1: {plik.open("Gladiators2.dat",ios::in);
                break;};
        case 2: {plik.open("Gladiators3.dat",ios::in);
                break;};
        default:cout<<"Error";
    }

    if(!plik.good()){
        cout << "Error #404!";
        exit(0);
    }

    int line_number=(gladiator_number-1)*5+1;
    int actual_number=1;
    string line;

    while(getline(plik,line))
    {
        if(actual_number==line_number) Name=line;
        if(actual_number==line_number+1) Gladiator::Strength=atoi(line.c_str());
        if(actual_number==line_number+2) Gladiator::Agility=atoi(line.c_str());
        if(actual_number==line_number+3) Gladiator::Defense=atoi(line.c_str());
        if(actual_number==line_number+4) Gladiator::HP=atoi(line.c_str());
        actual_number++;
    }
    plik.close();
}

void Hero::heal()
{
    cout << "Your current ammount of health points is: " << HP;
    if(gold>7)
    {
        cout << "\nDo you want to buy health potion (8 gold)? You have " << gold << " gold. (Y/N)";
        char ans_heal;
        cin >> ans_heal;
        if(ans_heal == 'Y' || ans_heal == 'y')
        {
            gold = gold - 8;
            HP = base_hp;
            cout << "\nYou are cured! Also you have now " << gold << " gold left." << endl;
        }
        else cout << "Ok, maybe next time." << endl;
    }
    else
    {
        cout << "Sadly you don't have enough gold to buy health potion!" << endl;
    }
}

void Gladiator::ViewGladiators(int n)
{
    cout<<endl<<Name;
    cout<<", Strength: "<<Strength;
    cout<<", Agility: "<<Agility;
    cout<<", Defense "<<Defense;
    cout<<", HP: "<<HP<<endl;
}

void Gladiator::Stats()
{
    cout << Name << ", Str: " << Strength << ", Agi: " << Agility << ", Def: " << Defense << ", HP: " << HP;
}