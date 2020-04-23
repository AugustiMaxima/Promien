#include <fstream>
#include <map>
#include "config.hpp"

namespace Promien{
	std::map<std::string, int> Config::settings;
	std::map<std::string, std::string> Config::configs;

	const std::string& Config::getConfig(const std::string& key){
		return configs[key];
	}

	int Config::getSetting(const std::string& key){
		return settings[key];
	}

	void Config::parseSettings(const char* ini, const char* manifest){
		using std::fstream;
		fstream setting = fstream(ini);
		std::string term;
		while(setting >> term){
			int val;
			setting >> val;
			settings[term] = val;
		}
		
		std::string line;
		fstream config = fstream(manifest);
		while(std::getline(config, line)){
			//removes new line
			if(line.back() == '\n')
				line = line.substr(0, line.length() - 1);
			int lim = line.find("\t");
			std::string key = line.substr(0, lim);
			std::string val = line.substr(lim+1, line.length() - lim - 1);
			configs[key] = val;
		}


		//some exception/default cases set here
		if(settings["xres"] == 0){
			settings["xres"] = 1920;
		}
		if(settings["yres"] == 0){
			settings["yres"] = 1080;
		}

		if(configs["AppName"] == ""){
			configs["AppName"] = "Promien SDK";
		}
	}

}

