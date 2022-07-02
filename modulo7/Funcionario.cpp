#include "Funcionario.h"
#include <iostream>
#include <ctime>


int Funcionario::maxServicos = 8;
int Funcionario::nextIdFuncionario = 0;

Funcionario::Funcionario() : Usuario(), idFuncionario(nextIdFuncionario++) {}

Funcionario::Funcionario(const std::string &nome) : Usuario(), idFuncionario(nextIdFuncionario++) {
    this->setNome(nome);
}

Funcionario::Funcionario(const Funcionario& funcionario) : Usuario(), idFuncionario(funcionario.idFuncionario), servicos(funcionario.servicos) {
    this->setNome(funcionario.getNome());
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

std::map<long, std::vector<std::reference_wrapper<Servico>>> const &Funcionario::getServicos() const {
    return this->servicos;
}

void Funcionario::setServicos(std::map<long, std::vector<std::reference_wrapper<Servico>>> &servicos) {
    this->servicos = servicos;
}

void Funcionario::adicionarServico(Servico &servico, Data data, int prioridade_servico) {
    verificarServico(servico);
    data.zerarHora();
    long key = data.getTicks();
    
    if (!(this->servicos.count(key))){
        std::vector<std::reference_wrapper<Servico>> _servicos;
        this->servicos.insert({key, _servicos});
    }
    
    if (this->servicos.at(key).size() >= Funcionario::maxServicos){
        std::cout << "Operacao nao realizada. Quantidade maxima de servicos ja cadastrada para a data: " + data.getData() + ".\n";
        return;
    }

    if(prioridade_servico < 1){
        prioridade_servico = 0;
    }

    else if(prioridade_servico > this->servicos.at(key).size() ){        
        prioridade_servico = this->servicos.at(key).size();
    }


    else if(prioridade_servico > Funcionario::maxServicos){
        prioridade_servico = Funcionario::maxServicos;
    }

    this->servicos.at(key).insert(this->servicos.at(key).begin() + prioridade_servico, servico);
}

std::vector<std::reference_wrapper<Servico>> Funcionario::extrairServicos(Data data){
    data.zerarHora();
    long key = data.getTicks();
    if (!(this->servicos.count(key))){
        return std::vector<std::reference_wrapper<Servico>> ();
    }    
        
    return this->servicos.at(key);
}

void Funcionario::executarServicos(Data data) {
    data.zerarHora();
    long key = data.getTicks();

    if (!(this->servicos.count(key))){
        return;
    }

    for (auto& ser: this->servicos.at(key)){
        ser.get().setInicio(time(0));
        ser.get().executar();
    }
}

int Funcionario::getQtdServicos(Data data_agenda) const{
    data_agenda.zerarHora();
    long key = data_agenda.getTicks();
    if ((this->servicos.count(key))){
        return this->servicos.at(key).size();
    }
    else {
        std::cout << "Nao ha servicos cadastrados para a data informada: " + data_agenda.getData() + ".\n";        
        return 0;
    }
}

void Funcionario::printServicos(std::vector<std::reference_wrapper<Servico>> servicos){
    for (auto& ser: servicos){
        std::cout << "\t\t" << "ID do servico: " << ser.get().getIDServico() << "; Data de inicio: " << ser.get().getInicio().getData() << "; Data de fim: " << ser.get().getFim().getData() << ".\n";
    }
    std::cout << "\n";
}

void Funcionario::printAgendaServicos(){
    std::map<long, std::vector<std::reference_wrapper<Servico>>>::iterator it;
    std::cout << "\nAgenda do funcionario: " << this->getNome() << "\n";
    for (it = this->servicos.begin(); it != this->servicos.end(); it++){
        Data temp(it->first);
        std::cout << "\tServicos agendados na data: " << temp.getData() << "\n";
        std::vector<std::reference_wrapper<Servico>> serv = it->second;
        Funcionario::printServicos(serv);
    }
    std::cout << "\n";
}

bool Funcionario::operator==(const Funcionario& other) {
  return this->idFuncionario == other.getIDFuncionario();
}

Funcionario& Funcionario::operator=(const Funcionario& other) {
    this->idFuncionario = other.getIDFuncionario();
    this->setNome(other.getNome());
    this->servicos = other.getServicos();

    return *this;
}

std::ostream& operator << (std::ostream &out, const Funcionario &funcionario){
  out << "Nome do Funcionario: " << funcionario.getNome() << ".\n" 
        << "ID do funcionario: " << funcionario.idFuncionario << ".\n"
        << "Quantidade maxima de servicos diarios: " << Funcionario::maxServicos << ".\n";  
  return out;

}

void Funcionario::verificarServico(Servico &servico) {

}

    