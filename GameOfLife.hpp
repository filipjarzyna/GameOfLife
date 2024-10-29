#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

class GameOfLife {

private:
    int size;
    unsigned char** grid;
    unsigned char** nextGrid;
    
    void CheckNeighbors(int x, int y);
    void ResetColors();
public:
    void PlayGame(unsigned short times);
    void PlayGame();
    GameOfLife(short size);
    ~GameOfLife();
    void DisplayGrid();
};

#endif