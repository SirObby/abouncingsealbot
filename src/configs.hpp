#pragma once
#if !defined(CONFIGS_HPP)
#define CONFIGS_HPP

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <dpp/fmt/format.h>
#include <iomanip>
#include <sstream>
#include <filesystem>
namespace fs = std::filesystem;

namespace OB_CONF {

    void checkConfigs(const dpp::interaction_create_t& event) {
        std::ifstream f;
        f.open(fmt::format("./configs/{}.json", event.command.guild_id));
    
        if(!f.good()) {

            std::string str = "{ \"leveling\": { \"enabled\": false } }";

            std::ofstream configfile;
            configfile.open(fmt::format("./configs/{}.json", event.command.guild_id));
            configfile << str;
            configfile.close();
        }
        f.close();
    }

    void checkConfig(std::string id) {

        std::ifstream f;
        f.open(fmt::format("./configs/{}.json", id));
    
        if(!f.good()) {

            std::string str = "{ \"leveling\": { \"enabled\": false, \"xp\": 0, \"level\": 0 } }";

            std::ofstream configfile;
            configfile.open(fmt::format("./configs/{}.json", id));
            configfile << str;
            configfile.close();

        }
        f.close();

        std::string path = "./configs/";
        for (const auto & entry : fs::directory_iterator(path)) {
        //std::cout << entry.path() << std::endl;
        if(entry.is_regular_file()) {
            std::string s = entry.path().string();
            s = s.substr(10);
            if(s != "placeholder.txt") {
                if(s.length() == 20) { // For some odd reason when using C++20 This has to be 19.
                    const char* fileC = entry.path().c_str();
                    std::remove(fileC);
                }  
            }
        }

        }

    }

    nlohmann::json getConf(std::string id) {

        nlohmann::json x;
        std::ifstream y(fmt::format("./configs/{}.json", id));
        y >> x;
        y.close();
        
        return x;
    }
}

#endif // MACRO