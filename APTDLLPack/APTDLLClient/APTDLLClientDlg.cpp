// APTDLLClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "APTDLLClient.h"
#include "APTDLLClientDlg.h"

#define DllImport   __declspec( dllimport )

#include "APTAPI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CAPTDLLClientDlg dialog

CAPTDLLClientDlg::CAPTDLLClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAPTDLLClientDlg::IDD, pParent)
	, m_ledtHWType(0)
	, m_lNumHWUnits(0)
	, m_ledtHWSerialNum(0)
	, m_fedtMinVel(0)
	, m_fedtAccn(0)
	, m_fedtMaxVel(0)
	, m_ledtStatusBits(0)
	, m_fedtRelDist(0)
	, m_fedtPosition(0)
	, m_fedtAbsPos(0)
	, m_ledtHomeDirection(0)
	, m_ledtHomeLimSwitch(0)
	, m_fedtHomeVel(0)
	, m_fedtZeroOffset(0)
	, m_ledtIndex(0)
	, m_edtModel(_T(""))
	, m_edtSWVer(_T(""))
	, m_edtHWNotes(_T(""))
	, m_ledtVelDirection(0)
	, m_ledtChanID(0)
	, m_fedtBLashDist(0)
	, m_ledtStepsPerRev(0)
	, m_ledtGearboxRatio(0)
	, m_fedtStageMinPos(0)
	, m_fedtStageMaxPos(0)
	, m_ledtStageUnits(0)
	, m_fedtStagePitch(0)
	, m_lRevLimSwitch(0)
	, m_lFwdLimSwitch(0)
	, m_ledtDCPIDProp(0)
	, m_ledtDCPIDInt(0)
	, m_ledtDCPIDDeriv(0)
	, m_ledtDCPIDIntLim(0)
	, m_fedtMaxVelLim(0)
	, m_fedtMaxAccnLim(0)
	, m_ledtPMDCurrProp(0)
	, m_ledtPMDCurrInt(0)
	, m_ledtPMDCurrIntLim(0)
	, m_ledtPMDCurrIntDeadBand(0)
	, m_ledtPMDCurrFeedFwd(0)
	, m_ledtPMDPosProp(0)
	, m_ledtPMDPosInt(0)
	, m_ledtPMDPosIntLim(0)
	, m_ledtPMDPosDeriv(0)
	, m_ledtPMDPosDerivTime(0)
	, m_ledtPMDPosLoopGain(0)
	, m_ledtPMDPosVelFFwd(0)
	, m_ledtPMDPosAccFFwd(0)
	, m_ledtPMDPosErrLim(0)
	, m_ledtPMDCurrProp2(0)
	, m_ledtPMDCurrInt2(0)
	, m_ledtPMDCurrIntLim2(0)
	, m_ledtPMDCurrIntDeadBand2(0)
	, m_ledtPMDCurrFeedFwd2(0)
	, m_fedtPMDContCurrLimit(0)
	, m_fedtPMDEnergyLimit(0)
	, m_fedtPMDMotorLimit(0)
	, m_fedtPMDMotorBias(0)
	, m_ledtPMDSettleTime(0)
	, m_ledtPMDSettleWnd(0)
	, m_ledtTrackWnd(0)
	, m_ledtPMDProfileMode(0)
	, m_fedtPMDJerk(0)
	, m_fedtPMDMaxVelLo(0)
	, m_fedtPMDMaxVelHi(0)
	, m_fedtPMDAccnLo(0)
	, m_fedtPMDAccnHi(0)
	, m_ledtPMDDirSense(0)
	, m_lEncCount(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAPTDLLClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDTHWTYPE, m_ledtHWType);
	DDX_Text(pDX, IDC_EDTNUMHWUNITS, m_lNumHWUnits);
	DDX_Text(pDX, IDC_EDTHWSERIALNUM, m_ledtHWSerialNum);
	DDX_Text(pDX, IDC_EDTMINVEL, m_fedtMinVel);
	DDX_Text(pDX, IDC_EDTACCN, m_fedtAccn);
	DDX_Text(pDX, IDC_EDTMAXVEL1, m_fedtMaxVel);
	DDX_Text(pDX, IDC_EDTSTATUSBITS, m_ledtStatusBits);
	DDX_Text(pDX, IDC_EDTRELDIST, m_fedtRelDist);
	DDX_Text(pDX, IDC_EDTPOSITION, m_fedtPosition);
	DDX_Text(pDX, IDC_EDTABSPOS, m_fedtAbsPos);
	DDX_Text(pDX, IDC_EDTHOMEDIRECTION, m_ledtHomeDirection);
	DDX_Text(pDX, IDC_EDTHOMELIMSWITCH, m_ledtHomeLimSwitch);
	DDX_Text(pDX, IDC_EDTHOMEVEL, m_fedtHomeVel);
	DDX_Text(pDX, IDC_EDTZEROOFFSET, m_fedtZeroOffset);
	DDX_Text(pDX, IDC_EDTINDEX, m_ledtIndex);
	DDX_Text(pDX, IDC_EDTMODEL, m_edtModel);
	DDX_Text(pDX, IDC_EDTSWVER, m_edtSWVer);
	DDX_Text(pDX, IDC_EDTHWNOTES, m_edtHWNotes);
	DDX_Text(pDX, IDC_EDTVELDIRECTION, m_ledtVelDirection);
	DDX_Text(pDX, IDC_EDTCHANID, m_ledtChanID);
	DDX_Text(pDX, IDC_EDTBLASHDIST, m_fedtBLashDist);
	DDX_Text(pDX, IDC_EDTSTEPSPERREV, m_ledtStepsPerRev);
	DDX_Text(pDX, IDC_EDTGEARBOXRATIO, m_ledtGearboxRatio);
	DDX_Text(pDX, IDC_EDTSTAGEMINPOS, m_fedtStageMinPos);
	DDX_Text(pDX, IDC_EDTSTAGEMAXPOS, m_fedtStageMaxPos);
	DDX_Text(pDX, IDC_EDTSTAGEUNITS, m_ledtStageUnits);
	DDX_Text(pDX, IDC_EDTSTAGEPITCH, m_fedtStagePitch);
	DDX_Text(pDX, IDC_EDTREVLIMSWITCH, m_lRevLimSwitch);
	DDX_Text(pDX, IDC_EDTFWDLIMSWITCH, m_lFwdLimSwitch);
	DDX_Text(pDX, IDC_EDTDCPIDPROP, m_ledtDCPIDProp);
	DDX_Text(pDX, IDC_EDTDCPIDINT, m_ledtDCPIDInt);
	DDX_Text(pDX, IDC_EDTDCPIDDERIV, m_ledtDCPIDDeriv);
	DDX_Text(pDX, IDC_EDTDCPIDINTLIMIT, m_ledtDCPIDIntLim);
	DDX_Text(pDX, IDC_EDTMAXVELLIM, m_fedtMaxVelLim);
	DDX_Text(pDX, IDC_EDTMAXACCNLIM, m_fedtMaxAccnLim);
	DDX_Text(pDX, IDC_EDTPMDCURRPROP, m_ledtPMDCurrProp);
	DDX_Text(pDX, IDC_EDTPMDCURRINT, m_ledtPMDCurrInt);
	DDX_Text(pDX, IDC_EDTPMDCURRINTLIM, m_ledtPMDCurrIntLim);
	DDX_Text(pDX, IDC_EDTPMDCURRINTDEADBAND, m_ledtPMDCurrIntDeadBand);
	DDX_Text(pDX, IDC_EDTPMDCURRFEEDFWD, m_ledtPMDCurrFeedFwd);
	DDX_Text(pDX, IDC_EDTPMDPOSPROP, m_ledtPMDPosProp);
	DDX_Text(pDX, IDC_EDTPMDPOSINT, m_ledtPMDPosInt);
	DDX_Text(pDX, IDC_EDTPMDPOSINTLIM, m_ledtPMDPosIntLim);
	DDX_Text(pDX, IDC_EDTPMDPOSDERIV, m_ledtPMDPosDeriv);
	DDX_Text(pDX, IDC_EDTPMDPOSDERIVTIME, m_ledtPMDPosDerivTime);
	DDX_Text(pDX, IDC_EDTPMDPOSLOOPGAIN, m_ledtPMDPosLoopGain);
	DDX_Text(pDX, IDC_EDTPMDPOSVELFFWD, m_ledtPMDPosVelFFwd);
	DDX_Text(pDX, IDC_EDTPMDPOSACCFFWD, m_ledtPMDPosAccFFwd);
	DDX_Text(pDX, IDC_EDTPMDPOSERRLIM, m_ledtPMDPosErrLim);
	DDX_Text(pDX, IDC_EDTPMDCURRPROP2, m_ledtPMDCurrProp2);
	DDX_Text(pDX, IDC_EDTPMDCURRINT2, m_ledtPMDCurrInt2);
	DDX_Text(pDX, IDC_EDTPMDCURRINTLIM2, m_ledtPMDCurrIntLim2);
	DDX_Text(pDX, IDC_EDTPMDCURRINTDEADBAND2, m_ledtPMDCurrIntDeadBand2);
	DDX_Text(pDX, IDC_EDTPMDCURRFEEDFWD2, m_ledtPMDCurrFeedFwd2);
	DDX_Text(pDX, IDC_EDTPMDCONTCURRLIMIT, m_fedtPMDContCurrLimit);
	DDX_Text(pDX, IDC_EDTPMDENERGYLIMIT, m_fedtPMDEnergyLimit);
	DDX_Text(pDX, IDC_EDTPMDMOTORLIMIT, m_fedtPMDMotorLimit);
	DDX_Text(pDX, IDC_EDTPMDMOTORBIAS, m_fedtPMDMotorBias);
	DDX_Text(pDX, IDC_EDTPMDSETTLETIME, m_ledtPMDSettleTime);
	DDX_Text(pDX, IDC_EDTPMDSETTLEWND, m_ledtPMDSettleWnd);
	DDX_Text(pDX, IDC_EDTPMDTRACKWND, m_ledtTrackWnd);
	DDX_Text(pDX, IDC_EDTPMDPROFILEMODE, m_ledtPMDProfileMode);
	DDX_Text(pDX, IDC_EDTPMDJERK, m_fedtPMDJerk);
	DDX_Text(pDX, IDC_EDTPMDMAXVELLO, m_fedtPMDMaxVelLo);
	DDX_Text(pDX, IDC_EDTPMDMAXVELHI, m_fedtPMDMaxVelHi);
	DDX_Text(pDX, IDC_EDTPMDACCNLO, m_fedtPMDAccnLo);
	DDX_Text(pDX, IDC_EDTPMDACCNHI, m_fedtPMDAccnHi);
	DDX_Text(pDX, IDC_EDTPMDDIRSENSE, m_ledtPMDDirSense);
	//	DDX_Control(pDX, IDC_MG17LOGGERCTRL, m_APTLogger);
	DDX_Text(pDX, IDC_EDTENCOUNT, m_lEncCount);
}

