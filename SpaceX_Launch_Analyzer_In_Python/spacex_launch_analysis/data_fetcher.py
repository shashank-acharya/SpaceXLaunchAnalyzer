import requests

def fetch_launch_data(url):
    """
    Fetches launch data from the SpaceX API.
    Returns:
        list: List of launches (JSON objects).
    """
    response = requests.get(url)
    response.raise_for_status()  # Raise HTTPError for bad responses
    return response.json()
