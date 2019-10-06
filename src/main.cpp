#include <array>
#include <cstdlib>
#include <iostream>
#include <thread>

const int SIZE = 15;
std::array<char, SIZE * SIZE> field;

struct Position {
    int x = 0;
    int y = 0;
};

void printField(Position playerPos)
{
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (x == playerPos.x && y == playerPos.y) {
                std ::cout << "@ ";
            }
            else {
                std::cout << field[y * SIZE + x] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void movement(Position &playerPos)
{
    std::cout << "W to go up, D to Right, A to go left, S to go down\n";

    char input;
    std::cin >> input;
    std::cin.ignore();

    if (input == 'w') {
        if (playerPos.y == 0) {
            std::cout << "whoopsie ya canny go there";
        }
        else {
            playerPos.y -= 1;
        }
    }
    else if (input == 'd') {
        if (playerPos.x == SIZE - 1) {
            std::cout << "whoopsie ya canny go there";
        }
        else {
            playerPos.x += 1;
        }
    }
    else if (input == 'a') {
        if (playerPos.x == 0) {
            std::cout << "whoopsie ya canny go there";
        }
        else {
            playerPos.x -= 1;
        }
    }
    else if (input == 's') {
        if (playerPos.y == SIZE - 1) {
            std::cout << "whoopsie ya canny go there";
        }
        else {
            playerPos.y += 1;
        }
    }
}

int main()
{
    field.fill('.');
    Position playerPos;
    playerPos.x = std::rand() % SIZE;
    playerPos.y = std::rand() % SIZE;

    printField(playerPos);
    while (true) {
        movement(playerPos);
        printField(playerPos);
    }
}

