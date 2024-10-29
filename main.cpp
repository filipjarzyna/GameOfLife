#include <iostream>
#include "GameOfLife.hpp"

int main() {
    GameOfLife g = GameOfLife(4);
    g.PlayGame(5);
}