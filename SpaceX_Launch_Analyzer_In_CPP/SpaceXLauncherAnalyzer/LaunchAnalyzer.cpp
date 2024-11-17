#include "pch.h"
#include "LaunchAnalyzer.h"
#include <cassert>
#include <stdexcept>

// Parses JSON manually to extract `name` and `identifier`
//std::vector<LaunchpadInfo> LaunchAnalyzer::ParseLaunchPadData(const std::string& json, const std::string& firstIdentifier, const std::string& secondIdentifier)
//{
//    std::vector<LaunchpadInfo> launches;
//
//    std::string launchData = json.substr(json.find(firstIdentifier));
//
//    while (true)
//    {
//        // Extract value for first identifier from JSON
//        size_t padStart = launchData.find(":") + 2;
//        size_t padEnd = launchData.find("\"", padStart);
//        std::string firstIdentifierValue = launchData.substr(padStart, padEnd - padStart);
//
//        // Extract value for second identifier from JSON
//        launchData = launchData.substr(launchData.find(secondIdentifier));
//        padStart = launchData.find(":") + 2;
//        padEnd = launchData.find("\"", padStart);
//        std::string secondIdentifierValue = launchData.substr(padStart, padEnd - padStart);
//
//        launches.push_back({ secondIdentifierValue, firstIdentifierValue });
//        padStart = launchData.find(firstIdentifier);
//        if (padStart == std::string::npos)
//        {
//            break;
//        }
//        launchData = launchData.substr(padStart);
//    }
//
//    return launches;
//}
//

std::vector<LaunchpadInfo> LaunchAnalyzer::ParseLaunchPadData(const std::string& json, const std::string& firstIdentifier, const std::string& secondIdentifier)
{
    std::vector<LaunchpadInfo> launches;

    size_t pos = 0;

    while (true) {
        // Find the first identifier
        size_t firstPos = json.find(firstIdentifier, pos);
        if (firstPos == std::string::npos) break;

        // Extract value for the first identifier
        size_t valueStart = json.find(":", firstPos) + 2;
        size_t valueEnd = json.find("\"", valueStart);
        if (valueStart == std::string::npos || valueEnd == std::string::npos) {
            throw std::runtime_error("Malformed JSON: Cannot extract first identifier value.");
        }
        std::string firstIdentifierValue = json.substr(valueStart, valueEnd - valueStart);

        // Find the second identifier
        size_t secondPos = json.find(secondIdentifier, valueEnd);
        if (secondPos == std::string::npos) break;

        // Extract value for the second identifier
        valueStart = json.find(":", secondPos) + 2;
        valueEnd = json.find("\"", valueStart);
        if (valueStart == std::string::npos || valueEnd == std::string::npos) {
            throw std::runtime_error("Malformed JSON: Cannot extract second identifier value.");
        }
        std::string secondIdentifierValue = json.substr(valueStart, valueEnd - valueStart);

        // Add the parsed data to the vector
        launches.push_back({ secondIdentifierValue, firstIdentifierValue });

        // Move the position forward for the next iteration
        pos = valueEnd;
    }

    return launches;
}
