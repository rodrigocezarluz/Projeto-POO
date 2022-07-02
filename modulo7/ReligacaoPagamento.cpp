#include "ReligacaoPagamento.h"

ReligacaoPagamento::ReligacaoPagamento() : Servico(TipoServico::RELIGACAO_POR_PAGAMENTO) {}

ReligacaoPagamento::ReligacaoPagamento(const Data &inicio, const Data &fim, const UC &uc)
        : Servico(TipoServico::RELIGACAO_POR_PAGAMENTO, inicio, fim, uc) {}

ReligacaoPagamento::ReligacaoPagamento(const Data &inicio, const UC &uc) : Servico(TipoServico::RELIGACAO_POR_PAGAMENTO,
                                                                                                            inicio,
                                                                                                            uc) {}
