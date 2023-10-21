#include "dictionary.hpp"

#include <fstream>
#include <iostream>

Dictionary::Dictionary(std::string path) {

    std::ifstream file(path);

    for(std::string line; std::getline(file, line);) {

        std::string word = line.substr(0, line.find(" "));
        unsigned value = std::stoi(line.substr(line.find(" ") + 1, line.length())); 

        word_to_points_[word] = value; 

    }

}