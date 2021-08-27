#include <dpp/dpp.h>
#include <iostream>
#include <dpp/fmt/format.h>
#include <string>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

// Self-Imports
#include "handler.h"

using namespace std;
using json = nlohmann::json;

vector<string> split(string x, string y) {
    int z = x.size();
    string s;
    vector<string> u;
    int t = 0;
    for (size_t i = 0; i < z; i++)
    {
        char w = x[i];
        char v = y[0];
        if(w == v) {    
            u.push_back(s);
            t++;
            s = "";
        } else {
            s += w;
        }
    }
    return u;
}

json cache;

void save() {

    ofstream o("./data.json");
	o << std::setw(4) << cache << std::endl;
    
    
}

int main()
{
    ifstream in("./config.json");
    json config;
	in >> config;

    dpp::cluster bot(config["token"]);
    
    bot.on_ready([&bot](const dpp::ready_t& event) {
        std::cout << "Logged in as " << bot.me.username << "!\n";
        bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_listening, "your commands."));

        // Loading Commands.
        commands::loadCommands();

        ifstream in("./data.json");
		in >> cache;
        dpp::slashcommand bouncecmd;
        bouncecmd.set_name("bounce")
            .set_description("Do you want to see Seals Bouncing?")
            .set_application_id(bot.me.id);
        //bot.global_command_create(bouncecmd);

        dpp::slashcommand infocmd;
        infocmd.set_name("info")
            .set_description("Information about this bot.")
            .set_application_id(bot.me.id);
        //bot.global_command_create(infocmd);
        
        dpp::slashcommand evalcmd;
        evalcmd.set_name("eval")
            .set_description("Information about this bot.")
            .set_application_id(bot.me.id)
            //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
            .add_option(dpp::command_option(dpp::co_string, "code", "The code to evaluate. (Sir Obsidian#2640 only)", false)
                );
        //bot.global_command_create(evalcmd);

    dpp::slashcommand goptcmd;
        goptcmd.set_name("guild-opt")
            .set_description("Choose whether to opt-in/out your guild for leveling.")
            .set_application_id(bot.me.id)
            //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
            //.add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true)))
                ;
        //bot.global_command_create(goptcmd);

        dpp::slashcommand uoptcmd;
        uoptcmd.set_name("user-opt")
            .set_description("Choose whether to opt-in/out for leveling.")
            .set_application_id(bot.me.id)
            //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
            //.add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true)
                ;
        //bot.global_command_create(uoptcmd);

        });
    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        /*if (event.msg->content == "!ping") {
            bot.message_create(dpp::message(event.msg->channel_id, "Pong!"));
        }*/
        });

    /* The interaction create event is fired when someone issues your commands */
    bot.on_interaction_create([&bot](const dpp::interaction_create_t& event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);

            commands::execute(event);

            if(cmd_data.name == "guild-opt") {
                //string guid = ;
                event.reply(dpp::ir_deferred_channel_message_with_source, "Checking permissions and opt-ability.");
                dpp::channel* ch = dpp::find_channel(event.command.channel_id);
                if(cache["guilds"][to_string(event.command.guild_id)] != false && cache["guilds"][to_string(event.command.guild_id)] != true) {
                        //string e = "`ERROR` Item `GUILDS/" + event.command.guild_id + *"` is `NULL`.";
                        json sus = {
                            event.command.guild_id, true
                        };
                        cache["guilds"].insert(sus.begin(), sus.end());
                        save();
                        if(cache["guilds"][to_string(event.command.guild_id)] == NULL) {
                            cache["guilds"][to_string(event.command.guild_id)] = true;
                            save();
                        }
                    }
                if(ch && (ch->get_user_permissions(&event.command.usr) & dpp::p_manage_messages) || ch && (ch->get_user_permissions(&event.command.usr) & dpp::p_administrator)) {           
                    if(cache["guilds"][to_string(event.command.guild_id)] == NULL) {
                            cache["guilds"][to_string(event.command.guild_id)] = true;
                            save();
                        }
                    
                    
                    /*if(cache["guilds"][to_string(event.command.guild_id)] == NULL) {
                        string e = "`ERROR` Item `GUILDS/" + event.command.guild_id + *"` is `NULL`.";
                        json sus = {
                            event.command.guild_id, true
                        };
                        cache["guilds"].insert(sus.begin(), sus.end());
                        save();
                        event.edit_response(e);
                    }*/
                    if(cache["guilds"][to_string(event.command.guild_id)]) {
                        cache["guilds"][to_string(event.command.guild_id)] = false;
                        save();
                        event.edit_response("Set `LEVELING` to `false`");
                    } else {
                        cache["guilds"][to_string(event.command.guild_id)] = true;
                        save();
                        event.edit_response("Set `LEVELING` to `true`");
                    }
                } else {
                    event.edit_response("You need the `MANAGE_MESSAGES` permission for this.");
                }
            }
            if(cmd_data.name == "user-opt") {
                event.reply(dpp::ir_deferred_channel_message_with_source, "Checking permissions and opt-ability.");
                string uid = to_string(event.command.usr.id);
                
                //if(cache["users"].at(uid)) {
                //    event.edit_response("No exists? UWU?");
                
                /*if(cache["users"][uid]["enabled"] == NULL || cache == NULL) {
                        string e = "`ERROR` Item `USERS/" + event.command.usr.id + *"`/ENABLED is `NULL`.";
                        cache["users"][uid] = {
                                {"enabled", true},
                                {"level", 0},
                                {"xp", 0}
                        };
                        cache["users"][uid]["enabled"] = true;
                        event.edit_response(e);
                        save();
                    }*/
                    //bool handled = false;
                    //cout << to_string(handled);
                    if(cache["users"][to_string(event.command.usr.id)]["enabled"]) {
                    //    handled = true;
                        cache["users"][to_string(event.command.usr.id)]["enabled"] = false;
                        event.edit_response("Set `LEVELING` to `false` (USER)");
                        save();
                        return;
                    } else {
                    //    handled = true;
                        cache["users"][to_string(event.command.usr.id)]["enabled"] = true;
                        event.edit_response("Set `LEVELING` to `true` (USER)");
                        save();
                        return;
                    }

cout << "unhandled.";
                        string e = "`ERROR` Item `USERS/" + event.command.usr.id + *"`/ENABLED is `NULL`.";
                        cache["users"][to_string(event.command.usr.id)] = {
                                {"enabled", true},
                                {"level", 0},
                                {"xp", 0}
                        };
                        cache["users"][to_string(event.command.usr.id)]["enabled"] = true;
                        event.edit_response(e);
                        save();

                    }
                    //if(handled == false) {
                        
                    //}

            /*} else {
                event.edit_response("You do not exist.");
            }*/
        }
        });

    bot.start(false);
    return 0;
}