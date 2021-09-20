#include "ping.hpp"

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

void _ping_execute(const dpp::interaction_create_t &event, dpp::command_interaction cmd_data, dpp::cluster* bot)
{
    double ping = event.from->websocket_ping;
    double pong = ping + bot->rest_ping;
    dpp::message m;
    m.set_flags(dpp::m_ephemeral);
    std::string str = "Pinged: " + std::to_string(pong) + "s";
    m.set_content(str);

    event.reply(dpp::ir_channel_message_with_source, m);
}