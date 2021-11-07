#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <vector>
#include "card.hpp"

using namespace std;
class Player {
    protected:
        std::vector<Card*> Hand;
    public:
        Player(){}

        Player(Card *a, Card *b)
        {
            Hand.push_back(a);
            Hand.push_back(b);
        }

        void hit() {
            srand(time(0));
            int c = rand();
            Card* newCard = new Card(c);
            Hand.push_back(newCard);
        }

        int calculateValue(){
            int total = 0;
            for (unsigned i = 0; i < Hand.size(); ++i)
            {
                total += Hand.at(i)->getValue();
            }

            return total;
        } 

        void display() {
           cout << "Your hand is: ";
            for(unsigned int i = 0; i < Hand.size(); i++){
                if(i == Hand.size() - 1){
                    cout << Hand.at(i)->getFace() << " " << Hand.at(i)->getSuit();
                } else {
                    cout << Hand.at(i)->getFace() << " " << Hand.at(i)->getSuit() << " | "; 
            }
            }
            cout << endl;
            cout << "----------------------------------------------" << endl;
            
        }

        void aceCheck(){
            if (calculateValue() > 21)
            {
                for (unsigned i = 0; i < Hand.size(); ++i)
                {
                    if (Hand.at(i)->getFace() == "Ace")
                    {
                        Hand.at(i)->setValue(1);
                        break;
                    }
                }
            }


        }


};

#endif