BEGIN_MESSAGE_MAP(CAPTDLLClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNSTARTTHREAD, &CAPTDLLClientDlg::OnBnClickedBtnstartthread)
	ON_BN_CLICKED(IDC_INITDLL, &CAPTDLLClientDlg::OnBnClickedInitdll)
	ON_BN_CLICKED(IDC_CLEANDLL, &CAPTDLLClientDlg::OnBnClickedCleandll)
	ON_BN_CLICKED(IDC_BTNGETNUMHWUNITSEX, &CAPTDLLClientDlg::OnBnClickedBtngetnumhwunitsex)
	ON_BN_CLICKED(IDC_BTNINITHWDEVICE, &CAPTDLLClientDlg::OnBnClickedBtninithwdevice)
	ON_BN_CLICKED(IDC_BTNSETVELPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetvelparams)
	ON_BN_CLICKED(IDC_BTNGETVELPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetvelparams)
	ON_BN_CLICKED(IDC_BTNGETSTATUSBITS, &CAPTDLLClientDlg::OnBnClickedBtngetstatusbits)
	ON_BN_CLICKED(IDC_BTNHOME, &CAPTDLLClientDlg::OnBnClickedBtnhome)
	ON_BN_CLICKED(IDC_BTNMOVERELEX, &CAPTDLLClientDlg::OnBnClickedBtnmoverelex)
	ON_BN_CLICKED(IDC_BTNGETPOS, &CAPTDLLClientDlg::OnBnClickedBtngetpos)
	ON_BN_CLICKED(IDC_BTNMOVEABSEX, &CAPTDLLClientDlg::OnBnClickedBtnmoveabsex)
	ON_BN_CLICKED(IDC_BTNIDENTIFY, &CAPTDLLClientDlg::OnBnClickedBtnidentify)
	ON_BN_CLICKED(IDC_BTNENABLEHWCHAN, &CAPTDLLClientDlg::OnBnClickedBtnenablehwchan)
	ON_BN_CLICKED(IDC_BTNDISABLEHWCHAN, &CAPTDLLClientDlg::OnBnClickedBtndisablehwchan)
	ON_BN_CLICKED(IDC_BTNSETHOMEPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsethomeparams)
	ON_BN_CLICKED(IDC_BTNGETHOMEPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngethomeparams)
	ON_BN_CLICKED(IDC_BTNGETHWSERNUMEX, &CAPTDLLClientDlg::OnBnClickedBtngethwsernumex)
	ON_BN_CLICKED(IDC_BTNGETHWINFO, &CAPTDLLClientDlg::OnBnClickedBtngethwinfo)
	ON_BN_CLICKED(IDC_BTNMOVEVELOCITY, &CAPTDLLClientDlg::OnBnClickedBtnmovevelocity)
	ON_BN_CLICKED(IDC_BTNSTOPPROFILED, &CAPTDLLClientDlg::OnBnClickedBtnstopprofiled)
	ON_BN_CLICKED(IDC_BTNSETCHAN, &CAPTDLLClientDlg::OnBnClickedBtnsetchan)
	ON_BN_CLICKED(IDC_BTNDISABLEEVENTDLG, &CAPTDLLClientDlg::OnBnClickedBtndisableeventdlg)
	ON_BN_CLICKED(IDC_BTNENABLEEVENTDLG, &CAPTDLLClientDlg::OnBnClickedBtnenableeventdlg)
	ON_BN_CLICKED(IDC_BTNSETBLASHDIST, &CAPTDLLClientDlg::OnBnClickedBtnsetblashdist)
	ON_BN_CLICKED(IDC_BTNGETBLASHDIST, &CAPTDLLClientDlg::OnBnClickedBtngetblashdist)
	ON_BN_CLICKED(IDC_BTNSETMOTORPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetmotorparams)
	ON_BN_CLICKED(IDC_BTNGETMOTORPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetmotorparams)
	ON_BN_CLICKED(IDC_BTNSETSTAGEAXISINFO, &CAPTDLLClientDlg::OnBnClickedBtnsetstageaxisinfo)
	ON_BN_CLICKED(IDC_BTNGETSTAGEAXISINFO, &CAPTDLLClientDlg::OnBnClickedBtngetstageaxisinfo)
	ON_BN_CLICKED(IDC_BTNSETHWLIMSWITCHES, &CAPTDLLClientDlg::OnBnClickedBtnsethwlimswitches)
	ON_BN_CLICKED(IDC_BTNGETHWLIMSWITCHES, &CAPTDLLClientDlg::OnBnClickedBtngethwlimswitches)
	ON_BN_CLICKED(IDC_BTNSETDCPIDPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetdcpidparams)
	ON_BN_CLICKED(IDC_BTNGETDCPIDPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetdcpidparams)
	ON_BN_CLICKED(IDC_BTNGETVELPARAMLIMITS, &CAPTDLLClientDlg::OnBnClickedBtngetvelparamlimits)
	ON_BN_CLICKED(IDC_BTNSETPMDCURRLOOPPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdcurrloopparams)
	ON_BN_CLICKED(IDC_BTNGETPMDCURRLOOPPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetpmdcurrloopparams)
	ON_BN_CLICKED(IDC_BTNSETPMDPOSLOOPPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdposloopparams)
	ON_BN_CLICKED(IDC_BTNGETPMDPOSLOOPPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetpmdposloopparams)
	ON_BN_CLICKED(IDC_BTNSETPMDCURRLOOPPARAMS2, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdcurrloopparams2)
	ON_BN_CLICKED(IDC_BTNGETPMDCURRLOOPPARAMS2, &CAPTDLLClientDlg::OnBnClickedBtngetpmdcurrloopparams2)
	ON_BN_CLICKED(IDC_BTNSETPMDMOTOROUTPUTPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdmotoroutputparams)
	ON_BN_CLICKED(IDC_BTNGETPMDMOTOROUTPUTPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetpmdmotoroutputparams)
	ON_BN_CLICKED(IDC_BTNSETPMDTRACKSETTLEPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdtracksettleparams)
	ON_BN_CLICKED(IDC_BTNGETPMDTRACKSETTLEPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetpmdtracksettleparams)
	ON_BN_CLICKED(IDC_BTNGETPMDPROFILEMODEPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetpmdprofilemodeparams)
	ON_BN_CLICKED(IDC_BTNSETPMDPROFILEMODEPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdprofilemodeparams)
	ON_BN_CLICKED(IDC_BTNSETPMDJOYSTICKPARAMS, &CAPTDLLClientDlg::OnBnClickedBtnsetpmdjoystickparams)
	ON_BN_CLICKED(IDC_BTNGETPMDJOYSTICKPARAMS, &CAPTDLLClientDlg::OnBnClickedBtngetpmdjoystickparams)
	ON_BN_CLICKED(IDC_BTNCLEAR, &CAPTDLLClientDlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_BTNLLSETENCCOUNT, &CAPTDLLClientDlg::OnBnClickedBtnllsetenccount)
	ON_BN_CLICKED(IDC_BTNLLGETENCCOUNT, &CAPTDLLClientDlg::OnBnClickedBtnllgetenccount)
