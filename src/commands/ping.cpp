#include "ping.h"

#include <dpp/dpp.h>

void ping_command(const dpp::slashcommand_t &event, dpp::cluster *bot) {
	int pong = ( event.from->websocket_ping + bot->rest_ping ) * 1000;
    dpp::message m;
    m.set_flags(dpp::m_ephemeral);
    std::string str = "Pinged: " + std::to_string(pong) + "ms";
    m.set_content(str);

    event.reply(dpp::ir_channel_message_with_source, m);
};
