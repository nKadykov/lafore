#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit {clubs, diamonds, hearts, spades};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card {
    int number;
    Suit suit;
public:
    Card() {}
    void set(int n, Suit s) {
        suit = s;
        number = n;
    }
    void display();
};

void Card::display() {
    if(number >= 2 && number <= 10) {
        cout << number;
    }
    else {
        switch(number) {
            case jack:
                cout << 'J';
                break;
            case queen:
                cout << 'Q';
                break;
            case king:
                cout << 'K';
                break;
            case ace:
                cout << 'A';
                break;
        }
        switch(suit) {
            case clubs:
                cout << static_cast<char>(5);
                break;
            case diamonds:
                cout << static_cast<char>(4);
                break;
            case hearts:
                cout << static_cast<char>(3);
                break;
            case spades:
                cout << static_cast<char>(6);
                break;
        }
    }
}

int main() {
    Card deck[52];
    int j;
    for(j = 0; j < 52; j++) {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    cout << "Cards: \n";
    for(j = 0; j < 52; j++) {
        deck[j].display();
        cout << ' ';
        if(!((j + 1) % 13))
            cout << '\n';
    }
    srand(time(NULL));
    for(j = 0; j < 52; j++) {
        int k = rand() % 52;
        Card temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
    cout << "\nNew cards:\n";
    for(j = 0; j < 52; j++) {
        deck[j].display();
        cout << ' ';
        if(!((j + 1) % 13)) {
            cout << '\n';
        }
    }
    return 0;
}