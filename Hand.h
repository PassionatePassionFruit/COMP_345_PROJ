//
// Created by Ryan on 2021-10-05.
//

#ifndef COMP_345_PROJ_HAND_H
#define COMP_345_PROJ_HAND_H


class Hand {

public:
    Hand(int cardNumber);
    int getCardNumber() const;
    void setCartNumber(int cardNumber);
private:
    int cardNumber;
};


#endif //COMP_345_PROJ_HAND_H