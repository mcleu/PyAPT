// APTDLLClientDlg.h : header file
//

#pragma once

// CAPTDLLClientDlg dialog
class CAPTDLLClientDlg : public CDialog
{
// Construction
public:
	CAPTDLLClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_APTDLLCLIENT_DIALOG };

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
	afx_msg void OnBnClickedBtnstartthread();

	//UINT MyThreadProc(LPVOID pParam);

	afx_msg void OnBnClickedGethandle();
	afx_msg void OnBnClickedKillhandle();
	afx_msg void OnBnClickedInitdll();
	afx_msg void OnBnClickedCleandll();
	afx_msg void OnBnClickedBtngetnumhwunitsex();
	long m_ledtHWType;
	long m_lNumHWUnits;
	long m_ledtHWSerialNum;
	afx_msg void OnBnClickedBtninithwdevice();
	float m_fedtMinVel;
	float m_fedtAccn;
	float m_fedtMaxVel;
	afx_msg void OnBnClickedBtnsetvelparams();
	afx_msg void OnBnClickedBtngetvelparams();
	long m_ledtStatusBits;
	afx_msg void OnBnClickedBtngetstatusbits();
	afx_msg void OnBnClickedBtnhome();
	float m_fedtRelDist;
	afx_msg void OnBnClickedBtnmoverelex();
	float m_fedtPosition;
	afx_msg void OnBnClickedBtngetpos();
	float m_fedtAbsPos;
	afx_msg void OnBnClickedBtnmoveabsex();
	afx_msg void OnBnClickedBtnidentify();
	afx_msg void OnBnClickedBtnenablehwchan();
	afx_msg void OnBnClickedBtndisablehwchan();
	long m_ledtHomeDirection;
	long m_ledtHomeLimSwitch;
	float m_fedtHomeVel;
	float m_fedtZeroOffset;
	afx_msg void OnBnClickedBtnsethomeparams();
	afx_msg void OnBnClickedBtngethomeparams();
	long m_ledtIndex;
	afx_msg void OnBnClickedBtngethwsernumex();
	CString m_edtModel;
	CString m_edtSWVer;
	CString m_edtHWNotes;
	afx_msg void OnBnClickedBtngethwinfo();
	afx_msg void OnBnClickedBtnmovevelocity();
	afx_msg void OnBnClickedBtnstopprofiled();
	long m_ledtVelDirection;
	long m_ledtChanID;
	afx_msg void OnBnClickedBtnsetchan();
	afx_msg void OnBnClickedBtndisableeventdlg();
	afx_msg void OnBnClickedBtnenableeventdlg();
	float m_fedtBLashDist;
	afx_msg void OnBnClickedBtnsetblashdist();
	afx_msg void OnBnClickedBtngetblashdist();
	long m_ledtStepsPerRev;
	long m_ledtGearboxRatio;
	afx_msg void OnBnClickedBtnsetmotorparams();
	afx_msg void OnBnClickedBtngetmotorparams();
	float m_fedtStageMinPos;
	float m_fedtStageMaxPos;
	long m_ledtStageUnits;
	float m_fedtStagePitch;
	afx_msg void OnBnClickedBtnsetstageaxisinfo();
	afx_msg void OnBnClickedBtngetstageaxisinfo();
	long m_lRevLimSwitch;
	long m_lFwdLimSwitch;
	afx_msg void OnBnClickedBtnsethwlimswitches();
	afx_msg void OnBnClickedBtngethwlimswitches();
	long m_ledtDCPIDProp;
	long m_ledtDCPIDInt;
	long m_ledtDCPIDDeriv;
	long m_ledtDCPIDIntLim;
	afx_msg void OnBnClickedBtnsetdcpidparams();
	afx_msg void OnBnClickedBtngetdcpidparams();
	afx_msg void OnBnClickedBtngetvelparamlimits();
	float m_fedtMaxVelLim;
	float m_fedtMaxAccnLim;
	afx_msg void OnBnClickedBtnsetpmdcurrloopparams();
	afx_msg void OnBnClickedBtngetpmdcurrloopparams();

	long m_ledtPMDCurrProp;
	long m_ledtPMDCurrInt;
	long m_ledtPMDCurrIntLim;
	long m_ledtPMDCurrIntDeadBand;
	long m_ledtPMDCurrFeedFwd;
	afx_msg void OnBnClickedBtnsetpmdposloopparams();
	afx_msg void OnBnClickedBtngetpmdposloopparams();
	long m_ledtPMDPosProp;
	long m_ledtPMDPosInt;
	long m_ledtPMDPosIntLim;
	long m_ledtPMDPosDeriv;
	long m_ledtPMDPosDerivTime;
	long m_ledtPMDPosLoopGain;
	long m_ledtPMDPosVelFFwd;
	long m_ledtPMDPosAccFFwd;
	long m_ledtPMDPosErrLim;
	afx_msg void OnBnClickedBtnsetpmdcurrloopparams2();
	afx_msg void OnBnClickedBtngetpmdcurrloopparams2();
	long m_ledtPMDCurrProp2;
	long m_ledtPMDCurrInt2;
	long m_ledtPMDCurrIntLim2;
	long m_ledtPMDCurrIntDeadBand2;
	long m_ledtPMDCurrFeedFwd2;
	afx_msg void OnBnClickedBtnsetpmdmotoroutputparams();
	afx_msg void OnBnClickedBtngetpmdmotoroutputparams();
	float m_fedtPMDContCurrLimit;
	float m_fedtPMDEnergyLimit;
	float m_fedtPMDMotorLimit;
	float m_fedtPMDMotorBias;
	long m_ledtPMDSettleTime;
	long m_ledtPMDSettleWnd;
	long m_ledtTrackWnd;
	afx_msg void OnBnClickedBtnsetpmdtracksettleparams();
	afx_msg void OnBnClickedBtngetpmdtracksettleparams();
	afx_msg void OnBnClickedBtngetpmdprofilemodeparams();
	afx_msg void OnBnClickedBtnsetpmdprofilemodeparams();
	long m_ledtPMDProfileMode;
	float m_fedtPMDJerk;
	afx_msg void OnBnClickedBtnsetpmdjoystickparams();
	afx_msg void OnBnClickedBtngetpmdjoystickparams();
	float m_fedtPMDMaxVelLo;
	float m_fedtPMDMaxVelHi;
	float m_fedtPMDAccnLo;
	float m_fedtPMDAccnHi;
	long m_ledtPMDDirSense;
//	CMg17loggerctrl1 m_APTLogger;
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnBnClickedBtnllsetenccount();
	afx_msg void OnBnClickedBtnllgetenccount();
	long m_lEncCount;
};
