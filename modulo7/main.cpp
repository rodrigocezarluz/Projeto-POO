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
#include "AcessoNegadoException.h"
#include "Erro.h"
#include "Log.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogTentativaAcesso.h"
#include "Logger.h"
#include "UsuarioLogado.h"

int main() {
    //TODO: Um usuário logado sendo acessado em duas situações diferentes de maneira a comprovar o comportamento do singleton
    //TODO: Registro de pelo menos uma violação de permissão de acesso pelo usuário logado
    //TODO: Log de tentativa de acesso do usuario

    //3 clientes com UC’s de 3 tipos diferentes
    UCComercial u1;
    UCResidencial u2;
    UCIluminacaoPublica u3;
    UCIndustrial u4;

    PessoaFisica cl1;
    PessoaJuridica cl2;
    PessoaJuridica cl3;

    Gerencia fin;

    fin.cadastrarCliente(cl1);
    fin.cadastrarCliente(cl2);
    fin.cadastrarCliente(cl3);

    fin.cadastrarUC(0, u1);
    fin.cadastrarUC(0, u2);
    fin.cadastrarUC(1, u3);
    fin.cadastrarUC(2, u4);

    //Registro de um cliente que viola a regra de validação do CPF
    //Registro de um cliente que viola a regra de validação do CNPJ
    cl1.setCpf("02062008627");
    cl2.setCnpj("46260781000154");

    try {
        cl1.setCpf("02062008629");
    } catch (Erro &e) {
        e.out();
    }

    try {
        cl2.setCnpj("46260781000153");
    } catch (Erro &e) {
        e.out();
    }

    //Registro de uma UC que viola as regras de tensão de atendimento
    u1.setNivelTensao("BT");
    u2.setNivelTensao("MT");
    u3.setNivelTensao("AT");
    u4.setNivelTensao("AT");

    try {
        u1.setNivelTensao("HT");
    } catch (Erro &e) {
        e.out();
    }

    try {
        u2.setNivelTensao("HT");
    } catch (Erro &e) {
        e.out();
    }

    //Registro de atribuição de um serviço para um funcionário que não pode executar aquele serviço, demonstrando o tratamento da exceção
    Data data_hoje = Data::dateNow();
    Data data_amanha(data_hoje.getTicks()+(24*60*60));
    
    Funcionario::setMaxServicos(8);
    Funcionario funcionario1("Jose Silva");
    Funcionario funcionario2("Luiza Maria");
    Leiturista leiturista1("Joao Vitor");
    Eletricista eletricista1("Juliana Maria"); 

    fin.cadastrarFuncionario(funcionario1);
    fin.cadastrarFuncionario(funcionario2);
    fin.cadastrarFuncionario(leiturista1);
    fin.cadastrarFuncionario(eletricista1);

    DesligEncerramento servico1, servico2;
    DesligInadimplencia servico3, servico4;
    LigacaoNova servico5, servico6;
    Medicao servico7, servico8;
    ReligacaoPagamento servico9, servico10;
    TrocaMedidor servico11, servico12;

    std::cout << "Adicionando servicos na fila dos funcionarios..." << std::endl;

    fin.cadastrarServico(0, servico1, data_hoje, 1);
    fin.cadastrarServico(0, servico2, data_hoje, 2);
    fin.cadastrarServico(0, servico3, data_hoje, 3);
    fin.cadastrarServico(1, servico4, data_hoje, 6);
    fin.cadastrarServico(1, servico5, data_hoje, 4);
    fin.cadastrarServico(1, servico6, data_hoje, 5);
    fin.cadastrarServico(2, servico7, data_hoje, 7);
    fin.cadastrarServico(2, servico8, data_hoje, 8);
    fin.cadastrarServico(3, servico9, data_hoje, 1);
    fin.cadastrarServico(3, servico10, data_amanha, 1);
    fin.cadastrarServico(3, servico11, data_amanha, 2);
    fin.cadastrarServico(3, servico12, data_amanha, 3);

    //atribuição de um serviço para um funcionário que não pode executar aquele serviço
    try {
        fin.cadastrarServico(3, servico7, data_hoje, 1);
    } catch (Erro &e) {
        e.out();
    }

    try {
        fin.cadastrarServico(2, servico9, data_hoje, 2);
    } catch (Erro &e) {
        e.out();
    }

    std::vector<std::reference_wrapper<Funcionario>> funcionarios(fin.getFuncionarios());
    funcionarios[0].get().printAgendaServicos();
    funcionarios[1].get().printAgendaServicos();

    std::cout << "\nExtraindo demanda diaria (" << data_hoje.getData() << ") da fila do funcionario: " << funcionarios[0].get().getNome() << std::endl;
    std::vector<std::reference_wrapper<Servico>> servicos_func1 = funcionarios[0].get().extrairServicos(data_hoje);
    std::cout << "Lista de servicos extraidos:" << std::endl;
    Funcionario::printServicos(servicos_func1);

    std::cout << "\nExtraindo demanda diaria (" << data_hoje.getData() << ") da fila do funcionario: " << funcionarios[1].get().getNome() << std::endl;
    std::vector<std::reference_wrapper<Servico>> servicos_func2 = funcionarios[1].get().extrairServicos(data_hoje);
    std::cout << "Lista de servicos extraidos:" << std::endl;
    Funcionario::printServicos(servicos_func2);

    std::cout << "\nExtraindo demanda diaria (" << data_hoje.getData() << ") da fila do funcionario: " << funcionarios[2].get().getNome() << std::endl;
    std::vector<std::reference_wrapper<Servico>> servicos_func3 = funcionarios[2].get().extrairServicos(data_hoje);
    std::cout << "Lista de servicos extraidos:" << std::endl;
    Funcionario::printServicos(servicos_func3);

    std::cout << "\nExtraindo demanda diaria (" << data_hoje.getData() << ") da fila do funcionario: " << funcionarios[3].get().getNome() << std::endl;
    std::vector<std::reference_wrapper<Servico>> servicos_func4 = funcionarios[3].get().extrairServicos(data_hoje);
    std::cout << "Lista de servicos extraidos:" << std::endl;
    Funcionario::printServicos(servicos_func4);

    std::cout << "Executando servicos do dia: " << data_hoje.getData() << std::endl;
    fin.executarServicos(0, data_hoje);
    fin.executarServicos(1, data_hoje);
    fin.executarServicos(2, data_hoje);
    fin.executarServicos(3, data_hoje);

    //Registro de 2 medições de um leiturista com cálculo de duas faturas, sendo uma delas em atraso
    Fatura fat1(100, 0, Data(2022, 7, 5, 0, 0, 0), Data(2022, 7, 3, 0, 0, 0), Data(2022, 7, 1, 0, 0, 0));
    Fatura fat2(100, 0, Data(2022, 7, 5, 0, 0, 0), Data(2022, 7, 7, 0, 0, 0), Data(2022, 7, 1, 0, 0, 0));

    fin.cadastrarFaturas(2, 0, fat1);
    fin.cadastrarFaturas(2, 0, fat2);

    Data today(2022, 7, 7, 0, 0, 0);

    double paidValue = fin.receberPagamento(1, fat1.getIdFatura(), today);
    std::cout << "Valor pagamento: R$" << paidValue << std::endl;

    fin.verificarInadimplentes(today);

    std::cout << "ID inadimplentes (Cliente - Fatura)" << std::endl;
    for(const auto& inadimplentes : fin.getRelatorioInandimplentes()) {
        std::cout << "    " << inadimplentes.first << " - ";
        for (const auto & count : inadimplentes.second) {
            std::cout << count.getIdFatura() << " ";
        }
        std::cout << std::endl;
    }

    //TODO: Registro de log de todas as operações realizadas anteriormente

    return 0;
}
