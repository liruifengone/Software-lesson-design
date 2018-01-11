// PAGE2.cpp : implementation file
//

#include "stdafx.h"
#include "Goband5.h"
#include "PAGE2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPAGE2 dialog


CPAGE2::CPAGE2(CWnd* pParent /*=NULL*/)
	: CDialog(CPAGE2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPAGE2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPAGE2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPAGE2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPAGE2, CDialog)
	//{{AFX_MSG_MAP(CPAGE2)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPAGE2 message handlers

void CPAGE2::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	LOGFONT logfont;
	ZeroMemory(&logfont,sizeof(LOGFONT));
	strcpy(logfont.lfFaceName,"华文行楷");
	logfont.lfCharSet = GB2312_CHARSET;
	logfont.lfHeight = 110;
	HFONT hFont = CreateFontIndirect(&logfont);
	SelectObject(dc,hFont);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,0));
	dc.TextOut(0,0,"白方");
	dc.TextOut(160,80,"胜利");
}
