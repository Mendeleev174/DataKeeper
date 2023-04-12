// DataKeeperDlg.h : header file
//

#if !defined(AFX_DATAKEEPERDLG_H__792E8097_6521_4D7E_A099_2D9B5983F064__INCLUDED_)
#define AFX_DATAKEEPERDLG_H__792E8097_6521_4D7E_A099_2D9B5983F064__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDataKeeperDlg dialog

class CDataKeeperDlg : public CDialog
{
// Construction
public:

	void Launch();
	BOOL LoadProfile(CWinApp*);
	void GenerateProfile(CWinApp*);

	CString m_AppVersion;					// ВЕРСИЯ ПРИЛОЖЕНИЯ!!!

	CString m_ProCommandLine;
	CString m_ProBasePath;
	CString m_ProArcPath;
	CString	m_ProSaveWeekend;
	CString m_ProSaveEveryDay;
	CString	m_ProDayOfWeek;
	CString	m_ProMinute;
	CString	m_ProHour;
	CString m_ProVer;						
	CString m_INIHandle;
	CDataKeeperDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDataKeeperDlg)
	enum { IDD = IDD_DATAKEEPER_DIALOG };
	CString	m_Hour;
	CString	m_Minute;
	CString	m_BasePath;
	CString	m_ArcPath;
	CString	m_KeyPath;
	CString	m_NowTime;
	BOOL	m_Everyday;
	int		m_EndSwitch;
	CString	m_Day;
	BOOL	m__Everyday;	// содержит m_Everyday до следущего обновления
	BOOL	m_Proceed;		// если TRUE, тогда начинаем резервирование
	UINT	m_nTimer;		// дескриптор прерывания от таймера
	UINT	m_Timerrate;	// частота прерывания таймера в Мс
	int		m_Selday;		// содержит текущее положение курсора в COMBO дней недели
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataKeeperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDataKeeperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEveryday();
	afx_msg void OnUpdate();
	afx_msg void OnSaver();
	afx_msg void OnResnow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAKEEPERDLG_H__792E8097_6521_4D7E_A099_2D9B5983F064__INCLUDED_)
