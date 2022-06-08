#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <vector>
#include <map>
#include "Servico.h"
#include "Data.h"
#include <functional>
#include "Usuario.h"

class Funcionario: public Usuario {
    static int nextIdFuncionario;
    static int maxServicos;
    int idFuncionario;
    std::map<long, std::vector< std::reference_wrapper<Servico> > > servicos = {};
        
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
        void adicionarServico(Servico &servico, Data data, int prioridade_servico);        
        
        /**
         * @brief Extrai a lista de serviços que o funcionário deve executar na data atual. 
         * Formato padrão da data: yyyy-mm-dd
         */
        std::vector<std::reference_wrapper<Servico>> extrairServicos(Data data);      

        /**
         * @brief Define a quantidade máxima de serviços que um funcionário pode executar em um dia
         * @param max_servicos Quantidade máxima de serviços permitida
         */
        static void setMaxServicos(const int &ms);

        /**
         * @brief Retorna a quantidade máxima de serviços que um funcionário pode executar
         */
        static int getMaxServicos();

        /**
         * @brief Retorna o ID do Funcionário
         */
        int getIDFuncionario() const;    
        

         /**
         * @brief Retorna a agenda de serviços do funcionário. Todas as datas e serviços já agendados nessas datas.
         */
         std::map<long, std::vector<std::reference_wrapper<Servico>>> const &getServicos() const;

         /**
         * @brief Seta a agenda de serviços do funcionário com base em uma agenda já existente
         * @param servicos Agenda de serviços que será copiada
         */
         void setServicos(std::map<long, std::vector<std::reference_wrapper<Servico>>> &servicos);


        /**
         * @brief Retorna a quantidade de serviços que estão na fila do funcionário em uma dada data
         * @param data Data na qual se quer avaliar a quantidade de serviços na fila
         */
        int getQtdServicos(Data data_agenda) const;

        void executarServicos(Data data);

        /**
         * @brief Verifica o tipo de servico e joga uma exceção se o tipo de serviço não for valido para o funcionario
         * @param servico
         */
        virtual void verificarServico(Servico &servico);

        /**
         * @brief Imprime uma lista de serviços 
         * @param servicos Lista de sevicos que será impressa
         */
        static void printServicos(std::vector<std::reference_wrapper<Servico>> servicos);


        /**
         * @brief Imprime toda a agenda de serviços do funcionário          
         */
        void printAgendaServicos();
        
        bool operator==(const Funcionario& other);

        Funcionario& operator=(const Funcionario& other);
        

        /**
         * \brief Streaming operator, define como Funcionario será impresso         
         */
        friend std::ostream& operator << (std::ostream &out, const Funcionario &funcionario);

};


#endif