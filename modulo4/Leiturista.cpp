//
// Created by Thales Nunes on 02/06/2022.
//

#include "Leiturista.h"

void verificarServico(Servico& servico) {
    if (servico.getTipoServico() != TipoServico::MEDICAO)
        throw std::invalid_argument("O Funcionario nao esta apto para este tipo de servico.");
}
