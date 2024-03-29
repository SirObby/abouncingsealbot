#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace ping_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        int ping = event.from->websocket_ping * 1000; 
        dpp::message m;
        m.set_flags(dpp::m_ephemeral);
        std::string str = "Pinged: " + std::to_string(ping) + "ms";
        m.set_content(str);

       event.reply(dpp::ir_channel_message_with_source, m);
    }
}