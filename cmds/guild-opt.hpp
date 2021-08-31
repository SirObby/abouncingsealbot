#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace guild_opt_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        event.reply(dpp::ir_deferred_channel_message_with_source, "Checking settings please wait.");
        std::string id = std::to_string(event.command.guild_id);
        dpp::channel* ch = dpp::find_channel(event.command.channel_id);
        if(ch && (ch->get_user_permissions(&event.command.usr) & dpp::p_administrator)) {           
        

        nlohmann::json configdocument;
        std::ifstream configfile(fmt::format("./configs/{}.json", id));
        configfile >> configdocument;

        std::cout << configdocument["enabled"];

        if(configdocument["enabled"] == false) {
            configdocument["enabled"] = true;
            std::ofstream o(fmt::format("./configs/{}.json", id));
	        o << std::setw(4) << configdocument << std::endl;
            o.close();
            event.edit_response("Set `LEVELING/enabled` to `true`");
        } else {
            configdocument["enabled"] = false;
            std::ofstream o(fmt::format("./configs/{}.json", id));
	        o << std::setw(4) << configdocument << std::endl;
            o.close();
            event.edit_response("Set `LEVELING/enabled` to `false`");
        }

        } else {
            event.edit_response("You require `ADMINISTRATOR` to change this setting.");
        }

    }
}