#if !defined(AFX_PAGE1_H__8F750307_45AC_4EBC_AD46_0703F8813EAB__INCLUDED_)
#define AFX_PAGE1_H__8F750307_45AC_4EBC_AD46_0703F8813EAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAGE1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPAGE1 dialog

class CPAGE1 : public CDialog
{
// Construction
public:
	CPAGE1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPAGE1)
	enum { IDD = PAGE1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPAGE1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPAGE1)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__8F750307_45AC_4EBC_AD46_0703F8813EAB__INCLUDED_)
