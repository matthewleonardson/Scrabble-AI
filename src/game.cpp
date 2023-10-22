#include "game.hpp"

Game::Game(std::string dict_file_path) {

    dict_ = new Dictionary(dict_file_path);
    board_ = new Board();
    scores_ = {0, 0};

}