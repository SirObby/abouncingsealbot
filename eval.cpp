#include <iostream>           
#include <dpp/dpp.h>                         

#include "handler.h"

    void execute_eval_cmd(const dpp::interaction_create_t& event, dpp::command_interaction cmd_data) {
        event.reply(dpp::ir_deferred_channel_message_with_source, "Checking permissions.");
                if(event.command.usr.id == 571362310778781697) {
                    event.edit_response("Evaluating...");
                }
    }

