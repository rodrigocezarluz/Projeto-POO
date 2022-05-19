#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
private:
    static int nextIdFuncionario;
    int idFuncionario;
    std::string nome;
    int maxServicos;
public:
    Funcionario();

};

#endif