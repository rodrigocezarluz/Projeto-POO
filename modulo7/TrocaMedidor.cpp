#include "TrocaMedidor.h"

TrocaMedidor::TrocaMedidor() : Servico(TipoServico::TROCA_MEDIDOR) {}

TrocaMedidor::TrocaMedidor(const Data &inicio, const Data &fim, const UC &uc) : Servico(
        TipoServico::TROCA_MEDIDOR, inicio, fim, uc) {}

TrocaMedidor::TrocaMedidor(const Data &inicio, const UC &uc) : Servico(TipoServico::TROCA_MEDIDOR, inicio,
                                                                                                uc) {}
