#include "board.hpp"

Board::Board() {

    // fill tiles_ with 15x15 of '*'
    for(unsigned n = 0; n < 15; n++) {
        std::vector<char> vec(15, ' ');
        tiles_.push_back(vec);
    }

    {
    // center
    place_tile('*', 7, 7);

    // triple word scores
    place_tile('#', 0, 0);
    place_tile('#', 7, 0);
    place_tile('#', 14, 0);
    place_tile('#', 0, 7);
    place_tile('#', 14, 7);
    place_tile('#', 0, 14);
    place_tile('#', 7, 14);
    place_tile('#', 14, 14); 

    // double word scores
    place_tile('@', 1, 1);
    place_tile('@', 2, 2);
    place_tile('@', 3, 3);
    place_tile('@', 4, 4);
    place_tile('@', 13, 1);
    place_tile('@', 12, 2);
    place_tile('@', 11, 3);
    place_tile('@', 10, 4);
    place_tile('@', 10, 10);
    place_tile('@', 11, 11);
    place_tile('@', 12, 12);
    place_tile('@', 13, 13);
    place_tile('@', 1, 13);
    place_tile('@', 2, 12);
    place_tile('@', 3, 11);
    place_tile('@', 4, 10);

    // triple letter scores
    place_tile('3', 5, 1);
    place_tile('3', 9, 1);
    place_tile('3', 1, 5);
    place_tile('3', 5, 5);
    place_tile('3', 9, 5);
    place_tile('3', 14, 5);
    place_tile('3', 1, 9);
    place_tile('3', 5, 9);
    place_tile('3', 9, 9);
    place_tile('3', 14, 9);
    place_tile('3', 5, 13);
    place_tile('3', 9, 13);

    // double letter scores
    place_tile('2', 3, 0);
    place_tile('2', 11, 0);
    place_tile('2', 0, 3);
    place_tile('2', 0, 11);
    place_tile('2', 3, 14);
    place_tile('2', 11, 14);
    place_tile('2', 14, 3);
    place_tile('2', 14, 11);
    place_tile('2', 6, 6);
    place_tile('2', 8, 8);  
    place_tile('2', 6, 8);
    place_tile('2', 8, 6);
    place_tile('2', 6, 2);       
    place_tile('2', 7, 3);       
    place_tile('2', 8, 2);       
    place_tile('2', 6, 12);       
    place_tile('2', 7, 11);       
    place_tile('2', 8, 12);
    place_tile('2', 2, 6);       
    place_tile('2', 3, 7);       
    place_tile('2', 2, 8);    
    place_tile('2', 12, 6);       
    place_tile('2', 11, 7);       
    place_tile('2', 12, 8);
    }

}

bool Board::place_word(std::string word, unsigned x, unsigned y, bool downward) {

    if(!word_is_valid(word, x, y, downward)) {
        return false;
    }

    for(int i = 0; i < word.length(); i++) {
        place_tile(word[i], x + ((int(downward) + 1) % 2) * i, y + int(downward) * i);
    }

    return true;

}


std::string Board::to_string() {

    std::string to_return;

    std::string values[15] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14"};

    for(int i = 0; i < 31; i++) {

        to_return.append("||");
        
        for(int j = 0; j < 15; j++) {
            
            if(i % 2) {
                to_return.append(" ");
                to_return += tiles_[i/2][j];
                to_return.append(" ");
                to_return.append("|");
            } else {
                if(j != 14) {
                    to_return.append("----");
                } else {
                    to_return.append("---|");
                }
            }
        }
        to_return.append("|\n");

    }

    return to_return;

}

void Board::place_tile(char letter, unsigned x, unsigned y) {
    tiles_[y][x] = letter;
}

bool Board::word_is_valid(std::string& word, unsigned x, unsigned y, bool downward) {

    for(int i = 0; i < word.length(); i++) {

        int new_x = x + ((int(downward) + 1) % 2) * i;
        int new_y = y + int(downward) * i;

        if(new_x >= 15 || new_y >= 15 || tiles_[new_y][new_x] >= 'A' && tiles_[new_y][new_x] <= 'Z' && tiles_[new_y][new_x] != word[i]) {
            return false;
        }
    }

    return true;    

}