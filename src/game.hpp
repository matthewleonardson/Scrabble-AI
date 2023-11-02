#pragma once
#include "board.hpp"
#include "dictionary.hpp"
#include "tilebag.hpp"

class Game {

public:

    Game() = default; 
    Game(std::string dict_file_path);

private:

    struct Player {
        Player();
        Player(std::vector<TileBag::Tile> starting_tiles);
        unsigned score = 0;
        std::vector<TileBag::Tile> tiles;
    };

    Dictionary* dict_;
    Board* board_;
    TileBag* tilebag_;
    std::pair<Player, Player> players_;

};