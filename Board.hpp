#include <string>
#include "Direction.hpp"
#include <map>
#include <iostream>
#include <stdexcept>
#include <limits.h>
#include<ctype.h>

namespace ariel
{

    class Board
    {

    public:
        std::map<std::pair<uint, uint>, char> board;


    public:
        Board()
        { 
            }

        void post(uint row, uint col, Direction d, std::string txt);
        std::string read(uint row, uint col, Direction d, uint len);
        void show();
    };
}