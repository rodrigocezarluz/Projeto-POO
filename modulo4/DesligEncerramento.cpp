#include "DesligEncerramento.h"

DesligEncerramento::DesligEncerramento() : Servico(TipoServico::ENCERRAMENTO) {}

DesligEncerramento::DesligEncerramento(const Data &inicio, const Data &fim, const UC &uc)
        : Servico(TipoServico::ENCERRAMENTO, inicio, fim, uc) {}

DesligEncerramento::DesligEncerramento(const Data &inicio, const UC &uc) : Servico(TipoServico::ENCERRAMENTO,
                                                                                                            inicio,
                                                                                                            uc) {}
