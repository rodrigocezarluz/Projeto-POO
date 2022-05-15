cmake_minimum_required(VERSION 3.22)
project(modulo1)

set(CMAKE_CXX_STANDARD 23)

add_executable(modulo1 main.cpp Cliente.h Cliente.cpp PessoaFisica.cpp PessoaFisica.h Pessoajuridica.h PessoaJuridica.cpp UC.cpp UC.h Fatura.cpp Fatura.h Financeiro.cpp Financeiro.h UCResidencial.cpp UCResidencial.h UCIndustrial.cpp UCIndustrial.h UCComercial.cpp UCComercial.h UCIluminacaoPublica.cpp UCIluminacaoPublica.h)
