//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_UC_H
#define MODULO1_UC_H

#include "Fatura.h"
#include "Data.h"
#include "Endereco.h"
#include <vector>
#include <stdexcept>

class UC {
private:
    static int nextIdUC;
    int idUC;
    std::vector<Fatura> faturas;
    double consumoEnergiaTotal;
    double consumoEnergiaMedido;
    Endereco endereco;

public:
    UC();

    UC(const std::vector<Fatura> &faturas);

    UC(const UC& uc);

    /**
     * @brief Retorna o ID da UC.
     *
     * @return int ID da UC.
     */
    int getIdUc() const;

     /**
     * @brief Define o ID da UC.
     */
    void setIdUc(int idUc);

    /**
     * @brief Retorna a quantidade de itens do produto.
     *
     * @return int Quantidade de itens do produto.
     */
    int getQtd() const;
    
    /**
     * @brief Retorna o consumo total de energia da UC.
     *
     * @return double Quantidade total de energia já consumida pela UC.
     */
    double getConsumoEnergiaTotal() const;


     /**
     * @brief Incrementa o consumo total de energia da UC.
     * 
     * @param consumoMedido Valor do consumo medido e que será incrementado ao consumo total da UC.
     */
    void setConsumoEnergiaTotal(double consumoMedido);


    /**
     * @brief Retorna o consumo energia corrente da UC, da medição atual.
     *
     * @return double Quantidade total de energia consumida na última leitura da UC.
     */
    double getConsumoEnergiaMedido() const;

    /**
     * @brief Define o consumo de energia corrente da UC,  da medição atual.
     * 
     * @param consumoMedido Valor do consumo medido pelo Leiturista e que será incrementado ao consumo total da UC.
     */
    void setConsumoEnergiaMedido(double consumoMedido);


     /**
     * @brief Retorna um vetor de ponteiros para as faturas que a UC já possui.
     * 
     * @return std::vector<Fatura> const & Vetor com faturas pertencencentes a UC.
     */
    std::vector<Fatura> const & getFaturas() const;


     /**
     * @brief Define um conjunto de faturas para a UC.
     */
    void setFaturas(std::vector<Fatura> &faturas);

    /**
     * @brief Define o endereco da UC.
     */
    void setEndereco();

    /**
     * @brief Retorna o endereco da UC.
     * 
     * @return o parametro endereco.
     */
    Endereco getEndereco();

    /**
     * @brief Método utilizado para realizar o pagamento de uma dada fatura.
     * 
     * @param idFaturaAPagar Número de id da fatura que será paga.
     * @param dtPagamento Data de pagamento da fatura.
     * 
     * @return double valor de pagamento da fatura.
     */
    double pagar(const int &idFaturaAPagar, const Data &dtPagamento);


    /**
     * @brief Retornar um vetor com as faturas pendentes de pagamento da UC.
     * 
     * @return std::vector<Fatura> Vetor com faturas pendentes de pagamento pertencencentes a UC.
     */
    std::vector<Fatura> verificarPagamento();

    /**
     * @brief Retornar um vetor com as faturas vencidas de uma dada UC.
     * 
     * @return std::vector<Fatura> Vetor com faturas vencidas pertencencentes a UC.
     */
    std::vector<Fatura> verificarVencimento(Data &now);

    /**
     * @brief Adicona uma nova fatura a lista de faturas da UC.
     * 
     * @param fatura Fatura que será adicionada à UC.
     */
    void addFatura(Fatura &fatura);

    /**
     * @brief Método utilizado para medir o consumo atual de energia da UC. Este valor será utilizado para gerar a Fatura mensal.     
     */
    double medirEnergia();
    
    /**
     * @brief Sobrecarga do operador ==. Verifica se o id da UC atual é igual a de outra UC. Nesse caso são iguais.
     * 
     * @param UC UC quer será utilizada para comparação.
     */
    bool operator==(const UC& other);

    /**
     * @brief Sobrecarga do operador de atribuição.
     * 
     * @param UC UC que será utilizada para realizar a operação de atribuição.
     */   
    UC& operator=(const UC& other);

};
#endif //MODULO1_UC_H
