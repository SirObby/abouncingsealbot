#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace info_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        dpp::message m;
        m.set_flags(dpp::m_ephemeral);
        m.set_content("**A Bouncing Seal**\nCreated by `Sir Obsidian#2640`  |  Using `D++`\nInvite: https://discord.com/oauth2/authorize?client_id=880337914528145438&permissions=3197952&scope=bot%20applications.commands\nSupport Server: https://discord.gg/kYGUzJAYHX");
        event.reply(dpp::ir_channel_message_with_source, m);
    }
}