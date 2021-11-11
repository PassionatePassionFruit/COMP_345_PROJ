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
#include <iostream>
#include <vector>
using namespace std;

//------------------------------------------------------
// OrdersList functions
//------------------------------------------------------

/**
 * output of the OrdersList class
 * @param out ostream operator of OrdersList
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
    cout << "Deploy order added." << endl;
}

/**
 * Adds a Advance object to a list of Order objects
 * @param advance Is the Advance object to add to the list of Order objects
 */
void OrdersList::addAdvance(Advance * advance) {
    this->ordersList.push_back(advance);
    cout << "Advance order added." << endl;
}

/**
 * Adds a Bomb object to a list of Order objects
 * @param bomb Is the Bomb object to add to the list of Order objects
 */
void OrdersList::addBomb(Bomb * bomb) {
    this->ordersList.push_back(bomb);
    cout << "Bomb order added." << endl;
}

/**
 * Adds a Blockade object to a list of Order objects
 * @param blockade Is the Blockade object to add to the list of Order objects
 */
void OrdersList::addBlockade(Blockade * blockade) {
    this->ordersList.push_back(blockade);
    cout << "Blockade order added." << endl;
}

/**
 * Adds a Airlift object to a list of Order objects
 * @param airlift Is the Airlift object to add to the list of Order objects
 */
void OrdersList::addAirlift(Airlift * airlift) {
    this->ordersList.push_back(airlift);
    cout << "Airlift order added." << endl;
}

/**
 * Adds a Negotiate object to a list of Order objects
 * @param negotiate Is the Negotiate object to add to the list of Order objects
 */
void OrdersList::addNegotiate(Negotiate * negotiate) {
    this->ordersList.push_back(negotiate);
    cout << "Negotiate order added." << endl;
}

/**
 * OrdersList default constructor
 */
OrdersList::OrdersList() = default;

/**
 * OrdersList destructor
 */
OrdersList::~OrdersList() {
    /*
     * the following for loop breaks everything
     */
//    for (auto *o : ordersList) {
//        delete o;
//    }
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
    this->ordersList.erase(ordersList.begin()+index);
}

