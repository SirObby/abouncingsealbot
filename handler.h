#ifndef HANDLER_F
#define HANDLER_F

#include <vector>
#include <dpp/dpp.h>

namespace commands
{
    void loadCommands();
    enum cmds {
        INFO
    };

    void execute(const dpp::interaction_create_t& event);
}
#endif