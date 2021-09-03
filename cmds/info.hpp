#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

namespace info_cmd
{
    void execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data, dpp::cluster* bot) {
        unsigned int gsize = 0;
                bot->current_user_get_guilds( [ & ]( const dpp::confirmation_callback_t &callback )
        {
            const auto &guilds = std::get< dpp::guild_map >( callback.value );
            gsize = guilds.size();

        } );
        
        dpp::message m;
        m.set_flags(dpp::m_ephemeral);
        std::string content = fmt::format("**A Bouncing Seal**\nCreated by `Sir Obsidian#2640`  |  Using `D++`\nInvite: https://discord.com/oauth2/authorize?client_id=880337914528145438&permissions=3197952&scope=bot%20applications.commands\nSupport Server: https://discord.gg/kYGUzJAYHX\nGuilds: {}", gsize);
        m.set_content(content);
        event.reply(dpp::ir_channel_message_with_source, m);
    }
}