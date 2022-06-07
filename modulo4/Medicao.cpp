#include "Medicao.h"

Medicao::Medicao() : Servico(TipoServico::MEDICAO) {}

Medicao::Medicao(const Data &inicio, const UC &uc) : Servico(TipoServico::MEDICAO, inicio, uc) {}

Medicao::Medicao(const Data &inicio, const Data &fim, const UC &uc) : Servico(TipoServico::MEDICAO,
                                                                                                       inicio, fim,
                                                                                                       uc) {}

void Medicao::executar() {
    // Verificando última fatura da UC
    double consumoHistorico_inicial = this->getUC().getConsumoEnergiaTotal();
    double consumoHistorico_final = this->getUC().medirEnergia();
    double consumoAtualFatura = consumoHistorico_final - consumoHistorico_inicial;
    
    Data data;        
    Data dt_emissao = data.dateNow();

    // todo tem que criar um método na classe Data para adicionar um número de dias a uma data e ter de retorno a nova data
    Data dt_vencimento(data.dateNow());
    Data dt_Emissao(data.dateNow());

    Fatura fatura;
    fatura.setDtEmissao(dt_Emissao);
    fatura.setConsumoEnergia(consumoAtualFatura);
    fatura.setValorInicial(consumoAtualFatura*Fatura::PRECO_ENERGIA);
    Servico::getUC().addFatura(fatura);
}


