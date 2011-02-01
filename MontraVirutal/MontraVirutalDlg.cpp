
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
	DDX_Control(pDX, IDC_DESCRPTION_1, m_description_1);
	DDX_Control(pDX, IDC_DESCRPTION_2, m_description_2);
	DDX_Control(pDX, IDC_DESCRPTION_3, m_description_3);
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
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CMontraVirutalDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CMontraVirutalDlg::OnBnClickedButtonRight)
END_MESSAGE_MAP()


// CMontraVirutalDlg message handlers

BOOL CMontraVirutalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CBitmap Bmpl;
	CBitmap Bmpc;
	CBitmap Bmpr;

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
	m_images[4] = IDB_ASPIRADOR;

	// array de descrições
	m_descrptions_1[0] = "TV";
	m_descrptions_1[1] = "TELEMOVEL";
	m_descrptions_1[2] = "CAMARA";
	m_descrptions_1[3] = "CPU";
	m_descrptions_1[4] = "ASPIRADOR";

	m_descrptions_2[0] = "SAMSUNG 32";
	m_descrptions_2[1] = "NOKIA ANDROID";
	m_descrptions_2[2] = "SONY ZOOM OPTICO 45X";
	m_descrptions_2[3] = "INTEL PENTIUM 5.5 GB";
	m_descrptions_2[4] = "LG 2500W";

	m_descrptions_3[0] = "390€";
	m_descrptions_3[1] = "150€";
	m_descrptions_3[2] = "350€";
	m_descrptions_3[3] = "250€";
	m_descrptions_3[4] = "55€";

	// iniciar fotos
	Bmpl.LoadBitmap(m_images[0]);
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[1]);
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images[2]);
	m_right.SetBitmap(Bmpr);

	// iniciar descrições
	m_description_1.SetWindowText(m_descrptions_1[1]);
	m_description_2.SetWindowText(m_descrptions_2[1]);
	m_description_3.SetWindowText(m_descrptions_3[1]);

	// definir tipos de letra
	CFont *m_Font1 = new CFont;
	m_Font1->CreatePointFont(250, "Arial Bold");

	CFont *m_Font2 = new CFont;
	m_Font2->CreatePointFont(500, "Arial Bold");

	m_description_1.SetFont(m_Font1);
	m_description_2.SetFont(m_Font1);
	m_description_3.SetFont(m_Font2);

	
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


void CMontraVirutalDlg::OnBnClickedButtonLeft()
{
	CBitmap Bmpl;
	CBitmap Bmpc;
	CBitmap Bmpr;
	int i_max = sizeof(m_images) / sizeof(int) - 1;

		// update image id for next image
	if (m_left_id == i_max) {
		// if it reaches maximum returns to 0
		m_left_id = 0;
    }
	else {
		m_left_id = m_left_id + 1;
	}

	// update image id for next image
	if (m_center_id == i_max) {
		// if it reaches maximum returns to 0
		m_center_id = 0;
    }
	else {
		m_center_id = m_center_id + 1;
	}

	// update image id for next image
	if (m_right_id == i_max) {
		// if it reaches maximum returns to 0
		m_right_id = 0;
    }
	else {
		m_right_id = m_right_id + 1;
	}
	UpdateData(TRUE);
	UpdateData(FALSE);

	// atualizar imagens
	Bmpl.LoadBitmap(m_images[m_left_id]);
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[m_center_id]);
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images[m_right_id]);
	m_right.SetBitmap(Bmpr);

	// atualizar descrições
	m_description_1.SetWindowText(m_descrptions_1[m_center_id]);
	m_description_2.SetWindowText(m_descrptions_2[m_center_id]);
	m_description_3.SetWindowText(m_descrptions_3[m_center_id]);
}


void CMontraVirutalDlg::OnBnClickedButtonRight()
{
	CBitmap Bmpl;
	CBitmap Bmpc;
	CBitmap Bmpr;
	int i_max = sizeof(m_images) / sizeof(int) - 1;

	// update image id for next image
	if (m_left_id == 0) {
		// if it reaches maximum returns to 0
		m_left_id = i_max;
    }
	else {
		m_left_id = m_left_id - 1;
	}

	// update image id for next image
	if (m_center_id == 0) {
		// if it reaches maximum returns to 0
		m_center_id = i_max;
    }
	else {
		m_center_id = m_center_id - 1;
	}

	// update image id for next image
	if (m_right_id == 0) {
		// if it reaches maximum returns to 0
		m_right_id = i_max;
    }
	else {
		m_right_id = m_right_id - 1;
	}
	UpdateData(TRUE);
	UpdateData(FALSE);

	// atualizar imagens
	Bmpl.LoadBitmap(m_images[m_left_id]);
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[m_center_id]);
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images[m_right_id]);
	m_right.SetBitmap(Bmpr);

	// atualizar descrições
	m_description_1.SetWindowText(m_descrptions_1[m_center_id]);
	m_description_2.SetWindowText(m_descrptions_2[m_center_id]);
	m_description_3.SetWindowText(m_descrptions_3[m_center_id]);

}
