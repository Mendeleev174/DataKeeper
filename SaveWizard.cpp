// SaveWizard.cpp : implementation file
//

#include "stdafx.h"
#include "DataKeeper.h"
#include "SaveWizard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaveWizard dialog


CSaveWizard::CSaveWizard(CWnd* pParent /*=NULL*/)
	: CDialog(CSaveWizard::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSaveWizard)
	m_Save1 = TRUE;
	m_Save2 = TRUE;
	m_Save3 = TRUE;
	//}}AFX_DATA_INIT
}


void CSaveWizard::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSaveWizard)
	DDX_Check(pDX, IDC_SAVE1, m_Save1);
	DDX_Check(pDX, IDC_SAVE2, m_Save2);
	DDX_Check(pDX, IDC_SAVE3, m_Save3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSaveWizard, CDialog)
	//{{AFX_MSG_MAP(CSaveWizard)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaveWizard message handlers
