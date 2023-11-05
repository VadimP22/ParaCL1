#include "LexerUtils.h"

#include <iostream>

void pcl::PrintSequence(const char* begin, const char* end) {   
    std::cout << "SEQUENCE: ";

    for (auto it = begin; it != end; ++it)
        std::cout << *it;

    std::cout << std::endl;
}

bool pcl::IsSymbol(char sym) {
    if (sym >= 65 && sym <= 90)
        return true;

    if (sym >= 97 && sym <= 122)
        return true;

    return false;
}

bool pcl::IsNumber(char sym) {
    if (sym >= 48 && sym <= 57)
        return true;

    return false;
}

bool pcl::CompareToString(const char* begin, const char* end, const char* str) {
    int counter = 0;
    for (auto it = begin; it != end; ++it) {
        if (str[counter] == 0)
            return false;

        if (str[counter] != *it)
            return false;

        counter += 1;
    }

    if(str[counter] != 0)
        return false;

    return true;  
};
