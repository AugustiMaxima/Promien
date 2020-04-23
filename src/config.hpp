#pragma once

#include <map>

namespace Promien{	

class Config{
static std::map<std::string, int> settings;
static std::map<std::string, std::string> configs;
public:
static const std::string& getConfig(const std::string& key);
static int getSetting(const std::string& key);
static void parseSettings(const char* ini, const char* manifest);
};

}
