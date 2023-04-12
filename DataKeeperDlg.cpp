// DataKeeperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DataKeeper.h"
#include "DataKeeperDlg.h"
#include "SaveWizard.h"			// by -=AS=-

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataKeeperDlg dialog

CDataKeeperDlg::CDataKeeperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataKeeperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataKeeperDlg)
	m_Hour = _T("3");
	m_Minute = _T("0");
	m_BasePath = _T("C:\\WINDOWS\\win.ini");
	m_ArcPath = _T("C:\\WINDOWS\\TEMP");
	m_KeyPath = _T("xcopy32 %b %a");
	m_NowTime = _T("");
	m_Everyday = TRUE;
	m__Everyday = TRUE;
	m_EndSwitch = 0;
	m_Day = _T("0");
	m_Proceed = FALSE;
	m_Timerrate = 1000;
	m_Selday = 0;
	m_AppVersion = "1.0";				// \---ВЕРСИЯ ПРИЛОЖЕНИЯ----\|
//--ProfileHandlers
	m_ProCommandLine = "CommandLine";
	m_ProArcPath = "Archive Path";
	m_ProBasePath = "Base Path";
	m_ProSaveWeekend = "Save Weekend";	
	m_ProSaveEveryDay = "Save Everyday";
	m_ProDayOfWeek = "Day Of Week";	
	m_ProMinute = "Minute";
	m_ProHour = "Hour";
	m_ProVer = "Version";				
	m_INIHandle = "Data Keeper";
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataKeeperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataKeeperDlg)
	DDX_Text(pDX, IDC_HOUR, m_Hour);
	DDV_MaxChars(pDX, m_Hour, 2);
	DDX_Text(pDX, IDC_MINUTE, m_Minute);
	DDV_MaxChars(pDX, m_Minute, 2);
	DDX_Text(pDX, IDC_BASEPATH, m_BasePath);
	DDX_Text(pDX, IDC_ARCPATH, m_ArcPath);
	DDX_Text(pDX, IDC_KEYPATH, m_KeyPath);
	DDX_Text(pDX, IDC_NOWTIME, m_NowTime);
	DDV_MaxChars(pDX, m_NowTime, 10);
	DDX_Check(pDX, IDC_EVERYDAY, m_Everyday);
	DDX_Radio(pDX, IDC_ENDYES, m_EndSwitch);
	DDX_CBString(pDX, IDC_DAY, m_Day);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDataKeeperDlg, CDialog)
	//{{AFX_MSG_MAP(CDataKeeperDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_EVERYDAY, OnEveryday)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_SAVER, OnSaver)
	ON_BN_CLICKED(IDC_RESNOW, OnResnow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataKeeperDlg message handlers

BOOL CDataKeeperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
//*******************************************************************
	// initialize by -=AS=-
	CWinApp* DKApp = AfxGetApp();		// указатель на объект приложения

	if(DKApp->GetProfileString(m_INIHandle,m_ProVer)!=m_AppVersion)
		GenerateProfile(DKApp);	// если профайла нет или не та версия,
								// генерируем профайл снова
	else
		if(!LoadProfile(DKApp))GenerateProfile(DKApp);// читаем профайл,
		// если один из пунктов отсутствует, то генерируем профайл снова

	m_nTimer=SetTimer(1,m_Timerrate,0);	// Включаем таймер

	UpdateData(FALSE);		// вывести загруженные параметры на экран
	CComboBox* comday=(CComboBox*) GetDlgItem(IDC_DAY);
	comday->SetCurSel(strtoul(m_Day,NULL,NULL));// устанавливаем в COMBO день недели

	if(m_Everyday)
		GetDlgItem(IDC_DAY)->EnableWindow(FALSE);	// отключаем COMBO дней недели

	OnUpdate();				// обновить
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDataKeeperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDataKeeperDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDataKeeperDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDataKeeperDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	// by -=AS=-

	CAboutDlg DKAbout;
	DKAbout.DoModal();

}

