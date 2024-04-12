#pragma once
#include <iostream>
#include "cup.hpp"

class Game
{
    private:
        int score;
        int streak;
    public:
        Game(int score = 0);

        void gameStart();
        void gameReset();
        void shuffleCups(Cup &cup1, Cup &cup2, Cup &cup3);
        void showSolution(Cup &cup1, Cup &cup2, Cup &cup3);

        int getRandomNumber();
        int getScore();
        int getStreak();
};