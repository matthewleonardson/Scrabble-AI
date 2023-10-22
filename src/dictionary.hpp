#pragma once

#include <unordered_map> 
#include <string>

class Dictionary {

public:
    Dictionary() = default;
    Dictionary(std::string path);
    void initialize_dictionary(std::string& path);
    unsigned get_point_value(std::string word);

private:
    void initialize_dictionary_(std::string& path);
    std::unordered_map<std::string, unsigned> word_to_points_;

};