//*******************************************************************
//  				   Функция прерывания от таймера
//*******************************************************************
void CDataKeeperDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	// by -=AS=-
	
	CDialog::OnTimer(nIDEvent);
//	MessageBeep(0xFFFFFFFF);	// "Тик" на PC Speaker
	
//------- инициализация текущего времени -----------------------------
	time_t osBinaryTime;	// C run-time time (defined in <time.h>)
	time( &osBinaryTime );  // Get the current time from the operating system.
	CTime _time(osBinaryTime);	// создаём объект класса CTime

//------- вывести текущее время в окно "Текущее время"----------------
	m_NowTime=_time.Format("%H:%M:%S");
	SetDlgItemText(IDC_NOWTIME,m_NowTime);

	int e_h,e_m, n_h,n_m;
	e_h=strtoul(m_Hour,NULL,NULL);
	e_m=strtoul(m_Minute,NULL,NULL);
	n_h=_time.GetHour();
	n_m=_time.GetMinute();

//------- каждый день -------

	if(m__Everyday){
		if(m_EndSwitch==1){				// не сохранять в выходные
			if((_time.GetDayOfWeek()!=7)&&(_time.GetDayOfWeek()!=1)){
				if((e_h==n_h)&&(e_m==n_m))m_Proceed=TRUE;
				}
			
			}
		else{
			if((e_h==n_h)&&(e_m==n_m))m_Proceed=TRUE;
			}
		}

//------- не каждый день -----

	else{
		//CComboBox* comday=(CComboBox*) GetDlgItem(IDC_DAY);
		int m_realday=_time.GetDayOfWeek();
		//int m_selday=comday->GetCurSel();

		switch(m_realday){
			case 2:m_realday=0;break;
			case 3:m_realday=1;break;
			case 4:m_realday=2;break;
			case 5:m_realday=3;break;
			case 6:m_realday=4;break;
			case 7:m_realday=5;break;
			case 1:m_realday=6;break;
			}

		if(m_realday==m_Selday)
			{
			if((e_h==n_h)&&(e_m==n_m))m_Proceed=TRUE;
			}
		else{
			if(m_EndSwitch==0){
				if((_time.GetDayOfWeek()==7)||(_time.GetDayOfWeek()==1))
					if((e_h==n_h)&&(e_m==n_m))m_Proceed=TRUE;
				}
			}

		}

//********* если m_Proceed=TRUE, то начинаем резервирование********

	if(m_Proceed){
		KillTimer(m_nTimer);// глушим таймер на время выполнения резервирования
		Launch();

//------ простой остатка минуты (если таковой имеется) -----------
		while((e_h==n_h)&&(e_m==n_m)){
			time_t osBinaryTime;	// C run-time time (defined in <time.h>)
			time( &osBinaryTime );  // Get the current time from the operating system.
			CTime _time2(osBinaryTime);	// создаём объект класса CTime
			n_h=_time2.GetHour();
			n_m=_time2.GetMinute();
			}	// когда заданная минута заканчивается, покидаем цикл

		m_nTimer=SetTimer(1,m_Timerrate,0);	// включаем таймер снова
		m_Proceed=FALSE;}
}

//*******************************************************************
//					Флажок резервирования каждый день
//*******************************************************************
void CDataKeeperDlg::OnEveryday() 
{
	// TODO: Add your control notification handler code here
	// by-=AS=-
	// если флажок "Сохранять каждый день?" установлен, значит выбор
	// дней недели невозможен, и наоборот.

	if(!m_Everyday){
		GetDlgItem(IDC_DAY)->EnableWindow(FALSE);
		m_Everyday=TRUE;
		}
	else{
		GetDlgItem(IDC_DAY)->EnableWindow(TRUE);
		m_Everyday=FALSE;
		}
	
}

