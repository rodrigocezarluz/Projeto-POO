#include "Medicao.h"
#include "Fatura.h"



Medicao::Medicao() : Servico(){}

void Medicao::executar(){
    // Verificando última fatura da UC
    double consumoHistorico_inicial = this->getUC().getConsumoEnergiaTotal();
    double consumoHistorico_final = this->getUC().medirEnergia();
    double consumoAtualFatura = consumoHistorico_final - consumoHistorico_inicial;
    
    Data data;        
    Data dt_emissao = data.dateNow();

    // todo tem que criar um método na classe Data para adicionar um número de dias a uma data e ter de retorno a nova data
    Data dt_vencimento(data.dateNow());

    Fatura fatura;
    fatura.setConsumoEnergia(consumoAtualFatura);
    fatura.setValorInicial(consumoAtualFatura*Fatura::PRECO_ENERGIA);
    this->getUC().addFatura(fatura);


}