/**
 * Created by: Simon Bilodeau 40130702
 * Due date: Oct 3rd, 2021
 * Class: COMP 345
 * Professor: Joey Paquet
 *
 * Orders.cpp description:
 * This file includes the method descriptions for the following classes:
 * OrdersList, Orders, and subclasses of Orders: Deploy, Advance, Bomb, Blockade, Airlift, Negotiate.
 * The class OrdersList has a vector of Orders objects as its only member. This vector is composed of
 * objects of the subclasses of Orders. These are orders used by the players to order their armies around
 * the map. Each order has a different function for the player, described in its "identify()" method.
 */

#include "Orders.h"
#include "Player.h"
#include "PlayerStrategy.h"
#include "AggressivePlayerStrategy.h"
#include <iostream>
#include <vector>
using namespace std;

//------------------------------------------------------
// OrdersList functions
//------------------------------------------------------

/**
 * output of the OrdersList class
 * @param out ostream insertion operator of OrdersList
 * @param ordersList the list of objects to output
 * @return returns string of text describing ordersList
 */
ostream &operator << (ostream &out, const OrdersList &ordersList) {
    out << "OrdersList object. Holds a list of objects that are subclasses to the Orders class. \n";
    return out;
}

/**
 * Adds a Deploy object to a list of Order objects
 * @param deploy Is the Deploy object to add to the list of Order objects
 */
void OrdersList::addDeploy(Deploy * deploy) {
    this->ordersList.push_back(deploy);
    for(Observer* observer : *_observers)
        deploy->Attach(observer);
    cout << "Deploy order added." << endl;
    Notify(this);
}

/**
 * Adds a Advance object to a list of Order objects
 * @param advance Is the Advance object to add to the list of Order objects
 */
void OrdersList::addAdvance(Advance * advance) {
    this->ordersList.push_back(advance);
    for(Observer* observer : *_observers)
        advance->Attach(observer);
    cout << "Advance order added." << endl;
    Notify(this);
}

/**
 * Adds a Bomb object to a list of Order objects
 * @param bomb Is the Bomb object to add to the list of Order objects
 */
void OrdersList::addBomb(Bomb * bomb) {
    this->ordersList.push_back(bomb);
    for(Observer* observer : *_observers)
        bomb->Attach(observer);
    cout << "Bomb order added." << endl;
    Notify(this);
}

/**
 * Adds a Blockade object to a list of Order objects
 * @param blockade Is the Blockade object to add to the list of Order objects
 */
void OrdersList::addBlockade(Blockade * blockade) {
    this->ordersList.push_back(blockade);
    for(Observer* observer : *_observers)
        blockade->Attach(observer);
    cout << "Blockade order added." << endl;
    Notify(this);
}

/**
 * Adds a Airlift object to a list of Order objects
 * @param airlift Is the Airlift object to add to the list of Order objects
 */
void OrdersList::addAirlift(Airlift * airlift) {
    this->ordersList.push_back(airlift);
    for(Observer* observer : *_observers)
        airlift->Attach(observer);
    cout << "Airlift order added." << endl;
    Notify(this);
}

/**
 * Adds a Negotiate object to a list of Order objects
 * @param negotiate Is the Negotiate object to add to the list of Order objects
 */
void OrdersList::addNegotiate(Negotiate * negotiate) {
    this->ordersList.push_back(negotiate);
    for(Observer* observer : *_observers)
        negotiate->Attach(observer);
    cout << "Negotiate order added." << endl;
    Notify(this);
}

/**
 * OrdersList default constructor
 */
OrdersList::OrdersList() = default;

/**
 * OrdersList destructor
 */
OrdersList::~OrdersList() {
    cout << "OrdersList destroyed\n";
}

/**
 * OrdersList copy constructor
 * @param o1 OrdersList object to be copied
 */
OrdersList::OrdersList(const OrdersList &o1) {
    for (auto i : o1.ordersList) {
        this->ordersList.push_back(i);
    }
}

/**
 * Returns the list of Order objects from the OrdersList object
 * @return ordersList, the list of Order objects in the OrdersList object
 */
std::vector<Orders*> OrdersList::getList(){
    return this->ordersList;
}

