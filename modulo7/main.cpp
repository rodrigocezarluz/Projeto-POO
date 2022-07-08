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

    std::cout << "Cliente1 ID: " << cl1.getIdCliente() << std::endl;
    std::cout << "Cliente2 ID: " << cl2.getIdCliente() << std::endl;
    std::cout << "Cliente3 ID: " << cl3.getIdCliente() << std::endl;

    std::cout << " " << std::endl;

    std::cout << "UC1 ID: " << u1.getIdUc() << std::endl;
    std::cout << "UC2 ID: " << u2.getIdUc() << std::endl;
    std::cout << "UC3 ID: " << u3.getIdUc() << std::endl;
    std::cout << "UC4 ID: " << u4.getIdUc() << std::endl;

    std::cout << " " << std::endl;

    //Registro de um cliente que viola a regra de validação do CPF
    //Registro de um cliente que viola a regra de validação do CNPJ
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

    //Registro de uma UC que viola as regras de tensão de atendimento
    u1.setNivelTensao("BT");
    u2.setNivelTensao("MT");
    u3.setNivelTensao("AT");
    u4.setNivelTensao("HT");

    //Registro de atribuição de um serviço para um funcionário que não pode executar aquele serviço, demonstrando o tratamento da exceção
    Data data_hoje = Data::dateNow();
    Data data_amanha(data_hoje.getTicks()+(24*60*60));
    
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
    fin.cadastrarServico(1, servico1, data_hoje, 1);//atribuição de um serviço para um funcionário que não pode executar aquele serviço
    fin.cadastrarServico(0, servico2, data_hoje, 2);
    fin.cadastrarServico(1, servico2, data_hoje, 2);//atribuição de um serviço para um funcionário que não pode executar aquele serviço
    fin.cadastrarServico(0, servico3, data_hoje, 3);
    fin.cadastrarServico(0, servico6, data_hoje, 6);
    fin.cadastrarServico(0, servico4, data_hoje, 4);
    fin.cadastrarServico(0, servico5, data_hoje, 5);
    fin.cadastrarServico(0, servico7, data_hoje, 7);
    fin.cadastrarServico(0, servico8, data_hoje, 8);

    fin.cadastrarServico(1, servico9, data_hoje, 1);

    fin.cadastrarServico(0, servico10, data_amanha, 1);
    fin.cadastrarServico(0, servico11, data_amanha, 2);
    fin.cadastrarServico(0, servico12, data_amanha, 3);
    fin.cadastrarServico(0, servico13, data_amanha, 4);
    fin.cadastrarServico(0, servico14, data_amanha, 5);
    fin.cadastrarServico(0, servico15, data_amanha, 6);
    fin.cadastrarServico(0, servico16, data_amanha, 9);

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

    std::cout << "Executando servicos do dia: " << data_hoje.getData() << std::endl;
    fin.executarServicos(0, data_hoje);
    fin.executarServicos(1, data_hoje);

    std::vector<std::reference_wrapper<Funcionario>> funcionarios2(fin.getFuncionarios());
    funcionarios2[0].get().printAgendaServicos();
    funcionarios2[1].get().printAgendaServicos();

    //Registro de 2 medições de um leiturista com cálculo de duas faturas, sendo uma delas em atraso
    Leiturista leiturista1("Joao Vitor");
    Eletricista eletricista1("Juliana Maria");

    std::cout << "Leiturista criado: " << "\n" << leiturista1 << std::endl;
    std::cout << "Eletricista criado: " << "\n" << eletricista1 << std::endl;    

    fin.cadastrarFuncionario(leiturista1);
    fin.cadastrarFuncionario(eletricista1);

    PessoaFisica cl5;
    PessoaJuridica cl6;

    fin.cadastrarCliente(cl5);
    fin.cadastrarCliente(cl6);

    std::cout << "Cliente5 ID: " << cl5.getIdCliente() << std::endl;
    std::cout << "Cliente6 ID: " << cl6.getIdCliente() << std::endl;

    DesligEncerramento servico18, servico19;
    DesligInadimplencia servico20, servico21;
    LigacaoNova servico22, servico23;
    Medicao servico24, servico25;
    ReligacaoPagamento servico26, servico27;
    TrocaMedidor servico28, servico29;

    fin.cadastrarServico(1, servico18, data_hoje, 2);
    fin.cadastrarServico(1, servico19, data_amanha, 1);
    fin.cadastrarServico(1, servico20, data_hoje, 2);
    fin.cadastrarServico(1, servico21, data_amanha, 1);
    fin.cadastrarServico(1, servico22, data_hoje, 2);
    fin.cadastrarServico(1, servico23, data_amanha, 1);
    fin.cadastrarServico(0, servico24, data_hoje, 2);
    fin.cadastrarServico(0, servico25, data_amanha, 1);
    fin.cadastrarServico(1, servico26, data_hoje, 2);
    fin.cadastrarServico(1, servico27, data_amanha, 1);
    fin.cadastrarServico(1, servico28, data_hoje, 2);
    fin.cadastrarServico(1, servico29, data_amanha, 1);

    std::vector<std::reference_wrapper<Funcionario>> funcionarios3(std::ref(fin.getFuncionarios()));
    funcionarios3[0].get().printAgendaServicos();
    funcionarios3[1].get().printAgendaServicos();

    std::cout << "Executando servicos do dia: " << data_hoje.getData() << std::endl;
    fin.executarServicos(0, data_hoje);
    std::cout << "Executando servicos do dia: " << data_amanha.getData() << std::endl;
    fin.executarServicos(1, data_amanha);

    std::vector<std::reference_wrapper<Funcionario>> funcionarios4(std::ref(fin.getFuncionarios()));
    funcionarios4[0].get().printAgendaServicos();
    funcionarios4[1].get().printAgendaServicos();

    Fatura fat1(100, 0, Data(2022, 7, 5, 0, 0, 0), Data(2022, 7, 3, 0, 0, 0), Data(2022, 7, 1, 0, 0, 0));
    Fatura fat2(100, 0, Data(2022, 7, 5, 0, 0, 0), Data(2022, 7, 7, 0, 0, 0), Data(2022, 7, 1, 0, 0, 0));

    fin.cadastrarFaturas(4, 0, fat1);
    fin.cadastrarFaturas(5, 0, fat2);

    Data today(2022, 7, 7, 0, 0, 0);

    double paidValue = fin.receberPagamento(1, fat1.getIdFatura(), today);
    std::cout << "Valor pagamento: R$" << paidValue << std::endl;

    fin.verificarInadimplentes(today);

    std::cout << "Fatura6 ID: " << fat1.getIdFatura() << std::endl;
    std::cout << "Fatura7 ID: " << fat2.getIdFatura() << std::endl;

    std::cout << "ID inadimplentes (Cliente - Fatura)" << std::endl;
    for(const auto& inadimplentes : fin.getRelatorioInandimplentes()) {
        std::cout << "    " << inadimplentes.first << " - ";
        for (const auto & count : inadimplentes.second) {
            std::cout << count.getIdFatura() << " ";
        }
        std::cout << std::endl;
    }

    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    //TODO: Registro de log de todas as operações realizadas anteriormente

    return 0;
}
