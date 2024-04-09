#include <iostream>
#include <chrono>
#include <thread>
#include "cup.hpp"

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

void Cup::printCup()
{
    std::system("clear");
    std::cout <<R"(

   /\\         /\\         /\\
  /  \\       /  \\       /  \\
 /    \\     /    \\     /    \\
/______\\   /______\\   /______\\
    )";
}

void Cup::animateCup()
{   
    printCup();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::system("clear");
    switch (this->id)
    {
        case 1:
            if (!this->withBall)
            {
                std::cout <<R"(
   /\\
  /  \\        /\\         /\\
 /    \\      /  \\       /  \\
/______\\    /    \\     /    \\
            /______\\   /______\\
)";
            }
            else if (this->withBall)
            {
                std::cout <<R"(
   /\\
  /  \\        /\\         /\\
 /    \\      /  \\       /  \\
/______\\    /    \\     /    \\
    O       /______\\   /______\\
)";
            }
            break;
        case 2:
            if (!this->withBall)
            {
                std::cout <<R"(
               /\\
   /\\        /  \\        /\\
  /  \\      /    \\      /  \\
 /    \\    /______\\    /    \\
/______\\               /______\\
)";
            }
            else if (this->withBall)
            {
                std::cout <<R"(
               /\\
   /\\        /  \\        /\\
  /  \\      /    \\      /  \\
 /    \\    /______\\    /    \\
/______\\       O       /______\\
)";
            }
            break;
        case 3:
            if (!this->withBall)
            {
                std::cout <<R"(
                           /\\
   /\\         /\\        /  \\
  /  \\       /  \\      /    \\
 /    \\     /    \\    /______\\
/______\\   /______\\
)";
            }
            else if (this->withBall)
            {
                std::cout <<R"(
                           /\\
   /\\         /\\        /  \\
  /  \\       /  \\      /    \\
 /    \\     /    \\    /______\\
/______\\   /______\\       O
)";
            }
            break;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    printCup();
}