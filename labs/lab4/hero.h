#ifndef HERO_H
#define HERO_H

#include "card.h"
#include <vector>

enum Kingdom {
    WEI = 34, SHU = 31, WU = 32, NEUTRAL = 90, KINGDOM_SIZE = 4
};

enum Gender {
    MALE, FEMALE, GENDER_SIZE
};

extern const char *GENDER_NAMES[GENDER_SIZE];

class Hero {
protected:
    Kingdom kingdom;
    Gender gender;
    unsigned int life;
    std::string name;
    std::string asciiArt;
    std::vector<const Card *> castedCards;
public:
    Hero(Kingdom kingdom, Gender gender, unsigned int life, const std::string &name, const std::string &asciiArt);

    virtual Kingdom getKingdom() const;

    virtual Gender getGender() const;

    virtual unsigned int getLife() const;

    virtual std::string getName() const;

    virtual void printName() const;

    virtual void printHero() const;

    virtual const Card *castCard(const Card *card) = 0;

    virtual ~Hero();
};

class ZhaoYun : public Hero {
public:
    ZhaoYun();

    const Card *castCard(const Card *card) override;
};

class ZhenJi : public Hero {
public:
    ZhenJi();

    const Card *castCard(const Card *card) override;
};

class HuaTuo : public Hero {
public:
    HuaTuo();

    const Card *castCard(const Card *card) override;
};

class LuBu : public Hero {
public:
    LuBu();

    const Card *castCard(const Card *card) override;
};

class DiaoChan : public Hero {
public:
    DiaoChan();

    const Card *castCard(const Card *card) override;
};

extern Hero *newHero();

#endif
