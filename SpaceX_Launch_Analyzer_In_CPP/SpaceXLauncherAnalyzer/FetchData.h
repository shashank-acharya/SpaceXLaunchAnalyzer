#pragma once
#include <windows.h>
#include <wininet.h>
#include <string>
#include <stdexcept>

// Fetches JSON data using WinINet
class FetchData 
{
public:
    static std::string FetchDataFromAPI(const std::string& url);
};
