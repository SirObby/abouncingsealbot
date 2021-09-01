#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace guild_opt_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        //event.reply(dpp::ir_deferred_channel_message_with_source, "Checking settings please wait.");
        std::string id = std::to_string(event.command.guild_id);
        dpp::channel* ch = dpp::find_channel(event.command.channel_id);
        //std::cout << std::to_string(ch->get_user_permissions(&event.command.usr)) << std::endl;
        if(ch && (ch->get_user_permissions(&event.command.usr) & dpp::p_administrator)) {           

        nlohmann::json configdocument;
        std::ifstream configfile(fmt::format("./configs/{}.json", id));
        configfile >> configdocument;

        //std::cout << configdocument["enabled"];

        if(configdocument["enabled"] == false) {
            configdocument["enabled"] = true;
            std::ofstream o(fmt::format("./configs/{}.json", id));
	        o << std::setw(4) << configdocument << std::endl;
            o.close();
            dpp::message m;
            m.set_flags(dpp::m_ephemeral);
            m.set_content("Set `LEVELING/enabled` to `true`");
            event.reply(dpp::ir_channel_message_with_source, m);
        } else {
            configdocument["enabled"] = false;
            std::ofstream o(fmt::format("./configs/{}.json", id));
	        o << std::setw(4) << configdocument << std::endl;
            o.close();
            dpp::message m;
            m.set_flags(dpp::m_ephemeral);
            m.set_content("Set `LEVELING/enabled` to `false`");
            event.reply(dpp::ir_channel_message_with_source, m);
        }

        } else {
            dpp::message m;
            m.set_flags(dpp::m_ephemeral);
            m.set_content("You require `ADMINISTRATOR` to change this setting.");
            event.reply(dpp::ir_channel_message_with_source, m);
        }

    }
}