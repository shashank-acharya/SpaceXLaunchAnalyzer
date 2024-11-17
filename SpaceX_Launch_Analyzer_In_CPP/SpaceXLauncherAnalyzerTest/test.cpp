#include "pch.h"

#include "gtest/gtest.h"
#include "LaunchAnalyzer.h"

// Test valid JSON input
TEST(ParseLaunchPadDataTest, ValidInput)
{
	std::string json = R"([
    {"date_utc":"2020-05-30T19:22:00.000Z", "launchpad":"site_A"},
    {"date_utc":"2020-11-15T12:30:00.000Z", "launchpad":"site_B"},
    {"date_utc":"2019-08-24T03:00:00.000Z", "launchpad":"site_A"}
    ])";

	auto launches = LaunchAnalyzer::ParseLaunchPadData(json, "date_utc", "launchpad");

	ASSERT_EQ(launches.size(), 3);
	EXPECT_EQ(launches[0].secondIdentifier, "2020-05-30T19:22:00.000Z");
	EXPECT_EQ(launches[0].firstIdentifier, "site_A");
	EXPECT_EQ(launches[1].secondIdentifier, "2020-11-15T12:30:00.000Z");
	EXPECT_EQ(launches[1].firstIdentifier, "site_B");
	EXPECT_EQ(launches[2].secondIdentifier, "2019-08-24T03:00:00.000Z");
	EXPECT_EQ(launches[2].firstIdentifier, "site_A");
}

// Test empty JSON
TEST(ParseLaunchPadDataTest, EmptyJSON)
{
    std::string json = R"([])";

    auto launches = LaunchAnalyzer::ParseLaunchPadData(json, "date_utc", "launchpad");

    ASSERT_TRUE(launches.empty());
}

// Test missing identifiers
TEST(ParseLaunchPadDataTest, MissingIdentifiers)
{
    std::string json = R"([
        {"date_utc":"2020-05-30T19:22:00.000Z"}}
    ])";

    auto launches = LaunchAnalyzer::ParseLaunchPadData(json, "date_utc", "launchpad");

    ASSERT_TRUE(launches.empty()); // Missing one of the required identifiers
}

// Test malformed JSON
TEST(ParseLaunchPadDataTest, MalformedJSON)
{
    std::string malformedJson = R"([
    {"date_utc":"2020-05-30T19:22:00.000Z", "launchpad":"site_A])";

    EXPECT_THROW({
        auto launches = LaunchAnalyzer::ParseLaunchPadData(malformedJson, "date_utc", "launchpad");
        }, std::exception);
}
