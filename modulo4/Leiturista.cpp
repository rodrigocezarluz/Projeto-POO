//
// Created by Thales Nunes on 02/06/2022.
//

#include "Leiturista.h"

void Leiturista::verificarServico(Servico& servico) {
    if (servico.getTipoServico() != TipoServico::MEDICAO)
        throw std::invalid_argument("O Funcionario nao esta apto para este tipo de servico.");
}

void Leiturista::adicionarServico(Servico &servico, Data data, int prioridade_servico) {
    this->verificarServico(servico);
    Funcionario::adicionarServico(servico, data, prioridade_servico);
}