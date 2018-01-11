#if !defined(AFX_PAGE2_H__A701D890_F923_4347_A198_57A70F742C7D__INCLUDED_)
#define AFX_PAGE2_H__A701D890_F923_4347_A198_57A70F742C7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAGE2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPAGE2 dialog

class CPAGE2 : public CDialog
{
// Construction
public:
	CPAGE2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPAGE2)
	enum { IDD = PAGE2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPAGE2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPAGE2)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__A701D890_F923_4347_A198_57A70F742C7D__INCLUDED_)
