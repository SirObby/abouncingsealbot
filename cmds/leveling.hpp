#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>
#include "../configs.hpp"

std::string generate_progress_bar(const double perc, const size_t siz)
{
    std::string result(siz, '_');
    for(size_t p = 0; p < siz && p < (perc * siz); p++)
        result[p] = ':';
    return result;
}

namespace leveling_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {

        std::string setting = std::get<std::string>(event.get_parameter("action"));

        if(setting == "rank") {
        std::string id = std::to_string(event.command.usr.id);
        nlohmann::json j = getConf(id);
        if(getConf(id)["leveling"]["enabled"]) {
            std::string x = "";
            int y = getConf(id)["leveling"]["xp"];
            int z = getConf(id)["leveling"]["level"];
            
            for (size_t i = 0; i < 15; i++)
            {
                int it = i;
                if(((15 * z) / 15 * it) <= y) {
                    x += "-";
                } else {
                    x += "_";
                }
            }
            
            std::string c = fmt::format("`{}`\nXP: `{}` Level: `{}`", x, y, z);
            dpp::message m;
            m.set_flags(dpp::m_ephemeral);
            m.set_content(c);
            event.reply(dpp::ir_channel_message_with_source, m);
        
        } else {

            dpp::message m;
            m.set_flags(dpp::m_ephemeral);
            m.set_content("`LEVELING/Enabled` is set to `false`");
            event.reply(dpp::ir_channel_message_with_source, m);

        }

        }

        if(setting == "leaderboard") {

            dpp::message m;
            m.set_flags(dpp::m_ephemeral);
            m.set_content("BOI, if you wanted a leaderboard for my leveling system you should've used MEE6.");
            event.reply(dpp::ir_channel_message_with_source, m);

        }
    }
}