#include "Config.h"
#include <fstream>
#include <sstream>

// Lit une chaîne entre guillemets à partir de la position pos (qui pointe sur le ")
static std::string lireChaine(const std::string& s, size_t& pos) {
    std::string r;
    ++pos;                                   // saute le guillemet ouvrant
    while (pos < s.size() && s[pos] != '"') {
        if (s[pos] == '\\' && pos + 1 < s.size()) ++pos;
        r += s[pos++];
    }
    ++pos;                                   // saute le guillemet fermant
    return r;
}

bool Config::charger(const std::string& chemin) {
    std::ifstream in(chemin);
    if (!in) return false;
    std::stringstream buf;
    buf << in.rdbuf();
    std::string s = buf.str();

    valeurs.clear();
    size_t pos = 0;
    while ((pos = s.find('"', pos)) != std::string::npos) {
        std::string cle = lireChaine(s, pos);
        pos = s.find(':', pos);
        if (pos == std::string::npos) break;
        ++pos;
        while (pos < s.size() && (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t' || s[pos] == '\r')) ++pos;

        std::string val;
        if (pos < s.size() && s[pos] == '"') {
            val = lireChaine(s, pos);
        } else {                              // nombre, booléen...
            while (pos < s.size() && s[pos] != ',' && s[pos] != '}' && s[pos] != '\n') val += s[pos++];
            while (!val.empty() && val.back() == ' ') val.pop_back();
        }
        valeurs[cle] = val;
    }
    return true;
}

std::string Config::get(const std::string& cle, const std::string& defaut) const {
    auto it = valeurs.find(cle);
    return it == valeurs.end() ? defaut : it->second;
}
