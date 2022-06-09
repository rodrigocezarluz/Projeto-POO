#include <iostream>
#include <vector>
#include <functional>
#include "Gerencia.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "UC.h"
#include "UCComercial.h"
#include "UCResidencial.h"
#include "UCIluminacaoPublica.h"
#include "UCIndustrial.h"
#include "Fatura.h"
#include "Funcionario.h"
#include "Servico.h"
#include "DesligEncerramento.h"
#include "DesligInadimplencia.h"
#include "LigacaoNova.h"
#include "Medicao.h"
#include "ReligacaoPagamento.h"
#include "TrocaMedidor.h"
#include "LocalizacaoGeografica.h"
#include "Leiturista.h"
#include "Eletricista.h"

int main() {
    // INICIANDO TESTES DO MÓDULO 4
    //-------------------------------------------------------------------------------------------------------------------------
    Gerencia fin;

    Data data_hoje = Data::dateNow();
    Data data_amanha(data_hoje.getTicks()+(24*60*60));

    PessoaFisica cl1;
    PessoaJuridica cl2;

    // instanciando Funcionarios
    Funcionario::setMaxServicos(8);
    Leiturista leiturista1("Joao Vitor");
    Eletricista eletricista1("Juliana Maria");

    std::cout << "Leiturista criado: " << "\n" << leiturista1 << std::endl;
    std::cout << "Eletricista criado: " << "\n" << eletricista1 << std::endl;


    fin.cadastrarFuncionario(leiturista1);
    fin.cadastrarFuncionario(eletricista1);

    fin.cadastrarCliente(cl1);
    fin.cadastrarCliente(cl2);

    std::cout << "Cliente1 ID: " << cl1.getIdCliente() << std::endl;
    std::cout << "Cliente2 ID: " << cl2.getIdCliente() << std::endl;

    DesligEncerramento servico1, servico2;
    DesligInadimplencia servico3, servico4;
    LigacaoNova servico5, servico6;
    Medicao servico7, servico8;
    ReligacaoPagamento servico9, servico10;
    TrocaMedidor servico11, servico12;

    // inserindo servicos na agenda do eletricista e do leiturista
    fin.cadastrarServico(1, servico1, data_hoje, 2);
    fin.cadastrarServico(1, servico2, data_amanha, 1);
    fin.cadastrarServico(1, servico3, data_hoje, 2);
    fin.cadastrarServico(1, servico4, data_amanha, 1);
    fin.cadastrarServico(1, servico5, data_hoje, 2);
    fin.cadastrarServico(1, servico6, data_amanha, 1);
    fin.cadastrarServico(0, servico7, data_hoje, 2);
    fin.cadastrarServico(0, servico8, data_amanha, 1);
    fin.cadastrarServico(1, servico9, data_hoje, 2);
    fin.cadastrarServico(1, servico10, data_amanha, 1);
    fin.cadastrarServico(1, servico11, data_hoje, 2);
    fin.cadastrarServico(1, servico12, data_amanha, 1);

    std::vector<std::reference_wrapper<Funcionario>> funcionarios(std::ref(fin.getFuncionarios()));
    funcionarios[0].get().printAgendaServicos();
    funcionarios[1].get().printAgendaServicos();

    // executando os servicos
    std::cout << "Executando servicos do dia: " << data_hoje.getData() << std::endl;
    fin.executarServicos(0, data_hoje);
    std::cout << "Executando servicos do dia: " << data_amanha.getData() << std::endl;
    fin.executarServicos(1, data_amanha);

    std::vector<std::reference_wrapper<Funcionario>> funcionarios2(std::ref(fin.getFuncionarios()));
    funcionarios2[0].get().printAgendaServicos();
    funcionarios2[1].get().printAgendaServicos();

    return 0;
}
