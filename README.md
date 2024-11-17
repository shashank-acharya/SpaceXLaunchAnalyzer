# SpaceXLaunchAnalyzer
This is a project which fetches data from publicly hosted server and processes data to produce a result which can answer a specific query. This repository contains two projects, one written in C++ and the other in Python, both works same to analyze SpaceX launches.

## Table of Contents
- [C++ Project](#cpp-project)
- [Python Project](#python-project)

---

## C++ Project

### Overview
This is a Dialog based C++ MFC project which fetches data from publicly hosted server and manually processes the JSON data (without ThirdParty component). Because of that it is tightly coupled with the JSON data. It shows the information about 

### Features
- Retrieves launch data using HTTP requests.
- Parses and processes the retrieved JSON data for further analysis.
- Stores processed data in a structured format.

### How to Build and Run
1. Clone the repository:
   ```bash
   git clone https://github.com/shashank-acharya/SpaceXLaunchAnalyzer.git
   cd SpaceXLaunchAnalyzer\SpaceX_Launch_Analyzer_In_CPP\SpaceXLauncherAnalyzer
2. Open SpaceXLauncherAnalyzer.sln in Visual Studio
3. Build all projects. Executables are generating in a folder as per build configuration. Ensure that all tests are passed.

## Python project

### Overview
A Python-based project to fetch, process, and analyze SpaceX launch data from their open API.This project provides a tool to analyze SpaceX's historical launch data. It fetches data from SpaceX's public API (https://github.com/r-spacex/SpaceX-API), processes the information, and outputs:
1.Launch counts by year.
2.Launch counts by launch site.
3.Detailed launch information.

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


