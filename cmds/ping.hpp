#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace ping_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        int ping = rand() % 360 + 40; // Random numer from 40 to 144 

        event.reply(dpp::ir_channel_message_with_source, fmt::format("Pinged: {}ms", ping));
    }
}