
#include <string>

#include "transportRequests.h"

int main() {
    std::string filename = "E://Downloads//check//Leaders2021//rzdcode//dataset_tab.txt";
    TransporRequestsList checktable_read;
    checktable_read.list_requests.reserve(8000);
    checktable_read.readFileWithTabDelim(filename);
}