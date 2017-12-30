// Goband5.h : main header file for the GOBAND5 application
//

#if !defined(AFX_GOBAND5_H__C1370E8C_0771_462F_B84E_CC8B89A793EF__INCLUDED_)
#define AFX_GOBAND5_H__C1370E8C_0771_462F_B84E_CC8B89A793EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGoband5App:
// See Goband5.cpp for the implementation of this class
//

class CGoband5App : public CWinApp
{
public:
	CGoband5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoband5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGoband5App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBAND5_H__C1370E8C_0771_462F_B84E_CC8B89A793EF__INCLUDED_)
