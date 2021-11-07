#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "dealer.hpp"
#include "card.hpp"
#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
class Game
{
private:
    Dealer *dealer = new Dealer();

public:
    Game()
    {
    }
    void runGame()
    {
        using namespace std::this_thread;
        using namespace std::chrono;
        bool bust = false;
        srand(time(0));
        int c = rand();
        Card *a = new Card(c);
        c = rand();
        Card *b = new Card(c);
        Player *player = new Player(a, b); // pass onto a new player class
        // bool flag = false;
        player->display(); 
        cout << endl << endl;
        dealer->hit();

        dealer->display();
        cout << endl << endl;

        // display what the player has and one of the cards that the dealer has
        while (player->calculateValue() < 21)
        {
            bool flag = false;
            cout << "Your total value is: " + to_string(player->calculateValue()) << "; would you like to Hit or Stay? (type answer)" << endl << endl;
            string answer;
            cin >> answer;
            cout << endl;
            while (flag == false)
            {
                if (answer == "Hit" || answer == "Stay")
                {
                    flag = true;
                }


                else
                {
                    cout << "Enter exactly \"Hit\" or \"Stay\"!" << endl << endl;
                    cin >> answer;
                    cout << endl;
                }
            }
            if (flag)
            {
                if (answer == "Hit")
                {
                    player->hit();
                    player->display();
                }
                else
                {
                    break;
                }
            }

            player->aceCheck();
        }

        if (player->calculateValue() == 21)
        {
            cout << "You hit 21! BLACKJACK!" << endl;
        }

        if (player->calculateValue() > 21)
        {
            bust = true;
            cout << endl
                 << endl
                 << endl
                 << "BUST!!!!" << endl
                 << endl
                 << endl;
            cout << "Your total value is: " + to_string(player->calculateValue()) << endl
                 << endl;
        }

        dealer->hit();

        dealer->display();
        cout << "Dealer's total value is: " + to_string(dealer->calculateValue()) << endl;
        if (dealer->calculateValue() < player->calculateValue() && player->calculateValue() <= 21)
        {
            while (dealer->calculateValue() < 17 || dealer->calculateValue() < player->calculateValue())
            {
                sleep_for(seconds(3));
                cout << "Dealer hits!" << endl;
                dealer->hit();
                dealer->display();
                cout << "Dealer's total value is: " + to_string(dealer->calculateValue()) << endl;
                dealer->aceCheck();
            }
        }

        if (dealer->calculateValue() > 21)
        {
            bust = true;
            cout << endl
                 << endl
                 << endl
                 << "DEALER BUST!!!!" << endl
                 << endl
                 << endl
                 << endl;
        }

        int result = calculateWin(player, dealer);

        if (result == 0)
        {
            cout << "Player wins!!! CONGRATS" << endl;
        }

        else if (result == 1)
        {
            cout << "Dealer wins!!" << endl;
        }

        else
        {
            cout << "DRAW" << endl;
        }
    }

    
    int calculateWin(Player* player, Dealer* dealer)   // returns 0 if player wins, 1 if dealer wins, 2 if draw
    {
        if (player->calculateValue() > 21) //player bust
        {
            return 1;
        }
        
        else if (dealer->calculateValue() > 21) //dealer bust
        {
            return 0;
        }

        else if (dealer->calculateValue() > player->calculateValue())
        {
            return 1;
        }
        
        else if (player->calculateValue() > dealer->calculateValue())
        {
            return 0;
        }

        else if (player->calculateValue() == dealer->calculateValue())
        {
            return 2;
        }
        
    }
};

#endif