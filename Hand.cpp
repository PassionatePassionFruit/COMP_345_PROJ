//
// Created by Ryan on 2021-10-05.
//

#include <iostream>
#include <vector>
#include "Hand.h"
using namespace std;

Hand::Hand(int cardNumber) {
    this->cardNumber = cardNumber;
}

int Hand::getCardNumber() const {
    return cardNumber;
}

void Hand::setCartNumber(int cardNumber) {
    this->cardNumber = cardNumber;
}


