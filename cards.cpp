#include <iostream>
using namespace std;
const int clubs = 0;
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

struct card {
    int number;
    int suit;
};

int main() {
    card temp, chosen, prize;
    int position;
    card card1 = {7, clubs};
    cout << "Card 1: 7 clubs\n";
    card card2 = {jack, hearts};
    cout << "Card 2: jack hearts\n";
    card card3 = {ace, spades};
    cout << "Card 3: ace spades\n";
    prize = card3;
    cout << "Change cards 1 and 3...\n";
    temp = card3;
    card3 = card1;
    card1 = temp;
    cout << "Change cards 2 and 3...\n";
    temp = card3;
    card3 = card2;
    card2 = temp;
    cout << "Change cards 1 and 2...\n";
    temp = card2;
    card2 = card1;
    card1 = temp;
    cout << "Positions (1, 2 or 3) where is ace now: ";
    cin >> position;
    switch(position) {
        case 1:
            chosen = card1;
            break;
        case 2:
            chosen = card2;
            break;
        case 3:
            chosen = card3;
            break;
    }
    if(chosen.number == prize.number && chosen.suit == prize.suit) {
        cout << "Correct! You won!\n";
    }
    else {
        cout << "Incorrect. You lost.\n";
    }

    return 0;
}