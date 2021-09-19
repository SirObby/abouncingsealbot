#include "commandhandler.hpp"
#include <dpp/dpp.h>
#include <vector>

std::vector<dpp::slashcommand> getMissingCommands(dpp::slashcommand_map map)
{

    std::vector<dpp::slashcommand> cmds;
    std::vector<dpp::slashcommand> missingcmds;

    dpp::slashcommand bouncecmd;
    bouncecmd.set_name("bounce")
        .set_description("Do you want to see Seals Bouncing?");

    dpp::slashcommand infocmd;
    infocmd.set_name("info")
        .set_description("Information about this bot.");

    dpp::slashcommand evalcmd;
    evalcmd.set_name("eval")
        .set_description("Evaluate code from within the bot.")
        //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
        .add_option(dpp::command_option(dpp::co_string, "code", "The code to evaluate.", true));

    dpp::slashcommand pingcmd;
    pingcmd.set_name("ping")
        .set_description("Check the bot's latency.");

    dpp::slashcommand guildconfcmd;
    guildconfcmd.set_name("guild-config")
        .set_description("Change the guild config.")
        .add_option(
            dpp::command_option(dpp::co_string, "setting", "The setting to change.", true).add_choice(dpp::command_option_choice("leveling", std::string("leveling"))))
        .add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true));

    dpp::slashcommand userconfcmd;
    userconfcmd.set_name("user-config")
        .set_description("Change the user config.")
        .add_option(
            dpp::command_option(dpp::co_string, "setting", "The setting to change.", true).add_choice(dpp::command_option_choice("leveling", std::string("leveling"))))
        .add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true));

    dpp::slashcommand levelingcmd;

    levelingcmd.set_name("leveling")
        .set_description("Commands related to A Bouncing Seal's leveling.")
        .add_option(
            dpp::command_option(dpp::co_string, "action", "What do you want to do leveling-wise?", true)
                .add_choice(dpp::command_option_choice("rank", std::string("rank")))
                .add_choice(dpp::command_option_choice("leaderboard", std::string("leaderboard"))));

    cmds.push_back(bouncecmd);
    cmds.push_back(infocmd);
    cmds.push_back(evalcmd);
    cmds.push_back(pingcmd);
    cmds.push_back(guildconfcmd);
    cmds.push_back(userconfcmd);
    cmds.push_back(levelingcmd);

    int mi = 0;
    for (const auto &[slashcommand_snowflake, command] : map)
    {
        mi++;
        bool found = false;
        for (size_t i = 0; i < cmds.size(); i++)
        {
            if(command.name == cmds[i].name) {
                found = true;
            }
        }
        
        if(!found) {
            missingcmds.push_back(cmds[mi]);
        }
    }

    return missingcmds;

}