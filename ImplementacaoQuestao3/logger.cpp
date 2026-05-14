#include "logger.hpp"
#include <iostream>

Logger* Logger::instance = nullptr;
Logger::Logger() {}

Logger* Logger::get_instance() {
    if (!instance) instance = new Logger(); 
    return instance;
}

void Logger::register_log(std::string msg) {
    std::cout << "[LOG]: " << msg << std::endl; 
    logs.push_back(msg);
}

std::vector<std::string> Logger::get_all_logs() { return logs; }