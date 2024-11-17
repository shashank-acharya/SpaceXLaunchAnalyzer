
// SpaceXLauncherAnalyzerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "SpaceXLauncherAnalyzer.h"
#include "SpaceXLauncherAnalyzerDlg.h"
#include "afxdialogex.h"
#include "FetchData.h"
#include "LaunchAnalyzer.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSpaceXLauncherAnalyzerDlg dialog



CSpaceXLauncherAnalyzerDlg::CSpaceXLauncherAnalyzerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPACEXLAUNCHERANALYZER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpaceXLauncherAnalyzerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSpaceXLauncherAnalyzerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Process_Data, &CSpaceXLauncherAnalyzerDlg::OnBnClickedProcessData)
END_MESSAGE_MAP()


// CSpaceXLauncherAnalyzerDlg message handlers

BOOL CSpaceXLauncherAnalyzerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSpaceXLauncherAnalyzerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpaceXLauncherAnalyzerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpaceXLauncherAnalyzerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/// <summary>
/// On Button Clicked it fetches data from url and parse that information.
/// </summary>
void CSpaceXLauncherAnalyzerDlg::OnBnClickedProcessData()
{
	try {
		// Fetch data from SpaceX API
		std::string apiUrl = "https://api.spacexdata.com/v5/launches";
		std::string jsonData = FetchData::FetchDataFromAPI(apiUrl);
		std::string dateString = "\"date_utc\":";
		std::string launchpad = "\"launchpad\":";

		// Parse launch data
		auto launches = LaunchAnalyzer::ParseLaunchPadData(jsonData,launchpad,dateString);

		// Count launches by year and site
		std::map<int, int> launches_by_year;
		std::map<std::string, int> launches_by_site;

		for (const auto& launch : launches) {
			// Extract year from date_utc
			int year = std::stoi(launch.firstIdentifier.substr(0, 4));
			launches_by_year[year]++;
			launches_by_site[launch.secondIdentifier]++;
		}

		// Format results
		CString output;
		output += _T("Launches per Year:\r\n");
		for (const auto& entry : launches_by_year) {
			CString line;
			line.Format(_T("%d: %d launches\r\n"), entry.first, entry.second);
			output += line;
		}

		std::string nameString = "\"name\":";
		std::string launchpadIdentifier = "\"id\":";
		apiUrl = "https://api.spacexdata.com/v4/launchpads/";
		jsonData = FetchData::FetchDataFromAPI(apiUrl);
		auto launchpads = LaunchAnalyzer::ParseLaunchPadData(jsonData, nameString, launchpadIdentifier);

		output += _T("\r\nLaunches per Launch Site:\r\n");
		std::string siteName;
		for (const auto& entry : launches_by_site) 
		{
			for (const auto& launch : launchpads) {
				if (launch.firstIdentifier == entry.first) {
					siteName = launch.secondIdentifier;
					break;
				}
			}
			CString line;
			line.Format(_T("%s: %d launches\r\n"), CString(siteName.c_str()), entry.second);
			output += line;
		}

		// Display results in the output control
		SetDlgItemText(IDC_FETCHED_DATA, output);
	}
	catch (const std::exception& e) {
		CString error(e.what());
		SetDlgItemText(IDC_FETCHED_DATA, _T("Error: ") + error);
	}
}
