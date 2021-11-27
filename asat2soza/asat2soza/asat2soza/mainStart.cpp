
#include <string>
#include <map>
#include <time.h>

#include "transportRequests.h"

//struct less_tm {
//    bool operator()(const struct tm &tmLeft, const struct tm& tmRight) const
//    {
//        bool is_less_time_4_get_vehicle_ =
//            tmLeft.tm_year < tmRight.tm_year ||
//            tmLeft.tm_mon < tmRight.tm_mon ||
//            tmLeft.tm_mday < tmRight.tm_mday ||
//            tmLeft.tm_hour < tmRight.tm_hour ||
//            tmLeft.tm_min < tmRight.tm_min ||
//            tmLeft.tm_sec < tmRight.tm_sec;
//        return is_less_time_4_get_vehicle_;
//    }
//};

int main() {
    std::string filename = "E://Downloads//check//Leaders2021//rzdcode//dataset_tab.txt";
    TransporRequestsList checktable_read, chck_equal;
    checktable_read.list_requests.reserve(8000);
    checktable_read.readFileWithTabDelim(filename);
    //chck_equal = checktable_read;
    //TransporRequestsList chck_assign(checktable_read);

    //std::map <struct tm *, TransportRequestUnitFull, less_tm> chck_map;
    std::map <struct tm*, TransportRequestUnitFull> chck_map;
    chck_map.insert(std::make_pair(&checktable_read.list_requests.at(0).time_4_get_vehicle_, checktable_read.list_requests.at(0)) );
    chck_map.insert(std::make_pair(&checktable_read.list_requests.at(1).time_4_get_vehicle_, checktable_read.list_requests.at(0)));
    chck_map.insert(std::make_pair(&checktable_read.list_requests.at(2).time_4_get_vehicle_, checktable_read.list_requests.at(0)));
}