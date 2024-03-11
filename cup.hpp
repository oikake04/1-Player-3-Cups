#include <iostream>

class Cup
{
    private:
        int id;
        bool withBall;

    public:
        Cup(int id, bool withBall = false);
        bool hasBall();

        void animateCup();
        void printCup();
};