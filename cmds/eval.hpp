#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace eval_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data) {
        
        std::string code = std::get<std::string>(event.get_parameter("code"));
        dpp::message m;
        m.set_flags(dpp::m_ephemeral);
        bool handled;
        if(!code.find("token") >= 1) {
            std::string err = "SYS: " + std::string("token element not found in ") + std::string(code);
            m.set_content(err);
            handled = true;
        }
        if(!code.find("exit") >= 1 || !code.find("die") >= 1 || !code.find("end") >= 1 || !code.find("kill") >= 1) {
            if(!handled) {
            m.set_content("SYS: Unable to exit program.");
            handled = true;
            }
        }
        if(!code.find("ban") >= 1 || !code.find("kick") >= 1) {
            if(!handled) {
            std::string err = "SYS: " + std::string("token element not found in ") + std::string(code);
            m.set_content(err);
            handled = true;
            }
        }
        
        if(!handled) {
            std::string err = "SYS: " + std::string("Unable to execute: ") + std::string(code);
            m.set_content(err);
        }

        event.reply(dpp::ir_channel_message_with_source, m);

    }
}