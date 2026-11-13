#ifndef LOGGER_H
#define LOGGER_H

#include <string>

// Singleton : écrit les messages dans la console et dans un fichier journal
class Logger {
private:
    std::string fichier;
    Logger();
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();
    void setFichier(const std::string& chemin);
    void log(const std::string& message) const;
};

#endif
