#include "GameOfLife.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void GameOfLife::ResetColors()
{
    cout << "\033[0m";
}

void GameOfLife::CheckNeighbors(int x, int y)
{
    srand(time(NULL));
    int lives = 0;
    int limL = x > 0 ? x - 1 : x;
    int limR = x < size - 1 ? x + 1 : x;
    int limT = y > 0 ? y - 1 : y;
    int limB = y < size - 1 ? y + 1 : y;

    for (int i = limL; i <= limR; i++) {
        for (int k = limT; k <= limB; k++) {
            if (grid[i][k] > 0) {
                lives++;
            }
        }
    }

    if (grid[x][y] > 0) {
        // if our element has been counted in the loop above
        lives--;

        if (lives == 2 || lives == 3) {
            nextGrid[x][y] = grid[x][y];
        } else {
            nextGrid[x][y] = 0;
        }
    } else {
        if (lives == 3) {
            nextGrid[x][y] = 1;
        }
    }
}

void GameOfLife::DisplayGrid()
{

    for (short i = 0; i < size; i++) {
        for (short k = 0; k < size; k++) {
            if (grid[i][k] > 0) {
                cout << "\033[" << 31 << ";" << 41 << "m";
                cout << "  ";
                ResetColors();
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void GameOfLife::PlayGame(unsigned short times)
{
    while (times-- > 0) {


        DisplayGrid();
        for (short i = 0; i < size; i++) {
            for (short k = 0; k < size; k++) {
                CheckNeighbors(i, k);
            }
        }
        auto temp = grid;
        grid = nextGrid;
        nextGrid = temp;

        unsigned int microsecond = 1000000;
        usleep(microsecond); // sleeps for 1 second
        cout << "\033[2J"; // Clear the screen
        cout << "\033[H";
    }
}

void GameOfLife::PlayGame()
{
    while (true) {

        DisplayGrid();
        for (short i = 0; i < size; i++) {
            for (short k = 0; k < size; k++) {
                CheckNeighbors(i, k);
            }
        }
        auto temp = grid;
        grid = nextGrid;
        nextGrid = temp;

        unsigned int microsecond = 1000000;
        usleep(microsecond); // sleeps for 1 second
        cout << "\033[2J"; // Clear the screen
        cout << "\033[H";
    }
}

GameOfLife::GameOfLife(short newSize)
    : size(newSize)
{
    srand(time(NULL));
    grid = new unsigned char*[size];
    nextGrid = new unsigned char*[size];

    for (short i = 0; i < size; i++) {
        grid[i] = new unsigned char[size];
        nextGrid[i] = new unsigned char[size];
        for (short k = 0; k < size; k++) {
            grid[i][k] = ((rand() % 10) > 8) ? 1 : 0;
        }
    }
}



GameOfLife::~GameOfLife()
{
    for (short i = 0; i < size; i++) {
        delete[] grid[i];
        delete[] nextGrid[i];
    }
    delete[] grid;
    delete[] nextGrid;

    grid = nullptr;
    nextGrid = nullptr;
    size = 0;
}
