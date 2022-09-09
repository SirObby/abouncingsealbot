#include "appcommand.h"
#include "commands/info.h"
#include <cstdint>
#include <dpp/dpp.h>
#include <fmt/format.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

void print_map(const dpp::slashcommand_map &m) {

  for (const auto &[key, value] : m) {
    std::cout << key << " = " << value.name.c_str() << "; ";
    std::cout << "\n";
  }

  // std::cout << "\n";
}

int main(int argc, char **argv) {

  nlohmann::json config;
  std::ifstream configfile("config.json");
  configfile >> config;
  configfile.close();

  /* Setup the bot */
  dpp::cluster bot(config["token"]);

  bot.on_log(dpp::utility::cout_logger());

  /* Executes on ready. */
  bot.on_ready([&bot](const dpp::ready_t &event) {
    if (dpp::run_once<struct register_bot_commands>()) {

      // list all comman
      //
      bot.global_commands_get(
          [&bot](const dpp::confirmation_callback_t &callback) {
            print_map(std::get<dpp::slashcommand_map>(callback.value));
          });

      dpp::slashcommand info("info", "Get bot information.", bot.me.id);

      // Define a slash command.
      dpp::slashcommand image("image", "Send a specific image.", bot.me.id);
      image.add_option(
          // Create a subcommand type option.
          dpp::command_option(dpp::co_sub_command, "dog",
                              "Send a picture of a dog.")
              .add_option(dpp::command_option(
                  dpp::co_user, "user", "User to make a dog off.", false)));
      image.add_option(
          // Create another subcommand type option.
          dpp::command_option(dpp::co_sub_command, "cat",
                              "Send a picture of a cat.")
              .add_option(dpp::command_option(
                  dpp::co_user, "user", "User to make a cat off.", false)));
      // Create command with a callback.
      bot.global_command_create(
          image, [&](const dpp::confirmation_callback_t &callback) {
            if (callback.is_error()) {
              std::cout << callback.http_info.body << "\n";
            }
          });
      bot.global_command_create(
          info, [&](const dpp::confirmation_callback_t &callback) {
            if (callback.is_error()) {
              std::cout << callback.http_info.body << "\n";
            }
          });
    }
  });

  /* Use the on_slashcommand event to look for commands */
  bot.on_slashcommand([&bot](const dpp::slashcommand_t &event) {
    dpp::command_interaction cmd_data =
        event.command
            .get_command_interaction(); // This can be done from the command.

    if (cmd_data.name == "info") {
      info_command(event, &bot);
    }
  });

  bot.start(dpp::st_wait);

  return 0;
}
