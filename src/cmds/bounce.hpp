#pragma once
#if !defined(BOUNCE_HPP)
#define BOUNCE_HPP

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

void _bounce_execute(const dpp::interaction_create_t & event, dpp::command_interaction cmd_data);

#endif // MACRO