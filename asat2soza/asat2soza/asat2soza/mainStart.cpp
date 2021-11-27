
#include <string>

#include "transportRequests.h"

int main() {
    std::string filename = "E://Downloads//check//Leaders2021//rzdcode//dataset_tab.txt";
    TransporRequestsList checktable_read, chck_equal;
    checktable_read.list_requests.reserve(8000);
    checktable_read.readFileWithTabDelim(filename);
    chck_equal = checktable_read;
    TransporRequestsList chck_assign(checktable_read);
}