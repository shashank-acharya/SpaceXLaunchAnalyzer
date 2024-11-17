from collections import defaultdict
from datetime import datetime

def process_launch_data(launches, launchpads):
    """
    Processes SpaceX launch data to count launches by year and by site.

    Args:
        launches (list): List of launch data (from /v5/launches API).
        launchpads (list): List of launchpad data (from /v4/launchpads API).

    Returns:
        tuple: (launches_by_year, launches_by_site, launches_with_site_names)
    """
    # Create a mapping of launchpad IDs to site names
    launchpad_mapping = {pad['id']: pad['name'] for pad in launchpads}

    launches_by_year = defaultdict(int)
    launches_by_site = defaultdict(int)
    launches_with_site_names = []

    for launch in launches:
        # Parse launch year
        launch_year = datetime.fromisoformat(launch['date_utc']).year
        launches_by_year[launch_year] += 1

        # Parse launch site and map launchpad ID to site name
        launchpad_id = launch['launchpad']
        site_name = launchpad_mapping.get(launchpad_id, "Unknown Site")
        launches_by_site[site_name] += 1

        # Add to launches_with_site_names for detailed data
        launches_with_site_names.append({
            "mission_name": launch.get("name", "Unknown Mission"),
            "launch_year": launch_year,
            "launchpad_id": launchpad_id,
            "site_name": site_name
        })

    # Convert dictionaries to sorted dictionaries for better readability
    launches_by_year = dict(sorted(launches_by_year.items()))
    launches_by_site = dict(sorted(launches_by_site.items()))

    return launches_by_year, launches_by_site, launches_with_site_names
