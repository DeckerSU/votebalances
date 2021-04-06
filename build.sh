#!/usr/bin/env bash
g++ -g stats.cpp curlite/curlite.cpp utilstrencodings.cpp -std=c++11 -I./rapidjson/include -lcurl -o stats