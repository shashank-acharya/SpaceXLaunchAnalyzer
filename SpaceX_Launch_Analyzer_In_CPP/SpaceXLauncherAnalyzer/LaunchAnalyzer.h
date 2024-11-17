#pragma once
#include <string>
#include <vector>
#include <map>


struct LaunchpadInfo
{
    std::string firstIdentifier;
    std::string secondIdentifier;
};

class LaunchAnalyzer 
{
public:
    static std::vector<LaunchpadInfo> ParseLaunchPadData(const std::string& json, const std::string& firstIdentifier, const std::string& secondIdentifier);
};
