#pragma once

#include <queue>

class TileBag {

public:
    
    struct Tile{

        Tile(char letter, unsigned point_value);

        char letter_;
        unsigned point_value_;
        bool is_blank_;
    };

    TileBag();

private:
    void populateTileVector(std::vector<Tile>& vect, char letter, unsigned point_value, unsigned count);
    std::queue<Tile> tiles_;

};