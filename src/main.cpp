#include <iostream>
#include <stdlib.h> 

#include "board.hpp"
#include "dictionary.hpp"

int main() { 

    // Board* board = new Board();

    // board->place_word("HELLO", 7, 7, false);
    // board->place_word("WORLD", 11, 6, true);
    
    // std::system("cls");    
    // std::cout << board->to_string() << std::endl;

    Dictionary* dictionary = new Dictionary("../assets/dictionary.txt");

    std::cout << dictionary->get_point_value("HELLO") << std::endl;
    std::cout << dictionary->get_point_value("WORLD") << std::endl;

}