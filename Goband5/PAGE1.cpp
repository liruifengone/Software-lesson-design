// PAGE1.cpp : implementation file
//

#include "stdafx.h"
#include "Goband5.h"
#include "PAGE1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPAGE1 dialog


CPAGE1::CPAGE1(CWnd* pParent /*=NULL*/)
	: CDialog(CPAGE1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPAGE1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPAGE1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPAGE1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPAGE1, CDialog)
	//{{AFX_MSG_MAP(CPAGE1)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPAGE1 message handlers

void CPAGE1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	LOGFONT logfont;
	ZeroMemory(&logfont,sizeof(LOGFONT));
	strcpy(logfont.lfFaceName,"华文行楷");
	logfont.lfCharSet = GB2312_CHARSET;
	logfont.lfHeight = 110;
	HFONT hFont = CreateFontIndirect(&logfont);
	SelectObject(dc,hFont);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,0));
	dc.TextOut(0,0,"黑方");
	dc.TextOut(160,80,"胜利");
/*	CRect rect;
	GetClientRect(&rect);
	CDC dcBMP;
	dcBMP.CreateCompatibleDC(&dc);
	CBitmap bmpBackGround;
	bmpBackGround.LoadBitmap(IDB_BITMAP16);
	BITMAP m_bitmap;
	bmpBackGround.GetBitmap(&m_bitmap);
	CBitmap *pbmpOld = dcBMP.SelectObject(&bmpBackGround);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBMP,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);

*/	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
