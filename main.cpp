#include <iostream> 
#include "board.hpp"

int main() { 

    Board* board = new Board();

    board->place_word("HELLO", 7, 7, false);
    board->place_word("WORLD", 11, 6, true);
    
    std::cout << board->to_string() << std::endl;

}