#ifndef CONFIG_H
#define CONFIG_H

#include <map>
#include <string>

// Chargement d'un fichier JSON plat : { "cle": "valeur", "port": 8080 }
class Config {
private:
    std::map<std::string, std::string> valeurs;
public:
    bool charger(const std::string& chemin);
    std::string get(const std::string& cle, const std::string& defaut = "") const;
};

#endif
