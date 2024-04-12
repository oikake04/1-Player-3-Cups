#include <iostream>
#include <chrono>
#include <thread>
#include "cup.hpp"

void clearScreen() {
    // Su Linux e macOS, usa ANSI escape sequences
    #ifdef __linux__
        std::cout << "\033[2J\033[1;1H";
    #endif

    // Su Windows, usa il comando "cls"
    #ifdef _WIN32
        std::system("cls");
    #endif
}

Cup::Cup(int id, bool withBall)
{
    this->id = id;
    this->withBall = withBall;
}

bool Cup::hasBall()
{
    return this->withBall;
}

void Cup::setWithBall()
{
    this->withBall = true;
}

void Cup::setWithoutBall()
{
    this->withBall = false;
}

void Cup::printCup(int score)
{
    clearScreen();
    std::cout << " Score: " << score;
    std::cout <<R"(

   /\\         /\\         /\\
  /  \\       /  \\       /  \\
 /    \\     /    \\     /    \\
/______\\   /______\\   /______\\
    )" << std::endl;
}

void Cup::animateCup(int score)
{   
    printCup(score);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    clearScreen();
    switch (this->id)
    {
        case 1:
            if (!this->withBall)
            {
                std::cout << " Score: " << score;
                std::cout <<R"(
   /\\
  /  \\        /\\         /\\
 /    \\      /  \\       /  \\
/______\\    /    \\     /    \\
            /______\\   /______\\
)" << std::endl;
            }
            else if (this->withBall)
            {
                std::cout << " Score: " << score;
                std::cout <<R"(
   /\\
  /  \\        /\\         /\\
 /    \\      /  \\       /  \\
/______\\    /    \\     /    \\
    O       /______\\   /______\\
)" << std::endl;
            }
            break;
        case 2:
            if (!this->withBall)
            {
                std::cout << " Score: " << score;
                std::cout <<R"(
               /\\
   /\\        /  \\        /\\
  /  \\      /    \\      /  \\
 /    \\    /______\\    /    \\
/______\\               /______\\
)" << std::endl;
            }
            else if (this->withBall)
            {
                std::cout << " Score: " << score;
                std::cout <<R"(
               /\\
   /\\        /  \\        /\\
  /  \\      /    \\      /  \\
 /    \\    /______\\    /    \\
/______\\       O       /______\\
)" << std::endl;
            }
            break;
        case 3:
            if (!this->withBall)
            {
                std::cout << " Score: " << score;
                std::cout <<R"(
                           /\\
   /\\         /\\        /  \\
  /  \\       /  \\      /    \\
 /    \\     /    \\    /______\\
/______\\   /______\\
)" << std::endl;
            }
            else if (this->withBall)
            {
                std::cout << " Score: " << score;
                std::cout <<R"(
                           /\\
   /\\         /\\        /  \\
  /  \\       /  \\      /    \\
 /    \\     /    \\    /______\\
/______\\   /______\\       O
)" << std::endl;
            }
            break;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    printCup(score);
}