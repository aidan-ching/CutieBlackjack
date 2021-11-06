#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <vector>
#include <string>
#include <cmath>
#include <ctime>
class Card {
    private:
        std::string suit;
        int value;
        std::string face;
        int possibleValues [14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
        std::string possibleFaces [3] = {"Jack", "Queen", "King"}; //ace not included bcuz 11 = ace
        std::string possibleSuits [4] = {"Diamond", "Hearts", "Spades", "Clubs"};
    public:
        Card(int seed) {
            //construct a random card
            srand(seed);
            value = possibleValues[rand() % 14];                  
            suit = possibleSuits[rand() % 4];
            if (value == 10)
            {
                face = possibleFaces[rand() % 3];
            }
            else if (value == 11)
            {
                face = "Ace";
            }
            else
            {
                face = std::to_string(value);
            }
        }

        int getValue() const {
            return value;
        }

        std::string getFace() const{
            return face;
        }

        std::string getSuit() const{
            return suit;
        }

};

#endif