#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Gerencia.h"
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
#include "Funcionario.h"
#include "Servico.h"


int main() {

    // INICIANDO TESTES DO MODULO 1
    //-------------------------------------------------------------------------------------------------------------------------
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

    Gerencia fin;

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

    double paidValue = fin.receberPagamento(1, fat3.getIdFatura(), today);
    std::cout << "Valor pagamento: R$" << paidValue << std::endl;


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

    std::cout << std::endl << std::endl;

     std::cout << "ID inadimplentes (Cliente - Fatura)" << std::endl;
     for(const auto& inadimplentes : fin.getRelatorioInandimplentes()) {
         std::cout << "    " << inadimplentes.first << " - ";
          for (const auto & count : inadimplentes.second) {
              std::cout << count.getIdFatura() << " ";
          }
         std::cout << std::endl;
     }

     cl1.setCpf("02062008627");
     cl2.setCnpj("46260781000154");

    try {
        cl1.setCpf("02062008629");
    } catch (std::invalid_argument &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    try {
        cl2.setCnpj("46260781000153");
    } catch (std::invalid_argument &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
    //-------------------------------------------------------------------------------------------------------------------------



    // INICIANDO TESTES DO MÓDULO 2
    //-------------------------------------------------------------------------------------------------------------------------
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::string data_hoje = std::to_string(now->tm_year + 1900) + "-" + 
                                std::string(2 - std::to_string(now->tm_mon + 1).length(), '0').append(std::to_string(now->tm_mon + 1))  + "-" + 
                                std::to_string(now->tm_mday);
    
    std::string data_amanha = std::to_string(now->tm_year + 1900) + "-" + 
                                std::string(2 - std::to_string(now->tm_mon + 1).length(), '0').append(std::to_string(now->tm_mon + 1))  + "-" + 
                                std::to_string(now->tm_mday + 1);


    // instanciando Funcionarios
    Funcionario funcionario1("Jose Silva", 8);
    Funcionario funcionario2("Luiza Maria", 8);
    std::cout << "Funcionario criado: " << "\n" << funcionario1 << "\n";
    std::cout << "Funcionario criado: " << "\n" << funcionario2 << "\n";

    Servico servico1, servico2, servico3, servico4, servico5, servico6, servico7, servico8, servico9;
    Servico servico10, servico11, servico12, servico13, servico14, servico15, servico16;

    
    std::cout << "Adicionando servicos na fila do Funcionario: " << funcionario1.getNome() << "\n";
    funcionario1.adicionarServico(servico1, data_hoje, 1);
    funcionario1.adicionarServico(servico2, data_hoje, 2);
    funcionario1.adicionarServico(servico3, data_hoje, 3);
    funcionario1.adicionarServico(servico6, data_hoje, 6);
    funcionario1.adicionarServico(servico4, data_hoje, 4);
    funcionario1.adicionarServico(servico5, data_hoje, 5);
    funcionario1.adicionarServico(servico7, data_hoje, 7);
    funcionario1.adicionarServico(servico8, data_hoje, 8);
    std::cout << "\nQuantidade de servicos na agenda do funcionario "<<  funcionario1.getNome() << " : " << funcionario1.getQtdServicos(data_hoje);

    // servico acima da quantidade maxima
    if (funcionario1.getQtdServicos(data_hoje) == funcionario1.getMaxServicos()){
        funcionario2.adicionarServico(servico9, data_hoje, 1);
    }

    
    funcionario1.printAgendaServicos();


    std::cout << "\nExtraindo demanda diaria (" << data_hoje << ") da fila do funcionario: " << funcionario1.getNome() << "\n";
    std::vector<Servico> &servicos_func1 = funcionario1.extrairServicos();    
    std::cout << "Lista de servicos extraidos: \n";
    Funcionario::printServicos(servicos_func1);


    // executando os servicos
    std::cout << "Executando servicos do funcionario: " << funcionario1.getNome() << "\n";
    for (Servico& ser: servicos_func1){
            ser.setInicio(time(0));
            ser.executar();
            std::cout << "ID do servico: " << ser.getIDServico() << "; Data de inicio: " << ser.getInicio() << "; Data de fim: " << ser.getFim() << ".\n";
        }


    // inserindo mais servicos na agenda do funcionario1
    funcionario1.adicionarServico(servico10, data_amanha, 1);
    funcionario1.adicionarServico(servico11, data_amanha, 2);
    funcionario1.adicionarServico(servico12, data_amanha, 3);
    funcionario1.adicionarServico(servico13, data_amanha, 4);
    funcionario1.adicionarServico(servico14, data_amanha, 5);
    funcionario1.adicionarServico(servico15, data_amanha, 6);
    funcionario1.adicionarServico(servico16, data_amanha, 9);


    funcionario1.printAgendaServicos();
    funcionario2.printAgendaServicos();


    //-------------------------------------------------------------------------------------------------------------------------


    return 0;
}
