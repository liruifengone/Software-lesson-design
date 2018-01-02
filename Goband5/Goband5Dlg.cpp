// Goband5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Goband5.h"
#include "Goband5Dlg.h"
//#include "cv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WHITE 1
#define BLACK 2

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoband5Dlg dialog

CGoband5Dlg::CGoband5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGoband5Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoband5Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGoband5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoband5Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGoband5Dlg, CDialog)
	//{{AFX_MSG_MAP(CGoband5Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDBack, OnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoband5Dlg message handlers

BOOL CGoband5Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	rank[0][0] = 0;
	for (i=0;i<16;i++)
	{
		for(j = 0;j<16;j++){
			board[i][j] = 0;
		}
	}
	count = 0;
	blackNum = 0;
	whiteNum = 0;

	//MessageBox("�����壬���������ʤ�ƶ�");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGoband5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGoband5Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CPaintDC dc(this);			//���û���
		//���ñ���ͼ��
		CRect rect;
		CRect BlackRect;
		CRect WhiteRect;
		CRect BlackFrac;
		CRect WhiteFrac;
		CRect PromptText;

		BlackRect.SetRect(640,10,790,90);
		WhiteRect.SetRect(640,90,790,170);
		BlackFrac.SetRect(790,10,940,90);
		WhiteFrac.SetRect(790,90,940,170);
		PromptText.SetRect(640,170,940,530);
		GetClientRect(&rect);

		

		CDC blackBMP;
		CDC whiteBMP;
		CDC BlackFracBMP;
		CDC WhiteFracBMP;
		CDC dcBMP;
		CDC PromptBMP;

		dcBMP.CreateCompatibleDC(&dc);
		blackBMP.CreateCompatibleDC(&dc);
		whiteBMP.CreateCompatibleDC(&dc);
		BlackFracBMP.CreateCompatibleDC(&dc);
		WhiteFracBMP.CreateCompatibleDC(&dc);
		PromptBMP.CreateCompatibleDC(&dc);

		CBitmap bmpBackground;
		CBitmap whiteback;
		CBitmap blackback;
		CBitmap blackfracback;
		CBitmap whitefracback;
		CBitmap promptback;

		bmpBackground.LoadBitmap(IDB_BITMAP2);
		blackback.LoadBitmap(IDB_BITMAP5);
		whiteback.LoadBitmap(IDB_BITMAP7);
	//	blackfracback.LoadBitmap();
	//	whitefracback.LoadBitmap();
		promptback.LoadBitmap(IDB_BITMAP11);
	
	
		
		BITMAP m_bitmap;
		BITMAP m_white;
		BITMAP m_black;
	//	BITMAP m_whitefrac;
    //	BITMAP m_blackfrac;
		BITMAP m_prompt;

		bmpBackground.GetBitmap(&m_bitmap);
		whiteback.GetBitmap(&m_white);
		blackback.GetBitmap(&m_black);
	//	blackfracback.GetBitmap(m_blackfrac);
	//	whitefracback.GetBitmap(m_whitefrac);
		promptback.GetBitmap(&m_prompt);

		CBitmap *pbmpOld = dcBMP.SelectObject(&bmpBackground);
		CBitmap *pbblack = blackBMP.SelectObject(&blackback);
		CBitmap *pbwhite = whiteBMP.SelectObject(&whiteback);
		CBitmap *pbwhitefrac = WhiteFracBMP.SelectObject(&whitefracback);
		CBitmap *pbblackfrac = BlackFracBMP.SelectObject(&blackfracback);
		CBitmap *pbprompt = PromptBMP.SelectObject(&promptback);

		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBMP,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);
		dc.StretchBlt(640,10,BlackRect.Width(),BlackRect.Height(),&blackBMP,0,0,m_black.bmWidth,m_black.bmHeight,SRCCOPY);
		dc.StretchBlt(640,90,WhiteRect.Width(),WhiteRect.Height(),&whiteBMP,0,0,m_white.bmWidth,m_black.bmHeight,SRCCOPY);
		dc.StretchBlt(640,170,PromptText.Width(),PromptText.Height(),&PromptBMP,0,0,m_prompt.bmWidth,m_prompt.bmHeight,SRCCOPY);

	
	
		//	dc.StretchBlt(BlackRect.TopLeft().x,WhiteRect.TopLeft().y,WhiteRect.Width(),WhiteRect.Height(),&blackBMP,0,0,m_black.bmWidth,m_black.bmHeight,SRCCOPY);��
		//������
		dc.MoveTo(10,10);
		dc.LineTo(10,610);
		dc.LineTo(610,610);
		dc.LineTo(610,10);
		dc.LineTo(10,10);

		i = 0;
		j = 0;
		for( i = 0;i<15;i++){
			dc.MoveTo(10,40*i+10);
			dc.LineTo(610,40*i+10);
		}
		for( j = 0;j<15;j++){
			dc.MoveTo(40*j+10,10);
			dc.LineTo(40*j+10,610);
		}

		dc.MoveTo(640,10);
		dc.LineTo(940,10);
		dc.LineTo(940,530);
		dc.LineTo(640,530);
		dc.LineTo(640,10);
		dc.MoveTo(640,90);
		dc.LineTo(940,90);
		dc.MoveTo(640,170);
		dc.LineTo(940,170);
		dc.MoveTo(790,10);
		dc.LineTo(790,170);

		i = 0;
		j = 0;
		for ( i = 0;i<16;i++)		//�������ӵİڷ�
		{
			for ( j = 0;j<16;j++)
			{
				if(board[i][j]==WHITE){
					dc.Ellipse(i*40+10-20,j*40+10-20,i*40+10+20,j*40+10+20);
				}else if(board[i][j]==BLACK){
					//�ȴ����û�����ɫ��������ɫ
					CBrush *newBrush,*oldBrush;
					newBrush = new CBrush(RGB(0,0,0));
					oldBrush = dc.SelectObject(newBrush);

					dc.Ellipse(i*40+10-20,j*40+10-20,i*40+10+20,j*40+10+20);

					dc.SelectObject(oldBrush);
					delete newBrush;

				}
			}
		}
		//dc.TextOut(640,10,"hello world");

		
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGoband5Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGoband5Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	i = 0;
	for (i = 0;i<16;i++)
	{
		for (j = 0;j<16;j++)
		{
			if ((point.x - (i*40+10))*(point.x - (i*40+10))+(point.y-(j*40+10))*(point.y-(j*40+10))<=225)
			{
				if (board[i][j]!=0)
				{
					Invalidate();
				}else if (count%BLACK==0)
				{
					board[i][j] = BLACK;
					count++;
					blackNum++;
					rank[count][0] = i;
					rank[count][1] = j;
					Invalidate();
					if(checkWin(i,j))
					{
						/*int answer = MessageBox("���ֱ����ڷ�ʤ��,�׷��Ƿ���Ҫ����","ս��",MB_YESNOCANCEL);
						if (answer == IDOK)
						{
							if (rank[1][0]!=0 && rank[1][1]!=0)
							{
								board[rank[count][0]][rank[count][1]] = 0;
								rank[count][0] = 0;
								rank[count][1] = 0;
								count--;
							}
							Invalidate();
						}else if(answer == IDNO)
						{*/
							if (MessageBox("���ֱ����ڷ�ʤ�����Ƿ�Ҫ����һ��","ϵͳ��Ϣ",MB_YESNOCANCEL) == IDYES)
							{
								InitBoard();
								blackNum++;
								Invalidate();

							}
							
						
					}
				}else if (count%BLACK==WHITE)
				{
					board[i][j] = WHITE;
					count++;
					whiteNum++;
					rank[count][0] = i;
					rank[count][1] = j;
					Invalidate();
					if (checkWin(i,j))
					{
						/*int answer = MessageBox("���ֱ����׷�ʤ�����ڷ��Ƿ���Ҫ����","ս��",MB_YESNOCANCEL);
						if (answer == IDOK)
						{
							if (rank[1][0]!=0 && rank[1][1]!=0)
							{
								board[rank[count][0]][rank[count][1]] = 0;
								rank[count][0] = 0;
								rank[count][1] = 0;
								count--;
							}
							InitBoard();
							Invalidate();
						}else if(answer == IDNO)
						*/
							if (MessageBox("���ֱ����׷�ʤ�����Ƿ�Ҫ����һ��","ϵͳ��Ϣ",MB_YESNOCANCEL) == IDYES)
							{
								InitBoard();
								whiteNum++;
								Invalidate();
							}
						
						
					}
					
				}
			} 
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

//DEL void CGoband5Dlg::OnCancel() 
//DEL {
//DEL 	// TODO: Add extra cleanup here
//DEL 	
//DEL 	CDialog::OnCancel();
//DEL }

void CGoband5Dlg::OnBack() 
{
	// TODO: Add your control notification handler code here
	int CHOICE = MessageBox("�Է���Ҫ���壬�Ƿ�ͬ��","ϵͳ��Ϣ",MB_YESNOCANCEL);
	if(CHOICE == IDYES)
	{
		if (rank[1][0]!=0 && rank[1][1]!=0)//�ж��Ƿ�Ϊ��һ���ӣ�����������
		{
			board[rank[count][0]][rank[count][1]] = 0;
			board[rank[count-1][0]][rank[count-1][1]] = 0;
			rank[count][0] = 0;
			rank[count-1][0] = 0;
			rank[count][1] = 0;
			rank[count-1][1] = 0;
			count-=2;
		}
	}else if(CHOICE == IDNO)
	{
		MessageBox("��Ǹ������Ķ����ƺ���̫Ը���أ�����");
	}
	Invalidate();	
}

//DEL BOOL CGoband5Dlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	lpszWindowName = ""
//DEL 	
//DEL 	return CDialog::Create(IDD, pParentWnd);
//DEL }

//DEL BOOL CGoband5Dlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	CBitmap bitmap;
//DEL 	HBITMAP hBmp;
//DEL 	bitmap.LoadBitmap(IDB_BITMAP5);
//DEL 	hBmp = (HBITMAP)bitmap.GetSafeHandle();
//DEL 	
//DEL 	
//DEL 	return CDialog::Create(IDD, pParentWnd);
//DEL }

//DEL int CGoband5Dlg::checkWin()
//DEL {
//DEL 
//DEL }

int CGoband5Dlg::checkWin(int x, int y)
{//���������µ�һ���������
	
		int total = 1;
		i = 0;
		j = 0;
		for (i = x + 1;board[i][y] == board[x][y];i++)
			total++;
		for (i = x - 1;board[i][y] == board[x][y];i--)
			total++;
		if (total >= 5) 
			return 1;
	//	else 
	//		return 0;//�������������ͬ�ĵ����������5������ֵΪ1����֮Ϊ0
		total = 1;
		for (j = y + 1;board[x][j] == board[x][y];j++)
			total++;
		for (j = y - 1;board[x][j] == board[x][y];j--)
			total++;
		if (total >= 5)
			return 1;//�������������ͬ�ĵ����������5������ֵΪ1
		total = 1;
		for (i = x + 1,j = y + 1;board[i][j] == board[x][y];i++,j++)
			total++;
		for (i = x - 1,j = y - 1;board[i][j] == board[x][y];i--,j--)
			total++;
		if (total >= 5) 
			return 1;//���y=x����������ͬ�ĵ����������5������ֵΪ1
		total = 1;
		for (i = x + 1, j = y - 1;board[i][j] == board[x][y];i++, j--)
			total++;
		for (i = x - 1, j = y + 1;board[i][j] == board[x][y];i--, j++)
			total++;
		if (total >= 5)
			return 1;//���y=-x����������ͬ�ĵ����������5������ֵΪ1
		return 0;

}

void CGoband5Dlg::InitBoard()
{
	for (i = 0;i<16;i++)
	{
		for (j = 0;j<16;j++)
		{
			board[i][j] = 0;
		}
	}
	
	for (i = 0;i<256;i++)
	{
		for (j = 0;j<2;j++)
		{
			rank[i][j] = 0;
		}
	}							
	count = 0;	
}
