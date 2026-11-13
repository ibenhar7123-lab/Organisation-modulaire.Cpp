#include "Logger.h"
#include <ctime>
#include <fstream>
#include <iostream>

Logger::Logger() : fichier("journal.log") {}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::setFichier(const std::string& chemin) { fichier = chemin; }

void Logger::log(const std::string& message) const {
    std::time_t t = std::time(nullptr);
    char horo[32];
    std::strftime(horo, sizeof horo, "%Y-%m-%d %H:%M:%S", std::localtime(&t));

    std::string ligne = std::string("[") + horo + "] " + message;
    std::cout << ligne << std::endl;
    std::ofstream out(fichier, std::ios::app);
    if (out) out << ligne << '\n';
}
