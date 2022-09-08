#pragma once

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <fmt/format.h>
#include <iomanip>
#include <sstream>
#include <filesystem>
namespace fs = std::filesystem;

namespace OB_CONF {

    void checkConfigs(const dpp::interaction_create_t& event);

    void checkConfig(std::string id);

    nlohmann::json getConf(std::string id);
}
