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
#include "versions.hpp"
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

        bot.current_user_get_guilds( [ & ]( const dpp::confirmation_callback_t &callback )
        {
            const auto &guilds = std::get< dpp::guild_map >( callback.value );
            unsigned int gsize = guilds.size();
            std::printf( "> Guild Count: %u\n", gsize );
            for ( const auto &[ guild_snowflake, guild ] : guilds )
            {
                std::printf( "> Guild Name: %s\n", guild.name.c_str() );
            }

        } );

        // Creating version.

        OB::Version v;
        v.setVersion(1, 0, 1, "d");
        v.setName("The Version Update");
        v.setCommit("Unknown"); // This is updated AFTER pushed into Github.
        cout << v.getText();

    });

    bot.on_interaction_create([&bot](const dpp::interaction_create_t & event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            checkConfigs(event);
            checkConfig(std::to_string(event.command.usr.id));

            if(cmd_data.name == "bounce") bounce_cmd::execute(event, cmd_data);
            if(cmd_data.name == "info") info_cmd::execute(event, cmd_data, &bot);
            if(cmd_data.name == "ping") ping_cmd::execute(event, cmd_data);
            if(cmd_data.name == "user-config") user_conf_cmd::execute(event, cmd_data);
            if(cmd_data.name == "guild-config") guild_conf_cmd::execute(event, cmd_data);
            if(cmd_data.name == "eval") eval_cmd::execute(event, cmd_data);
        
        }
    });

    bot.on_message_create([&bot](const dpp::message_create_t & event) {
        //int integer = event.msg->member.user_id;
        checkConfig(to_string(event.msg->member.user_id));

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
    
    /*bot.on_log([](const dpp::log_t & event) {
        if (event.severity > dpp::ll_trace) {
            std::cout << event.message << "\n";
        } I decided this is unnecessary.
    });*/ 

    bot.start(false);
    return 0;
}