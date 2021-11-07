#ifndef __DEALER_HPP__
#define __DEALER_HPP__

#include "player.hpp"

class Dealer : public Player
{
public:
    Dealer()
    {
    }

    void hit() {
            srand(time(0));
            int c = rand() + rand();
            Card* newCard = new Card(c);
            Hand.push_back(newCard);
        }

    void display()
    {
        cout << "Dealer's hand is: ";
        for (unsigned int i = 0; i < Hand.size(); i++)
        {
            if(i == Hand.size() - 1){
                cout << Hand.at(i)->getFace() << " " << Hand.at(i)->getSuit();
            } else {
            cout << Hand.at(i)->getFace() << " " << Hand.at(i)->getSuit() << " | ";
        }
        }
        cout << endl; 
        cout << "----------------------------------------------" << endl;

        //  generateCards()
    }

};

#endif
