#ifndef LOGGER_H
#define LOGGER_H
#include <vector>
#include <string>

class Logger {
private:
    static Logger* instance;
    std::vector<std::string> logs;
    Logger(); 

public:
    static Logger* get_instance(); 
    void register_log(std::string msg); 
    std::vector<std::string> get_all_logs(); 
};
#endif