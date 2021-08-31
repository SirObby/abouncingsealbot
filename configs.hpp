#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

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

    void checkConfig(const long unsigned int id2) {
        std::string id = std::to_string(id2);

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

    }
