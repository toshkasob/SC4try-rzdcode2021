#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "transportRequests.h"

int 
TransportRequestUnitFull::read_file_with_tab_delim(std::string filename)
{
    enum returnErrors
    {
        OK, ERROR_FILE_OPEN
    };
    std::ifstream finCsv(filename.c_str(), 'w');
    if (!finCsv.is_open())
        return ERROR_FILE_OPEN;
    std::string str_str;
    std::getline(finCsv, str_str);  //! read header

    while (!finCsv.eof())
    {
        std::getline(finCsv, str_str);  //! read each string
        size_t prev_pos = 0;
        size_t next_pos = 0;
        std::string delim = "\t";
        std::string cur_cell = "";

        next_pos = str_str.find(delim, prev_pos);
        this->request_numb_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

        next_pos = str_str.find(delim, prev_pos);
        this->request_id_intro_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

        next_pos = str_str.find(delim, prev_pos);
        this->status_description_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

        // date get vehicle
        next_pos = str_str.find(delim, prev_pos);
        cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
        {
            size_t prev4date = 0; size_t next4date = 0;
            std::string str4date = "";

            // day
            next4date = cur_cell.find("/", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_4_get_vehicle_->tm_mday = std::strtol(str4date.c_str(), NULL, str4date.length());

            // month
            next4date = cur_cell.find("/", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_4_get_vehicle_->tm_mon = std::strtol(str4date.c_str(), NULL, str4date.length());

            // year
            next4date = cur_cell.find("/", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_4_get_vehicle_->tm_year = std::strtol(str4date.c_str(), NULL, str4date.length());
        }

        // time get vehicle
        next_pos = str_str.find(delim, prev_pos);
        cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
        {
            size_t prev4date = 0; size_t next4date = 0;
            std::string str4date = "";

            // hour
            next4date = cur_cell.find(":", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_4_get_vehicle_->tm_hour = std::strtol(str4date.c_str(), NULL, str4date.length());
            if (cur_cell.find("PM") != std::string::npos) {
                this->time_4_get_vehicle_->tm_hour += 12;
            }

            // minute
            next4date = cur_cell.find(":", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_4_get_vehicle_->tm_min = std::strtol(str4date.c_str(), NULL, str4date.length());

            // sec
            next4date = cur_cell.find(":", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_4_get_vehicle_->tm_sec = std::strtol(str4date.c_str(), NULL, str4date.length());
        }

        // time return vehicle
        next_pos = str_str.find(delim, prev_pos);
        cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
        {
            size_t prev4date = 0; size_t next4date = 0;
            std::string str4date = "";

            // hour
            next4date = cur_cell.find(":", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_return_vehicle_->tm_hour = std::strtol(str4date.c_str(), NULL, str4date.length());
            if (cur_cell.find("PM") != std::string::npos) {
                this->time_return_vehicle_->tm_hour += 12;
            }

            // minute
            next4date = cur_cell.find(":", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_return_vehicle_->tm_min = std::strtol(str4date.c_str(), NULL, str4date.length());

            // sec
            next4date = cur_cell.find(":", prev4date);
            str4date = cur_cell.substr(prev4date, next4date - prev4date);
            this->time_return_vehicle_->tm_sec = std::strtol(str4date.c_str(), NULL, str4date.length());
        }

        //pass
        next_pos = str_str.find(delim, prev_pos);
        cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);
        this->passengers_numb_ = std::strtol(cur_cell.c_str(), NULL, cur_cell.length() );

        next_pos = str_str.find(delim, prev_pos);
        this->request_numb_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);

        next_pos = str_str.find(delim, prev_pos);
        this->request_numb_ = cur_cell = str_str.substr(prev_pos, next_pos - prev_pos);


    }
}
