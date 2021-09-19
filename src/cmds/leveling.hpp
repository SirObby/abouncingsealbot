#pragma once
#if !defined(LEVELING_HPP)
#define LEVELING_HPP

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iomanip>
#include <sstream>

std::string generate_progress_bar(const double perc, const size_t siz);
void _leveling_execute(const dpp::interaction_create_t &event, dpp::command_interaction cmd_data);

#endif // MACRO