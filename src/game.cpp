#include "game.hpp"

Game::Player::Player() {

    score = 0;
    tiles.resize(7);

}

Game::Player::Player(std::vector<TileBag::Tile> starting_tiles) {

    score = 0;
    
    for(auto tile : starting_tiles) {
        tiles.push_back(tile);
    }

}

Game::Game(std::string dict_file_path) {

    dict_ = new Dictionary(dict_file_path);
    board_ = new Board();
    tilebag_ = new TileBag();
    
    players_.first = Player();
    players_.second = Player();

    for(unsigned n = 0; n < 7; n++) {

        players_.first.tiles.push_back(tilebag_->getNextTile());
        players_.second.tiles.push_back(tilebag_->getNextTile());

    }

}

