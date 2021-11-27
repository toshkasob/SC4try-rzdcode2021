
#include <string>

#include "transportRequests.h"

int main() {
    std::string filename = "E://Downloads//check//Leaders2021//rzdcode//dataset_tab.txt";
    TransporRequestsList checktable_read;
    checktable_read.list_requests.resize(1);
    checktable_read.list_requests.at(0).read_file_with_tab_delim(filename);
}