// DPP Includes
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>
#include <dpp/nlohmann/json.hpp>
// Other Includes
#include <iomanip>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
// Project Includes
#include "configs.hpp"
#include "cmds/bounce.hpp"
#include "cmds/eval.hpp"
#include "cmds/info.hpp"
#include "cmds/ping.hpp"
#include "cmds/user-conf.hpp"
#include "cmds/guild-conf.hpp"

// Constants or Other Top-Level stuff
using json = nlohmann::json;
using namespace std;

void print_map( const dpp::slashcommand_map &m )
{
    for ( const auto &[ key, value ] : m )
    {
        std::cout << key << " = " << value.name.c_str() << "; ";
        std::cout << "\n";
    }
    //std::cout << "\n";
}
/*
@brief sus
*/
int main()
{   
    json configdocument;
    std::ifstream configfile("./config.json");
    configfile >> configdocument;
    configfile.close();

    dpp::cluster bot(configdocument["token"], dpp::i_default_intents |  dpp::i_guild_members, 1);
    
    bot.on_ready([&bot](const dpp::ready_t & event) {
        std::cout << "Logged in as " << bot.me.username << "!" << std::endl;
        bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_listening, "your commands."));

        // Create commands.   

        // Deleting commands.

        bot.global_commands_get( [ & ]( const dpp::confirmation_callback_t &callback )
                             { print_map( std::get< dpp::slashcommand_map >( callback.value ) ); if(callback.is_error()) std::cout << "sus";} );
        //bot.global_command_delete(880738145849712680);
    });

    bot.on_interaction_create([&bot](const dpp::interaction_create_t & event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            checkConfigs(event);
            checkConfig(event.command.usr.id);

            if(cmd_data.name == "bounce") bounce_cmd::execute(event, cmd_data);
            if(cmd_data.name == "info") info_cmd::execute(event, cmd_data);
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

    bot.on_message_create([&bot](const dpp::message_create_t & event) {
    
        checkConfig(event.command.usr.id);

        std::string id = std::to_string(event.msg->guild_id);  
        std::string id2 = std::to_string(event.msg->member.user_id);

        if(getConf(id)["leveling"]["enabled"] && getConf(id2)["leveling"]["enabled"]) {
            json z = getConf(id2);
            int zint = z["leveling"]["xp"];
            int vint = z["leveling"]["level"];
            z["leveling"]["xp"] = zint + 1;
            int v = z["leveling"]["level"];
            int u = z["leveling"]["xp"];
            int w = v * 15;
            if(zint > w) {
                z["leveling"]["level"] = vint + 1;
                z["leveling"]["xp"] = 0;
            }

            std::ofstream o(fmt::format("./configs/{}.json", id2));
	        o << std::setw(4) << z << std::endl;
            o.close();

        }

    });
    
    bot.on_log([](const dpp::log_t & event) {
        if (event.severity > dpp::ll_trace) {
            std::cout << event.message << "\n";
        }
    });

    bot.start(false);
    return 0;
}