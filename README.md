# SpaceXLaunchAnalyzer
This is a project which fetches data from publicly hosted server and processes data to produce a result which can answer a specific query. This repository contains two projects, one written in C++ and the other in Python, both works same to analyze SpaceX launches.

## Table of Contents
- [C++ Project](#cpp-project)
- [Python Project](#python-project)

---

## C++ Project

### Overview
This is a Dialog based C++ MFC project which fetches data from publicly hosted server and manually processes the JSON data (without ThirdParty component). Because of that it is tightly coupled with the data. It shows the information about 

### Features
- Retrieves launch data using HTTP requests.
- Parses and processes the retrieved JSON data for further analysis.
- Stores processed data in a structured format.

### How to Build and Run
1. Clone the repository:
   ```bash
   git clone https://github.com/shashank-acharya/SpaceXLaunchAnalyzer.git
   cd SpaceXLaunchAnalyzer

