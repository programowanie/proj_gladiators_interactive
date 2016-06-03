#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include "gladiator.h"

using namespace std;

int main(int argc, char const *argv[])
{
    
{
	srand(argc == 2
		? atoi(argv[1])
		: time(NULL));

    int sleep = 1000000;
    printf("\x1b[1m\x1b[31m\nINTERACTIVE GLADIATORS FIGHT v0.01\n");
    printf("\x1b[0m"); usleep(2*sleep);
    cout << "\nWelcome in Ancient Rome!"<<endl;usleep(sleep);
    cout <<"Where people spent their lives on drinking wine and watching slaves fight to death!" << endl; usleep(4*sleep);
    cout << "What an era to be alive!!!" << endl; usleep(2*sleep);
    cout << "\nYou are gladiator exiled to death. You are supposed to fight for your life and for glory!" << endl; usleep(3*sleep);

    Hero h1;
    h1.AddHero();
    h1.HP = 80;
    h1.base_hp = 80;
    h1.gold = 8;

    cout << "\nYou spent your first night near arena. Tomorrow that will be your fist duel." << endl; usleep(3*sleep);
    cout << "You are really nervous and you can't sleep. All you do is thinking about tommorow. Will you survive?" << endl; usleep(3*sleep);
    cout << "You can't escape. They took everything from you, they will find you when you will try to run." << endl; usleep(3*sleep);
    cout << "The only thing left is to defeat all enemies on arenas and become the Grand Master!" << endl; usleep(3*sleep);
    cout << "\nYou are going to try to go to sleep..." << endl; usleep(2*sleep);
    cout << "Then idea has appeared in your head!" << endl;  usleep(2*sleep);
    cout << "You can train in the nearby forest. Do you want go to the woods? (Y/N)" << endl;
    char ans_bear;
    cin >> ans_bear;

    if(ans_bear=='y' || ans_bear=='Y'){
        cout << "\nYou went into the forest in the late night. You can't see anything, but you hear some strange sounds."<< endl; usleep(3*sleep);
        cout << "Sounds are getting louder!"<<endl; usleep(2*sleep);
        cout << "You have been attacked by wild bear! You are supposed to fight for your life!"<<endl; usleep(3*sleep);
        Gladiator bear;
        bear.Name="Bear"; bear.Strength=5; bear.Agility=5; bear.Defense=3; bear.HP=50;

        cout << "\n----------------------------------------------------------------------------------------" << endl;;
        h1.Stats();
        cout << "   vs.   ";
        bear.Stats();
        cout << "\n----------------------------------------------------------------------------------------";
        int who_hits_first=rand()%(h1.Agility+bear.Agility);
        int dmg=0;

        cout <"\n";

        if(who_hits_first<bear.Agility) { cout << "\nBear attacks first!"<< endl; usleep(3); }
            else { cout << "\n" <<h1.Name << " attacked first!" << endl; usleep(3); }

        for(int first_fight=0; first_fight>-1; first_fight++)
        {
            bear.dmg_chance= ((bear.Strength*0,7)*(rand()%100))/100;
            bear.hit_chance= ((bear.Agility*0,7)*(rand()%100))/100;
            bear.def_chance= 1-(((bear.Defense*0,7)*(rand()%100))/100);


             h1.dmg_chance=((h1.Strength*0,7)*(rand()%100))/100;
             h1.hit_chance=((h1.Agility*0,7)*(rand()%100))/100;
             h1.def_chance= 1-(((h1.Defense*0,7)*(rand()%100))/100);

            if(who_hits_first<bear.Agility){
                if(bear.hit_chance<bear.Agility)
                    {
                        cout << "Bear attacked you for: ";
                        dmg = bear.dmg_chance - h1.def_chance;
                        if(dmg<0) dmg=0;
                        h1.HP= h1.HP - dmg ;
                        cout << dmg << ". ";
                    }
                else
                    {
                        cout << "Bear doesn't hit you!";
                    }
                cout << "You have " << h1.HP << " hp left." << endl;usleep(sleep);

                if(h1.HP<1) {printf("\x1b[31mYou have been defeated! "); printf("\x1b[0m"); break;}
                if(bear.HP<1) {printf("\x1b[32mYou won! "); printf("\x1b[0m"); break;}

                if(h1.hit_chance<h1.Agility)
                    {
                        cout << "You attacked bear for: ";
                        dmg = h1.dmg_chance - bear.def_chance;
                        if(dmg<0) dmg=0;
                        bear.HP= bear.HP - dmg ;
                        cout << dmg <<". ";
                    }
                else
                    {
                        cout << "You miss bear!";
                    }
                    cout << "Bear has " << bear.HP << " hp left." << endl; usleep(sleep);
                
                if(h1.HP<1) {printf("\x1b[31mYou have been defeated! "); printf("\x1b[0m"); break;}
                if(bear.HP<1) {printf("\x1b[32mYou won! "); printf("\x1b[0m"); break;}
            }

            else
            {
                if(h1.hit_chance<h1.Agility)
                    {
                        cout << "You attacked bear for: ";
                        dmg = h1.dmg_chance - bear.def_chance;
                        if(dmg<0) dmg=0;
                        bear.HP= bear.HP - dmg ;
                        cout << dmg <<". ";
                    }
                else
                    {
                        cout << "You miss bear! ";
                    }
                    cout << "Bear has " << bear.HP << " hp left." << endl; usleep(sleep);
                    
                    if(h1.HP<1) {printf("\x1b[31mYou have been defeated! "); printf("\x1b[0m"); break;}
                    if(bear.HP<1) {printf("\x1b[32mYou won! "); printf("\x1b[0m"); break;}

                if(bear.hit_chance<bear.Agility)
                    {
                        cout << "Bear attacked you for: ";
                        dmg = bear.dmg_chance - h1.def_chance;
                        if(dmg<0) dmg=0;
                        h1.HP= h1.HP - dmg ;
                        cout << dmg << ". ";
                    }
                else
                    {
                        cout << "Bear doesn't hit you!";
                    }
                    cout << "You have " << h1.HP << " hp left." << endl;usleep(sleep);
                    
                    if(h1.HP<1) {printf("\x1b[31mYou have been defeated! "); printf("\x1b[0m"); break;}
                    if(bear.HP<1) {printf("\x1b[32mYou won! "); printf("\x1b[0m"); break;}

            }
            
        }
        if(h1.HP<1) { printf("\x1b[31m\n\n\nGAME OVER!"); printf("\x1b[0m"); return 0; }
        h1.heal();
    }

    cout << "You are deadly tired, everything you think about now is bed and some sleep." << endl;
    cout << "You went back to your room. Tomorrows is mystery..." << endl;

    for(int arena = 0 ; arena < 3 ; arena++)
    {
        cout << "\nArena #" << arena+1 << endl;
        Gladiator glad[10];

        for(int i=0; i<=9; i++)
        {
            glad[i].gladiator_number=i+1;
            glad[i].LoadGladiators(arena);
            glad[i].ViewGladiators(arena);
        }

        cout << "--------------------"<< endl;
        if(h1.HP<1){
            printf("\x1b[31mYou died, game over! :C");
            break;
        }
    }
    return 0;
}
}