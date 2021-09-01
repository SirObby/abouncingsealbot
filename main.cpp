// DPP Includes
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>
#include <dpp/nlohmann/json.hpp>
// Other Includes
#include <iomanip>
#include <sstream>
#include <vector>
#include <iostream>
// Project Includes
#include "configs.hpp"
#include "cmds/bounce.hpp"
#include "cmds/eval.hpp"
#include "cmds/info.hpp"
#include "cmds/user-opt.hpp"
#include "cmds/guild-opt.hpp"
#include "cmds/ping.hpp"
#include "cmds/user-conf.hpp"
#include "cmds/guild-conf.hpp"

// Constants or Other Top-Level stuff
using json = nlohmann::json;

int main()
{   
    json configdocument;
    std::ifstream configfile("./config.json");
    configfile >> configdocument;

    dpp::cluster bot(configdocument["token"], dpp::i_default_intents |  dpp::i_guild_members, 1);
    
    bot.on_ready([&bot](const dpp::ready_t & event) {
        std::cout << "Logged in as " << bot.me.username << "!" << std::endl;
        bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_listening, "your commands."));

        // Create commands.
        
        bot.global_commands_get(dpp::command_completion_event_t callback) {
            
        }
        //bot.global_command_delete()

    });

    bot.on_interaction_create([&bot](const dpp::interaction_create_t & event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            checkConfigs(event);
            checkConfig(event.command.usr.id);

            if(cmd_data.name == "bounce") bounce_cmd::execute(event, cmd_data);
            if(cmd_data.name == "info") info_cmd::execute(event, cmd_data);
            if(cmd_data.name == "user-opt") user_opt_cmd::execute(event, cmd_data);
            if(cmd_data.name == "guild-opt") guild_opt_cmd::execute(event, cmd_data);
            if(cmd_data.name == "ping") ping_cmd::execute(event, cmd_data);
            if(cmd_data.name == "user-config") user_conf_cmd::execute(event, cmd_data);
            if(cmd_data.name == "guild-config") guild_conf_cmd::execute(event, cmd_data);
            
            // Guild Specific / User Specific Commands
            if(cmd_data.name == "eval") if(eval_cmd::execute(event, cmd_data)) {
                std::string code = std::get<std::string>(event.get_parameter("code"));
                dpp::message m;
                m.set_flags(dpp::m_ephemeral);
                m.set_content("Command has been evaluated!");
                event.reply(dpp::ir_channel_message_with_source, m);
                bot.message_create(dpp::message(event.command.channel_id, fmt::format("{}", code)));
            } // Sorry about messy code for some reason Idk how to pass bot into eval. 
        }
    });

    bot.start(false);
    return 0;
}