END_MESSAGE_MAP()


// CAPTDLLClientDlg message handlers

BOOL CAPTDLLClientDlg::OnInitDialog()
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

	m_ledtHWSerialNum = 83000001;
	m_fedtRelDist = 1.0f;
	m_ledtVelDirection = MOVE_FWD;

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAPTDLLClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAPTDLLClientDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAPTDLLClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT MyThreadProc(LPVOID pParam);

void CAPTDLLClientDlg::OnBnClickedBtnstartthread()
{
	// TODO: Add your control notification handler code here

	// Start secondary processing thread and make test calls to try out APT.DLL.
	AfxBeginThread(MyThreadProc, NULL /*pNewObject*/);
}

UINT MyThreadProc(LPVOID pParam)
{
	float fMinVel, fAccn, fMaxVel;

	// Make call to APT DLL on secondary thread.
	APTInit();

	InitHWDevice(83813314);

	MOT_GetVelParams(83813314, &fMinVel, &fAccn, &fMaxVel);

	MOT_SetVelParams(83813314, fMinVel, fAccn, fMaxVel);

	MOT_MoveHome(83813314, TRUE);

	MOT_MoveRelativeEx(83813314, 1.0f, TRUE);

	MOT_MoveAbsoluteEx(83813314, 3.0f, TRUE);

	APTCleanUp();

    return 0;   // thread completed successfully
}

