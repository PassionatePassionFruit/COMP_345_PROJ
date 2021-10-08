//
// Created by Nicolo on 2021-09-24.
//
using namespace std;

#ifndef COMP_345_PROJ_GAMEENGINE_H
#define COMP_345_PROJ_GAMEENGINE_H


enum State
{
    ST_START,
    ST_MAP_LOADED,
    ST_MAP_VALIDATED,
    ST_PLAYERS_ADDED,
    ST_ASSIGN_REINFORCEMENT,
    ST_ISSUE_ORDERS,
    ST_EXECUTE_ORDERS,
    ST_WIN,
    ST_END
};

enum Transition {
    T_LOAD_MAP,
    T_VALIDATE_MAP,
    T_ADD_PLAYER,
    T_ASSIGN_COUNTRIES,
    T_ISSUE_ORDER,
    T_END_ISSUE_ORDERS,
    T_EXEC_ORDER,
    T_END_EXEC_ORDERS,
    T_WIN,
    T_PLAY,
    T_END
};

class GameEngine {
    private:
        State currentState;
        void loadmap();
        void validatemap();
        void addplayer();
        void assigncountries();
        void issueorder();
        void execorder();
        void endexecorders();
        void endissueorders();
        void win();
        void end();
        void play();

    public:
        GameEngine();
        GameEngine(const GameEngine &);
        GameEngine(GameEngine *);
        ~GameEngine();

        string getState();

        bool transition(Transition);

        GameEngine& operator =(const GameEngine &);
        friend ostream & operator << (ostream &, const GameEngine &ge);
        friend istream & operator >> (istream &, GameEngine &ge);

};


#endif //COMP_345_PROJ_GAMEENGINE_H