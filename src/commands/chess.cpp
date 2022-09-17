#include <iostream>
#include <string>
#include <dpp/dpp.h>
#include "chess.h"


void chess_command(const dpp::slashcommand_t &event, dpp::cluster *bot)
{

    dpp::snowflake guest = std::get<dpp::snowflake>(event.get_parameter("user"));

    std::string content = "g_new ";
    content.append(std::to_string(event.command.usr.id));
    content.append(" ");
    content.append(std::to_string((uint64_t) guest));

    dpp::message m(content);

    dpp::command_interaction cmd_data =
        event.command
            .get_command_interaction();

    dpp::embed ask_question;
    ask_question.set_title("Chess game invite.");
    ask_question.set_description("Challenge to start a game of chess.");

    ask_question.add_field("Host", event.command.usr.username, true);
    ask_question.add_field("Guest", std::to_string((uint64_t) guest), true);

    m.add_embed(ask_question).add_component(dpp::component().add_component(dpp::component().set_label("Accept").set_type(dpp::cot_button).set_style(dpp::cos_success).set_id("accept")).add_component(dpp::component().set_label("Deny").set_type(dpp::cot_button).set_style(dpp::cos_danger).set_id("deny")));

    event.reply(m);

};
