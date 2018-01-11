// Goband5Dlg.h : header file
//

#if !defined(AFX_GOBAND5DLG_H__8A018133_6702_4FAA_A1CB_C466420AA3CC__INCLUDED_)
#define AFX_GOBAND5DLG_H__8A018133_6702_4FAA_A1CB_C466420AA3CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGoband5Dlg dialog

class CGoband5Dlg : public CDialog
{
// Construction
public:
	void InitBoard();
	int checkWin(int x,int y);
	int rank[256][2];
	int board[16][16];
	int i;
	int j;
	int blackNum;
	int whiteNum;
	int count;
	CGoband5Dlg(CWnd* pParent = NULL);
	int colorJudge;
	int blackFrac;
	int whiteFrac;
//	bool judge;// standard constructor

// Dialog Data
	//{{AFX_DATA(CGoband5Dlg)
	enum { IDD = IDD_GOBAND5_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoband5Dlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGoband5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBAND5DLG_H__8A018133_6702_4FAA_A1CB_C466420AA3CC__INCLUDED_)
