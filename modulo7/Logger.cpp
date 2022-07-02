//
// Created by Thales Nunes on 02/07/2022.
//

#include "Logger.h"

vector<std::reference_wrapper<Log>> MakeVector()
{
    vector<std::reference_wrapper<Log>> v;

    return v;
}

vector<std::reference_wrapper<Log>> Logger::logs = MakeVector();


vector<std::reference_wrapper<Log>> Logger::getLogs() {
    return Logger::logs;
}

void Logger::addLog(Log log) {
    Logger::logs.emplace_back(log);
}

vector<std::reference_wrapper<Log>> Logger::getLogsPorData(Data data) {
    vector<std::reference_wrapper<Log>> logsResult;

    vector<std::reference_wrapper<Log>> logsToFilter = Logger::logs;

    std::copy_if (logsToFilter.begin(), logsToFilter.end(), std::back_inserter(logsResult), [&data](std::reference_wrapper<Log> log) {
        return data == log.get().getData();
    });

    return logsResult;
}

vector<std::reference_wrapper<Log>> Logger::getLogsPorUsuario(Usuario usuario) {
    vector<std::reference_wrapper<Log>> logsResult;

    vector<std::reference_wrapper<Log>> logsToFilter = Logger::logs;

    std::copy_if (logsToFilter.begin(), logsToFilter.end(), std::back_inserter(logsResult), [&usuario](std::reference_wrapper<Log> log) {
        return log.get().getUsuario().getIdUsuario() == usuario.getIdUsuario();
    });

    return logsResult;
}
