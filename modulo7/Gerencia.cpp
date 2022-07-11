//
// Created by Thales Nunes on 5/11/22.
//

#include "Gerencia.h"
#include "Erro.h"
#include <stdexcept>

Gerencia::Gerencia() {}

Gerencia::Gerencia(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes,
                       const std::vector<Cliente> &clientes) : relatorioInandimplentes(relatorioInandimplentes),
                                                               clientes(clientes) {};

const std::map<int, std::vector<Fatura>> &Gerencia::getRelatorioInandimplentes() const {
    return relatorioInandimplentes;
}

void Gerencia::setRelatorioInandimplentes(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes) {
    this->relatorioInandimplentes = relatorioInandimplentes;
}

const std::vector<Cliente> &Gerencia::getClientes() const {
    return clientes;
}

void Gerencia::setClientes(const std::vector<Cliente> &clientes) {
    this->clientes = clientes;
}

const vector<std::reference_wrapper<Funcionario>> &Gerencia::getFuncionarios() const {
    return funcionarios;
}

void Gerencia::setFuncionarios(const vector<std::reference_wrapper<Funcionario>> &funcionarios) {
    Gerencia::funcionarios = funcionarios;
}

void Gerencia::cadastrarCliente(Cliente &cliente) {
    UsuarioLogado* usuario_logado = UsuarioLogado::GetInstance();
    std::vector<std::reference_wrapper<Permissao>> permissoes =  usuario_logado->getUsuario().getPermissoes();

    bool negado = true;
    for (auto& perm: permissoes){
        if (perm.get() == Permissao::Administrator) {
            negado = false;
        }
    }
    if (negado) {
        throw AcessoNegadoException("cadastrarCliente", usuario_logado->getUsuario());
    }

    this->clientes.push_back(cliente);
}

void Gerencia::cadastrarFuncionario(Funcionario &funcionario) {
    UsuarioLogado* usuario_logado = UsuarioLogado::GetInstance();
    std::vector<std::reference_wrapper<Permissao>> permissoes =  usuario_logado->getUsuario().getPermissoes();

    bool negado = true;
    for (auto& perm: permissoes){
        if (perm.get() == Permissao::Administrator) {
            negado = false;
        }
    }
    if (negado) {
        throw AcessoNegadoException("cadastrarFuncionario", usuario_logado->getUsuario());
    }
    
    this->funcionarios.push_back(funcionario);
}

void Gerencia::cadastrarUC(const int &clienteToInsert, UC &uc) {
    UsuarioLogado* usuario_logado = UsuarioLogado::GetInstance();
    std::vector<std::reference_wrapper<Permissao>> permissoes =  usuario_logado->getUsuario().getPermissoes();

    bool negado = true;
    for (auto& perm: permissoes){
        if (perm.get() == Permissao::Administrator) {
            negado = false;
        }
    }
    if (negado) {
        throw AcessoNegadoException("cadastrarUC", usuario_logado->getUsuario());
    }

    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() == clienteToInsert){
            cliente.addUC(uc);
            return;
        }
    }

    throw Erro("O cliente da UC nao existe.");
}


void Gerencia::cadastrarFaturas(const int &idCliente, int idUC, Fatura& fatura) {
    UsuarioLogado* usuario_logado = UsuarioLogado::GetInstance();
    std::vector<std::reference_wrapper<Permissao>> permissoes =  usuario_logado->getUsuario().getPermissoes();

    bool negado = true;
    for (auto& perm: permissoes){
        if (perm.get() == Permissao::Administrator) {
            negado = false;
        }
    }
    if (negado) {
        throw AcessoNegadoException("cadastrarFaturas", usuario_logado->getUsuario());
    }

    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() != idCliente) {
            continue;
        }
        cliente.addFatura(idUC, fatura);
        return;
    }
    throw Erro( "O cliente da UC nao existe." );
}

void Gerencia::cadastrarServico(const int &idFuncionario, Servico &servico, const Data &data, int prioridade_servico) {
    UsuarioLogado* usuario_logado = UsuarioLogado::GetInstance();
    std::vector<std::reference_wrapper<Permissao>> permissoes =  usuario_logado->getUsuario().getPermissoes();

    bool negado = true;
    for (auto& perm: permissoes){
        if (perm.get() == Permissao::Administrator) {
            negado = false;
        }
    }
    if (negado) {
        throw AcessoNegadoException("cadastrarServico", usuario_logado->getUsuario());
    }

    for (auto &funcionario : this->funcionarios) {
        if (funcionario.get().getIDFuncionario() == idFuncionario){
            funcionario.get().adicionarServico(servico, data, prioridade_servico);
            return;
        }
    }

    throw Erro("O funcionario nao existe.");
}

void Gerencia::executarServicos(const int &idFuncionario, const Data &data) {
    for (auto &funcionario : this->funcionarios) {
        if (funcionario.get().getIDFuncionario() == idFuncionario) {
            funcionario.get().executarServicos(data);
            return;
        }
    }
    throw Erro("O funcionario nao existe.");
}

double Gerencia::receberPagamento(const int &idCliente, const int &idFaturaAPagar, const Data &dtPagamento) {
    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() == idCliente) {
            return cliente.pagar(idFaturaAPagar, dtPagamento);
        }
    }
    throw Erro("O cliente nao existe.");
}

void Gerencia::verificarInadimplentes(Data &now) {
    relatorioInandimplentes.clear();
    for (auto &cliente : this->clientes) {
        std::vector<Fatura> faturasVencidas = cliente.verificarVencimento(now);
        if (faturasVencidas.size() > 0) {
                relatorioInandimplentes[cliente.getIdCliente()] = faturasVencidas;
        }
    }
}
