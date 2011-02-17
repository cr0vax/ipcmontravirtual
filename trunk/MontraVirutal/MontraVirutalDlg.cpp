
// MontraVirutalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MontraVirutal.h"
#include "MontraVirutalDlg.h"
#include "MontraVirtualDlg2.h"
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
	m_timer = 1;
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
	DDX_Control(pDX, IDC_GIF_LEFT_ANIMATION, m_left_hand);
	DDX_Control(pDX, IDC_GIF_LEFT_ANIMATION2, m_left_hand2);
	DDX_Control(pDX, IDC_GIF_RIGHT_ANIMATION, m_right_hand);
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
	ON_WM_ERASEBKGND()
//	ON_WM_TIMER()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_DETAILS, &CMontraVirutalDlg::OnBnClickedDetails)
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

	// timer
	this->SetTimer(m_timer, 60000, 0);

	ShowWindow(SW_SHOWMAXIMIZED);

	// array de fotos
	m_images[0] = IDB_TV;
	m_images[1] = IDB_TELEMOVEL;
	m_images[2] = IDB_CAMARA;
	m_images[3] = IDB_CPU;
	m_images[4] = IDB_ASPIRADOR;

	// array de fotos
	m_images_b[0] = IDB_TV_B;
	m_images_b[1] = IDB_TELEMOVEL_B;
	m_images_b[2] = IDB_CAMARA_B;
	m_images_b[3] = IDB_CPU_B;
	m_images_b[4] = IDB_ASPIRADOR_B;

	// array de descrições
	m_descrptions_1[0] = "TV";
	m_descrptions_1[1] = "TELEMOVEL";
	m_descrptions_1[2] = "CAMARA";
	m_descrptions_1[3] = "CPU";
	m_descrptions_1[4] = "ASPIRADOR";

	m_descrptions_2[0] = "SAMSUNG 32";
	m_descrptions_2[1] = "BLACKBERRY BOLD 9700";
	m_descrptions_2[2] = "SONY ZOOM OPTICO 45X";
	m_descrptions_2[3] = "INTEL PENTIUM 5.5 GB";
	m_descrptions_2[4] = "LG 2500W";

	m_descrptions_3[0] = "390€";
	m_descrptions_3[1] = "150€";
	m_descrptions_3[2] = "350€";
	m_descrptions_3[3] = "250€";
	m_descrptions_3[4] = "55€";

	// iniciar fotos
	Bmpl.LoadBitmap(m_images_b[0]);
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[1]);
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images_b[2]);
	m_right.SetBitmap(Bmpr);

	// iniciar descrições
	m_description_1.SetWindowText(m_descrptions_1[1]);
	m_description_2.SetWindowText(m_descrptions_2[1]);
	m_description_3.SetWindowText(m_descrptions_3[1]);

	// definir tipos de letra
	CFont *m_Font1 = new CFont;
	m_Font1->CreatePointFont(196, "Arial Bold");

	CFont *m_Font2 = new CFont;
	m_Font2->CreatePointFont(384, "Arial Bold");

	m_description_1.SetFont(m_Font1);
	m_description_2.SetFont(m_Font1);
	m_description_3.SetFont(m_Font2);


	// hands
	if (m_left_hand.Load(_T("res/hands_left.gif")))
		m_left_hand.Draw();

	if (m_left_hand2.Load(_T("res/hands_left.gif")))
		m_left_hand2.Draw();

	if (m_right_hand.Load(_T("res/hands_right.gif")))
		m_right_hand.Draw();


	
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
	// rodar para a esquerda
	rotateLeft();

	// esconder maos
	hideHands(SW_HIDE);

	// definir timer
	timer(1);

}


void CMontraVirutalDlg::OnBnClickedButtonRight()
{
	// rodar para a direita
	rotateRight();

	// esconder maos
	hideHands(SW_HIDE);

	// definir timer
	timer(1);
	
}

void CMontraVirutalDlg::timer(int iType)
{
	KillTimer(iType);

	if (iType == 2)
	{
		this->SetTimer(1, 60000, 0);
		m_timer = 1;
	}
	else
	{
		this->SetTimer(2, 300000, 0);
		m_timer = 2;
	}
	
}

void CMontraVirutalDlg::OnTimer(UINT_PTR nIDEvent)
{
	// set timer
	if (m_timer == 2)
	{
		timer(m_timer);

		// mostra as mãos
		hideHands(SW_SHOW);
	}

	// rotate left
	rotateLeft();
	
	CDialogEx::OnTimer(nIDEvent);
}

void CMontraVirutalDlg::hideHands(int iShow)
{
	// esconder maos
	m_left_hand.ShowWindow(iShow);
	m_right_hand.ShowWindow(iShow);
}

void CMontraVirutalDlg::rotateLeft()
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
	Bmpl.LoadBitmap(m_images_b[m_left_id]);
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[m_center_id]);
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images_b[m_right_id]);
	m_right.SetBitmap(Bmpr);

	// atualizar descrições
	m_description_1.SetWindowText(m_descrptions_1[m_center_id]);
	m_description_2.SetWindowText(m_descrptions_2[m_center_id]);
	m_description_3.SetWindowText(m_descrptions_3[m_center_id]);
}

void CMontraVirutalDlg::rotateRight()
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
	Bmpl.LoadBitmap(m_images_b[m_left_id]);
	m_left.SetBitmap(Bmpl);

	Bmpc.LoadBitmap(m_images[m_center_id]);
	m_center.SetBitmap(Bmpc);

	Bmpr.LoadBitmap(m_images_b[m_right_id]);
	m_right.SetBitmap(Bmpr);

	// atualizar descrições
	m_description_1.SetWindowText(m_descrptions_1[m_center_id]);
	m_description_2.SetWindowText(m_descrptions_2[m_center_id]);
	m_description_3.SetWindowText(m_descrptions_3[m_center_id]);

}

void CMontraVirutalDlg::OnBnClickedDetails()
{
	MontraVirtualDlg2 dlg;

	dlg.SetProduto(m_descrptions_1[m_center_id]);

	OnOK(); //Fecha a actual

	dlg.DoModal(); //Chama a nova
}

BOOL CMontraVirutalDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(67, 192, 230));
	CBrush *pOld = pDC ->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);
	return bRes;
}

