#pragma once
#if !defined(GUILD_CONF_HPP)
#define GUILD_CONF_HPP

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

void _guild_conf_execute(const dpp::interaction_create_t &event, dpp::command_interaction cmd_data);
#endif // GUILD_CONF_HPP