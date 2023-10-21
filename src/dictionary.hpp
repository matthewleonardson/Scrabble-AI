#pragma once

#include <unordered_map> 
#include <string>


class Dictionary {

public:
    Dictionary() = default;
    Dictionary(std::string path);

private:
    std::unordered_map<std::string, unsigned> word_to_points_;

};