void CAPTDLLClientDlg::OnBnClickedInitdll()
{
	// TODO: Add your control notification handler code here
	APTInit();
}

void CAPTDLLClientDlg::OnBnClickedCleandll()
{
	// TODO: Add your control notification handler code here
	APTCleanUp();
}

void CAPTDLLClientDlg::OnBnClickedBtngetnumhwunitsex()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	GetNumHWUnitsEx(m_ledtHWType,&m_lNumHWUnits);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtngethwsernumex()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	GetHWSerialNumEx(m_ledtHWType,m_ledtIndex, &m_ledtHWSerialNum);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtninithwdevice()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	
	InitHWDevice(m_ledtHWSerialNum);

	//UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnllsetenccount()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_LLSetEncoderCount(m_ledtHWSerialNum, m_lEncCount);
}

void CAPTDLLClientDlg::OnBnClickedBtnllgetenccount()
{
	UpdateData(TRUE);

	MOT_LLGetEncoderCount(m_ledtHWSerialNum, &m_lEncCount);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetvelparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetVelParams(m_ledtHWSerialNum, m_fedtMinVel, m_fedtAccn, m_fedtMaxVel);

	//UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtngetvelparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetVelParams(m_ledtHWSerialNum, &m_fedtMinVel, &m_fedtAccn, &m_fedtMaxVel);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtngetstatusbits()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetStatusBits(m_ledtHWSerialNum, &m_ledtStatusBits);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnhome()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_MoveHome(m_ledtHWSerialNum, TRUE);
}

