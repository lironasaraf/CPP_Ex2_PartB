#include <stdexcept>
#include "Board.hpp"
#include <iostream>
#include <ctype.h>
#include <map>
using namespace std;
using namespace ariel;

/* the main idea of the task is to build board with messages
the board is unlimited and the messages can be one on another
to make this happen I used map that contains pair and char */



namespace ariel
{

   


    void Board::post(uint row, uint col, Direction d, string txt)
    {
        int Message_len = txt.length();
        if(Message_len == 0){ return;} //no message to put
        pair<uint, uint> Location;//where to start the board

        

            for (uint i = 0; i < Message_len; i++)
            {
                Location.first = row;
                Location.second = col;
                board.erase(Location); //if there is another letter delete
                board.insert({Location, txt.at(i)}); //put the letter in the board
                if (d == Direction::Vertical)
                {
                   row++;
                }
                else
                {
 
                  col++;
                }
            }
    }

    string Board::read(uint row, uint col, Direction d, uint len)
    {
        pair<uint, uint> Location;
        string result;
        char c;

            for (uint i = 0; i < len; i++)
            {
                Location.first = row;
                Location.second = col;

                if (board.count(Location) != 0) //exist letter
                {
                    c = board.at(Location); //take the letter at this location

                    result += c; //add the letter
                }
                else
                {
                    c = '_'; // if there is no letter in this location put the default
                    result += c; // add to the resault
                }
                if (d == Direction::Vertical){
                   row++;
                }
        
                else
                {
                    col++;
                }

                
            }
        
        return result;
    }


   void Board::show()
       {
        
        if (board.empty())
        {
            cout << "Board is empty!" << endl;
        }
        
  		map <std::pair<uint, uint>, char >::iterator it = board.begin();
		unsigned int rowNum = (it->first).first;
		while (it != board.end()) //keep reading until the end of the board
		{
			if (rowNum != (it->first).first) {
				cout << endl;
				rowNum = (it->first).first;
			}
			cout << it->second;
			++it;
		}
    }
}