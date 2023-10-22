#pragma once
#include "board.hpp"
#include "dictionary.hpp"

class Game {

public:
    Game() = default;
    Game(std::string dict_file_path);

private:
    Dictionary* dict_;
    Board* board_;
    std::pair<unsigned, unsigned> scores_;

};