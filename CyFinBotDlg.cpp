
// CyFinBotDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CyFinBot.h"
#include "CyFinBotDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCyFinBotDlg dialog

#pragma comment(lib,"AutoUpdate.lib")
#include "AutoUpdate_DEF.h"



CCyFinBotDlg::CCyFinBotDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CYFINBOT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCyFinBotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCyFinBotDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_CHECKFORUPDATES, &CCyFinBotDlg::OnCheckforupdates)
	ON_COMMAND(ID_EXCHANGE_BYBIT, &CCyFinBotDlg::OnExchangeBybit)
END_MESSAGE_MAP()


// CCyFinBotDlg message handlers

BOOL CCyFinBotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// ���α׷� ���۽� ��������. 
	CheckForUpdate_AutoUpdate(1); //1 �ǹ� : ���� �Ұ� ���� ��� ���� â �ڵ����� �ݱ� ó����. 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCyFinBotDlg::OnPaint()
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
HCURSOR CCyFinBotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCyFinBotDlg::OnCheckforupdates()
{
	CheckForUpdate_AutoUpdate(0);
}


void CCyFinBotDlg::OnExchangeBybit()
{
	

	// ����� PC �� ũ�� �ִ� ��쿡�� �Ʒ� ���� ���������� ũ�� �����Ű�� �ִ�.  ũ�� ���ٸ� ��ȯ�� ���� �ִٸ�, �⺻ ������ ����ǰ� �ϸ� �ɰ���  
	HINSTANCE h_inst_retv = ShellExecute(NULL, _T("open"), _T("chrome.exe"), _T("https://partner.bybit.com/b/igotit"), _T(""), SW_SHOW);
	
	if ((INT_PTR)h_inst_retv > 32) //  success
	{
	}
	else // chrome �� ��ġ�Ǿ����� ���� ��� ERROR_FILE_NOT_FOUND ��ȯ�Ǹ� ��Ÿ����� ���� �߻��� 32������ ���� ����.��·�� �̰ɷ� �����ϸ� �Ʒ� ����
	{
		ShellExecute(NULL, _T("open"), _T("https://partner.bybit.com/b/igotit"), _T(""), _T(""), SW_SHOW);// PC �� ������ �⺻ ������ ������ ��. 
	}

}

	
