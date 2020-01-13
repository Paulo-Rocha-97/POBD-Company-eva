
// MFCMechRateDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCMechRateDlg dialog
class CMFCMechRateDlg : public CDialogEx
{
// Construction
public:
	CMFCMechRateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCMECHRATE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox CRTLCOMBOZONE;
	CString zone;
	CComboBox CRTLCOMBODIM;
	CComboBox CRTLCOMBOSEC;
	afx_msg void OnCbnSelchangeDimension();
	afx_msg void OnCbnSelchangeZone();
	CString dimension;
	afx_msg void OnCbnSelchangeSector();
	CString sector;
	afx_msg void OnBnClickedQuery();
};
