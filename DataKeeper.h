// DataKeeper.h : main header file for the DATAKEEPER application
//

#if !defined(AFX_DATAKEEPER_H__E9E24F14_C3C5_45D8_A44B_CE3EE2B66860__INCLUDED_)
#define AFX_DATAKEEPER_H__E9E24F14_C3C5_45D8_A44B_CE3EE2B66860__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataKeeperApp:
// See DataKeeper.cpp for the implementation of this class
//

class CDataKeeperApp : public CWinApp
{
public:
	CDataKeeperApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataKeeperApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDataKeeperApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAKEEPER_H__E9E24F14_C3C5_45D8_A44B_CE3EE2B66860__INCLUDED_)
