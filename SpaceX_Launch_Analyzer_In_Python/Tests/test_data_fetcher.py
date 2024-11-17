import unittest
from unittest.mock import patch
from spacex_launch_analysis.data_fetcher import fetch_launch_data

class TestDataFetcher(unittest.TestCase):
    @patch("spacex_launch_analysis.data_fetcher.requests.get")
    def test_fetch_launch_data(self, mock_get):
        # Mock API response
        mock_get.return_value.status_code = 200
        mock_get.return_value.json.return_value = [{"key": "value"}]
        url = "https://api.spacexdata.com/v5/launches"
        # Call the function
        result = fetch_launch_data(url)

        # Assertions
        self.assertEqual(result, [{"key": "value"}])
        mock_get.assert_called_once_with("https://api.spacexdata.com/v5/launches")

    @patch("spacex_launch_analysis.data_fetcher.requests.get")
    def test_fetch_launch_data_failure(self, mock_get):
        # Mock API failure
        mock_get.return_value.status_code = 500

        with self.assertRaises(Exception):
            fetch_launch_data()

if __name__ == "__main__":
    unittest.main()
