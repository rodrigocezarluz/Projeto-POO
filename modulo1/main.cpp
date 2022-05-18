#include <iostream>
#include <vector>


#include "Financeiro.h"
#include "Cliente.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "UC.h"
#include "UCComercial.h"
#include "UCResidencial.h"
#include "UCIluminacaoPublica.h"
#include "UCIndustrial.h"
#include "Fatura.h"
#include "utils.h"

int main() {
    UCComercial u1;
    UCResidencial u2;
    UCIluminacaoPublica u3;
    UCIndustrial u4;

    PessoaFisica cl1;
    PessoaJuridica cl2;
    PessoaJuridica cl3;

    Fatura fat1(100, 0, getTime(30, 5, 2022, 0, 0, 0), getTime(15, 5, 2022, 0, 0, 0), getTime(10, 5, 2022, 0, 0, 0));
    Fatura fat2(100, 0, getTime(30, 5, 2022, 0, 0, 0), 0, getTime(10, 5, 2022, 0, 0, 0));
    Fatura fat3(100, 0, getTime(14, 5, 2022, 0, 0, 0), 0, getTime(25, 4, 2022, 0, 0, 0));
    Fatura fat4(100, 0, getTime(14, 5, 2022, 0, 0, 0), 0, getTime(25, 4, 2022, 0, 0, 0));

    Financeiro fin;

    fin.cadastrarCliente(cl1);
    fin.cadastrarCliente(cl2);
    fin.cadastrarCliente(cl3);

    fin.cadastrarUC(0, u1);
    fin.cadastrarUC(0, u2);
    fin.cadastrarUC(1, u3);
    fin.cadastrarUC(2, u4);

    fin.cadastrarFaturas(0, 0, fat1);
    fin.cadastrarFaturas(0, 1, fat2);
    fin.cadastrarFaturas(1, 2, fat3);
    fin.cadastrarFaturas(2, 3, fat4);

    time_t today = getTime(18, 5, 2022, 0, 0, 0);

    // double valor = fin.receberPagamento(1, 2, today);

    fin.verificarInadimplentes(today);

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

    // std::cout << "Valor pagamento: " << valor << std::endl;

    std::cout << " " << std::endl;

    // std::cout << "ID inadimplentes (Cliente - Fatura)" << std::endl;
    // for(const auto& inad : fin.getRelatorioInandimplentes()) {
    //     std::cout << "    " << inad.first << " - " << inad.second << std::endl;
    // }
    return 0;
}
