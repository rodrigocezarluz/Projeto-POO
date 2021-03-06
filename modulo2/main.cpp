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
#include "DesligEncerramento.h"
#include "DesligInadimplencia.h"
#include "LigacaoNova.h"
#include "Medicao.h"
#include "ReligacaoPagamento.h"
#include "TrocaMedidor.h"


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

    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    // INICIANDO TESTES DO M??DULO 2
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
    Funcionario::setMaxServicos(8);
    Funcionario funcionario1("Jose Silva");
    Funcionario funcionario2("Luiza Maria");
    std::cout << "Funcionario criado: " << "\n" << funcionario1 << std::endl;
    std::cout << "Funcionario criado: " << "\n" << funcionario2 << std::endl;

    fin.cadastrarFuncionario(funcionario1);
    fin.cadastrarFuncionario(funcionario2);

    DesligEncerramento servico1, servico2, servico3;
    DesligInadimplencia servico4, servico5, servico6;
    LigacaoNova servico7, servico8, servico9;
    Medicao servico10, servico11, servico12;
    ReligacaoPagamento servico13, servico14;
    TrocaMedidor servico15, servico16;

    
    std::cout << "Adicionando servicos na fila dos funcionarios..." << std::endl;

    fin.cadastrarServico(0, servico1, data_hoje, 1);
    fin.cadastrarServico(0, servico2, data_hoje, 2);
    fin.cadastrarServico(0, servico3, data_hoje, 3);
    fin.cadastrarServico(0, servico6, data_hoje, 6);
    fin.cadastrarServico(0, servico4, data_hoje, 4);
    fin.cadastrarServico(0, servico5, data_hoje, 5);
    fin.cadastrarServico(0, servico7, data_hoje, 7);
    fin.cadastrarServico(0, servico8, data_hoje, 8);

    fin.cadastrarServico(1, servico9, data_hoje, 1);

    // inserindo mais servicos na agenda do funcionario1
    fin.cadastrarServico(0, servico10, data_amanha, 1);
    fin.cadastrarServico(0, servico11, data_amanha, 2);
    fin.cadastrarServico(0, servico12, data_amanha, 3);
    fin.cadastrarServico(0, servico13, data_amanha, 4);
    fin.cadastrarServico(0, servico14, data_amanha, 5);
    fin.cadastrarServico(0, servico15, data_amanha, 6);
    fin.cadastrarServico(0, servico16, data_amanha, 9);


    std::vector<Funcionario> funcionarios(fin.getFuncionarios());
    funcionarios[0].printAgendaServicos();
    funcionarios[1].printAgendaServicos();


    std::cout << "\nExtraindo demanda diaria (" << data_hoje << ") da fila do funcionario: " << funcionarios[0].getNome() << std::endl;
    std::vector<Servico> servicos_func1 = funcionarios[0].extrairServicos(data_hoje);    
    std::cout << "Lista de servicos extraidos:" << std::endl;
    Funcionario::printServicos(servicos_func1);

    std::cout << "\nExtraindo demanda diaria (" << data_hoje << ") da fila do funcionario: " << funcionarios[1].getNome() << std::endl;
    std::vector<Servico> servicos_func2 = funcionarios[1].extrairServicos(data_hoje);    
    std::cout << "Lista de servicos extraidos:" << std::endl;
    Funcionario::printServicos(servicos_func2);


    // executando os servicos
    std::cout << "Executando servicos do dia: " << data_hoje << std::endl;
    fin.executarServicos(0, data_hoje);
    fin.executarServicos(1, data_hoje);

    std::vector<Funcionario> funcionarios2(fin.getFuncionarios());
    funcionarios2[0].printAgendaServicos();
    funcionarios2[1].printAgendaServicos();


    //-------------------------------------------------------------------------------------------------------------------------


    return 0;
}
