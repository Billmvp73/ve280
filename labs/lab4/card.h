#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

enum Suit {
    SPADES, HEARTS, CLUBS, DIAMONDS, SUIT_SIZE
};

extern const char *SUIT_NAMES[SUIT_SIZE];

enum Spot {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, SPOT_SIZE
};

extern const char *SPOT_NAMES[SPOT_SIZE];

enum Action {
    STRIKE,
    DODGE,
    PEACH,
    ARROW_BARRAGE,
    BARBARIAN_INVASION,
    SOMETHING_FOR_NOTHING,
    BOUNTIFUL_HARVEST,
    DISMANTLE,
    SNATCH,
    DUEL,
    ACTION_SIZE
};

extern const char *ACTION_NAMES[ACTION_SIZE];

class Player;

const size_t CARD_WIDTH = 13;

class Card {
protected:
    Spot spot;
    Suit suit;
    Action action;
public:
    Card(Spot spot, Suit suit, Action action);

    virtual Spot getSpot() const;

    virtual Suit getSuit() const;

    virtual Action getAction() const;

    virtual std::string toString() const;

    virtual void printCard() const;

    virtual void takeEffect(Player *source, const std::vector<Player *> &targets) const = 0;

    virtual ~Card() = default;
};


class Strike : public Card {
public:
    Strike(Spot spot, Suit suit) : Card(spot, suit, STRIKE) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class Dodge : public Card {
public:
    Dodge(Spot spot, Suit suit) : Card(spot, suit, DODGE) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class Peach : public Card {
public:
    Peach(Spot spot, Suit suit) : Card(spot, suit, PEACH) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class ArrowBarrage : public Card {
public:
    ArrowBarrage(Spot spot, Suit suit) : Card(spot, suit, ARROW_BARRAGE) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class BarbarianInvasion : public Card {
public:
    BarbarianInvasion(Spot spot, Suit suit) : Card(spot, suit, BARBARIAN_INVASION) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class SomethingForNothing : public Card {
public:
    SomethingForNothing(Spot spot, Suit suit) : Card(spot, suit, SOMETHING_FOR_NOTHING) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class BountifulHarvest : public Card {
public:
    BountifulHarvest(Spot spot, Suit suit) : Card(spot, suit, BOUNTIFUL_HARVEST) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class Dismantle : public Card {
public:
    Dismantle(Spot spot, Suit suit) : Card(spot, suit, DISMANTLE) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class Snatch : public Card {
public:
    Snatch(Spot spot, Suit suit) : Card(spot, suit, SNATCH) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

class Duel : public Card {
public:
    Duel(Spot spot, Suit suit) : Card(spot, suit, DUEL) {}

    void takeEffect(Player *source, const std::vector<Player *> &targets) const override;
};

#endif
