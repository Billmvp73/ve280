#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <list>

const int NUM_CARDS = 77;

class Deck {
    const Card *cards[NUM_CARDS];
    std::list<const Card *> deck;
public:
    Deck();

    void pushCard(const Card *card);

    const Card *popCard();

    ~Deck();
};

extern Deck *getDeck();

#endif
