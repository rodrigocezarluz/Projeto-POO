#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Data.h"
#include <ctime>

int main() {
    // Data data(time(0));

    // Data data_hoje = Data::dateNow();   // get time now
    
    // Data data_amanha = Data::dateNow();
    // data_amanha.setDia(data_amanha.getDia()+1);

    // std::cout << "hoje: " << data_hoje.getData() << std::endl;
    // std::cout << "amanha: " << data_amanha.getData() << std::endl;

    // std::cout << "amanha: " << Data::dateNow().getData() << std::endl;
    // std::cout << "amanha: " << data.dateNow().getData() << std::endl;
    // std::cout << "amanha: " << data.getData() << std::endl;

    Data data(2022, 30, 5, 0, 0, 0);
    Data data2(2022, 28, 5, 0, 0, 0);
    std::cout << "data: " << data.getData() << std::endl;
    std::cout << "data2: " << data2.getData() << std::endl;
    std::cout << "diff dias: " << (data-data2).getData() << std::endl;

    //-------------------------------------------------------------------------------------------------------------------------


    return 0;
}
