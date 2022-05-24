#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <vector>
#include <map>
#include "Servico.h"

class Funcionario {
    private:    
        static int nextIdFuncionario;
        static int maxServicos;        
        int idFuncionario;
        std::string nome;
        std::map<std::string, std::vector<Servico>> servicos = {};
        
    public:
        /**
         * @brief Construtor padrao da clasee
         */
        Funcionario();
        
        /**
         * @brief Construtor padrao que inicializa a variável nome.
         *
         * @param nome Nome do funcionário
         */
        Funcionario(const std::string &nome);

        /**
         * @brief Construtor padrao que inicializa as variáveis nome e maxServicos.
         *
         * @param nome Nome do funcionário
         * @param maxServicos Quantidade máxima de serviços que o funcionário pode executar por dia
         */
        Funcionario(const std::string &nome, int maxServicos);

         /**
         * @brief Construtor padrao que inicializa o objeto a partir de outro objeto da mesma classe já existente.
         *
         * @param funcionario Funcionário         
         */
        Funcionario(const Funcionario& funcionario);

        /**
         * @brief Adiciona um Servico a lista de servicos que o funcionário deve executar em 
         * uma determinada data. O serviço é adicionado à fila de acordo com a prioridade de execução informada.
         * @param servico Servico que deverá ser executado.
         * @param data Data na qual o serviço será executado, formato yyyy-mm-dd
         * @param prioridade_servico Prioridade de execução do serviço. Prioridade máxima para 0.
         */
        void adicionarServico(Servico &servico, std::string data, int prioridade_servico);        
        
        /**
         * @brief Extrai a lista de serviços que o funcionário deve executar na data atual. 
         * Formato padrão da data: yyyy-mm-dd
         */
        std::vector<Servico> &extrairServicos();
        

        /**
         * @brief Seta um nome para o funcionario
         * @param nome Nome do funcionário
         */
        void setNome(std::string nome);

        /**
         * @brief Retorna o nome do funcionário
         */
        std::string getNome() const;        

        /**
         * @brief Define a quantidade máxima de serviços que um funcionário pode executar em um dia
         * @param max_servicos Quantidade máxima de serviços permitida
         */
        void setMaxServicos(int max_servicos);

        /**
         * @brief Retorna a quantidade máxima de serviços que um funcionário pode executar
         */
        int getMaxServicos() const;

        /**
         * @brief Retorna o ID do Funcionário
         */
        int getIDFuncionario() const;    
        

         /**
         * @brief Retorna a agenda de serviços do funcionário. Todas as datas e serviços já agendados nessas datas.
         */
        std::map<std::string, std::vector<Servico>> const &getServicos() const;

         /**
         * @brief Seta a agenda de serviços do funcionário com base em uma agenda já existente
         * @param servicos Agenda de serviços que será copiada
         */
        void setServicos(std::map<std::string, std::vector<Servico>> &servicos);        


        /**
         * @brief Retorna a quantidade de serviços que estão na fila do funcionário em uma dada data
         * @param data Data na qual se quer avaliar a quantidade de serviços na fila
         */
        int getQtdServicos(const std::string data_agenda) const;        


        /**
         * @brief Imprime uma lista de serviços 
         * @param servicos Lista de sevicos que será impressa
         */
        static void printServicos(std::vector<Servico> servicos);


        /**
         * @brief Imprime toda a agenda de serviços do funcionário          
         */
        void printAgendaServicos();     
        

        /**
         * \brief Streaming operator, define como Funcionario será impresso         
         */
        friend std::ostream& operator << (std::ostream &out, const Funcionario &funcionario);


};


#endif