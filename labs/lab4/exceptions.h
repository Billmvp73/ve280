#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "card.h"
#include "player.h"
#include <exception>
#include <string>

class EmptyDeckException : public std::exception {
};

class DiscardException : public std::exception {
};

class InvalidInputException : public std::exception {
    const std::string m;

public:
    InvalidInputException(const std::string &s);

    virtual const char *what() const noexcept;
};

class CardException : public std::exception {
public:
    virtual const char *what() const noexcept = 0;
};

class NonCastableCardException : public CardException {
    const std::string m;

public:
    NonCastableCardException(const Card *card);

    virtual const char *what() const noexcept;
};

class NonPlayableCardException : public CardException {
    const std::string m;

public:
    NonPlayableCardException(const Card *card);

    virtual const char *what() const noexcept;
};

class TargetException : public std::exception {
public:
    virtual const char *what() const noexcept = 0;
};

class SelfTargetException : public TargetException {
    const std::string m;
public:
    SelfTargetException(const Player *player);

    virtual const char *what() const noexcept;
};

class DeadTargetException : public TargetException {
    const std::string m;
public:
    DeadTargetException(const Player *player);

    virtual const char *what() const noexcept;
};

class GenderException : public TargetException {
    const std::string m;
public:
    GenderException(const Player *player);

    virtual const char *what() const noexcept;
};

#endif
