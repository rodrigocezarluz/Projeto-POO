#ifndef MEDICAO_H
#define MEDICAO_H

#include "Servico.h"
#include "Data.h"


class Medicao : public Servico {
    //using Servico::Servico;



    public:
        Medicao();

        /**
         * @brief Executa o serviço de medição de consumo. Toda vez que o serviço é executado é gerada uma nova fatura para a UC
         * na qual o serviço foi realizado.
         */
        void executar() override;



};


 

#endif