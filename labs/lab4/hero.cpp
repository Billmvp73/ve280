#include "card.h"
#include "hero.h"
#include "exceptions.h"
#include <iostream>
#include <random>

using namespace std;

const char *GENDER_NAMES[] = {"Male", "Female"};

Hero::Hero(Kingdom kingdom, Gender gender, unsigned int life, const std::string &name, const std::string &asciiArt) :
        kingdom(kingdom), gender(gender), life(life), name(name), asciiArt(asciiArt) {}


Kingdom Hero::getKingdom() const {
    return kingdom;
}

Gender Hero::getGender() const {
    return gender;
}

unsigned int Hero::getLife() const {
    return life;
}

std::string Hero::getName() const {
    return name;
}

void Hero::printName() const {
    cout << "\033[" << kingdom << "m" << name << "\033[0m";
}

void Hero::printHero() const {
    printName();
    cout << endl << "\033[" << kingdom << "m" << asciiArt << "\033[0m" << endl;
}

Hero::~Hero() {
    for (const Card *castedCard: castedCards) {
        delete castedCard;
    }
}

ZhaoYun::ZhaoYun() : Hero(SHU, MALE, 4, "赵云", R"(    ,/##(*%@@%/###(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((/*,......,*/(####/
  .,/(#&%/%@@%(%#/*//////////////////////////////////////////////////////////////////*********//(#(
*//##%%/&@@%(#//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
#%#((#%#/,***/(#//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
#&&&&%(,    .,*/*/%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
#####/.  ,@@@@@@@@@@@&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
%%%%%(,..,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
/#######//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
((/***//*(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%/(/
(//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%/(/
(//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&%%%%%&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@@@@@@@@@@@@@@@%/((
(//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&%%&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#((###%&@@@@@@@@@@@@%///
(//%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&%(#%&&%%#%&@@@@@@@@@@@%///
(//%&&@@@@@@@@@@@@@@@@&&&&&&&&&&&@@@@@@@@@@@@&&&&%%%%%&&@@@@@@@@@@@&&&%%##&&&&&&&&&&@@@@@@@@@@@%/(/
((/%&&@@@@@@@@@@@@@@&&%####%%&&&&&&@@@@@@@@@&&%%#((((((##%&@@@@@@@@@@@&%##&&&&%%%&&&@@@@@@@@@@@%/(/
(//%&@@@@@@@@@@@@@@&%##((((###%&&&@@@@@@@@@@&%%#(/****,***/(#&@@@@@@@@&%%%%%%%%###%&&&@@@@@@@@@%/(/
(//%@@@@@@@@@@@@@@@&%########%%&&@@@@@&&&@@@&&%%#///**,,,,*//(#&@@@@@&&%%%%%&%%######&@@@@@@@@@%/(/
(//%&@@@@@@@@@@@@@&###%%&&&&&@@@@&&%%&&&@@@@&&%#(/*,.,,,,*/((#&@@@@&&%%#%%%%%#((#((%@@@@@@@@@%/(/
(//#&&@@@@@&%%((#%&&%%&&&&@@@@@@@@&&&&&&&&&&@@@@@%(*,..,,,***//(#%&@@@&&&%%###%####(#&@@@@@@@@@%/(/
(//#%&&@@@@&&%(/(#%&&@@@&&&@@@@@@&&&@@@&%##(#%%&&(*,,,,,****//((%&@@@&&%%###%%##(/&@@@@@@@@@@%/(/
(//##%&@@@&&&&%##%&&@@@@@@@@@@@@&&@@&%&//((((((%&/,,,,***//////(%@@@&((((((/(%@@@@@@@@@@@%/(/
(//###&@@@&&%%%&&&&@@@@@@@@@@@&&&&&&&%%#(/**/((///(%%#*,,,**////////(&@@@&(////((%&@@@@@@@@@@@@%/(/
((/###%&@@&%%%#%&&@@@&&&&&&&&&&%%#%%%##//**,,,,**,*/#%(/*****////////#&@@////%&@@@@@@@@@@@@@@%/(/
(//#%##%@@&%#((%%%&&@@@&%%%%%&%%##(((((/*,,......,,,,*%#(***///////**/(%&&%(/(%@@@@@@@@@@@@@@@@%/(/
(//####%&@@((///(#&@@(######((/****,,,.........,,,(##(/*///////***/(%&&%#%&@@@@@@@&@@@@@@@@%/(/
(//#((##%&@@%(/****/#&&%(,*/(//**,,,,,................,*/((/***////*****/#&&&&&&@@@@@@&&&&&&&&/(/
(//(//(#%&@@/*******///,*////**,,,..................,,,*///***********/(&@@@&&&@@@@&&&&%&&&%%(*(/
(//(///(#%&@@%(****,,,,**,,*////**,,,..................,,,,///**********/(&@@@&&&&&&&&&%%#####%(*(/
(//#(////#&&@@&/****,,.,,.,*/////**,,,..................,,,,***********/(#&&&&&&&%%#(////(###%%#/((
(//#(/////#&&@@#/****,,,,.,**/////***,,..................,,,,********//(%%%%##((///***//(###%%%(/(/
(//%#((((((#%&@&%(/**,,,,.,,**///////**,,................,,,****((###((///////******((##((#####(/(/
(//%#(((///((%&@&%(/*,,,,.,,**//(((((((*,................,,*/((#((////////((((//(###(////(((##%(/(/
(//#%(///////(#&&@***,,,,*/##%%&&%%#(,.................,,,*/(#(/***,**/((##((((*******//(#%%%(/((
(//#%#(///////(#%&@&/**,*/(##%%%%%##((/,..........,,....,,,,***(#(*******/(////((*******/((#%%%(/(/
(//###(/////////(#&/***//((((((((((/*.....,*////*,,,,,,,,,****##(/*,***/(//((/*******/((#%%%/(/
(//##((((//////////(&%(***,,..    ,,*,,*/(###(*,,,*,,,,,,,,,****/(%%#**,,,/((((/****//(#%%%&&&/(/
(//##(((((//(((/////(%%(/**,,..    .,,*(###/,,,**/**,,,,,,,*****(#%&&(/*,,*/#%#/****(##%%&&&&&/(/
///%#((((#((////////**/(#****,..     ..,,,,*/((((/*,,,,,,,,***/(%%%%%&/*,,/##///((%##%%%%##%%(*(/
///%#((((#(////(((//*,,*//***,,.       .,,,.,*****,,,,,,,,,**(#%%%%%%&&&%(,,*/##((#%#(##%##%%%#/*(/
///%#((((((((((((((/*,,,*/***,,.. ..  . .,,,,,,,,,,,,,,,,,,(#%%%%%%%%%%&&%**,*/####%####%%#%%%#(/(/
///##((((##((((((((/**,,*******,,......   ..*,,,,.....,,/(#%%&&&%%%%%%##%&(/***#%###&&&&&&%%%%((/(/
///##((((#((((((((((*************,..........***,,...,,(#%%%&&&&&%%%%%####%%(***(#%##&&&&&/*/((//##/
,,/#((((((((((((((((//***********,.....,,*/#%%%#(#%%&&&&@@@@@@@@&&%%%##(((&%#/*/(#%%&&&&&(%(****,
.,/#(((((((((((((((((//***********,,,,*(#%&&&&&&&&&@@@@@@@@@@@@@&&&%%##(((%&%(/*/#%%&&@&&(%#*(##(((
.,/#(((((((((((////(((//**********//(#%&&&&&&&&&&@@@@@@@&&&@@@@@@&&&%##(((#%&%(///((%%%%%#%#/((/***
 .*#(((###(((((/////((//*///((#%%&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@&&&&%##((((#%%%(/,*%&%%%&&%/,.  .//
..*##(####(((((/////(##(((#%%&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&%%#(((//(#%%%(*(%//////*. ,*,*(/
*,*##(((##(((///////(#%&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&%%#((//((#%&&%//(/%@.. .(%((#(
##(/////////////******/////////////////////////////////////////////*********///(((#(/%@&(,***/((##()") {}

const Card *ZhaoYun::castCard(const Card *card) {
    if (card == nullptr) {
        throw NonCastableCardException(card);
    }
    const Card *castedCard;
    switch (card->getAction()) {
        case STRIKE:
            castedCard = new Dodge(card->getSpot(), card->getSuit());
            break;
        case DODGE:
            castedCard = new Strike(card->getSpot(), card->getSuit());
            break;
        default:
            throw NonCastableCardException(card);
    }
    castedCards.push_back(castedCard);
    return castedCard;
}

ZhenJi::ZhenJi() : Hero(WEI, FEMALE, 3, "甄姬", R"(    ,/##(*%@@%/####(((((((((((((((((((((((((((((((((((((((((((((((//(((((((((((((/*,......,*/(####/
  .,/(#&%/%@@%(%#///////////////////////////////////////////////////**************************//(#(
*//#@%#%%/%@@%(#//%@@@@@@@@@@@@@@@&&@@@@@@@@@@@&%#%%&&&&%(//#&@&%#(**,,,,,,,,,,,,,,,,,*#&&@@@&%#(((
#%#(##%#/,,**/(#//%@@@@@@@@@@@@@@@&&@@@@@@@@@&&%%%%#%/,.,#&@&%(*........     .,,....,(%&@@&%##(((
#&&&&%(,.   .,*/*/%@@@@@@@@@@&&&@@@@@@@@@@@@@&&&%##%%(....*&&%#(,..,,,..  .......,,,,,*(%&@@&%#((((
#####/.  ,@@@@@@@@@@@@@@@@@@@&%%&@@&&&@@@@@@@&%###/,.. ./%@%(((///*,,.,,,,..,**//((((##%&@@@&%((/((
%%%%%(,..,@@@@@@@@@@@@@@@@@@@&&&&@@&%%&@@@@@&&%%#,    ,(&&%(###(*,,,*/////(#%%%%%%%&&&&&&&&&&%///((
/#######//@@&@@@@@@@@@@@@@@@@@@&&&@&&&&@@@@&@/,   ./&&%%%%(*,,*/(####%%&&@@@@&&&&&&&%%&&&&**/((
((/***///(@@&@@@@@@@@@@@@@@@@@&&%&@@&%%&@@@@@%(*, .*#&%%%%#*,,,*###(/%&@@@@@@@%%%&%%%%&&@&%(,,*(/
(//%@@@@@@@@&&@@@@@@@@@@@@@@@@@&%%&@&%#%&@@@@%(*,*(%#(///*,.,,/((//(%&&&&@@@@&&&&&&&%%##%@@&%/,,*((
(//%@@@@@@@@@&@@@@@@@@@@@@@@&&@&%%&@&&%#%%&&///*,,.,,.....,**,*(%%#/(#&&%%%%&@&&&%#/*/#@&%(,..,(/
(//%@@@@@@@@@&@@@@@@@@@@@@@@&&&@&&&&@@&&&&&&/*,  .,,.    ..,,,(((**,,/#%&&&&&%#(//,,.*#@*...,//
(//%@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&%%&&&%##%%&%/,. .,,.     ....,*,..,*//((/////*,,,.  .*%@%/,...,//
(//%@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&&@&%######*....                                  ./%%/,....,(/
((/%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&%%###(*.                                    ,(&(,.....,(/
(//%@@@@@@@@@@@@@@@@@@@@@@@@@%#%&@&@@&&&&&&%%%#(/..                                  .*##.......,(/
(//%@@@@@@@@@@@@@@@@@@@@@@@@@%((#&&&%%%&&&(##(*,.                                  ./(*.......,(/
(//%@@@@@@@@@@@@@@@@@@@@@@@@&%%##%&&&&&%%%%#((/*,,,.                                .,/*. ....,,*(/
(//%@@@@@@@@@@@@@@@@@@@@@@@@&&%%&&&&%(/,,,/#%/,.,,,,.                               .,.   ....,**(/
((/#%&@@@@@@@@@@@@@@@@@@@@@@&%%#(((##/,....,%#*.,,**,.                              ,.   .....***(/
(//%%%&&@@@@@@@@@@@@@@@@@@@@&%%#*..*(#/     ,((*.,***,                                   ...,,(/*(/
(//#((%%&@@@@@@@@@@@@@@@@@@@@%%#(* .*((.     *(/*,*//,                                   ..,,*%#/(/
(//#*.,/#%@@@@@@@@@@@@@@@@@@@&&%#/. .*(,     .*//**//*                                  ..,,*(/(/
(//#(,    *#&@@&@@@@@@@@@@@@@@&&&%*...,(*.    .,*/**//.                                ..,*/#%%(*(/
(/*(#/.     ,(%@&&&@@@@@@@@@@@@@@&/*...**,.   ..,*////,      ..                       ...*((((#/*(/
(/*(**/,       /%&@@@@@@@@@@@@@@@@%(/,,.....     .,**///***///*,                     ..,***/(##(*(/
(/*(..*/,       .*(%@@@@@@&&&@@@@@&/*,....      ...,*//(/*,,,.                    ..,,**(#((%(/(/
(/*(.  ,/*         .#&@@@@@&&&@@@@&&/*,...         .........       ...,,**,,.     ..,,,((//#%#/(/
(/*(.    .*.         .*#&@@&%%&&@@@@&&&(/*,...               ...,**//(####/*.     ..,,,*//(##%%#/(/
(/*(.     .,,          .*&@@#%&&@&&&&&%#/*...           .,*/((#####((///,.      ..,****(#%%%%#/(/
(//(.                    *#&@##%@@&%#%&&&%*,.          .,(((/***,,,,*///.     ..,,,,*(#%%%%%%(*(/
(/*(,                     ,(&@&%(#@@@*/#%&%(/,...        .,,,,****/(/*,.     .,,,,*/#%%%%%%%#/*(/
((/(,                    ...*&@@#&@&%.  .,%&&%#*,...         .,,,,,.       ..,,**/%%&%####(/***(/
(/*(,.           ..........  /%&@%@@%. ...*(#%&%#(/*..                    ..,**/#%&&%%##(*,. .,(/
((*(,.               ..,,,,,,,/#&@%%&@&.  .,//(((#%%%#/*,..               ..,,*/#%%%%%%%#(/,....,(/
(/*(.               .....,,,...,/#&&&@@/,,*,,,**//(((#%%%#(*,...      .....,*(#&&%%%%%%%%&%(*...,(/
(/*(.               .....,,,,.  .*%%%&@(*,*////((((///(((((%##(/*,,.....,,(#%%%######(((#(*,    ,(/
///(.           .............     (#((%*,,,,,*/(/*,*///**#%%%%%%%##%%%%%%%###%&&&/*,.       ,(/
///(,.          ....,,,,,,,,.     ,/#(#%#/*.....,****////**##((#%%%#(//(%%#(##%%&%#/*//*. .    .,(/
///(................,,,,,,,,,...   ,/(#(/***...,,**,*//////(##%%##%##((/((#(**(%%#(#&/.      .*(/
///(,....,,,,,,,,,,,,,,,,........    ,//.  ..    ,////(((#%%%###(##(##(##%###(*.,,***,.        .*(/
///(*,,,,,,,,,,,,,,,,,,,,..          .**.      ../////(##((##(((((##(((((#####%/,.       .,,***/##/
,,/#*,,**,,,,,,,,,,,,......          ./,     ./(//((((#%#(#%(/#%(//(#%######%%%&&%#/.    /%(****,
.,*(/*,,,***,,,,,,,,,,.              ,/.      .*(((######(##(#%#(((##(####%#%%%###(*     /%#*/((//(
.,*(**********,,,........            .*      ..*#&%(//(/(###(((((######((###%%%%#(/*....,(%#//*,,,*
 .*(*,,,,*,,,,,.                    .**     *//*/#%%###(((####%##%%%%##%%%%%####/,*%&%%%%&%/,.  .//
..*(*,..,,...                       .*******,*/((///(#%%%%###((######%%%%%%#(//*,,(%**/*//*. ,,,*(/
*,*(*,,........   .,    ..,,.   .,#####((#%##%#//((##%#######%%%%%%%%&%%#%&%#(****/(*(/,,.. .//*/#(
##//**,,,,****,,,,,*,,,,,,**,,,,,*///**/****/////*****////////////*******//****/((#(*/*..,****//##()") {}

const Card *ZhenJi::castCard(const Card *card) {
    throw NonCastableCardException(card);
}

HuaTuo::HuaTuo() : Hero(NEUTRAL, MALE, 3, "华佗", R"(    ,/##(*%@@%/###((((((((((((((((((((((((((((((((((((((((((((((((//(((((((((((((/*,......,*/(####/
  .,/(#&%/%@@%(%#/*///*****////////*************************************/*////////**/*********//(#(
*//#@%#%%/%@@%(#/*%((////(#####(////*****,,,,,,,,,,,,,,,,,,,,,*****/////(((#####(/(%&&@@@@@@&%(((
#%#(##%#/,,**/(#//#%//*****/(###(/**,,,,,,,,,...................,,,,,,****//((((((/*,*#%&&@@@@&%(((
#&&&&%(,.   .,*/**##(//**,*/(%%%(/*,,,,,,,,,,,,,......,,,,,,,,,,,,,,,,***///((#(((//,,*(%&&&@@@%(((
#####/.  ,&%##%%%%%#**,,.*/((#%%(/**************,****,*******************////(###((/*,,,,#&&&@@%(((
%%%%%(,..,%#%&&%#(/*,,...*/((%%%#/***********************************////////(###((//*,.,*/%&@@%(((
/#######/*@&%#(//***...../(((%%%#(****//////****************////////////(((///(%%#((//*..**,/#@%(((
((/***//*(%%##(/*,,.....,(((#%%%#(****/////////////***///////////((((//(((***/(%%#((((/,.*/**/%#/(/
(//%@@@@@&%%#(/*,.....,,*((##%&%#/*,***/((((((/////////////////((((((((/**,***/%%%#(((/,,*/***(/*((
(//%@&&%%%((/*,......,*//(#%%&%#(*,,****//((#####(((((((((((((((((((#/*,,,,,**/#%%%####/,/(/**(/*(/
(//%&%%%#(/**,......,*/((##%%%#(/*,******//(########(((((((########(/*,,,,,,**/#%%%%###(**(////**//
(//%(///*,........,*/(#%%%%#(/*,,,*******/(####################(/**,,,,.,,***/#%%%####(*////(/*//
(//#((((/*........,,*/#%%%%%#//*,,,,,,,,***///(((##########(((((***,,....,****//(#%&%###(**/((/**(/
((/%%%(*,,,..,,....,/#&&&%%%%/*,,,,..,,,,***///**(((///((((((//***,,,,,,,,***//(#%&&&%##(*/(##/**((
(//#/****,,,,,....,*#&&%%%&%%(///******///((((((((##(/**/(####((////(/(((((((##&&&&&&&/(/***,,,(/
(//(////*,(%%/,...,*%&&&&&&&%#((#####%%&&&&&@@@&&&&%#(///(#&&&&&&%&&%%%%%%%%%%&&&&&&@&%(((/,,,,,,(/
(//#(/***/%/,,...*%&&&&%&&&&&%%%&&&&&&&&&&@@@@@&&&&&&&&&&@@&&&&&&&&&%%&&&&&&&&&&&&&&%(///*,,,,*(/
(//#%&%(/#&%(/////((%&&&&&&%&&&&&&&&&%%#((##%&@@@&&&&&%%%&&&&&@@&&&&%%%&&&&&&&&%%%&&&&&%%(///*,,*(/
((/%@/(%%%#(#%####&&&&&&&%%%%%%%&&&%#(((#(##%%&&&&&%###%&&&&&&&&%%#####%&&@&%((%&&&@/////*,,,(/
((/%@#%%#(((####%%%&%%&&&%%(((//#%%&&%#(((%%%%%&&&,,*#&%%%%#%%##%##(##%%#(//((#%&&%((((/**,,,(/
(//%((##(#%#######&&&%%&&%#///**/(###(((##((##%%&@,,*(%&&&%%##(((#(((((//////(#%&&&%(*****,,*(/
((/%&%####(%&%%%#((/#%&&&&&%#/***,,,,***//***/(##&&&%(,,*(%&&&%%#((/******///***/(#%&@@%(*****,,*(/
(//%&&%##(#&@@&%%%#///(%&&&&%/**,,,........,*/#&&&&&%(,,*/#@@&&&%##(/*****,,,..,/(%&&%#(/****,,,*(/
(//#((((/*(&@@&%%%&%(/(%%&&&/**,,......,**(#&&&&&%#(,,,/(&&&&&&%##(/****,,...*(%&&%#((/***,,,,*(/
(//(/****,*#&@@&&%(#&%#####%&&%#((//****/(#%%#(%&&&%#(,,*/#&&%#(#%%%##((((////(%%&&&((#((/*,,,,,*(/
(//(/*****#%&@@@&%#(#%%##((#%&&%###((/(##%%#,..*#&&&&%(/(#%&%(/****/(%%%##((((#%&&&%/((((*,,,,,,*(/
(//(///(##%&&@@@&%%((#%&&(/(%&&%%#####%#(/,.   ..*(#%%%%%%%/***,...,,*(#%%%%###%%%%#*/((/,,,,,,,*(/
(//#%&&&&&&@@@&%#((#%&&&@(**/(/****,,..         ........,,,,.......... ..*(####%%%%(..,,,,,,,,,,*(/
(//%&&@@@&&&@&%(/(#%@&&&@(**(%###%/,.        ......,,,,,***,,,,....     ..(%%%%%%%#/.,***,,,,,,,*(/
(//%@&%%%&@&%#####%@&&&@&/,.*(/*,.         .,*/(#%&&&%%&&&&&&&&%(/*,.     .,/#%%#(/,.,/(#(/*,,,,*(/
(//%%%%&&@%##%#%&@&&@@%,...,,.         ...,*/((//((##%%%#(/(//*,,,.       .*(%#/*. .*/(###/*,,,(/
(//%&&&&%#%&@@#%&&%#(*.    ......    .....  .,/#####(((##%##(* ....         .**,,...,*,***/#(*,(/
(//%@&&%##@@@&%####/,.       ....      .....  ...,*(##%%%%%#(*,. .....     .   ,*,....*//*,,,*(/*(/
((/%@@&%%%@@@&%(*,,..                  .....     ....,,,,,,,....    ..      .  .,,,. .,*//*,,,***(/
(//%@&%%&&%#/*,....                    ....      .....   ..          .    .       .,..,*//***,,,,(/
((/%&%###(*,,,..                       ..       .............        ..   ..       .. .,*//*,,,,,(/
///%(*****..                               .......................  .....              ..*///*,,*(/
///#/**,.                                  ..............................             ..,**///,,*(/
///#*.                                     ..........................  ...             .*((///*,*(/
///(.     ....      ..,,,....             .......................      ...              ./****///(/
/**(,. .....      .,//*,....              .......................      ...              .,,**///##/
,,*(*,,,..     ,/(((,,,,,                .......................       ...              ./%(****,
.,*(*,..     .,(((/,,**,.                .................... ...      ....             ./%#*/##(((
.,*(,.    .,//****,***..                .................      ..      ....   .     ..,,,(%#///**/*
 .*(.   .,//(/,.,*,,.    .              ............           .....    ....  . ..*%&%%%&&%/,.  .//
..*/...,*////,.*/*,.    ..             .............           ......   ....  ...,(%**////*. ,,,*(/
*,*(**////*,,,/#(,....,,,        .......,,......................,,,..............,/(*((/*.. .((//#(
##/////******///*,,,,,***,,,,,,,,,,,,,,,**,,,,,,,,,,,,,,,,,,,,,***,,,.,,,,,,,,,*/(#(*//**,***///##()") {}

const Card *HuaTuo::castCard(const Card *card) {
    throw NonCastableCardException(card);
}

LuBu::LuBu() : Hero(NEUTRAL, MALE, 4, "吕布", R"(,/(#(*#%%(/####((((((((((((((((((((((((((((((((((((((((((((((((/(((((((((((((/*,......,*/(####/
  .,/(#&%/%&%#/%#////////////////////////////////////////////////////////////////////*********//(#(
*//#&%#%%/%@&%(#/*%@@@@@@@@@@@@@@@@@@@@@@@@&%&@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
#%#(##%#/,,**/(#//%@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@&&&@%(((
#&&&&%(,.   .,//*/#&@@@@@@@@&%&@@@@@@@@@@@@@@@&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@%(((
#####/.  ,@@@@@@@@&&@@@@@@@&%%#%&@@@@@@@@@@@@@&%%#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((
####%(,..,@@@@@@&%(#@@@@@@@&%%#(#&@@@@@@&&%%%###%%%%&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@%(((
/#######//@@@@@@&&&&**#&@@&&%%#(/(@@@@&&%%%#///#&%%%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@%(((
((/***//*(@@@@@@@@@&/*/#&@&&(//(&@@&&%%#((*/#&&&&@@@@@@@@@@@@@&&&@@@@@@@@@@@@@@@@@@@@@&&&@@@@%/((
(//%&&@@@@@@@@@@@&&/*/#@@&&%%#(#@@&%%##(/*/#&&&&@@@@@@@@@@@@&%%&@@@@@@@@@@@@@@@@@@@@&%%@@@@@@%/(/
(//#%%&&@@&&&&&&&&&&%#(//#&@&%%&@@@&%##%&%%%&&&&&%#%&@@@@&###%&%%%%%&@@@@@@@@@@@@&%%&@@@@@@@@%/(/
(//#%%%&&@&&&&&&&&&&&%##(/#&&%#%%&&%#%&@@@@@@@@@(#&&&&%######%&&&%%&&&@@@@@@@@&&%%&@@@@@@@@@@%///
(//%%%#%&@@&&&@&&&@@@&&&%/(&&(/#%&&%#%&@@@@@@@&&%#((((#%%#######%%&%%####%&&&&%%%%%&@@@@@@@@@@@%///
(//%%##%%&@&&%&&%%%&&&%%(%&%%&&&##&@@&&&%%####%%&@@&&&&&&%%#((%&&((#%((#%@@@@@@@@@@@@@@@@%/(/
((/%%%#%%%@@&&%&&%%######%((%&&&&&%#((%&@@&###%&&&&%%%%%&&&&&%(#%%%&&&&#%&@@@@@@@&&@@@@@@@@%/((
(//%%%%%%%&&&&&&&&@&%###%&%(/%&@&((/*%&&%###((((##%&&&&%%#%%%#&&&&&&&&&&%&@@@@@@@@#%&%%&@@@@@%/(/
(//%%%%%#%&&&&&&&@@@@&%%%&%#((%&&%((//(&%##%&&&&&&&&&%#((((%&&&&&&&&&&@@@&&@@@@@@@@&%&&%#%&@@@@%/(/
(//%&%%##%&&&&&&&&&@@@@@&&&%#(#%%#((#%&&&&&&&&&%%##(//(#(((%&@@@%%%%%&&@@&&@@@@@@@@@@@@@@@@@@@@%/(/
(//%&%%%##%&&@@@@@@&&&&&&@@@%%%##&&@@&&%##%%(*,*/(%&&%%%&(/*/((##&@@&%@@@@@@@@@@@@@@@@&@@@@%/(/
(//%&&%%%#%&@@@@@@@@@&&%%&@@@&&%##&@@@&%#((%%(//(%%&@@@@&%#/**/(##(/(&&%%&@@@@@@@@@@&&%#%%%&@@@%/(/
(//%@&&&%%#%&@@@@@@@&&@@#%@@&%%&@&&%%(%&@@&&&@@@@@&&&&&%%%%%%%(//(&&&@@@@@@@@@@@@@@@@@@@@@@@@%/(/
(//%@@@&&%#%&@@@@@@@@@@@@%#%&&&&&@@&&&%&@@@@@@@@@@@@@@@&&&&&&%%#*,*(#%%&&&&@@@@@@@@&&&&&&&@@@@/(/
(//%&&@@&%#%%@@@@@@@@@@@@@@&&&&&&@@@@@@@@@@@@@@@@@@@@@&%#(#&%%#/,,,*/##%%&@&@@@@@@@&@@&&&@@@&&/(/
(//%&&&@@&%#%&@@@@@@@@@@&&@@@@@%%%&&&@@@@@@@@&/*/(%%%##%&&%/*,,**/(%%&&&&@@@@@@&&&@@@@@@@@@@/(/
(//%&&&@@&%%#%&@@@@@@@@@@%%&@@@&%#&&&&@@@@@@@@@&&%%&&&&&&%%(*,,,,*/(#%&&&&&@@@@@@@@@@&&@@@@@@(*(/
(//%&%&@@@%%##%&@@@@@@@&&@@@@@@@%(#%%&&@@&&&&&&&&&&%#((((/*,****//(#%&&&&&&&@@@@@@@@@@@@@@@@&%#(*((
(//%&%&&@@&%%##&&@@@@@@&&%%&&@@/((#%%&&&&&%###((((///********/(((#%&&&&&&@@@@@@@@@@@@@@@@&%%#(*(/
(//#&&%&@@&&%%#%&&@@@@@&&%#%&@@//((#%%%%%%%%####((((//******//(##%&&&&&&&@@@@@@@@@@@@@@@@&%%#(*(/
(//#%%%%&@@&&%%#%&&@@@@@@&&@@@@**//(((((///////////******//((##%%%&&&%%%&&@@@@@@@@@@@@@@&%%#%(/(/
(//%%%%%%&@@&&%#%%&&@@@@@@@@@@@***///((//**********,,,***///(#%%%&&&%%%%%&@@@@@@@@@@@@@&%%#%%#/(/
(//%&%%%%%@@@@&%%%%&@@@@@@@@@@@&(**/(((((((/**********,,*****//(%%%%&%%%%%&@@@@@@@@@@@@@@%%%%&/((
(//%&&%%%%&@@@@&%%%&@@@@@@@@@@@&(**/(##(/((#/,,,,,,,,*********//#%%%%%%%%%&@@@@@@@@@@@@@&%%%&&/(/
(//%@@@&&&&&&@@@%##%&@@@@@@@@@@&(*.*///,,*/#(*,,,,,,,,,,**//////(#%%%%%%&&@@@@@@@@@@@&&&&&&&&&/(/
((/%&@@@@&&&&&@@&%#%&&@@@@@@@@@*.,,,,((#%&*,,,,,,,,,..,,*////((##%%%%%&&@@@@@@@@@@&&&%&&&&&&/(/
(//%&&&@@@@&&&&@@&%%%&@@@@@@@@@@&(.,,*(&@@@%/**,,****,,,,,,*/(((((#%%%%&@@@@@@@@@@&&&%&&&&&&&&%(*(/
((/%&&&&&&@@&&&&&@&%%&&@@@@@@@@@@@@@@@@@@@@&((//*,,*((/*,,***/((((#%%&&@@@@@@@@&&&&&&&&&&&&%%#%(*(/
(//%&&&&&&@@@&&&&&&&%%&&@@@@@@@&&@@@@@@@@&&&&%%%%%#%&@&%#/*///(((##%%@@@@@@@@@&&&&&&&&&&&%%###%(/(/
///%@&&&&&&&&&@&&%&&&&&&@@@@@@@@@&&&@@@&&%%#((((((((/**(#(/*///(##%%&@@@@@&&&&&%%%&&&&&%%#####%#/(/
//(&@&&&&&&&&&&@&&&&&&&&&@@@@@@@@&&&@@@@@@@@&&&&%##((/,,*/*///((#%&@@@@&&&&&&%%%&&&&&%######%%&%/(/
///%@@@@@&&&&&&@@@&&&&&&&@@@@@@@@@&&&@@@@@@@@@&&%##(/*,,***//((#%&@@@@&@@&%%%%%&&&&%######%%&&@%((/
///%&@@@@@@&&&&&&&@@&&&&&&@@@@@@@@@&&&&@@@@#((////*,,****(##%%@@@&&&&&%%%%&&&&%%####%%&@@@@&%(((/
///%@&@@@@@@&&&&&&&@@@&&&@@@@@@@@@@@&&&@@@@&(/*,,,,,,,,,**/#%&&@@@&&&&&%%%&&&&&%###%%&&&@//((//(##/
,*/%&&@@@@@@@@&&&&&&@@@@&&&@@@@@@@@@@@@@@@@@&%%########%%%%@@@@@&&@&&%&&&&&&%%#%&&&&&&@&&(%(****,
.,/%&&@@@@@@@@@&&&&&&@@@@&&&&@@@@@@@@@@@@@@@@@@@&&&&&&&&@@@@@@@&&&&&%&&&&&%##%&&&&&&&&%%%(%#/(%%%%%
.,/%&&&@@@@@@@@&&&&&&&@@@@&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@&%%%&&&%%##%&&&&%%%##((###%#/(#####
 ./%&&&&@@&&&&&@@&&&&&&&&&@&&&%&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%%&&&&%##%&@@@@@,*%&%%%&&%/,.  .//
../%&&&&&&&&&&&@&&&&&&&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@&%%&&&&&%&&&@@@@@&&%(*(%*/////*..,*,*(/
*,/%&&&&&&&&&&&@&&&&&&&&&&&&&&@@@&@@&&&@&&&&&&@@@@@@@@@@@@&%%&&&&&&&@@@@@@%%###//(/%@&%,. .((#(
##(((((((((((((((///////////////////////////////////////////////////***///***//(((#(/%@,***/((##()") {}

const Card *LuBu::castCard(const Card *card) {
    throw NonCastableCardException(card);
}

DiaoChan::DiaoChan() : Hero(NEUTRAL, FEMALE, 3, "貂蝉", R"(    ,/(#(*%@@%/###(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((/*,......,*/(####/
  .,/(#&%/%@@%(%#/*/////////////////////////////////////////////////////////////////***********/(#(
*//#&%#%%/%@@%(#//%@@@@@&&&&&&@@@@&&&&&&&%%%%&&&&&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@%%&&@@@@@@%(/((
#%#(##%#/,***/(#//%&&@@@@&&&%&&&&&%#//(%%&&%%%%%%&&@@&&%%%&@@@@@@@@@@@@@@@@@@@@@@@(#%%&@@@@@(((
#&&&&%(,.   .,*/*/%@@@@@@&&&&&%%%#*,...*(#%%&&&%%##%&&@@@&&&&&@@@@@@@@@@@@@@@@@@@&(*(((###&@@@@%(((
#####/,  ,@@@@@@@@@@@@@@&&&&&%%%#(,..    ..*(#%%&&&%%%%%&&&@@@@&&@@@@@@@@@@@@@@@@%#/#((##(#&@@@%(((
&%%%%(,..,@@@@@@@@&&&&&&%%##/,,*#%(,.       ,*(##&&&%%%%%%%%&&@@@@@@@@@@@@@@@@@@@&%##(///(%&@@@%(((
/#######//@@&&&%##(/,,..        .,%*.      .,*/#####&&&&&%%%%%&&&&@@@@@@@@@@@@@@@&%%%#(#%&@@@%(((
((/***//*(@&%#(*,..            .,*(#%%(. .. .*//*,,/(((##%%&&&&%%%%&&&&@@@@@@@@@@@@@@@&&&%&&@@@%/((
(//%@@@@@@%(*..               ..*/,*/#&/,,. ,***,   .,//((###%%%&&&&&&&&&@@@@@@@@@@@&&&%#%%%&@@%/((
(//%@@&%#(#*.               ....,,**,,*%*,*/,.       ..,*(####/((#%&&&&&&&@@@@@@@@@&&&&&@@@@@%/(/
(//%@*..(/,.               .,,,,*,,,,/#%%(/*,      .,..  .,*(#%%#((%&&&&&&&&&@@@@@@&&&&@@@@@@%///
(//%@&(,  */*.           .   ...,**,,***//#%(,    .,,,.    ..,*/#%&@@@&&&&%%%%%&&&@@@@@@&@@@@@@%///
(//%&*.  ,//,          .,,,**,,*,*///(///(##(//(*,.....,*(#%%&&&%(/#%&&&%%%###%%%&@@@@@@@@@@@%/(/
((/%&&%(*...*//            .,,****///***/((/*(%&%,....,*/(#&&&&&&*,###(/**/(####%%@@@@@@@@@@@%/(/
(//%&%&%%#/**/(/**///****/////(////**,,(##/,.,,,*#(/*,/(%%%/#&&##((/*,. .....,,**/%&@@@@@@@@@%/(/
(//%@&%&%#,,***/*,,***,,,,,,,,.,,,**///((/,.  .,,*(####%&&%(%&&%(/**,... ......,,,,*(%&@@@@@@@@%/(/
(//%@&&&&%,.   .,,..               .,***,.     ..***(#%&&%%#(/*,,..............,,,,*/(%&@@@@@@@%/(/
(//#&@@&&/.            ..,*((((*.....        ..,,****(#%%*,..................,,,,,*/#%&@@@@@@%/(/
(//#&&@@&&&%/.       ..,**///***,,,,,,,...       ..,***,,*(%#(*,    ...........,,,,,*/(%&@@@@@@%/(/
(//%%&&@@@&&&%/  ......,,,,,******/////**,,.        ....,,...*/##(/*.    ...........*/(%&@@@@@@%/(/
(//%%%&@@@&%%&&,......,,,,,**//(((##(/////*,              ......*(###/*..  .........,*(#&@@@@@@%/((
(//%%%%&@@@&%%*...,,,,*/((##%%%%%%#(/**/**..                ......,(###(,... .....,*/#&@@@@@@%/(/
(//%&&%%&@@@@&&%%#(***/(#&&&&&&&%(..,,,,*****,.                          .*/((#(((((((#%&@@@@@@%/(/
(//%@&&&&&@@@@@&%((#/(#%#&&&%#%#*,...,,,,,*,,.                              .,,**/(##%&@@@@@@%/(/
(//%@@@&&&@@@@@@@&%(%&&&%%%&&%#(/*.....,,,,,,,,,.                                ...,*/##%&@@@@#/(/
(//%@@@@@@&@@@@@@@@&(#%%%%%%#(/*,...........,,,,,                                 ..,*(##/#&@@@#/(/
(//%@@@@@@&&&@@@@@@@((#(//*,,..............,,,,.                                ..,*(#(,*(&@@#/(/
(//%@@&@@@@@&&@@@@@@@@&%(*,...........  ......,,,,,.       ...                    ..,/##(,.,*#@#/(/
(//%@@@@&&@@@&&@@@@@@@@&&(/*,........     ....,,,**,.    ..**,.                   ..*(#(/,...,%#/(/
((/#%%%&@@&&&&@&&@@@@@@@&%###*,,.....       ..,,,********///*.                   ..,(#((/,,,..***(/
(//(((##%&&&&&&&&&@@@@@@@&%####/*....       ...,,****//////*,                    ..,##(//,,,.,*,*(/
(//(***/((#%&&&&&&&@@@@@@@@&&%#(/**,..        .....,,*****,.   ..,,**,          ..*(#((/*,,,,,..,(/
((/#*,,,*///(#%&&&&&@@@@@@@@@@&&%(,....          ...........,,,,,****.         ..,/(((//*,,,,..,*(/
(//#/*,,,,*////#&&&@@@@@@@@@@@@&&&%(*,.                 ..,**,,,,***,          .,/(#(////,,..,/**(/
((/(*,***,,,,,,,,*/(%&&@@@@@@@@@@&%%&&%(/,.           ,***********,,.         .*(##(((/*,,,*(((**(/
(//(*,,,,,,,,,,,,,,,,*/((#%&&@@@@@&&&%%(((/,          ...,,***,,,,...        .,(##((((/*,*/(#(*,*(/
///#*,,,,,,,,,,..,,,..,,,*/#%%##%########((((*,..            ...,...       ..*(#((((((/*.*/(/*,,*(/
///#*,,,,,,,,,,,,...,********,....,,,,****//##((/*,..                     .,*/(((##((((/,,/(/****(/
///(*,,,,,,,,,,..,,,,,,..........................,,,,,.....            ...*//((###%%%####/((((///(/
///(*,,,,,,,,,,,,,,.............                      ...,,,,,,,,,,,*(#%%&&&&&&%%%%%&&&&&&&&&&&%((/
///(*,,,,,,,,,*,............                              ..........,***/(((/**,,..,**//(**/((((##/
,,/(/*,,,,,**,.........                                                 .,,,...     ...../%(****,
.,*(/***,,*,........                                                   .,,.....   ......./%#*/###%%
.,*(/**,**,.......                                                    .,,.......   .,,,.,(%#//***/(
 .*(/****,......                                                     .......     .*%&%%%&&%/,.  .//
..*(*****......                                                      ..  ...    .,(%**/*//*. ,,,*(/
*,*(***,......                                                  ................,,/(*(/*,.. .//*/#(
##//**********,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*/(#(*(/,.,***///##()") {}

const Card *DiaoChan::castCard(const Card *card) {
    throw NonCastableCardException(card);
}

Hero *newHero() {
    switch (rand() % 5) {
        case 0:
            return new ZhaoYun();
        case 1:
            return new ZhenJi();
        case 2:
            return new HuaTuo();
        case 3:
            return new LuBu();
        case 4:
            return new DiaoChan();
        default:
            return nullptr;
    }
}
