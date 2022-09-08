#include "user-conf.hpp"

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <fmt/format.h>
#include <iomanip>
#include <sstream>

void _user_conf_execute(const dpp::interaction_create_t &event, dpp::command_interaction cmd_data)
{

    std::string setting = std::get<std::string>(event.get_parameter("setting"));
    bool value = std::get<bool>(event.get_parameter("value"));

    if (setting == "leveling")
    {

        //std::cout << setting << std::endl;

        std::string id = std::to_string(event.command.usr.id);

        nlohmann::json configdocument;
        std::ifstream configfile(fmt::format("./configs/{}.json", id));
        configfile >> configdocument;

        //std::cout << configdocument["enabled"];

        configdocument["leveling"]["enabled"] = value;
        std::ofstream o(fmt::format("./configs/{}.json", id));
        o << std::setw(4) << configdocument << std::endl;
        o.close();
        dpp::message m;
        m.set_flags(dpp::m_ephemeral);
        std::string valuestr;
        if (value == 0)
        {
            valuestr = "false";
        }
        else
        {
            valuestr = "true";
        }
        std::string c = "Set `LEVELING/enabled` to `" + valuestr + "` (USER)";
        m.set_content(c);
        event.reply(dpp::ir_channel_message_with_source, m);
    }
}