void CAPTDLLClientDlg::OnBnClickedBtnmoverelex()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_MoveRelativeEx(m_ledtHWSerialNum, m_fedtRelDist, TRUE);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpos()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetPosition(m_ledtHWSerialNum, &m_fedtPosition);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnmoveabsex()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_MoveAbsoluteEx(m_ledtHWSerialNum, m_fedtAbsPos, TRUE);
}

void CAPTDLLClientDlg::OnBnClickedBtnidentify()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_Identify(m_ledtHWSerialNum);
}

void CAPTDLLClientDlg::OnBnClickedBtnenablehwchan()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_EnableHWChannel(m_ledtHWSerialNum);
}

void CAPTDLLClientDlg::OnBnClickedBtndisablehwchan()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_DisableHWChannel(m_ledtHWSerialNum);
}

void CAPTDLLClientDlg::OnBnClickedBtnsethomeparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetHomeParams(m_ledtHWSerialNum, m_ledtHomeDirection, m_ledtHomeLimSwitch, m_fedtHomeVel, m_fedtZeroOffset);
}

void CAPTDLLClientDlg::OnBnClickedBtngethomeparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetHomeParams(m_ledtHWSerialNum, &m_ledtHomeDirection, &m_ledtHomeLimSwitch, &m_fedtHomeVel, &m_fedtZeroOffset);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtngethwinfo()
{
	// TODO: Add your control notification handler code here

	TCHAR szModel[255];
	TCHAR szSWVer[255];
	TCHAR szHWNotes[255];

	UpdateData(TRUE);

	GetHWInfo(m_ledtHWSerialNum, szModel, 255, szSWVer, 255, szHWNotes, 255);

	m_edtModel = szModel;
	m_edtSWVer = szSWVer;
	m_edtHWNotes = szHWNotes;

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnmovevelocity()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_MoveVelocity(m_ledtHWSerialNum, m_ledtVelDirection);
}

