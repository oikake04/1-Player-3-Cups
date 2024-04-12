#pragma once
#include <iostream>

class Cup
{
    private:
        int id;
        bool withBall;

    public:
        Cup(int id, bool withBall = false);
        bool hasBall();
        void setWithBall();
        void setWithoutBall();

        void animateCup(int score);
        void printCup(int score);
};