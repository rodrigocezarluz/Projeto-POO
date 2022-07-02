#include "LigacaoNova.h"

LigacaoNova::LigacaoNova() : Servico(TipoServico::LIGACAO_NOVA) {
}

LigacaoNova::LigacaoNova(const Data &inicio, const Data &fim, const UC &uc) : Servico(
        TipoServico::LIGACAO_NOVA, inicio, fim, uc) {

}

LigacaoNova::LigacaoNova(const Data &inicio, const UC &uc) : Servico(TipoServico::LIGACAO_NOVA, inicio,
                                                                                              uc) {}