void CDataKeeperDlg::OnUpdate() 
{
	// TODO: Add your control notification handler code here
	// by -=AS=-

	// проверка на правильность интервала задаваемых часов
	if((GetDlgItemInt(IDC_HOUR)>23)||(GetDlgItemInt(IDC_HOUR)<0))
		{
		MessageBox("Введено недопустимое значение в текстовом поле \"Часы\".\n         Значения должны быть в интервале от 0 до 23.",
			"Ошибка", MB_ICONERROR | MB_OK);
		return;
		}
	// проверка на правильность интервала задаваемых минут
	if((GetDlgItemInt(IDC_MINUTE)>59)||(GetDlgItemInt(IDC_MINUTE)<0))
		{
		MessageBox("Введено недопустимое значение в текстовом поле \"Минуты\".\n           Значения должны быть в интервале от 0 до 59.",
			"Ошибка", MB_ICONERROR | MB_OK);
		return;
		}

	UpdateData();	// долгожданное обновление!!!
	m__Everyday=m_Everyday;	// данные во временную переменную

	CComboBox* comday=(CComboBox*) GetDlgItem(IDC_DAY);
	m_Selday=comday->GetCurSel();	// узнаём день недели из COMBO
	m_Day.Format("%d",m_Selday);	// сохраняем его порядковый номер для профайла

}

//*******************************************************************
//					       Генерируем профайл
//*******************************************************************
void CDataKeeperDlg::GenerateProfile(CWinApp* DKApp)
{

// запись версии приложения
	DKApp->WriteProfileString(m_INIHandle,m_ProVer,m_AppVersion);
// запись часа
	DKApp->WriteProfileString(m_INIHandle,m_ProHour,m_Hour);
// запись минуты
	DKApp->WriteProfileString(m_INIHandle,m_ProMinute,m_Minute);
// запись дня недели
	DKApp->WriteProfileString(m_INIHandle,m_ProDayOfWeek,m_Day);
// запись сохранения каждый день
	if(m_Everyday==TRUE)DKApp->WriteProfileString(m_INIHandle,m_ProSaveEveryDay,"TRUE");
	else
		DKApp->WriteProfileString(m_INIHandle,m_ProSaveEveryDay,"FALSE");
// запись сохранения каждую неделю
	DKApp->WriteProfileInt(m_INIHandle,m_ProSaveWeekend,m_EndSwitch);
// запись пути к базе по умолчанию
	DKApp->WriteProfileString(m_INIHandle,m_ProBasePath,m_BasePath);
// запись пути архива
	DKApp->WriteProfileString(m_INIHandle,m_ProArcPath,m_ArcPath);
// запись командной строки
	DKApp->WriteProfileString(m_INIHandle,m_ProCommandLine,m_KeyPath);

}

//*******************************************************************
//                     Загружаем данные из профайла
//-------------------------------------------------------------------
//	если идентификационная запись не найдена, тогда выход из
//	процедуры и генерация профайла. Причём, те данные которые удалось
//  прочитать в этой процедуре, будут помещены в новый профайл, а
//  остальные данные будут записаны как данные по умолчанию.
//*******************************************************************
BOOL CDataKeeperDlg::LoadProfile(CWinApp* DKApp)
{
CString GetPro=DKApp->GetProfileString(m_INIHandle,m_ProHour,"error");
	if(GetPro=="error")return FALSE;
	m_Hour=GetPro;
GetPro=DKApp->GetProfileString(m_INIHandle,m_ProMinute,"error");
	if(GetPro=="error")return FALSE;
	m_Minute=GetPro;
GetPro=DKApp->GetProfileString(m_INIHandle,m_ProDayOfWeek,"error");
	if(GetPro=="error")return FALSE;
	m_Day=GetPro;
GetPro=DKApp->GetProfileString(m_INIHandle,m_ProSaveEveryDay,"error");
	if(GetPro=="error")return FALSE;
	if(GetPro=="TRUE")m_Everyday=TRUE;
	else
		m_Everyday=FALSE;
int GetProInt=DKApp->GetProfileInt(m_INIHandle,m_ProSaveWeekend,255);
	if(GetProInt==255)return FALSE;
	m_EndSwitch=GetProInt;
GetPro=DKApp->GetProfileString(m_INIHandle,m_ProBasePath,"error");
	if(GetPro=="error")return FALSE;
	m_BasePath=GetPro;
GetPro=DKApp->GetProfileString(m_INIHandle,m_ProArcPath,"error");
	if(GetPro=="error")return FALSE;
	m_ArcPath=GetPro;
GetPro=DKApp->GetProfileString(m_INIHandle,m_ProCommandLine,"error");
	if(GetPro=="error")return FALSE;
	m_KeyPath=GetPro;

	return TRUE;
}

