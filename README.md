# SpaceXLaunchAnalyzer
This project fetches data from a publicly hosted server, processes it, and generates results that answer specific queries about SpaceX launches.

The repository includes two implementations:
1. C++ Project: A Dialog based application for analyzing SpaceX launches.
2. Python Project: A user-friendly and flexible implementation that performs the same analysis as the C++ version.
Both implementations work independently but achieve the same functionality: analyzing SpaceX launches and answering predefined queries.
## Table of Contents
- [C++ Project](#cpp-project)
- [Python Project](#python-project)

---

## C++ Project

### Overview
This is a Dialog based C++ MFC project which fetches data from publicly hosted server and manually processes the JSON data (without ThirdParty component). Because of that it is tightly coupled with the JSON data. It shows the information about "Launches per year" and "Launches per Launch Site"

### Features
- Retrieves launch data using HTTP requests.
- Parses and processes the retrieved JSON data for further analysis.
- Shows processed data in a structured format.

### How to Build and Run
1. Clone the repository:
   ```bash
   git clone https://github.com/shashank-acharya/SpaceXLaunchAnalyzer.git
   cd SpaceXLaunchAnalyzer\SpaceX_Launch_Analyzer_In_CPP\SpaceXLauncherAnalyzer
2. Open the Project in Visual Studio.
      * Navigate to the SpaceXLauncherAnalyzer folder.
      * Open the solution file SpaceXLauncherAnalyzer.sln in Visual Studio.
3. Build the Solution.
      * In Visual Studio, build all projects by selecting Build → Build Solution (or press Ctrl+Shift+B).
4. Verify Build Output.
      * Executable files will be generated in the output directory based on the build configuration (e.g., Debug or Release).

        ![image](https://github.com/user-attachments/assets/4605e925-98fb-47a8-8e75-2be2cea473a2)
5. Run Tests
      * Ensure all tests pass by running them from the Test Explorer in Visual Studio.
        ![image](https://github.com/user-attachments/assets/29786046-a030-42dc-b53e-ef5af324ce81)

#### Note
Current implementation and testing done on Windows 10(x86)

## Python project

### Overview
A Python-based project to fetch, process, and analyze SpaceX launch data from their open API.This project provides a tool to analyze SpaceX's historical launch data. It fetches data from SpaceX's public API (https://github.com/r-spacex/SpaceX-API), processes the information, and outputs:
1. Launch counts by year.
2. Launch counts by launch site.
3. Detailed launch information.

### Features
1. Fetches live data from SpaceX's public API.
2. Summarizes launch counts by year and launch site.
3. Displays detailed information about the launches.
4. Modular design for easy extension.

### Installation
#### Prerequisites
1. Python 3.7.5 or later
2. pip (Python package manager)

#### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/shashank-acharya/SpaceXLaunchAnalyzer.git
   cd SpaceXLaunchAnalyzer
2. Install required dependencies:
   ```bash
   pip install requests

### Usage
1. Run the main script:
   ```bash
   python main.py

### Example Output

   ```sql
   Launches per Year:
   2006: 1
   2007: 1
   Launches per Launch Site:
   CCSFS SLC 40: 112
   Detailed Launch Data (first 5 launches):
   {'mission_name': 'FalconSat', 'launch_year': 2006, 'launchpad_id': '5e9e4502f5090995de566f86', 'site_name': 'Kwajalein Atoll'}
    ...


