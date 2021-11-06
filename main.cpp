#include <iostream>
#include "game.hpp"
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int c = rand();
    Card* a = new Card(c);
    c = rand();
    Card* b = new Card(c);

    cout << a->getFace() << " " << a->getSuit() << endl;
    cout << b->getFace() << " " << b->getSuit() << endl;

    Player* player = new Player(a, b); //pass onto a new player class



    cout << player->calculateValue() << endl;




    return 0;
};