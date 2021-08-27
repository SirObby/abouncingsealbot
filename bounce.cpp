#include <iostream>           
#include <dpp/dpp.h>                         

#include "handler.h"

    void execute_bounce_cmd(const dpp::interaction_create_t& event, dpp::command_interaction cmd_data) {
        event.reply(dpp::ir_channel_message_with_source, "https://cdn.discordapp.com/attachments/878681451384668170/880399400533368882/BouncingSeals.mp4");
    }

