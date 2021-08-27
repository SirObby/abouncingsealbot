#include <iostream>           
#include <dpp/dpp.h>                         

#include "handler.h"

    void execute_info_cmd(const dpp::interaction_create_t& event, dpp::command_interaction cmd_data) {
        event.reply(dpp::ir_channel_message_with_source, "https://www.youtube.com/watch?v=xDg_T0WLolQ");
    }

