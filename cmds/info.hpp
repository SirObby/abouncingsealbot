#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace info_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        event.reply(dpp::ir_channel_message_with_source, "https://www.youtube.com/watch?v=xDg_T0WLolQ");

        
    }
}