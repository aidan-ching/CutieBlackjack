#ifndef __GAME_HPP__
#define __GAME_HPP__



#include "dealer.hpp"
#include "card.hpp"
#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;
class Game {
    private:
        Dealer* dealer = new Dealer();
    public:
        Game(){
            
            
        }
        void runGame(){
            bool bust = false;
            intro();
            srand(time(0));
            int c = rand();
            Card* a = new Card(c);
            c = rand();
            Card* b = new Card(c);
            Player* player = new Player(a, b); //pass onto a new player class

            //display what the player has and one of the cards that the dealer has

             while (player->calculateValue() < 21)
            {
                player->display();
                cout << "Your total value is: " + to_string(player->calculateValue()) << "would you like to Hit or Stay? (type answer)" << endl;
                string answer;
                cin >> answer;

                while (answer != "Hit" || answer != "Stay")
                {
                cout << "Your total value is: " + to_string(player->calculateValue()) << "would you like to Hit or Stay? (type answer)" << endl; //make it so it repeats till right answer
                cin >> answer;
                }
                if(answer == "Hit"){
                    player->hit();
                } else if (answer == "Stay"){
                    break;
                }
                
            }

            if (player->calculateValue() > 21)
            {
                bust = true;
                cout << endl << endl << endl << "BUST!!!!" << endl << endl << endl;
            }
            
            
            while (dealer->calculateValue() < 21 && !bust) //if dealer < player, & under 15, hit. if larger, stay. 
            {
                //finish hit or stay logic.
            }

            //calculateWin();


        }
        void intro() {
            std::cout << "this is how u play: ........" << std::endl;
        }

        



};

#endif