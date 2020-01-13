
// MFCMechRateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCMechRate.h"
#include "MFCMechRateDlg.h"
#include "afxdialogex.h"
#include "myconnectorclassDB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCMechRateDlg dialog



CMFCMechRateDlg::CMFCMechRateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCMechRateDlg::IDD, pParent)
	, zone(_T(""))
	, dimension(_T(""))
	, sector(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCMechRateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ZONE, CRTLCOMBOZONE);
	DDX_CBString(pDX, IDC_ZONE, zone);
	DDX_Control(pDX, IDC_DIMENSION, CRTLCOMBODIM);
	DDX_Control(pDX, IDC_SECTOR, CRTLCOMBOSEC);
	DDX_CBString(pDX, IDC_DIMENSION, dimension);
	DDX_CBString(pDX, IDC_SECTOR, sector);
}

BEGIN_MESSAGE_MAP(CMFCMechRateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_DIMENSION, &CMFCMechRateDlg::OnCbnSelchangeDimension)
	ON_CBN_SELCHANGE(IDC_ZONE, &CMFCMechRateDlg::OnCbnSelchangeZone)
	ON_CBN_SELCHANGE(IDC_SECTOR, &CMFCMechRateDlg::OnCbnSelchangeSector)
	ON_BN_CLICKED(IDC_QUERY, &CMFCMechRateDlg::OnBnClickedQuery)
END_MESSAGE_MAP()


// CMFCMechRateDlg message handlers

BOOL CMFCMechRateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRTLCOMBOZONE.AddString(L"North");
	CRTLCOMBOZONE.AddString(L"Center");
	CRTLCOMBOZONE.AddString(L"South");

	CRTLCOMBODIM.AddString(L"1-50");
	CRTLCOMBODIM.AddString(L"51-500");
	CRTLCOMBODIM.AddString(L"+500");

	CRTLCOMBOSEC.AddString(L"Aeronautics");
	CRTLCOMBOSEC.AddString(L"Automobile");
	CRTLCOMBOSEC.AddString(L"Appliances");


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CMFCMechRateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCMechRateDlg::OnPaint()
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
HCURSOR CMFCMechRateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCMechRateDlg::OnCbnSelchangeDimension()
{
	// TODO: Add your control notification handler code here
	CRTLCOMBODIM.GetLBText(CRTLCOMBODIM.GetCurSel(), dimension);
}


void CMFCMechRateDlg::OnCbnSelchangeZone()
{
	// TODO: Add your control notification handler code here
	CRTLCOMBOZONE.GetLBText(CRTLCOMBOZONE.GetCurSel(), zone);
}


void CMFCMechRateDlg::OnCbnSelchangeSector()
{
	// TODO: Add your control notification handler code here
	CRTLCOMBOSEC.GetLBText(CRTLCOMBOSEC.GetCurSel(), sector);
}


void CMFCMechRateDlg::OnBnClickedQuery()
{
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	UpdateData(TRUE);
	city = MyConnection.CheckCity(company);   // MUDAR AQUI PARA AS NOSSAS VARIÁVEIS
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
