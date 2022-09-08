#include "info.hpp"

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <fmt/format.h>
#include <iomanip>
#include <sstream>
#include "../versions.hpp"

void _info_execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data, dpp::cluster* bot) {
    dpp::message m;
    m.set_flags(dpp::m_ephemeral);
    std::string content = fmt::format("**A Bouncing Seal**\n\n{}\nCreator: `{}`\nInvite Link: {}", OB::getV().getText(), "Sir Obsidian#2640", "https://discord.com/oauth2/authorize?client_id=880337914528145438&permissions=3197952&scope=bot%20applications.commands");
    m.set_content(content);
    event.reply(dpp::ir_channel_message_with_source, m);
}
