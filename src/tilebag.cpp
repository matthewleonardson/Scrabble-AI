#include "tilebag.hpp"

#include <iostream>
#include <algorithm>
#include <random>


TileBag::Tile::Tile(char letter, unsigned point_value) {

    if(letter == ' ') {
        is_blank_ = true;
    }

    letter_ = letter;
    point_value_ = point_value;

}

TileBag::TileBag() {

    std::vector<Tile> to_be_shuffled;

    {
    populateTileVector(to_be_shuffled, 'A', 1, 9);
    populateTileVector(to_be_shuffled, 'B', 3, 2);
    populateTileVector(to_be_shuffled, 'C', 3, 2);
    populateTileVector(to_be_shuffled, 'D', 2, 4);
    populateTileVector(to_be_shuffled, 'E', 1, 12);
    populateTileVector(to_be_shuffled, 'F', 4, 2);
    populateTileVector(to_be_shuffled, 'G', 2, 3);
    populateTileVector(to_be_shuffled, 'H', 4, 2);
    populateTileVector(to_be_shuffled, 'I', 1, 9);
    populateTileVector(to_be_shuffled, 'J', 8, 1);
    populateTileVector(to_be_shuffled, 'K', 5, 1);
    populateTileVector(to_be_shuffled, 'L', 1, 4);
    populateTileVector(to_be_shuffled, 'M', 3, 2);
    populateTileVector(to_be_shuffled, 'N', 1, 6);
    populateTileVector(to_be_shuffled, 'O', 1, 8);
    populateTileVector(to_be_shuffled, 'P', 3, 2);
    populateTileVector(to_be_shuffled, 'Q', 10, 1);
    populateTileVector(to_be_shuffled, 'R', 1, 6);
    populateTileVector(to_be_shuffled, 'S', 1, 4);
    populateTileVector(to_be_shuffled, 'T', 1, 6);
    populateTileVector(to_be_shuffled, 'U', 1, 4);
    populateTileVector(to_be_shuffled, 'V', 4, 2);
    populateTileVector(to_be_shuffled, 'W', 4, 2);
    populateTileVector(to_be_shuffled, 'X', 8, 1);
    populateTileVector(to_be_shuffled, 'Y', 4, 2);
    populateTileVector(to_be_shuffled, 'Z', 10, 1);
    populateTileVector(to_be_shuffled, ' ', 0, 2);
    }

    auto rng = std::default_random_engine {};
    std::shuffle(to_be_shuffled.begin(), to_be_shuffled.end(), rng);

    for(Tile& tile : to_be_shuffled) {

        tiles_.push(tile);

    }
    
}

void TileBag::populateTileVector(std::vector<Tile>& vect, char letter, unsigned point_value, unsigned count) {

    for(unsigned n = 0; n < count; n++) {
        vect.push_back(Tile(letter, point_value));
    }

}