/**
 * To access a single member of the list of Order objects in OrdersList object
 * @param index The index of the object being accessed
 */
Orders* OrdersList::getListMember(int index) {
    return this->ordersList.at(index);
}

/**
 * To move an object from the ordersList from one index to another
 * @param indexFrom The object being moved
 * @param indexTo Where to move the object
 */
void OrdersList::move(int indexFrom, int indexTo) {
    if (indexFrom > indexTo) {
        this->ordersList.insert(ordersList.begin() + indexTo, this->ordersList[indexFrom]);
        this->ordersList.erase(ordersList.begin() + indexFrom + 1);
    } else if (indexFrom < indexTo) {
        this->ordersList.insert(ordersList.begin() + indexTo, this->ordersList[indexFrom]);
        this->ordersList.erase(ordersList.begin() + indexFrom);
    } else {
        std::cout << "Order already there, cancelling move call.\n\n";
    }
}

/**
 * Removes an object from the list of Orders
 * @param index The index of the object being removed
 */
void OrdersList::remove(int index) {
    delete this->ordersList.at(index);
    this->ordersList.erase(ordersList.begin()+index);
}

/**
 * copy constructor of Orderslist
 * @param p copied object
 * @return the object
 */
OrdersList &OrdersList::operator=(const OrdersList &p) {
    return *this;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string OrdersList::stringToLog(){
    string log = "Log :: Added Order : " + ordersList.back()->name + " to Player : " + ordersList.back()->playerLink->getName();
    return log;
}

//------------------------------------------------------
// Orders functions
//------------------------------------------------------

/**
 * Orders default constructor
 */
Orders::Orders() = default;

/**
 * Orders destructor
 */
Orders::~Orders() = default;

/**
 * Orders copy constructor
 * @param o1 Object to be copied
 */
Orders::Orders(const Orders &o1) = default;

/**
 * Orders identify to output a string identifying the object called
 */
void Orders::identify() {
    std::cout << "Orders object: ";
}

/**
 * output of the OrdersList class
 * @param out ostream insertion operator of Orders class
 * @param orders the object being outputted as a string
 * @return the string output for the Orders class
 */
ostream &operator << (ostream &out, const Orders &orders) {
    out << "Orders object: ";
    return out;
}

/**
 * Orders validate, a placeholder for the validate method of subclasses
 */
void Orders::validate(Player & player) {
    std::cout << "Orders validate method.";
}

/**
 * Orders execute, a placeholder for the execute method of subclasses
 */
void Orders::execute(Player & player) {
    Notify(this);
    std::cout << "\nOrders executed.\n";
}

/**
 * Player linked to an order
 * @return the player linked
 */
Player * Orders::getPlayerLink(){
    return this->playerLink;
}

/**
 * setting player to an order
 * @param player the player being linked
 */
void Orders::setPlayerLink(Player & player){
    this->playerLink = &player;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Orders::stringToLog(){
    string log = "Log :: Generic Order Executed";
    return log;
}


//------------------------------------------------------
// Deploy functions
//------------------------------------------------------

/**
 * Deploy setArmies to change the value of armies in a Deploy object
 * @param sArmies the new number of armies
 */
void Deploy::setArmies(int sArmies) {
    this->armies = sArmies;
}

/**
 * Deploy getArmies to get the number of armies in a Deploy object
 * @return the number of armies in the Deploy object
 */
int Deploy::getArmies() const {
    return this->armies;
}

/**
 * Deploy default constructor
 */
Deploy::Deploy() = default;

/**
 * Deploy constructor
 * @param sArmies armies to be deployed on selected territory
 * @param territory the selected territory
 */
Deploy::Deploy(int sArmies, Territory& sTerritory) {
    name = "Deploy";
    this->armies = sArmies;
    this->territory = &sTerritory;
}

/**
 * Deploy destructor
 */
Deploy::~Deploy() {
    cout << "Deploy destroyed\n";
}

/**
 * Deploy copy constructor
 * @param d1 Deploy object being copied
 */
Deploy::Deploy(const Deploy &d1) {
    this->armies = d1.armies;
}

/**
 * assignment operator for Deploy
 * @param p pointer of Deploy
 * @return returns assigned Deploy
 */
Deploy &Deploy::operator=(const Deploy &p) {
    this->armies = p.armies;
    return *this;
}

/**
 * Deploy validate checks if the Deploy object can execute
 * @param player player deploying armies
 */
void Deploy::validate(Player & player) {
    int checkRefusal = player.getTerritorySize();
    // validate if player has enough armies
    if (this->getArmies() <= player.getReinforcements()) {
        // validate if territory is owned by current player
        for (int i = 0; i < player.getTerritorySize(); i++) {
            if (this->territory->id == (player.getTerritoriesOwned(i)->id)) {
                std::cout << "Enough armies, and territory owned by " << player.getName() << "! Deploying armies in " << territory->name << "!";
                Deploy::execute(player);
                return;
            } else {
                // refuse to deploy vArmies
                if (checkRefusal == 1) {
                    std::cout << "Territory not owned by current player, cannot deploy armies.\n";
                } else {
                    checkRefusal--;
                }
            }

        }
    } else {
        // refuse to deploy vArmies
        std::cout << "Not enough armies available to deploy in " << territory->name << "." << endl;
    }
}

/**
 * Executes a Deploy order
 * @param player player deploying armies
 */
void Deploy::execute(Player & player) {
    this->territory->unitsGarrisoned = this->territory->unitsGarrisoned + this->armies;
    player.setReinforcements(player.getReinforcements()-this->armies);
    std::cout << "\nDeploy executed. New number of armies in " << territory->name << ": " << this->territory->unitsGarrisoned << endl;
    Notify(this);
}

/**
 * Identifies a Deploy object when called
 */
void Deploy::identify() {
    Orders::identify();
    std::cout << "Deploy object. Can deploy armies to territories. It needs " << this->getArmies() << " armies.\n";
}

/**
 * output of the Deploy class
 * @param out ostream insertion operator of Deploy class
 * @param deploy object to be outputted
 * @return string of text describing the passed Deploy object
 */
ostream &operator << (ostream &out, const Deploy &deploy) {
    out << "Deploy object. Can deploy armies to territories. It needs " << deploy.getArmies() << " armies.\n";
    return out;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Deploy::stringToLog(){
    string log = "Log :: " + playerLink->getName() + " Deployed " + to_string(getArmies()) + " Units to " + territory->name;
    return log;
}

//------------------------------------------------------
// Advance functions
//------------------------------------------------------

/**
 * Advance setArmies to change the value of armies in a Advance object
 * @param sArmies the new number of armies
 */
void Advance::setArmies(int sArmies) {
    this->armies = sArmies;
}

/**
 * Advance getArmies to get the number of armies in a Advance object
 * @return the number of armies in the Advance object
 */
int Advance::getArmies() const {
    return this->armies;
}

/**
 * Advance default constructor
 */
Advance::Advance() = default;

/**
 * Advance destructor
 */
Advance::~Advance() {
    cout << "Advance destroyed\n";
}

/**
 * Advance constructor
 * @param sArmies armies being advanced
 * @param source from territory
 * @param target to territory
 */
Advance::Advance(int sArmies, Territory& source, Territory& target) {
    name = "Advance";
    this->armies = sArmies;
    this->source = &source;
    this->target = &target;
}


/**
 * Advance copy constructor
 * @param a1 Advance object to be copied
 */
Advance::Advance(const Advance &a1) {
    this->armies = a1.armies;
}

/**
 * assignment operator of Advance
 * @param p pointer of Advance
 * @return returns assigned Advance
 */
Advance &Advance::operator=(const Advance &p) {
    this->armies = p.armies;
    return *this;
}

/**
 * Advance validate checks if the Advance object can execute
 * @param player player using the advance order
 */
void Advance::validate(Player & player) {
    bool canAttack = false;
    for (int j = 0; j < player.negotiatingWith.size(); j++) {
        if (playerLink->getName().rfind(player.negotiatingWith.at(j)->getName(), 0) == 0) {
            canAttack = true;
        }
    }
    if (!canAttack) {
        // check source territory is owned by player
        int checkRefusal = player.getTerritorySize();
        if (source->IsAdjacent(*target)) {
            for (int i = 0; i < player.getTerritorySize(); i++) {
                if (this->source->id == (player.getTerritoriesOwned(i)->id)) {
                    Advance::execute(player);
                    return;
                } else {
                    if (checkRefusal == 1) {
                        cout << "Source territory not owned by player! Advance order not executed.\n";
                    } else {
                        checkRefusal--;
                    }
                }
            }
        } else {
            cout << "Cannot execute advance order because territories are not adjacent!\n";
        }
    } else {
        cout << "You are currently in Negotiations with " << target->playerLink->getName() << " and can't advance to there territory!" << endl;
    }
}

/**
 * Executes an Advance order
 * @param player player using the advance order
 */
void Advance::execute(Player & player) {
    // int to check if all territories have been checked
    int checkRefusal = player.getTerritorySize();
    // loop though all owned territories
    for (int i = 0; i < player.getTerritorySize(); i++) {
        // check if source is owned by payer
        if (this->target->id == (player.getTerritoriesOwned(i)->id)) {
            // if owned by player, simply move armies to that territory
            cout << "Target owned by player, moving armies to target.\n";
            target->unitsGarrisoned = target->unitsGarrisoned + this->getArmies();
            source->unitsGarrisoned = source->unitsGarrisoned - this->getArmies();
            cout << target->name << " now has " << target->unitsGarrisoned << " armies, and " << source->name << " now has "
                 << source->unitsGarrisoned << " armies.";
            Notify(this);
            return;
        } else { // if not owned by player, attack target territory
            if (target->playerLink->getPlayerStrategy() == 1) {
                auto aggresiveStrat = new AggressivePlayerStrategy(target->playerLink);
                target->playerLink->setPlayerStrategy(aggresiveStrat);
            }
            if (checkRefusal == 1) {
                if (target->unitsGarrisoned == 0) {
                    target->unitsGarrisoned = target->unitsGarrisoned + this->getArmies();
                    source->unitsGarrisoned = source->unitsGarrisoned - this->getArmies();
                    player.addTerritory(target);
                    target->playerLink->removeTerritory(target);
                    target->playerLink = &player;
                    player.deckLink->Draw(player.getHand());
                    cout << player.getName() << " has won " << target->name << "!" << endl;
                    cout << target->name << " now has " << target->unitsGarrisoned << " armies, and " << source->name << " now has "
                            << source->unitsGarrisoned << " armies, and they have gained a card!" << endl;
                    Notify(this);
                    return;
                }
                int sourceAttack = 0;
                int targetDefense = 0;

                for (int j = 0; j < this->getArmies(); j++) {
                    bool victoryDefeat = (rand() % 100) < 60;
                    if (victoryDefeat)
                        sourceAttack++;
                }
                for (int j = 0; j < target->unitsGarrisoned; j++) {
                    bool victoryDefeat = (rand() % 100) < 70;
                    if (victoryDefeat)
                        targetDefense++;
                }
                source->unitsGarrisoned = source->unitsGarrisoned - targetDefense;
                target->unitsGarrisoned = target->unitsGarrisoned - sourceAttack;
                // check attacker has units left
                if (source->unitsGarrisoned > 0) {
                    // check if target has units left
                    if (target->unitsGarrisoned <= 0){
                        // if target has no units left, but attacker does, transfer territory to attacker
                        target->unitsGarrisoned = this->getArmies() - targetDefense;
                        source->unitsGarrisoned = source->unitsGarrisoned - (this->getArmies() - targetDefense);

                        player.addTerritory(target);
                        //player.setIncrementTerritoryCount(player.getTerritoriesOwned(player.getTerritorySize()-1)->continent-1);
                        target->playerLink->removeTerritory(target);
                        //target->playerLink->setDecrementTerritoryCount(player.getTerritoriesOwned(player.getTerritorySize()-1)->continent);
                        player.deckLink->Draw(player.getHand());
                        target->playerLink = &player;
                        cout << player.getName() << " won " << target->name << " and now has " << target->unitsGarrisoned << " units there." << endl;
                        Notify(this);
                        return;
                    } else { // if both sides have units left, nobody moves
                        cout << "Units left on both sides, no territories conquered.\n";
                        cout << source->name << " has " << source->unitsGarrisoned << " armies left, and " << target->name << " has " << target->unitsGarrisoned << " armies left." << endl;
                        Notify(this);
                    }
                } else { // if attacker has no units left, make sure target still does and set attacker units to 0
                    source->unitsGarrisoned = 0;
                    if (target->unitsGarrisoned < 0){
                        target->unitsGarrisoned = 0;
                    }
                    cout << source->name << " has " << source->unitsGarrisoned << " armies left, and " << target->name << " has " << target->unitsGarrisoned << " armies left." << endl;
                    Notify(this);
                }
            } else {
                checkRefusal--;
            }
        }
    }
}

/**
 * Identifies an Advance object when called
 */
void Advance::identify() {
    Orders::identify();
    std::cout << "Advance object. Can advance armies to territories owned. It needs " << this->getArmies() << " armies.\n";
}

/**
 * output of the Advance class
 * @param out ostream insertion operator of Advance class
 * @param Advance object to be outputted
 * @return string of text describing the passed Advance object
 */
ostream &operator << (ostream &out, const Advance &advance) {
    out << "Advance object. Can advance armies to territories. It needs " << advance.getArmies() << " armies.\n";
    return out;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Advance::stringToLog(){
    string log = "Log :: " + playerLink->getName() + " Advanced " + to_string(getArmies()) + " Units from " + source->name + " to " + target->name;
    return log;
}

//------------------------------------------------------
// Bomb functions
//------------------------------------------------------

/**
 * Bomb default constructor
 */
Bomb::Bomb() = default;

/**
 * Bomb destructor
 */
Bomb::~Bomb() {
    cout << "Bomb destroyed\n";
}

/**
 * Bomb constructor
 * @param target target territory being bombed
 */
Bomb::Bomb(Territory& target){
    name = "Bomb";
    this->target = &target;
}

/**
 * Bomb copy constructor
 * @param b1 Bomb object being copied
 */
Bomb::Bomb(const Bomb &b1) {
    // empty because Bomb has no members.
}

/**
 * assignment operator of Bomb
 * @param p pointer to Bomb
 * @return returns assigned Bomb
 */
Bomb &Bomb::operator=(const Bomb &p) {
    return *this;
}

/**
 * Bomb validate checks if the Bomb object can execute
 * @param player player bombing another player
 */
void Bomb::validate(Player & player) {
    bool checkTerritories = false;
    //check if the target territory is adjacent to a player territory
    for (int i = 0; i < player.getTerritorySize(); i++) {
        if (player.getTerritoriesOwned(i)->IsAdjacent(*target)){
            checkTerritories = true;
        }
    }
    if (checkTerritories) {
        //check if the territory target is owned by the player bombing
        int checkRefusal = player.getTerritorySize();
        for (int j = 0; j < player.getTerritorySize(); j++) {
            if (this->target->id == (player.getTerritoriesOwned(j)->id)) {
                // invalidates the order
                cout << "You are trying to bomb your own territory! Don't do that!" << endl;
            } else {
                if (checkRefusal == 1) {
                    Bomb::execute(player);
                } else {
                    checkRefusal--;
                }
            }
        }
    } else {
        cout << "Territory not adjacent to an owned territory! Target too far to bomb." << endl;
    }
}

/**
 * Executes a Bomb order
 * @param player player bombing another player
 */
void Bomb::execute(Player & player) {
    player.getHand()->removeCard(player.getHand()->getCardIndex("Bomb"));
    int bomb = target->unitsGarrisoned / 2;
    target->unitsGarrisoned = bomb;
    std::cout << "Bombing half the enemy armies! " << target->name << " now has " << target->unitsGarrisoned << " armies!" << endl;
    Notify(this);
}

/**
 * Identifies a Bomb object
 */
void Bomb::identify() {
    Orders::identify();
    std::cout << "Bomb object. Can eliminate half of the armies located on an opponent's territory that is adjacent to one of the current player's territories.\n";
}

/**
 * output of the Bomb class
 * @param out ostream insertion operator of Bomb class
 * @param Bomb object to be outputted
 * @return string of text describing the passed Bomb object
 */
ostream &operator << (ostream &out, const Bomb &bomb) {
    out << "Bomb object. Can eliminate half of the armies located on an opponent's territory that is adjacent to one of the current player's territories.\n";
    return out;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Bomb::stringToLog(){
    string log = "Log :: " + playerLink->getName() + " Bombed " + target->name;
    return log;
}

//------------------------------------------------------
// Blockade functions
//------------------------------------------------------

/**
 * Blockade default constructor
 */
Blockade::Blockade() = default;

/**
 * Blockade destructor
 */
Blockade::~Blockade() {
    cout << "Blockade destroyed\n";
}

/**
 * Blockade constructor
 * @param target territory blockaded
 */
Blockade::Blockade(Territory& target) {
    name = "Blockade";
    this->target = &target;
}


/**
 * Blockade copy constructor
 * @param b1 Blockade object being copied
 */
Blockade::Blockade(const Blockade &b1) {
    // empty because Blockade has no members.
}

/**
 * assignment operator of Blockade
 * @param p pointer to Blockade
 * @return returns assigned Blockade
 */
Blockade &Blockade::operator=(const Blockade &p) {
    return *this;
}

/**
 * Blockade validate checks if the Blockade object can execute
 * @param player the player passing the blockade order
 */
void Blockade::validate(Player & player) {
    int checkRefusal = player.getTerritorySize();
    for (int i = 0; i < player.getTerritorySize(); i++) {
        if (this->target->id == (player.getTerritoriesOwned(i)->id)) {
            Blockade::execute(player);
        } else {
            if (checkRefusal == 1) {
                // invalidates order
                cout << "The territory you are trying to Blockade is not owned by you!";
            } else {
                checkRefusal--;
            }
        }
    }
}

/**
 * Executes a Blockade order
 * @param player the player passing the blockade order
 */
void Blockade::execute(Player & player) {
    target->unitsGarrisoned = target->unitsGarrisoned * 2;
    target->playerLink->removeTerritory(target);
    //Player::neutralPlayer().addTerritory(target);
    //target->playerLink = &Player::neutralPlayer();
    std::cout << "Territory blockade set up! " << target->name << " now has " << target->unitsGarrisoned << " armies, and is not owned by " << player.getName() << " anymore." << endl;
    //std::cout << target->name << " now owned by " << Player::neutralPlayer().getName() << endl;
    Notify(this);
}

/**
 * Identifies a Blockade object
 */
void Blockade::identify() {
    Orders::identify();
    std::cout << "Blockade object. Can triple the number of armies on one of the current player's territory and make it a neutral territory.\n";
}

/**
 * output of the Blockade class
 * @param out ostream insertion operator of Blockade class
 * @param blockade object to be outputted
 * @return string of text describing the passed Blockade object
 */
ostream &operator << (ostream &out, const Blockade &blockade) {
    out << "Blockade object. Can triple the number of armies on one of the current player's territory and make it a neutral territory.\n";
    return out;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Blockade::stringToLog(){
    string log = "Log :: " + playerLink->getName() + " Blockaded " + target->name + ", Now owned by NEUTRAL PLAYER";
    return log;
}

//------------------------------------------------------
// Airlift functions
//------------------------------------------------------

/**
 * Airlift default constructor
 */
Airlift::Airlift() = default;

/**
 * Airlift destructor
 */
Airlift::~Airlift() {
    cout << "Airlift destroyed\n";
}

/**
 * Airlift constructor
 * @param sArmies armies airlifting
 * @param source territory from
 * @param target territory to
 */
Airlift::Airlift(int sArmies, Territory& source, Territory& target){
    name = "Airlift";
    this->armies = sArmies;
    this->source = &source;
    this->target = &target;
}

/**
 * Airlift copy constructor
 * @param a1 Airlift object being copied
 */
Airlift::Airlift(const Airlift &a1) {
    // empty because Airlift has no members.
}

/**
 * assignment operator of Airlift
 * @param p pointer to Airlift
 * @return returns assigned Airlift
 */
Airlift &Airlift::operator=(const Airlift &p) {
    return *this;
}

/**
 * Airlift validate checks if the Airlift object can execute
 * @param player player using airlift
 */
void Airlift::validate(Player & player) {
    bool sourceBool = false;
    bool targetBool = false;
    for (int i = 0; i < player.getTerritorySize(); i++) {
        if (this->source->id == (player.getTerritoriesOwned(i)->id)) {
            sourceBool = true;
        }
    }
    for (int i = 0; i < player.getTerritorySize(); i++) {
        if (this->target->id == (player.getTerritoriesOwned(i)->id)) {
            targetBool = true;
        }
    }
    if (sourceBool && targetBool) {
        Airlift::execute(player);
    } else {
        // invalidates order
        cout << "One of the selected territories is not owned by the player. Order not executed.";
    }
}

/**
 * Executes an Airlift order
 * @param player player using airlift
 */
void Airlift::execute(Player & player) {
    if (this->source->unitsGarrisoned - this->armies != 0) {
        this->source->unitsGarrisoned = this->source->unitsGarrisoned - this->armies;
        this->target->unitsGarrisoned = this->target->unitsGarrisoned + this->armies;
        std::cout << "Airlifting " << this->armies << " armies to " << target->name << " from " << source->name << "!\n";
        Notify(this);
    } else {
        cout << "Too many armies selected! Source territory cannot provide so many. Order not executed.";
    }
}

/**
 * Identifies an Airlift object
 */
void Airlift::identify() {
    Orders::identify();
    std::cout << "Airlift object. Can advance some armies from one of the current player's territories to any other territory.\n";
}

/**
 * output of the Airlift class
 * @param out ostream insertion operator of Airlift class
 * @param airlift object to be outputted
 * @return string of text describing the passed Airlift object
 */
ostream &operator << (ostream &out, const Airlift &airlift) {
    out << "Airlift object. Can advance some armies from one of the current player's territories to any other territory.\n";
    return out;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Airlift::stringToLog(){
    string log = "Log :: " + playerLink->getName() + " Airlifted from " + source->name + " to " + target->name;
    return log;
}

//------------------------------------------------------
// Negotiate functions
//------------------------------------------------------

/**
 * Negotiate default constructor
 */
Negotiate::Negotiate() = default;

/**
 * Negotiate destructor
 */
Negotiate::~Negotiate() {
    cout << "Negotiate destroyed\n";
}

/**
 * Negotiate constructor
 * @param targetPlayer player negotiating with
 */
Negotiate::Negotiate(Player & targetPlayer) {
    name = "Negotiate";
    this->targetPlayer = &targetPlayer;
}

/**
 * Negotiate copy constructor
 * @param n1 Negotiate object being copied
 */
Negotiate::Negotiate(const Negotiate &n1) {
    // empty because Negotiate has no members.
}

/**
 * assignment operator of Negotiate
 * @param p pointer to Negotiate
 * @return returns assigned Negotiate
 */
Negotiate &Negotiate::operator=(const Negotiate &p) {
    return *this;
}

/**
 * Negotiate validate checks if the Negotiate object can execute
 * @param player player negotiating
 */
void Negotiate::validate(Player & player) {
    std::cout << "Validating if negotiate can happen between the two selected players...\n";
    if (player.getName().compare(playerLink->getName())) {
        cout << "Cannot negotiate with yourself. Order not executed." << endl;
    } else {
        Negotiate::execute(player);
    }
}

/**
 * Executes a Negotiate order
 * @param player player negotiating
 */
void Negotiate::execute(Player & player) {
    playerLink->getHand()->removeCard(playerLink->getHand()->getCardIndex("Diplomacy"));
    player.negotiatingWith.push_back(playerLink);
    playerLink->negotiatingWith.push_back(&player);
    std::cout << "Negotiate active between the two selected players.\n";
    Notify(this);
}

/**
 * Identifies a Negotiate object
 */
void Negotiate::identify() {
    Orders::identify();
    std::cout << "Negotiate object. Can prevent attacks between the current player and another player until the end of the turn. \n";
}

/**
 * output of the Negotiate class
 * @param out ostream insertion operator of Negotiate class
 * @param negotiate object to be outputted
 * @return string of text describing the passed Negotiate object
 */
ostream &operator << (ostream &out, const Negotiate &negotiate) {
    out << "Negotiate object. Can prevent attacks between the current player and another player until the end of the turn.\n";
    return out;
}

/**
 * method logging to game log
 * @return the string being logged
 */
string Negotiate::stringToLog(){
    string log = "Log :: " + playerLink->getName() + " Negotiated with " + targetPlayer->getName();
    return log;
}
