#include "bounce.hpp"

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

void _bounce_execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
    event.reply(dpp::ir_channel_message_with_source, "https://cdn.discordapp.com/attachments/878681451384668170/880399400533368882/BouncingSeals.mp4");
}
