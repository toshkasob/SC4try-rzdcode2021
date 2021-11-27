#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "transportRequests.h"

int 
TransportRequestUnitFull::read_xlsx(std::string filename) 
{
    enum returnErrors
    {
        OK, ERROR_FILE_OPEN
    };
    std::ifstream finCsv(filename.c_str(), 'w');
    if (!finCsv.is_open())
        return ERROR_FILE_OPEN;
    while (!finCsv.eof())
    {
        char str[255];
        std::string str_str;
        std::getline(finCsv, str_str);  //! read header
    }
}
