#include "dictionary.hpp"

#include <fstream>
#include <iostream>

Dictionary::Dictionary(std::string path) {

    initialize_dictionary_(path);

}

void Dictionary::initialize_dictionary(std::string& path) {

    initialize_dictionary_(path);

}

unsigned Dictionary::get_point_value(std::string word) {
    return word_to_points_[word];
}

void Dictionary::initialize_dictionary_(std::string& path) {
    
    word_to_points_.clear();

    std::ifstream file(path);

    for(std::string line; std::getline(file, line);) {

        std::string word = line.substr(0, line.find(" "));
        unsigned value = std::stoi(line.substr(line.find(" ") + 1, line.length())); 

        word_to_points_[word] = value; 

    }

}