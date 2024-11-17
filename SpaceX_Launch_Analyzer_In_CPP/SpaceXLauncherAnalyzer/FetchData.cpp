#include "pch.h"
#include "FetchData.h"

// Fetch data from API using WinINet
std::string FetchData::FetchDataFromAPI(const std::string& url) {
    HINTERNET hSession = InternetOpen(L"SpaceXAnalyzer", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (!hSession) {
        throw std::runtime_error("Failed to open Internet session.");
    }

    HINTERNET hConnect = InternetOpenUrl(hSession, CString(url.c_str()), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hConnect) {
        InternetCloseHandle(hSession);
        throw std::runtime_error("Failed to open URL.");
    }

    std::string response;
    char buffer[4096];
    DWORD bytesRead;

    while (InternetReadFile(hConnect, buffer, sizeof(buffer) - 1, &bytesRead) && bytesRead > 0) {
        buffer[bytesRead] = '\0';
        response.append(buffer);
    }

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hSession);

    return response;
}
