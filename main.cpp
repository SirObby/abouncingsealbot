// DPP Includes
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>
#include <dpp/nlohmann/json.hpp>
// Other Includes
#include <iomanip>
#include <sstream>
// Project Includes
#include "configs.hpp"
#include "cmds/bounce.hpp"
#include "cmds/eval.hpp"
#include "cmds/info.hpp"
#include "cmds/user-opt.hpp"
#include "cmds/guild-opt.hpp"

// Constants or Other Top-Level stuff
using json = nlohmann::json;

int main()
{   
    json configdocument;
    std::ifstream configfile("./config.json");
    configfile >> configdocument;

    bot.on_ready([&bot](const dpp::ready_t & event) {
        std::cout << "Logged in as " << bot.me.username << "!\n";
        bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_listening, "your commands."));

    });

    dpp::cluster bot(configdocument["token"], dpp::i_default_intents, 1);
    /* The interaction create event is fired when someone issues your commands */
    bot.on_interaction_create([&bot](const dpp::interaction_create_t & event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            checkConfigs(event);
            checkConfig(event.command.usr.id);

            if(cmd_data.name == "bounce") bounce_cmd::execute(event, cmd_data);
            if(cmd_data.name == "eval") eval_cmd::execute(event, cmd_data);
            if(cmd_data.name == "info") info_cmd::execute(event, cmd_data);
            if(cmd_data.name == "user-opt") user_opt_cmd::execute(event, cmd_data);
            if(cmd_data.name == "guild-opt") guild_opt_cmd::execute(event, cmd_data);

        }
    });

    bot.start(false);
    return 0;
}