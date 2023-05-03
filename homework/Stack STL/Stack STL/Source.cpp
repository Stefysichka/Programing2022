#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Card {
private:
    int value;
public:
    Card(int value) : value(value) {}
    bool operator>(Card& card) {
        return value > card.value;
    }
    bool operator==(Card& card) {
        return value == card.value;
    }
    int getValue() {
        return value;
    }
};
class Deck {
private:
    stack<Card> cards;
public:
    void makeDeck() {
        for (int i = 2; i <= 14; i++) {
            Card card(i);
            cards.push(card);
        }
    }
    bool isEmpty() {
        return cards.empty();
    }
    size_t size() {
        return cards.size();
    }
    Card deal() {
        Card card = cards.top();
        cards.pop();
        return card;
    }
};
class Player {
private:
    stack<Card> cards;
public:
    bool hasCards() {
        return !cards.empty();
    }
    void addCard(Card& card) {
        cards.push(card);
    }
    Card playCard() {
        Card card = cards.top();
        cards.pop();
        return card;
    }
    bool canPlayWar() {
        return cards.size() >= 4;//якщо попадеться однакова карта, щоб можна було ще 3 покласти 
    }
    void playWar(stack<Card>& pile) {//коли однакова
        pile.push(playCard());
        pile.push(playCard());
        pile.push(playCard());
    }
    size_t getNumCards() {
        return cards.size();
    }
    bool CanPlay() {
        return cards.size() == 0;
    }
};

int main() {
    Deck deck;
    deck.makeDeck();
    Player player1, player2;
    int numRounds = 0;
    if (player1.CanPlay() && player2.CanPlay()) {
        while (!deck.isEmpty()) {
            numRounds++;
            Card card1 = deck.deal();
            Card card2 = deck.deal();
            cout << "Player 1 played: ";
            switch (card1.getValue()) {
            case 11:
                cout << "Jack" << endl;
                break;
            case 12:
                cout << "Queen" << endl;
                break;
            case 13:
                cout << "King" << endl;
                break;
            case 14:
                cout << "Ace" << endl;
                break;
            default:
                cout << card1.getValue() << endl;
                break;
            }
            cout << "Player 2 played: ";
            switch (card2.getValue()) {
            case 11:
                cout << "Jack" << endl;
                break;
            case 12:
                cout << "Queen" << endl;
                break;
            case 13:
                cout << "King" << endl;
                break;
            case 14:
                cout << "Ace" << endl;
                break;
            default:
                cout << card2.getValue() << endl;
                break;
            }
            if (card1 > card2) {
                player1.addCard(card1);
                player1.addCard(card2);
                cout << "Player 1 wins the round." << endl;
            }
            else if (card2 > card1) {
                player2.addCard(card1);
                player2.addCard(card2);
                cout << "Player 2 wins the round." << endl;
            }
            else {
                //війна
                if (card1 == card2) {
                    if (player1.canPlayWar() && player2.canPlayWar()) {
                        cout << "War!" << endl;
                        stack<Card> pile;
                        pile.push(card1);//забираєм однакові
                        pile.push(card2);
                        player1.playWar(pile);
                        player2.playWar(pile);
                        Card card3 = player1.playCard();
                        Card card4 = player2.playCard();
                        pile.push(card3);
                        pile.push(card4);
                        cout << "Player 1's war card is: ";
                        switch (card3.getValue()) {
                        case 11:
                            cout << "Jack" << endl;
                            break;
                        case 12:
                            cout << "Queen" << endl;
                            break;
                        case 13:
                            cout << "King" << endl;
                            break;
                        case 14:
                            cout << "Ace" << endl;
                            break;
                        default:
                            cout << card3.getValue() << endl;
                            break;
                        }
                        cout << "Player 2's war card is: ";
                        switch (card4.getValue()) {
                        case 11:
                            cout << "Jack" << endl;
                            break;
                        case 12:
                            cout << "Queen" << endl;
                            break;
                        case 13:
                            cout << "King" << endl;
                            break;
                        case 14:
                            cout << "Ace" << endl;
                            break;
                        default:
                            cout << card4.getValue() << endl;
                            break;
                        }
                        if (card3 > card4) {
                            cout << "Player 1 wins the war and gets all 6 cards." << endl;
                            while (!pile.empty()) {
                                player1.addCard(pile.top());
                                pile.pop();
                            }
                        }
                        else {
                            cout << "Player 2 wins the war and gets all 6 cards." << endl;
                            while (!pile.empty()) {
                                player2.addCard(pile.top());
                                pile.pop();
                            }
                        }
                    }
                    // якщо хтось 1 не може грати
                    else if (player1.canPlayWar() && !player2.canPlayWar()) {
                        cout << "Player 2 wins the game!" << endl;
                        break;
                    }
                    else if (player2.canPlayWar() && !player1.canPlayWar()) {
                        cout << "Player 1 wins the game!" << endl;
                        break;
                    }
                }
            }

        }
    }
    else if (player1.CanPlay() && !player2.CanPlay()) {
        cout << "Player 1 wins the game" << endl;
    }
    else {
        cout << "Player 2 wins the game" << endl;
    }

}