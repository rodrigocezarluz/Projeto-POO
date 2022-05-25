#include "Funcionario.h"
#include <iostream>
#include <ctime>


int Funcionario::maxServicos = 8;
int Funcionario::nextIdFuncionario = 0;

Funcionario::Funcionario() : idFuncionario(nextIdFuncionario++) {}

Funcionario::Funcionario(const std::string &nome) : idFuncionario(nextIdFuncionario++), nome(nome) {}

Funcionario::Funcionario(const Funcionario& funcionario) : idFuncionario(funcionario.idFuncionario), 
                                                           nome(funcionario.nome),
                                                           servicos(funcionario.servicos) {}

void Funcionario::setNome(const std::string &nome){
    this->nome = nome;
}

std::string Funcionario::getNome() const{
    return this->nome;
}

void Funcionario::setMaxServicos(const int &ms){
    Funcionario::maxServicos = ms;
}

int Funcionario::getMaxServicos(){
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

void Funcionario::adicionarServico(Servico &servico, const std::string &data, int prioridade_servico) {    
    
    if (!(this->servicos.count(data))){  
            std::vector<Servico> _servicos;            
            this->servicos.insert({data, _servicos});
        }
    
    if (this->servicos.at(data).size() >= Funcionario::maxServicos){
        std::cout << "Operacao nao realizada. Quantidade maxima de servicos ja cadastrada para a data: " + data + ".\n";
        return;
    }

    if(prioridade_servico < 1){
        prioridade_servico = 0;
    }

    else if(prioridade_servico > this->servicos.at(data).size() ){        
        prioridade_servico = this->servicos.at(data).size();
    }


    else if(prioridade_servico > Funcionario::maxServicos){
        prioridade_servico = Funcionario::maxServicos;
    }

    this->servicos.at(data).insert(this->servicos.at(data).begin() + prioridade_servico, servico);
}


std::vector<Servico> Funcionario::extrairServicos(const std::string &data){
    if (!(this->servicos.count(data))){  
        return std::vector<Servico> ();
    }    
        
    return this->servicos.at(data);
}

void Funcionario::executarServicos(const std::string &data) {
    if (!(this->servicos.count(data))){
        return;
    }
    for (auto& ser: this->servicos.at(data)){
        ser.setInicio(time(0));
        ser.executar();
    }
}

int Funcionario::getQtdServicos(const std::string data_agenda) const{
    if ((this->servicos.count(data_agenda))){
        return this->servicos.at(data_agenda).size();
    }
    else {
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

bool Funcionario::operator==(const Funcionario& other) {
  return this->idFuncionario == other.getIDFuncionario();
}

Funcionario& Funcionario::operator=(const Funcionario& other) {
    this->idFuncionario = other.getIDFuncionario();
    this->nome = other.getNome();
    this->servicos = other.getServicos();

    return *this;
}

std::ostream& operator << (std::ostream &out, const Funcionario &funcionario){
  out << "Nome do Funcionario: " << funcionario.nome << ".\n" 
        << "ID do funcionario: " << funcionario.idFuncionario << ".\n"
        << "Quantidade maxima de servicos diarios: " << Funcionario::maxServicos << ".\n";  
  return out;

}

    