OrdersList &OrdersList::operator=(const OrdersList &p) {

    return *this;
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
 * @param out ostream operator of Orders class
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
void Orders::validate(Player * player) {
    std::cout << "Orders validate method.";
}

/**
 * Orders execute, a placeholder for the execute method of subclasses
 */
void Orders::execute(Player * player) {
    std::cout << "\nOrders executed.\n";
}

Player * Orders::getPlayerLink(){
    return this->playerLink;
}
void Orders::setPlayerLink(Player & player){
    this->playerLink = &player;
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
    this->armies = sArmies;
    this->territory = sTerritory;
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
 */
void Deploy::validate(Player * player) {
    int checkRefusal = player->getTerritorySize();
    // validate if player has enough armies
    if (this->getArmies() <= player->getReinforcements()) {
        // validate if territory is owned by current player
        for (int i = 0; i < player->getTerritorySize(); i++) {
            if (this->territory.id == (player->getTerritoriesOwned(i)->id)) {
                std::cout << "Enough armies, and territory owned by player! Deploying armies!";
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
        std::cout << "Not enough armies available for this deployment.\n";
    }
}

/**
 * Executes a Deploy order
 */
void Deploy::execute(Player * player) {
    this->territory.addArmies(this->armies);
    std::cout << "\nDeploy executed. New number of armies in territory: \n";
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
 * @param out ostream operator of Deploy class
 * @param deploy object to be outputted
 * @return string of text describing the passed Deploy object
 */
ostream &operator << (ostream &out, const Deploy &deploy) {
    out << "Deploy object. Can deploy armies to territories. It needs " << deploy.getArmies() << " armies.\n";
    return out;
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

Advance::Advance(int sArmies, Territory& source, Territory& target) {
    this->armies = sArmies;
    this->source = source;
    this->target = target;
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
 */
void Advance::validate(Player * player) {
    // check source territory is owned by player
    int checkRefusal = player->getTerritorySize();
    for (int i = 0; i < player->getTerritorySize(); i++) {
        if (this->source.id == (player->getTerritoriesOwned(i)->id)) {
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
}

/**
 * Executes an Advance order
 */
void Advance::execute(Player * player) {
    //TODO Each attacking army unit involved has a 60% chances of killing one defending army
    // Each defending army unit has 70% chances of killing one attacking army unit
    // If all defending armies die, the remaining attacking units occupy the defending territory
    // A player receives a card at the end of his turn if they successfully conquered at least
    // one territory during their turn.

    // check if enemy territory is owned by current player or not
    int checkRefusal = player->getTerritorySize();
    for (int i = 0; i < player->getTerritorySize(); i++) {
        if (this->source.id == (player->getTerritoriesOwned(i)->id)) {
            cout << "Target owned by player, moving armies to target.\n";
            // do more stuff here
            return;
        } else {
            if (checkRefusal == 1) {
                cout << "ATTACKING!!!!!\n";
                // do a lot more stuff here
            } else {
                checkRefusal--;
            }
        }
    }

    std::cout << "Is the territory destination adjacent to a territory of the current player? (1 for yes, 0 for no)";
    int adjacentTerritory;
    std::cin >> adjacentTerritory;
    if (adjacentTerritory >= 1) {
        std::cout << "Is the territory destination owned by the current player? (1 for yes, 0 for no)";
        int ownedTerritory;
        std::cin >> ownedTerritory;
        if (ownedTerritory >= 1) {
            std::cout << "Advancing armies to an owned territory.\n";
        } else {
            std::cout << "Advancing armies to enemy territory. Time for battle!\n";
        }
    } else {
        std::cout << "Territory is not adjacent, therefore cannot move armies to it.\n";
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
 * @param out ostream operator of Advance class
 * @param Advance object to be outputted
 * @return string of text describing the passed Advance object
 */
ostream &operator << (ostream &out, const Advance &advance) {
    out << "Advance object. Can advance armies to territories. It needs " << advance.getArmies() << " armies.\n";
    return out;
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

//TODO implement validate/execute of Bomb with the other classes
// validate: check that the target territory does not belong to the player issuing the order
//          check that the target territory is adjacent to a territory belonging to the player issuing the order
// execute: if validate returns true, remove half the enemy armies from the target territory

/**
 * Bomb validate checks if the Bomb object can execute
 */
void Bomb::validate(Player * player) {
    std::cout << "Is the territory being bombed an enemy territory that is adjacent to a territory owned by the current player? (1 for yes, 0 for no)";
    int adjacentTerritory;
    std::cin >> adjacentTerritory;
    if (adjacentTerritory >= 1) {
        Bomb::execute(player);
    } else {
        std::cout << "Cannot bomb territory.\n";
    }
}

/**
 * Executes a Bomb order
 */
void Bomb::execute(Player * player) {
    std::cout << "Bombing half the enemy armies!\n";
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
 * @param out ostream operator of Bomb class
 * @param Bomb object to be outputted
 * @return string of text describing the passed Bomb object
 */
ostream &operator << (ostream &out, const Bomb &bomb) {
    out << "Bomb object. Can eliminate half of the armies located on an opponent's territory that is adjacent to one of the current player's territories.\n";
    return out;
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
//TODO implement validate/execute of Blockade with the other classes
// validate: check that the target territory is owned by the current player
// execute: if validate returns true, double the armies on the target territory and turn the territory neutral (give to the Neutral player)

/**
 * Blockade validate checks if the Blockade object can execute
 */
void Blockade::validate(Player * player) {
    std::cout << "Is the territory being blockaded owned by the current player? (1 for yes, 0 for no)";
    int blockade;
    std::cin >> blockade;
    if (blockade >= 1) {
        Blockade::execute(player);
    } else {
        std::cout << "Cannot blockade territory.\n";
    }
}

/**
 * Executes a Blockade order
 */
void Blockade::execute(Player * player) {
    std::cout << "Territory blockade set up! Armies doubled, territory lost, now neutral.\n";
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
 * @param out ostream operator of Blockade class
 * @param blockade object to be outputted
 * @return string of text describing the passed Blockade object
 */
ostream &operator << (ostream &out, const Blockade &blockade) {
    out << "Blockade object. Can triple the number of armies on one of the current player's territory and make it a neutral territory.\n";
    return out;
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

//TODO implement validate/execute of Airlift with the other classes
// validate: check that the source and target territories are owned by the player (do not need to be adjacent)
// execute: if validate returns true, then the selected number of armies is moved from the source to the target territory

/**
 * Airlift validate checks if the Airlift object can execute
 */
void Airlift::validate(Player * player) {
    std::cout << "Is starting territory owned by player? (1 for yes, 0 for no)";
    int airlift;
    std::cin >> airlift;
    if (airlift >= 1) {
        Airlift::execute(player);
    } else {
        std::cout << "Cannot take armies from this location!\n";
    }
}

/**
 * Executes an Airlift order
 */
void Airlift::execute(Player * player) {
    std::cout << "Airlifting armies to destination.\n";
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
 * @param out ostream operator of Airlift class
 * @param airlift object to be outputted
 * @return string of text describing the passed Airlift object
 */
ostream &operator << (ostream &out, const Airlift &airlift) {
    out << "Airlift object. Can advance some armies from one of the current player's territories to any other territory.\n";
    return out;
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
 */
void Negotiate::validate(Player * player) {
    //TODO Negotiate happens when playing a Diplomacy card.
    // Validate: check that the target player is not the player issuing the order.
    // execute: if validate returns true, the player issuing the order and the target player cannot attack each other for the remainder of the turn
    std::cout << "Validating if negotiate can happen between the two selected players...\n";
    Negotiate::execute(player);
}

/**
 * Executes a Negotiate order
 */
void Negotiate::execute(Player * player) {
    std::cout << "Negotiate active between the two selected players.\n";
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
 * @param out ostream operator of Negotiate class
 * @param negotiate object to be outputted
 * @return string of text describing the passed Negotiate object
 */
ostream &operator << (ostream &out, const Negotiate &negotiate) {
    out << "Negotiate object. Can prevent attacks between the current player and another player until the end of the turn.\n";
    return out;
}
