#include <vector>

class Card {
    private:
        char suit;
        int value;
    public:
        char getSuit() const {
            return suit;
        }

        int getValue() const {
            return value;
        }
};