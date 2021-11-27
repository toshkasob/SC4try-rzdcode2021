#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "transportRequests.h"

int 
TransporRequestsList::readFileWithTabDelim(const std::string & filename)
{
    enum returnErrors
    {
        OK, ERROR_FILE_OPEN
    };

    //FILE* file4read = fopen(filename.c_str(), "r");
    //std::fstream finCsv(file4read);
    std::fstream finCsv(filename.c_str());
    if (!finCsv.is_open())
        return ERROR_FILE_OPEN;
    std::string str_str;
    std::getline(finCsv, str_str);  //! read header
    while (!finCsv.eof())
    {
        std::getline(finCsv, str_str);  //! read each string
        TransportRequestUnitFull cur_request;
        cur_request.parseRequest(str_str);
        this->list_requests.push_back(cur_request);
    }
    return OK;
}


int 
TransportRequestUnitFull::parseRequest(const std::string & str_str)
{
    enum returnErrors
    {
        OK, STR_IS_NULL
    };
    if (str_str == "")
        return STR_IS_NULL;

    size_t prev_pos = -1;
    size_t next_pos = -1;
    size_t delta_pos = 0;
    std::string delim = "\t";
    std::string cur_cell = "";

    delta_pos = delim.length();

    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    this->request_numb_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    this->request_id_intro_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    this->status_description_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

    // date get vehicle
    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
    {
        size_t prev4date = -1;
        size_t next4date = -1;
        size_t delta4date = 0;
        std::string str4date = "";

        std::string delim4date = "/";
        if (cur_cell.find(delim4date) == std::string::npos)
            delim4date = ".";
        delta4date = delim4date.length();

        // day
        prev4date = next4date + delta4date;
        next4date = cur_cell.find(delim4date, prev4date);
        (next4date == std::string::npos && prev4date != std::string::npos) ? (next4date = cur_cell.length()) : NULL ;
        str4date = (next4date != std::string::npos && prev4date != std::string::npos) ? 
                    cur_cell.substr(prev4date, next4date - prev4date) : "01";
        //auto tmp = std::strtol(str4date.c_str(), NULL, str4date.length());
        std::istringstream (str4date) >> this->time_4_get_vehicle_.tm_mday ;

        // month
        prev4date = next4date + delta4date;
        next4date = cur_cell.find(delim4date, prev4date);
        (next4date == std::string::npos && prev4date != std::string::npos) ? (next4date = cur_cell.length()) : NULL;
        str4date = (next4date != std::string::npos && prev4date != std::string::npos) ?
            cur_cell.substr(prev4date, next4date - prev4date) : "01";
        std::istringstream(str4date) >> this->time_4_get_vehicle_.tm_mon;

        // year
        prev4date = next4date + delta4date;
        next4date = cur_cell.find(delim4date, prev4date);
        (next4date == std::string::npos && prev4date != std::string::npos) ? (next4date = cur_cell.length()) : NULL;
        str4date = (next4date != std::string::npos && prev4date != std::string::npos) ?
            cur_cell.substr(prev4date, next4date - prev4date) : "2000";
        std::istringstream(str4date) >> this->time_4_get_vehicle_.tm_year;
    }

    // time get vehicle
    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
    {
        size_t prev4time = -1;
        size_t next4time = -1;
        size_t delta4time = 0;
        std::string str4time = "";

        std::string delim4time = ":";
        if (cur_cell.find(delim4time) == std::string::npos)
            delim4time = "-";
        delta4time = delim4time.length();

        // hour
        prev4time = next4time + delta4time;
        next4time = cur_cell.find(delim4time, prev4time);
        (next4time == std::string::npos && prev4time != std::string::npos) ? (next4time = cur_cell.length()) : NULL;
        str4time = (next4time != std::string::npos && prev4time != std::string::npos) ?
            cur_cell.substr(prev4time, next4time - prev4time) : "00";
        std::istringstream(str4time) >> this->time_4_get_vehicle_.tm_hour;
        if (cur_cell.find("PM") != std::string::npos) {
            this->time_4_get_vehicle_.tm_hour += 12;
        }

        // minute
        prev4time = next4time + delta4time;
        next4time = cur_cell.find(delim4time, prev4time);
        (next4time == std::string::npos && prev4time != std::string::npos) ? (next4time = cur_cell.length()) : NULL;
        str4time = (next4time != std::string::npos && prev4time != std::string::npos) ?
            cur_cell.substr(prev4time, next4time - prev4time) : "00";
        std::istringstream(str4time) >> this->time_4_get_vehicle_.tm_min;

        // sec
        prev4time = next4time + delta4time;
        next4time = cur_cell.find(delim4time, prev4time);
        (next4time == std::string::npos && prev4time != std::string::npos) ? (next4time = cur_cell.length()) : NULL;
        str4time = (next4time != std::string::npos && prev4time != std::string::npos) ?
            cur_cell.substr(prev4time, next4time - prev4time) : "00";
        std::istringstream(str4time) >> this->time_4_get_vehicle_.tm_sec;
    }

    //passenger
    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    (next_pos == std::string::npos && prev_pos != std::string::npos) ? (next_pos = str_str.length()) : NULL;
    cur_cell = (next_pos != std::string::npos && prev_pos != std::string::npos) ?
        str_str.substr(prev_pos, next_pos - prev_pos) : "0";
    std::istringstream(cur_cell) >> this->passengers_numb_;

    // time return vehicle
    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
    {
        size_t prev4time = -1;
        size_t next4time = -1;
        size_t delta4time = 0;
        std::string str4time = "";

        std::string delim4time = ":";
        if (cur_cell.find(delim4time) == std::string::npos)
            delim4time = "-";
        delta4time = delim4time.length();

        // hour
        prev4time = next4time + delta4time;
        next4time = cur_cell.find(delim4time, prev4time);
        (next4time == std::string::npos && prev4time != std::string::npos) ? (next4time = cur_cell.length()) : NULL;
        str4time = (next4time != std::string::npos && prev4time != std::string::npos) ?
            cur_cell.substr(prev4time, next4time - prev4time) : "00";
        std::istringstream(str4time) >> this->time_return_vehicle_.tm_hour;
        if (cur_cell.find("PM") != std::string::npos) {
            this->time_return_vehicle_.tm_hour += 12;
        }

        // minute
        prev4time = next4time + delta4time;
        next4time = cur_cell.find(delim4time, prev4time);
        (next4time == std::string::npos && prev4time != std::string::npos) ? (next4time = cur_cell.length()) : NULL;
        str4time = (next4time != std::string::npos && prev4time != std::string::npos) ?
            cur_cell.substr(prev4time, next4time - prev4time) : "00";
        std::istringstream(str4time) >> this->time_return_vehicle_.tm_min;

        // sec
        prev4time = next4time + delta4time;
        next4time = cur_cell.find(delim4time, prev4time);
        (next4time == std::string::npos && prev4time != std::string::npos) ? (next4time = cur_cell.length()) : NULL;
        str4time = (next4time != std::string::npos && prev4time != std::string::npos) ?
            cur_cell.substr(prev4time, next4time - prev4time) : "00";
        std::istringstream(str4time) >> this->time_return_vehicle_.tm_sec;
    }

    //pass

    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    this->request_numb_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

    prev_pos = next_pos + delta_pos;
    next_pos = str_str.find(delim, prev_pos);
    this->request_numb_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

    return OK;
}
