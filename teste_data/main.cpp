#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Data.h"
#include <ctime>

int main() {

    Data data(2022, 5, 30, 0, 20, 0);
    Data data2 = Data::dateNow();

    data.zerarHora();

    std::cout << "data: " << data.getData() << std::endl;
    std::cout << "data2: " << data2.getData() << std::endl;
    std::cout << "diff dias: " << data.diffData(data2) << std::endl;
    std::cout << "diff dias operator: " << data-data2 << std::endl;

    //-------------------------------------------------------------------------------------------------------------------------


    return 0;
}
