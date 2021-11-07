#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <random>
class Card {
    private:
        std::string suit;
        int value;
        std::string face;
        int possibleValues [14] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
        std::string possibleFaces [3] = {"Jack", "Queen", "King"}; //ace not included bcuz 11 = ace
        std::string possibleSuits [4] = {"Diamond", "Hearts", "Spades", "Clubs"};
    public:
        Card(int seed) {
            std::random_device dvc;
            std::mt19937 eng(dvc());
            std::uniform_int_distribution<int> dist(1, 100000);
            int ans = dist(eng);
            //srand(ans);
            value = possibleValues[ans % 13];                  
            suit = possibleSuits[ans % 4];
            if (value == 10)
            {
                face = possibleFaces[ans % 3];
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

        void setValue(int val)
        {
            value = val;
        }

};

#endif