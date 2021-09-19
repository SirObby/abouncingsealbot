#pragma once
#if !defined(USER_CONF_HPP)
#define USER_CONF_HPP

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

void _user_conf_execute(const dpp::interaction_create_t &event, dpp::command_interaction cmd_data);

#endif // USER_CONF_HPP