// Regular Imports
#include <iostream> 

#include "handler.h" // IMPORT YOSELF

// Commands.
#include "info.h"
#include "bounce.h"
#include "eval.h"

using namespace std; 

namespace commands
{
    void loadCommands() {
        std::cout << "SUS";
    }

    void execute(const dpp::interaction_create_t& event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);

            if(cmd_data.name == "info") {
                execute_info_cmd(event, cmd_data);
            }

        }
    }
}