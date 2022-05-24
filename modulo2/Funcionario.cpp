#include "Funcionario.h"
#include <iostream>
#include <ctime>


int Funcionario::maxServicos = 8;
int Funcionario::nextIdFuncionario = 0;

Funcionario::Funcionario() : idFuncionario(nextIdFuncionario++) {}

Funcionario::Funcionario(const std::string &nome) : idFuncionario(nextIdFuncionario++), nome(nome) {}

Funcionario::Funcionario(const std::string &nome, int maxServicos) : idFuncionario(nextIdFuncionario++), nome(nome) {}

Funcionario::Funcionario(const Funcionario& funcionario) : idFuncionario(funcionario.idFuncionario), 
                                                           nome(funcionario.nome) {}

void Funcionario::setNome(std::string nome){
    this->nome = nome;
}

std::string Funcionario::getNome() const{
    return this->nome;
}

void Funcionario::setMaxServicos(int max_servicos){
    this->maxServicos = max_servicos;
}

int Funcionario::getMaxServicos() const{
    return Funcionario::maxServicos;
}

int Funcionario::getIDFuncionario() const{
    return this->idFuncionario;
}

std::map<std::string, std::vector<Servico>> const &Funcionario::getServicos() const {
    return this->servicos;
}

void Funcionario::setServicos(std::map<std::string, std::vector<Servico>> &servicos) {
    this->servicos = servicos;
}

void Funcionario::adicionarServico(Servico &servico, std::string data, int prioridade_servico) {    
    
    if (!(this->servicos.count(data))){  
            std::vector<Servico> _servicos;            
            this->servicos.insert({data, _servicos});
            //std::cout << "Vetor de servicos criado para a data: " << data << "\n";
        }
    
    //std::cout << "Qtd de servicos ja alocados: " << this->servicos.at(data).size() << "\n";
    if (this->servicos.at(data).size() >= this->getMaxServicos()){
        std::cout << "Operacao nao realizada. Quantidade maxima de servicos ja cadastrada para a data: " + data + ".\n";
        return;
    }

    if(prioridade_servico < 1){
        prioridade_servico = 0;
    }

    else if(prioridade_servico > this->servicos.at(data).size() ){        
        prioridade_servico = this->servicos.at(data).size();
    }


    else if(prioridade_servico > this->getMaxServicos()){
        prioridade_servico = this->getMaxServicos();
    }

    //std::cout << "Servico cadastrado com prioridade: " << prioridade_servico << "\n";
    this->servicos.at(data).insert(this->servicos.at(data).begin() + prioridade_servico, servico);
    //std::cout << "Cadastro de servico finalizado" << "\n";
    return;
}


std::vector<Servico> &Funcionario::extrairServicos(){
    // obtendo a data atual
    std::time_t t = std::time(0);   
    std::tm* now = std::localtime(&t);
    std::string today_date = std::to_string(now->tm_year + 1900) + "-" + 
                            std::string(2 - std::to_string(now->tm_mon + 1).length(), '0').append(std::to_string(now->tm_mon + 1))  + "-" + 
                            std::to_string(now->tm_mday);

    
    if (!(this->servicos.count(today_date))){  
        //std::cout << "Nao ha servicos cadastrados para a data atual: " + today_date + ".\n";
        std::vector<Servico>* demanda_diaria = new std::vector<Servico>;
        return *demanda_diaria;        
        }    
        
    return this->servicos.at(today_date);    
}

int Funcionario::getQtdServicos(const std::string data_agenda) const{
    if ((this->servicos.count(data_agenda))){
        return this->servicos.at(data_agenda).size();
    }
    else{
        std::cout << "Nao ha servicos cadastrados para a data informada: " + data_agenda + ".\n";        
        return 0;
    }
}

void Funcionario::printServicos(std::vector<Servico> servicos){    
    for (Servico ser: servicos){
            std::cout << "\t\t" << "ID do servico: " << ser.getIDServico() << "; Data de inicio: " << ser.getInicio() << "; Data de fim: " << ser.getFim() << ".\n";
        }
    std::cout << "\n";
}

void Funcionario::printAgendaServicos(){
    std::map<std::string, std::vector<Servico>>::iterator it;
    std::cout << "\nAgenda do funcionario: " << this->getNome() << "\n";
    for (it = this->servicos.begin(); it != this->servicos.end(); it++){
        std::cout << "\tServicos agendados na data: " << it->first << "\n";
        std::vector<Servico> servicos = it->second;
        Funcionario::printServicos(servicos);
    }
    std::cout << "\n";
}



std::ostream& operator << (std::ostream &out, const Funcionario &funcionario){
  out << "Nome do Funcionario: " << funcionario.nome << ".\n" 
        << "ID do funcionario: " << funcionario.idFuncionario << ".\n"
        << "Quantidade maxima de servicos diarios: " << funcionario.maxServicos << ".\n";  
  return out;

}

    