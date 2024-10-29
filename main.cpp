#include <iostream>
#include "GameOfLife.hpp"

int main() {
    GameOfLife g = GameOfLife(80);
    g.PlayGame(15);
}