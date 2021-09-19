#pragma once
#if !defined(PING_HPP)
#define PING_HPP

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

void _ping_execute(const dpp::interaction_create_t &event, dpp::command_interaction cmd_data);

#endif // PING_HPP