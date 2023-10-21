#pragma once

#include <string>
#include <vector>

class Board {

public:
    Board();    
    std::string to_string();
    bool place_word(std::string word, unsigned x, unsigned y, bool downward);

private:
    std::vector<std::vector<char>> tiles_; 
    void place_tile(char letter, unsigned x, unsigned y);
    bool word_is_valid(std::string& word, unsigned x, unsigned y, bool downward);
    
};