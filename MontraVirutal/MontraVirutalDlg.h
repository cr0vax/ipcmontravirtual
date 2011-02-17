
// MontraVirutalDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "PictureEx.h"


// CMontraVirutalDlg dialog
class CMontraVirutalDlg : public CDialogEx
{
// Construction
public:
	CMontraVirutalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MONTRAVIRUTAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:

	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void rotateLeft();
	void rotateRight();
	void hideHands(int iShow);
	void timer(int iType);

	CStatic m_left;
	CStatic m_center;
	CStatic m_right;

	CStatic m_description_1;
	CStatic m_description_2;
	CStatic m_description_3;

	// array de imagens
	int m_images[5];
	int m_images_b[5];

	// arrays de descrições
	CString m_descrptions_1[5];
	CString m_descrptions_2[5];
	CString m_descrptions_3[5];

	int m_left_id;
	int m_center_id;
	int m_right_id;

	int m_timer;

	CPictureEx m_left_hand;
	CPictureEx m_right_hand;	
	CPictureEx m_left_hand2;
	afx_msg void OnBnClickedDetails();

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
