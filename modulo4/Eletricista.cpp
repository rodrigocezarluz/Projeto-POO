//
// Created by Thales Nunes on 02/06/2022.
//

#include "Eletricista.h"

void Eletricista::verificarServico(Servico &servico) {
    if (servico.getTipoServico() == TipoServico::MEDICAO) {
        throw std::invalid_argument("O Funcionario nao faz esse tipo de servico.");
    }
}
