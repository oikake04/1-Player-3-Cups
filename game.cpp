#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "game.hpp"
#include "cup.hpp"

Game::Game(int score)
{
    this->score = score;
}

int Game::getRandomNumber() {
    // Use std::random_device to obtain a seed for the random number engine
    std::random_device rd;

    // Use std::mt19937 as the random number engine
    std::mt19937 gen(rd());

    // Use std::uniform_int_distribution to generate a random number in the specified range
    std::uniform_int_distribution<int> distribution(1, 3);

    // Generate and return the random number
    return distribution(gen);
}

void Game::shuffleCups(Cup &cup1, Cup &cup2, Cup &cup3)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    switch (getRandomNumber())
    {
        case 1:
            cup1.setWithBall();
            cup2.setWithoutBall();
            cup3.setWithoutBall();
            break;
        case 2:
            cup1.setWithoutBall();
            cup2.setWithBall();
            cup3.setWithoutBall();
            break;
        case 3:
            cup1.setWithoutBall();
            cup2.setWithoutBall();
            cup3.setWithBall();
            break;
    }
};

void Game::gameStart()
{
    std::cout << "\n\t| One Player - 3 Cups |\n";
    std::cout << "\nGame Rules: Chose the right Cup and guess where is the Ball!\n";

    std::cout << " (Press enter to start...)";
    getchar();

    int cupChosen;
    int tryCount = 0;
    int continueCheck = 1;
    bool winCheck;
    bool invalidInput;

    Cup cup1(1);
    Cup cup2(2);
    Cup cup3(3);

    while (continueCheck == 1)
    {
        shuffleCups(cup1, cup2, cup3);
        cup1.printCup(this->score);
        //scelta della Cup
        std::cout << "\tWhere is the Ball?\n\t(Digit 1, 2 o 3)\n";
        invalidInput = true;
        while(invalidInput)
        {
            std::cin >> cupChosen;
            if (cupChosen == 1 || cupChosen == 2 || cupChosen == 3)
            {
                invalidInput = false;
            } else {
                std::cout << "Invalid input" << std::endl;
                std::cin.clear(); // resetta lo stato di errore di cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // svuota il buffer
            }
        }
        //animazione della Cup
        switch (cupChosen)
        {
            case 1:
                cup1.animateCup(this->score);
                winCheck = cup1.hasBall();
                break;
            case 2:
                cup2.animateCup(this->score);
                winCheck = cup2.hasBall();
                break;
            case 3:
                cup3.animateCup(this->score);
                winCheck = cup3.hasBall();
                break;
        }
        //assegnazione punti e streak
        if (winCheck){
            std::cout << "            You Win!\n";
            this->score++;
            tryCount = 0;
        }
        else
        {
            showSolution(cup1,cup2,cup3);
            std::cout << "            You Lose!\n";
            tryCount++;
        }
        //exit check
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (tryCount >= 3)
        {
            this->score = 0;

            std::cout << "\n Retry?   (1 (Yes) / 0 (No))\n";
            invalidInput = true;
            while(invalidInput)
            {
                std::cin >> continueCheck;
                if (continueCheck == 1 || continueCheck == 0)
                {
                    invalidInput = false;
                }
            }
            tryCount = 0;
        }
    }
};

void Game::showSolution(Cup &cup1, Cup &cup2, Cup &cup3)
{
    if (cup1.hasBall())
        cup1.animateCup(this->score);
    else if (cup2.hasBall())
        cup2.animateCup(this->score);
    else if (cup3.hasBall())
        cup3.animateCup(this->score);
}