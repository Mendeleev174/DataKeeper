#if !defined(AFX_SAVEWIZARD_H__84306099_97E3_4179_8843_E37AA956367A__INCLUDED_)
#define AFX_SAVEWIZARD_H__84306099_97E3_4179_8843_E37AA956367A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaveWizard.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSaveWizard dialog

class CSaveWizard : public CDialog
{
// Construction
public:
	CSaveWizard(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSaveWizard)
	enum { IDD = IDD_DIALOGSAVER };
	BOOL	m_Save1;
	BOOL	m_Save2;
	BOOL	m_Save3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveWizard)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSaveWizard)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVEWIZARD_H__84306099_97E3_4179_8843_E37AA956367A__INCLUDED_)
