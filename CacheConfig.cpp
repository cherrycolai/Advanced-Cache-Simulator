#include "CacheConfig.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

CacheConfig parseConfig(const string& filename) {
    CacheConfig config;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Cannot open the config file: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);

            if (key == "CACHE_SIZE") 
                config.cache_size = stoi(value);
            else if (key == "BLOCK_SIZE") 
                config.block_size = stoi(value);
            else if (key == "ASSOCIATIVITY") 
                config.associativity = stoi(value);
            else if (key == "REPLACEMENT_POLICY") 
                config.replacement_policy = value;
            else if (key == "WRITE_POLICY") 
                config.write_policy = value;
            else if (key == "WRITE_ALLOCATE") 
                config.write_allocate = (stoi(value) == 1);
            
        }
    }

    file.close();
    return config;
}
