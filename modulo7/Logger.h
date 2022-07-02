//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_LOGGER_H
#define MODULO7_LOGGER_H


#include <vector>
#include "Log.h"

class Logger {
    static std::vector<std::reference_wrapper<Log>> logs;
    Logger() = delete;

public:
    static vector<std::reference_wrapper<Log>> getLogs();

    static void addLog(Log log);

    static vector<std::reference_wrapper<Log>> getLogsPorUsuario(Usuario usuario);

    static vector<std::reference_wrapper<Log>> getLogsPorData(Data data);
};


#endif //MODULO7_LOGGER_H
