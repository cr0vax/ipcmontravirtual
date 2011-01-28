
// MontraVirutalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MontraVirutal.h"
#include "MontraVirutalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMontraVirutalDlg dialog




CMontraVirutalDlg::CMontraVirutalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMontraVirutalDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_left_id = 0;
	m_center_id = 1;
	m_right_id = 2;
}

void CMontraVirutalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CENTER_IMAGE, m_images);
	DDX_Control(pDX, IDC_LEFT_IMAGE, m_left);
	DDX_Control(pDX, IDC_CENTER_IMAGE, m_center);
	DDX_Control(pDX, IDC_RIGHTIMAGE, m_right);
}

BEGIN_MESSAGE_MAP(CMontraVirutalDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_ACTIVATE()
//	ON_WM_SHOWWINDOW()
	ON_WM_CREATE()
//	ON_STN_CLICKED(IDC_CENTER_IMAGE, &CMontraVirutalDlg::OnClickedCenterImage)
//	ON_STN_DBLCLK(IDC_CENTER_IMAGE, &CMontraVirutalDlg::OnStnDblclickCenterImage)
//	ON_STN_CLICKED(IDC_CENTER_IMAGE, &CMontraVirutalDlg::OnStnClickedCenterImage)
	ON_BN_CLICKED(IDC_BUTTON1, &CMontraVirutalDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMontraVirutalDlg message handlers

BOOL CMontraVirutalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	ShowWindow(SW_SHOWMAXIMIZED);

	// array de fotos
	m_images[0] = IDB_TV;
	m_images[1] = IDB_TELEMOVEL;
	m_images[2] = IDB_CAMARA;
	m_images[3] = IDB_CPU;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMontraVirutalDlg::OnPaint()
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
HCURSOR CMontraVirutalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMontraVirutalDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CBitmap Bmpl;
	CBitmap Bmpc;
	CBitmap Bmpr;

	Bmpl.LoadBitmap(m_images[m_left_id]);
	// update image
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[m_center_id]);
	// update image
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images[m_right_id]);
	// update image
	m_right.SetBitmap(Bmpr);

	// update image id for next image
	if (m_left_id == 3) {
		// if it reaches maximum returns to 0
		m_left_id = 0;
    }
	else {
		m_left_id = m_left_id + 1;
	}

	// update image id for next image
	if (m_center_id == 3) {
		// if it reaches maximum returns to 0
		m_center_id = 0;
    }
	else {
		m_center_id = m_center_id + 1;
	}

	// update image id for next image
	if (m_right_id == 3) {
		// if it reaches maximum returns to 0
		m_right_id = 0;
    }
	else {
		m_right_id = m_right_id + 1;
	}
	UpdateData(TRUE);
	UpdateData(FALSE);
}