void CAPTDLLClientDlg::OnBnClickedBtnstopprofiled()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_StopProfiled(m_ledtHWSerialNum);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetchan()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetChannel(m_ledtHWSerialNum,m_ledtChanID);
}

void CAPTDLLClientDlg::OnBnClickedBtndisableeventdlg()
{
	// TODO: Add your control notification handler code here
	EnableEventDlg(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnenableeventdlg()
{
	// TODO: Add your control notification handler code here
	EnableEventDlg(TRUE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetblashdist()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_SetBLashDist(m_ledtHWSerialNum, m_fedtBLashDist);
}

void CAPTDLLClientDlg::OnBnClickedBtngetblashdist()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_GetBLashDist(m_ledtHWSerialNum, &m_fedtBLashDist);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetmotorparams()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_SetMotorParams(m_ledtHWSerialNum, m_ledtStepsPerRev, m_ledtGearboxRatio);
}

void CAPTDLLClientDlg::OnBnClickedBtngetmotorparams()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_GetMotorParams(m_ledtHWSerialNum, &m_ledtStepsPerRev, &m_ledtGearboxRatio);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetstageaxisinfo()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_SetStageAxisInfo(m_ledtHWSerialNum, m_fedtStageMinPos, m_fedtStageMaxPos, m_ledtStageUnits, m_fedtStagePitch);
}

void CAPTDLLClientDlg::OnBnClickedBtngetstageaxisinfo()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_GetStageAxisInfo(m_ledtHWSerialNum, &m_fedtStageMinPos, &m_fedtStageMaxPos, &m_ledtStageUnits, &m_fedtStagePitch);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsethwlimswitches()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetHWLimSwitches(m_ledtHWSerialNum, m_lRevLimSwitch, m_lFwdLimSwitch);
}

void CAPTDLLClientDlg::OnBnClickedBtngethwlimswitches()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_GetHWLimSwitches(m_ledtHWSerialNum, &m_lRevLimSwitch, &m_lFwdLimSwitch);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetdcpidparams()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_SetPIDParams(m_ledtHWSerialNum, m_ledtDCPIDProp, m_ledtDCPIDInt, m_ledtDCPIDDeriv, m_ledtDCPIDIntLim);
}