//*******************************************************************
//				Окно сохранения параметров в профайле
//*******************************************************************
void CDataKeeperDlg::OnSaver() 
{
	// TODO: Add your control notification handler code here
	// by -=AS=-

	CWinApp* DKAppSave = AfxGetApp();	// указатель на объект приложения

	CSaveWizard savedlg;
	int nSaverres = savedlg.DoModal();	// запуск окна сохранения
	if (nSaverres == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK

		if(savedlg.m_Save1){
			// запись часа
			DKAppSave->WriteProfileString(m_INIHandle,m_ProHour,m_Hour);
			// запись минуты
			DKAppSave->WriteProfileString(m_INIHandle,m_ProMinute,m_Minute);
			// запись дня недели
			DKAppSave->WriteProfileString(m_INIHandle,m_ProDayOfWeek,m_Day);
			// запись сохранения каждый день
			if(m_Everyday==TRUE)DKAppSave->WriteProfileString(m_INIHandle,m_ProSaveEveryDay,"TRUE");
			else
				DKAppSave->WriteProfileString(m_INIHandle,m_ProSaveEveryDay,"FALSE");

			}

		if(savedlg.m_Save2){
			// запись сохранения каждую неделю
			DKAppSave->WriteProfileInt(m_INIHandle,m_ProSaveWeekend,m_EndSwitch);

			}

		if(savedlg.m_Save3){
			// запись пути к базе по умолчанию
			DKAppSave->WriteProfileString(m_INIHandle,m_ProBasePath,m_BasePath);
			// запись пути архива
			DKAppSave->WriteProfileString(m_INIHandle,m_ProArcPath,m_ArcPath);
			// запись командной строки
			DKAppSave->WriteProfileString(m_INIHandle,m_ProCommandLine,m_KeyPath);

			}

	}
	else if (nSaverres == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	
}

//*******************************************************************
//		Подготовка командной строки и запуск её на исполнение
//*******************************************************************
void CDataKeeperDlg::Launch()
{

	if(!m_KeyPath.IsEmpty()){

		CString m_LaunchPath=m_KeyPath;
		if(m_BasePath.IsEmpty()){
			m_LaunchPath.Replace("%b ",NULL);
			}
		else {
			m_LaunchPath.Replace("%b",m_BasePath);	// путь базы
			}

		if(m_ArcPath.IsEmpty()){
			m_LaunchPath.Replace(" %a",NULL);
			}
		else {
			m_LaunchPath.Replace("%a",m_ArcPath);	// путь архива
			}
		system(m_LaunchPath);
		}
}

//*******************************************************************
//				Функция немедленного резервирования данных
//*******************************************************************
void CDataKeeperDlg::OnResnow() 
{
	// TODO: Add your control notification handler code here
	// by -=AS=-

	KillTimer(m_nTimer);// глушим таймер на время выполнения резервирования
	Launch();			// резервирование
	m_nTimer=SetTimer(1,m_Timerrate,0);	// включаем таймер снова
	
}
