#include <unordered_map>
#include <string>
#include "verifySol.hpp"

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::unordered_map<char, unsigned> & mapping)
{
    std::string x1 = "1";
    for (int i = 0; i< s1.size(); i++){
        //x1 += mapping.at(s1[i]);
    } 
    
    std::string x2 = "2";
    for (int i = 0; i< s2.size(); i++){
        //x2 += mapping.at(s2[i]);
    }
    
    std::string x3 = "3";
    for (int i = 0; i< s3.size(); i++){
        //x3 += mapping.at(s3[i]);
    }
    if (std::stoi(x1) + std::stoi(x2) == std::stoi(x3)){
        return true;
    }
    else{
        return false;
    }
}

