#pragma once
#include "board.hpp"
#include "dictionary.hpp"

class Game {

public:

    Game() = default; 
    Game(std::string dict_file_path);

private:

    struct Player {
        Player();
        Player(std::vector<char> starting_tiles);
        unsigned score = 0;
        std::vector<char> tiles;
    };

    Dictionary* dict_;
    Board* board_;
    std::pair<Player, Player> players_;

};