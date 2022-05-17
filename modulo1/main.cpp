#include <iostream>
#include "Financeiro.h"
#include "Cliente.h"
#include "UC.h"
#include "Fatura.h"
#include "utils.h"

int main() {
    Financeiro fin;

    Cliente cl1;
    Cliente cl2;
    Cliente cl3;

    UC u1;
    UC u2;
    UC u3;
    UC u4;

    Fatura fat1;
    Fatura fat2;
    Fatura fat3;
    Fatura fat4;

    std::cout << "Cliente1 ID: " << cl1.getIdCliente() << std::endl;
    std::cout << "Cliente2 ID: " << cl2.getIdCliente() << std::endl;
    std::cout << "Cliente3 ID: " << cl3.getIdCliente() << std::endl;

    std::cout << " " << std::endl;

    std::cout << "UC1 ID: " << u1.getIdUc() << std::endl;
    std::cout << "UC2 ID: " << u2.getIdUc() << std::endl;
    std::cout << "UC3 ID: " << u3.getIdUc() << std::endl;
    std::cout << "UC4 ID: " << u4.getIdUc() << std::endl;

    std::cout << " " << std::endl;

    std::cout << "Fatura1 ID: " << fat1.getIdFatura() << std::endl;
    std::cout << "Fatura2 ID: " << fat2.getIdFatura() << std::endl;
    std::cout << "Fatura3 ID: " << fat3.getIdFatura() << std::endl;
    std::cout << "Fatura4 ID: " << fat4.getIdFatura() << std::endl;

    std::cout << " " << std::endl;

    time_t day1 = getTime(18, 5, 2022, 0, 0, 0);
    time_t day2 = getTime(25, 5, 2022, 0, 0, 0);

    int diff = diffDays(day2, day1);
    std::cout << "Diff days: " << diff << std::endl;

    return 0;
}
