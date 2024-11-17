from spacex_launch_analysis.data_fetcher import fetch_launch_data
from spacex_launch_analysis.data_processor import process_launch_data

def main():
    # Fetch launch data
    launches_url = "https://api.spacexdata.com/v5/launches"
    launchpads_url = "https://api.spacexdata.com/v4/launchpads"

    launches = fetch_launch_data(launches_url)
    launchpads = fetch_launch_data(launchpads_url)

    # Process data
    launches_by_year, launches_by_site, detailed_launches = process_launch_data(launches, launchpads)

    # Display results
    print("Launches per Year:")
    for year, count in launches_by_year.items():
        print(f"{year}: {count}")

    print("\nLaunches per Launch Site:")
    for site, count in launches_by_site.items():
        print(f"{site}: {count}")

    print("\nDetailed Launch Data (first 5 launches):")
    for launch in detailed_launches[:5]:
        print(launch)

if __name__ == "__main__":
    main()
