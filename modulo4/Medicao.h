#ifndef MEDICAO_H
#define MEDICAO_H

#include "Servico.h"
#include "Data.h"
#include "Fatura.h"


class Medicao : public Servico {
    public:
    Medicao();

    Medicao(const Data &inicio, const UC &uc);

    Medicao(const Data &inicio, const Data &fim, const UC &uc);

    /**
     * @brief Executa o serviço de medição de consumo. Toda vez que o serviço é executado é gerada uma nova fatura para a UC
     * na qual o serviço foi realizado.
     */
    void executar() override;
};


 

#endif