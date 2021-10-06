#include <vector>
#include <iostream>
#include <algorithm>
#include "utils.hpp"

int getIndex(std::vector<std::string> v, std::string K)
{
    auto it = std::find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end())
    {
     
        // calculating the index
        // of K
        int index = it - v.begin();
//        std::cout << index << endl;
        return index;
    }

    return -1;
}