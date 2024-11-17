import unittest
from spacex_launch_analysis.data_processor import process_launch_data
from Tests.mock_data import MOCK_LAUNCHES, MOCK_LAUNCHPADS

class TestDataProcessor(unittest.TestCase):
    def test_process_launch_data(self):
        # Call the function with mock data
        launches_by_year, launches_by_site, detailed_launches = process_launch_data(MOCK_LAUNCHES, MOCK_LAUNCHPADS)

        # Assertions for launches by year
        self.assertEqual(launches_by_year, {2019: 1, 2020: 2})

        # Assertions for launches by site
        self.assertEqual(launches_by_site, {
            "Launch Site Alpha": 2,
            "Launch Site Beta": 1,
        })

        # Assertions for detailed launches
        self.assertEqual(len(detailed_launches), 3)
        self.assertEqual(detailed_launches[0]["mission_name"], "Mission 1")
        self.assertEqual(detailed_launches[0]["site_name"], "Launch Site Alpha")

    def test_missing_launchpad(self):
        # Remove a launchpad mapping
        partial_launchpads = MOCK_LAUNCHPADS[:1]

        # Call the function
        launches_by_year, launches_by_site, detailed_launches = process_launch_data(MOCK_LAUNCHES, partial_launchpads)

        # Assert "Unknown Site" is used for unmapped IDs
        self.assertIn("Unknown Site", launches_by_site)
        self.assertEqual(launches_by_site["Unknown Site"], 1)

if __name__ == "__main__":
    unittest.main()
