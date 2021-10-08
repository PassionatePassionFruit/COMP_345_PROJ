//
// Created by Nicolo on 2021-09-24.
//

#ifndef COMP_345_PROJ_GAMEENGINEDRIVER_H
#define COMP_345_PROJ_GAMEENGINEDRIVER_H
#include "GameEngine.h"


class GameEngineDriver {
private:
    GameEngine* game;
public:
    bool isGameDone;
    GameEngineDriver();
    GameEngineDriver(const GameEngineDriver &);
    ~GameEngineDriver();

    void chooseCommand();
    GameEngineDriver& operator =(const GameEngineDriver &);

    friend ostream & operator << (ostream &, const GameEngineDriver &ged);
    friend istream & operator >> (istream &, GameEngineDriver &ged);
};



#endif //COMP_345_PROJ_GAMEENGINEDRIVER_H