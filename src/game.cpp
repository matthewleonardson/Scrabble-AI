#include "game.hpp"

Game::Player::Player() {

    score = 0;
    tiles.resize(7);

}

Game::Player::Player(std::vector<char> starting_tiles) {

    score = 0;
    
    for(char tile : starting_tiles) {
        tiles.push_back(tile);
    }

}

Game::Game(std::string dict_file_path) {

    dict_ = new Dictionary(dict_file_path);
    board_ = new Board();
    players_.first = Player();
    players_.second = Player();

}