void CAPTDLLClientDlg::OnBnClickedBtngetdcpidparams()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	MOT_GetPIDParams(m_ledtHWSerialNum, &m_ledtDCPIDProp, &m_ledtDCPIDInt, &m_ledtDCPIDDeriv, &m_ledtDCPIDIntLim);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtngetvelparamlimits()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetVelParamLimits(m_ledtHWSerialNum, &m_fedtMaxVelLim, &m_fedtMaxAccnLim);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdcurrloopparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCCurrentLoopParams(m_ledtHWSerialNum, m_ledtPMDCurrProp, m_ledtPMDCurrInt, m_ledtPMDCurrIntLim, m_ledtPMDCurrIntDeadBand, m_ledtPMDCurrFeedFwd);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdcurrloopparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCCurrentLoopParams(m_ledtHWSerialNum, &m_ledtPMDCurrProp, &m_ledtPMDCurrInt, &m_ledtPMDCurrIntLim, &m_ledtPMDCurrIntDeadBand, &m_ledtPMDCurrFeedFwd);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdposloopparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCPositionLoopParams(m_ledtHWSerialNum, m_ledtPMDPosProp, m_ledtPMDPosInt, m_ledtPMDPosIntLim,
								m_ledtPMDPosDeriv, m_ledtPMDPosDerivTime, m_ledtPMDPosLoopGain, m_ledtPMDPosVelFFwd,
								m_ledtPMDPosAccFFwd, m_ledtPMDPosErrLim);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdposloopparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCPositionLoopParams(m_ledtHWSerialNum, &m_ledtPMDPosProp, &m_ledtPMDPosInt, &m_ledtPMDPosIntLim,
								&m_ledtPMDPosDeriv, &m_ledtPMDPosDerivTime, &m_ledtPMDPosLoopGain, &m_ledtPMDPosVelFFwd,
								&m_ledtPMDPosAccFFwd, &m_ledtPMDPosErrLim);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdcurrloopparams2()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCSettledCurrentLoopParams(m_ledtHWSerialNum, m_ledtPMDCurrProp2, m_ledtPMDCurrInt2, m_ledtPMDCurrIntLim2, m_ledtPMDCurrIntDeadBand2, m_ledtPMDCurrFeedFwd2);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdcurrloopparams2()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCSettledCurrentLoopParams(m_ledtHWSerialNum, &m_ledtPMDCurrProp2, &m_ledtPMDCurrInt2, &m_ledtPMDCurrIntLim2, &m_ledtPMDCurrIntDeadBand2, &m_ledtPMDCurrFeedFwd2);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdmotoroutputparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCMotorOutputParams(m_ledtHWSerialNum, m_fedtPMDContCurrLimit, m_fedtPMDEnergyLimit, m_fedtPMDMotorLimit, m_fedtPMDMotorBias);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdmotoroutputparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCMotorOutputParams(m_ledtHWSerialNum, &m_fedtPMDContCurrLimit, &m_fedtPMDEnergyLimit, &m_fedtPMDMotorLimit, &m_fedtPMDMotorBias);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdtracksettleparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCTrackSettleParams(m_ledtHWSerialNum, m_ledtPMDSettleTime, m_ledtPMDSettleWnd, m_ledtTrackWnd);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdtracksettleparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCTrackSettleParams(m_ledtHWSerialNum, &m_ledtPMDSettleTime, &m_ledtPMDSettleWnd, &m_ledtTrackWnd);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdprofilemodeparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCProfileModeParams(m_ledtHWSerialNum, m_ledtPMDProfileMode, m_fedtPMDJerk);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdprofilemodeparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCProfileModeParams(m_ledtHWSerialNum, &m_ledtPMDProfileMode, &m_fedtPMDJerk);

	UpdateData(FALSE);
}

void CAPTDLLClientDlg::OnBnClickedBtnsetpmdjoystickparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_SetDCJoystickParams(m_ledtHWSerialNum, m_fedtPMDMaxVelLo, m_fedtPMDMaxVelHi, m_fedtPMDAccnLo, m_fedtPMDAccnHi, m_ledtPMDDirSense);
}

void CAPTDLLClientDlg::OnBnClickedBtngetpmdjoystickparams()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	MOT_GetDCJoystickParams(m_ledtHWSerialNum, &m_fedtPMDMaxVelLo, &m_fedtPMDMaxVelHi, &m_fedtPMDAccnLo, &m_fedtPMDAccnHi, &m_ledtPMDDirSense);

	UpdateData(FALSE);
}


void CAPTDLLClientDlg::OnBnClickedBtnclear()
{
	// TODO: Add your control notification handler code here
}


