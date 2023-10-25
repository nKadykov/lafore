#include <iostream>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card {
    int number;
    Suit suit;
public:
    Card() {}
    Card(int n, Suit s) : number(n), suit(s) {}
    void display();
    bool isEqual(Card);
};

void Card::display() {
    if(number >= 2 && number <= 10)
        cout << number;
    else
        switch(number) {
            case jack: 
                cout << "Jack";
                break;
            case queen:
                cout << "Queen";
                break;
            case king:
                cout << "King";
                break;
            case ace:
                cout << "Ace";
             break;
        }
     switch(suit) {
        case clubs:
            cout << " Сlubs";
            break;
        case diamonds:
            cout << " Diamonds";
            break;
        case hearts:
            cout << " Hearts";
            break;
        case spades:
            cout << " Spades";
            break;
    }
}

bool Card::isEqual(Card c2) {
    return (number == c2.number && suit == c2.suit) ? true : false;
}

int main() {
    Card temp, chosen, prize;
    int position;
    Card card1(7, clubs);
    cout << "\nCard 1: ";
    card1.display();
    Card card2(jack, hearts);
    cout << "\nCard 2: ";
    card2.display();
    Card card3(ace, spades);
    cout << "\nCard 3: ";
    card3.display();
    prize = card3;
    cout << "\nChange cards 1 and 3...";
    temp = card3;
    card3 = card1;
    card1 = temp;
    cout << "\nChange cards 2 and 3...";
    temp = card3;
    card3 = card2;
    card2 = temp;
    cout << "\nChange cards 1 and 2...";
    temp = card2;
    card2 = card1;
    card1 = temp;
    cout << "\nPosition (1, 2, 3): ";
    prize.display();
    cout << "?";
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
    if(chosen.isEqual(prize))
        cout << "Correct! You won!";
    else
        cout << "Incorrect! You lose!";
    cout << " You choose the card";
    chosen.display();
    cout << '\n';
    return 0;
}