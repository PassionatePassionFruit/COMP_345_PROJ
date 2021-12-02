//
// Created by Ryan on 2021-12-01.
//

#ifndef GAMEENGINE_CPP_NEUTRALPLAYERSTRATEGY_H
#define GAMEENGINE_CPP_NEUTRALPLAYERSTRATEGY_H

#include "PlayerStrategy.h"

class NeutralPlayerStrategy : public PlayerStrategy {

public:
    void issueOrder(vector<Player *> &vPlayersInPlay) override;
    vector<Territory*> toAttack() override;
    vector<Territory*> toDefend() override;
};


#endif//GAMEENGINE_CPP_NEUTRALPLAYERSTRATEGY_H
