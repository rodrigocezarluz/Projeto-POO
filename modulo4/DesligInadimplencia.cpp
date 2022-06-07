#include "DesligInadimplencia.h"

DesligInadimplencia::DesligInadimplencia() : Servico(TipoServico::INADIMPLENCIA) {}

DesligInadimplencia::DesligInadimplencia(const Data &inicio, const UC &uc) : Servico(
        TipoServico::INADIMPLENCIA, inicio, uc) {}
