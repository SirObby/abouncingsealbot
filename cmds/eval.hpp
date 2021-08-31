#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace eval_cmd
{
    bool execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
                if(event.command.usr.id == 571362310778781697) {
                    return true;
                } else {
                    return false;
                }
    }
}