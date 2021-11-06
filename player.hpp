#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <vector>
#include <card.hpp>

class Player {
    private:
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
            display();
        }

        /* void stay() {
            //ends turn
            //dealer plays next
        } */

        int calculateValue(){
            int total;
            for (unsigned i = 0; i < Hand.size(); ++i)
            {
                total += Hand.at(i)->getValue();
            }

            return total;
        } 

        void display() {
            std::cout << "Your hand is: ";
            for(unsigned int i = 0; i < Hand.size(); i++){
                std::cout << Hand.at(i)->getFace() << " " << Hand.at(i)->getSuit() << " "; 
            }
        }

};

#endif