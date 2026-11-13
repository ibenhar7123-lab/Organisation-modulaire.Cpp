#include <iostream>
#include "Logger.h"
#include "Config.h"

int main() {
    Logger::getInstance().log("Demarrage du programme");

    Config cfg;
    if (!cfg.charger("config.json")) {
        Logger::getInstance().log("Impossible de lire config.json");
        return 1;
    }
    std::cout << "app  = " << cfg.get("app") << std::endl;
    std::cout << "port = " << cfg.get("port") << std::endl;
    std::cout << "xxx  = " << cfg.get("xxx", "(valeur par defaut)") << std::endl;

    Logger::getInstance().log("Fin du programme, port lu = " + cfg.get("port"));
    return 0;
}
