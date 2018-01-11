// Goband5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Goband5.h"
#include "Goband5Dlg.h"
#include <string.h>
#include "PAGE1.h"
#include "PAGE2.h"
#include   <mmsystem.h>   
#pragma   comment(lib,   "winmm.lib")   
//#include "cv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WHITE 1
#define BLACK 2
#define INITX 30
#define INITY 30
#define FOUR 3

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
	colorJudge=BLACK;
	whiteFrac = 0;
	blackFrac = 0;

	//MessageBox("五子棋，采用五局三胜制度");
	
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
		
		CPaintDC dc(this);			//设置画笔
		//设置背景图形
		CRect rect;
		CRect BlackRect;
		CRect BoardRect;

		BlackRect.SetRect(660,30,960,550);
		BoardRect.SetRect(20,20,640,640);
		GetClientRect(&rect);

		CDC blackBMP;
		CDC dcBMP;
		CDC BoardBMP;

		dcBMP.CreateCompatibleDC(&dc);
		blackBMP.CreateCompatibleDC(&dc);
		BoardBMP.CreateCompatibleDC(&dc);

		CBitmap bmpBackground;
		CBitmap blackback;
		CBitmap BoardBack;

		bmpBackground.LoadBitmap(IDB_BITMAP17);
		blackback.LoadBitmap(IDB_BITMAP18);
		BoardBack.LoadBitmap(IDB_BITMAP16);
	
		
		BITMAP m_bitmap;
		BITMAP m_black;
		BITMAP m_board;

		bmpBackground.GetBitmap(&m_bitmap);
		blackback.GetBitmap(&m_black);
		BoardBack.GetBitmap(&m_board);

		CBitmap *pbmpOld = dcBMP.SelectObject(&bmpBackground);
		CBitmap *pbblack = blackBMP.SelectObject(&blackback);
		CBitmap *pbBoard = BoardBMP.SelectObject(&BoardBack);

		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBMP,0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY);
		dc.StretchBlt(660,30,BlackRect.Width(),BlackRect.Height(),&blackBMP,0,0,m_black.bmWidth,m_black.bmHeight,SRCCOPY);
		dc.StretchBlt(20,20,BoardRect.Width(),BoardRect.Height(),&BoardBMP,0,0,m_board.bmWidth,m_board.bmHeight,SRCCOPY);
		
		//画格子
		dc.MoveTo(30,30);
		dc.LineTo(30,630);
		dc.LineTo(630,630);
		dc.LineTo(630,30);
		dc.LineTo(30,30);

		i = 0;
		j = 0;
		for( i = 0;i<15;i++){
			dc.MoveTo(30,40*i+30);
			dc.LineTo(630,40*i+30);
		}
		for( j = 0;j<15;j++){
			dc.MoveTo(40*j+30,30);
			dc.LineTo(40*j+30,630);
		}

		dc.MoveTo(660,30);
		dc.LineTo(960,30);
		dc.LineTo(960,550);
		dc.LineTo(660,550);
		dc.LineTo(660,30);
		dc.MoveTo(660,110);
		dc.LineTo(960,110);
		dc.MoveTo(660,190);
		dc.LineTo(960,190);
		dc.MoveTo(810,30);
		dc.LineTo(810,190);

		i = 0;
		j = 0;
		for ( i = 0;i<16;i++)		//设置棋子的摆放
		{
			for ( j = 0;j<16;j++)
			{
				if(board[i][j]==WHITE){
					dc.Ellipse(i*40+30-20,j*40+30-20,i*40+30+20,j*40+30+20);
				}else if(board[i][j]==BLACK){
					//根据位置设置图形的颜色及位置
					CBrush *newBrush,*oldBrush;
					newBrush = new CBrush(RGB(0,0,0));
					oldBrush = dc.SelectObject(newBrush);

					dc.Ellipse(i*40+30-20,j*40+30-20,i*40+30+20,j*40+30+20);

					dc.SelectObject(oldBrush);
					delete newBrush;

				}
			}
		}
		
		LOGFONT logfont;
		ZeroMemory(&logfont,sizeof(LOGFONT));

		strcpy(logfont.lfFaceName,"华文行楷");
		logfont.lfCharSet = GB2312_CHARSET;
		logfont.lfHeight = 70;
		HFONT hFont = CreateFontIndirect(&logfont);
		SelectObject(dc,hFont);
		dc.SetBkMode(TRANSPARENT);
		dc.SetTextColor(RGB(0,0,0));
		dc.TextOut(670,40,"黑方");
		dc.TextOut(670,120,"白方");
		char blackFraction[3] ; 
		itoa(blackFrac,blackFraction,3);
		char whiteFraction[3] ; 
		itoa(whiteFrac,whiteFraction,3);
		dc.TextOut(870,40,blackFraction);
		dc.TextOut(870,120,whiteFraction);

		logfont.lfHeight = 40;
		hFont = CreateFontIndirect(&logfont);
		SelectObject(dc,hFont);
		switch (colorJudge)
		{
		case BLACK:
			dc.TextOut(670,200,"现在由黑方执子");
			break;
		case WHITE:
			dc.TextOut(670,200,"现在由白方执子");
			break;
		case FOUR:
			dc.TextOut(670,200,"对方已有四个棋");
			dc.TextOut(670,250,"子连成一排，请");
			dc.TextOut(670,300,"注意");
			break;
		default:
			break;
		}
		
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
			if ((point.x - (i*40+30))*(point.x - (i*40+30))+(point.y-(j*40+30))*(point.y-(j*40+30))<=225)
			{
			//	PlaySound("C:\\Users\\11736\\Documents\\Tencent Files\\1173686358\\FileRecv\\Visual C++ 6.0(英文专业安装版) (3)\\VC6\MyProjects\\Goband5\\res\\棋子音效d.mp3",NULL,SND_FILENAME | SND_ASYNC);
			//	sndPlaySound("res\5390.wav",SND_ASYNC);
				if (board[i][j]!=0)
				{
					Invalidate();
				}else if (count%BLACK==0)
				{
					colorJudge = WHITE;
					board[i][j] = BLACK;
					count++;
					blackNum++;
					rank[count][0] = i;
					rank[count][1] = j;
					Invalidate();
					int answer = checkWin(i,j);
					if(answer>=5)
					{
						blackFrac++;
						//弹出提示对话框
						CPAGE1 page1;
						page1.DoModal();
							if (MessageBox("本局比赛黑方胜利，是否要再来一局","系统消息",MB_YESNOCANCEL) == IDYES)
							{
								InitBoard();
								blackNum++;
								Invalidate();

							}
							
						
					}else if (answer==4)
					{
						colorJudge = FOUR;
					}

				}else if (count%BLACK==WHITE)
				{
					colorJudge = BLACK;
					board[i][j] = WHITE;
					count++;
					whiteNum++;
					rank[count][0] = i;
					rank[count][1] = j;
					Invalidate();
					int answer = checkWin(i,j);
					if (answer>=5)
					{
					
						whiteFrac++;
						CPAGE2 page2;
						page2.DoModal();
							if (MessageBox("本局比赛白方胜利，是否要再来一局","系统消息",MB_YESNOCANCEL) == IDYES)
							{
								InitBoard();
								whiteNum++;
								Invalidate();
							}
						
						
					}else if (answer==4)
					{
						colorJudge = FOUR;
					}
					
				}
			} 
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CGoband5Dlg::OnBack() 
{
	// TODO: Add your control notification handler code here
	int CHOICE = MessageBox("对方想要悔棋，是否同意","系统消息",MB_YESNOCANCEL);
	if(CHOICE == IDYES)
	{
		//判断是否为第一个子，避免程序崩溃
		if (rank[1][0]!=0 && rank[1][1]!=0 && rank[2][0]!=0 &&rank[2][1]!=0)	
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
		MessageBox("抱歉咯，你的对手似乎不太愿意呢！！！");
	}
	Invalidate();	
}

int CGoband5Dlg::checkWin(int x, int y)
{//输入最新下的一个点的坐标
	
		int maxone = 0;;
		int total = 1;
		i = 0;
		j = 0;
		for (i = x + 1;board[i][y] == board[x][y];i++)
			total++;
		for (i = x - 1;board[i][y] == board[x][y];i--)
			total++;
		maxone = max(maxone,total);
		//如果左右连续相同的点加起来超过5个则函数值为1，反之为0
		total = 1;
		for (j = y + 1;board[x][j] == board[x][y];j++)
			total++;
		for (j = y - 1;board[x][j] == board[x][y];j--)
			total++;
		//如果上下连续相同的点加起来超过5个则函数值为1
		maxone = max(maxone,total);
		total = 1;
		for (i = x + 1,j = y + 1;board[i][j] == board[x][y];i++,j++)
			total++;
		for (i = x - 1,j = y - 1;board[i][j] == board[x][y];i--,j--)
			total++;
		//如果y=x方向连续相同的点加起来超过5个则函数值为1
		maxone = max(maxone,total);
		total = 1;
		for (i = x + 1, j = y - 1;board[i][j] == board[x][y];i++, j--)
			total++;
		for (i = x - 1, j = y + 1;board[i][j] == board[x][y];i--, j++)
			total++;
		//如果y=-x方向连续相同的点加起来超过5个则函数值为1
		maxone = max(maxone,total);
		return maxone;

}

void CGoband5Dlg::InitBoard()
{
	colorJudge = BLACK;
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


//DEL void CGoband5Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	switch(nChar){
//DEL 		case 
//DEL 	}
//DEL 	
//DEL 	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
//DEL }

//DEL int* CGoband5Dlg::AIChess()
//DEL {
//DEL 	int returnNum[4];
//DEL 	for (i=0;i<)
//DEL 	{
//DEL 	}
//DEL }


//此处尝试写AI失败，以下内容已全部注释掉。不必翻
//DEL int CGoband5Dlg::AICalculate(int x, int y)
//DEL {
//DEL 
//DEL 	int Fraction = 0;
//DEL 	int WHITEONE[8] = {0};
//DEL 	int BLACKONE[8] = {0};
//DEL //计算周围棋子的情况
//DEL 	//横右
//DEL 	for (i=1;board[x+i][y]==WHITE;i++  )
//DEL 	{
//DEL 		WHITEONE[0]++;
//DEL 	}
//DEL 	for (i=1;board[x+i][y]==BLACK;i++)
//DEL 	{
//DEL 		BLACKONE[0]++;
//DEL 	}
//DEL 	//横左
//DEL 	for (i=-1;board[x+i][y]==WHITE;i--  )
//DEL 	{
//DEL 		WHITEONE[1]++;
//DEL 	}
//DEL 	for (i=-1;board[x+i][y]==BLACK;i--)
//DEL 	{
//DEL 		BLACKONE[1]++;
//DEL 	}
//DEL 	//竖上
//DEL 	for (i=1;board[x][y+i]==WHITE;i++  )
//DEL 	{
//DEL 		WHITEONE[2]++;
//DEL 	}
//DEL 	for (i=1;board[x][y+i]==BLACK;i++)
//DEL 	{
//DEL 		BLACKONE[2]++;
//DEL 	}
//DEL 	//竖下
//DEL 	for (i=-1;board[x][y+i]==WHITE;i--  )
//DEL 	{
//DEL 		WHITEONE[3]++;
//DEL 	}
//DEL 	for (i=-1;board[x][y+i]==BLACK;i--)
//DEL 	{
//DEL 		BLACKONE[3]++;
//DEL 	}
//DEL 	//右上斜向上
//DEL 	for (i=1,j=1;board[x+i][y]==WHITE;i++,j++  )
//DEL 	{
//DEL 		WHITEONE[4]++;
//DEL 	}
//DEL 	for (i=1,j=1;board[x+i][y]==BLACK;i++,j++)
//DEL 	{
//DEL 		BLACKONE[4]++;
//DEL 	}
//DEL 	//右上斜向下
//DEL 	for (i=-1,j=-1;board[x+i][y+j]==WHITE;i--,j--  )
//DEL 	{
//DEL 		WHITEONE[5]++;
//DEL 	}
//DEL 	for (i=-1,j=-1;board[x+i][y+j]==BLACK;i--,j--)
//DEL 	{
//DEL 		BLACKONE[5]++;
//DEL 	}
//DEL 	//左上斜向上
//DEL 	for (i=1,j=-1;board[x+i][y+j]==WHITE;i++,j--  )
//DEL 	{
//DEL 		WHITEONE[6]++;
//DEL 	}
//DEL 	for (i=1,j=-1;board[x+i][y+j]==BLACK;i++,j--)
//DEL 	{
//DEL 		BLACKONE[6]++;
//DEL 	}
//DEL 	//左上斜向下
//DEL 	for (i=-1,j=1;board[x+i][y+j]==WHITE;i--,j++  )
//DEL 	{
//DEL 		WHITEONE[7]++;
//DEL 	}
//DEL 	for (i=-1,j=1;board[x+i][y+j]==BLACK;i--,j++)
//DEL 	{
//DEL 		BLACKONE[7]++;
//DEL 	}
//DEL //攻
//DEL 	switch(WHITEONE[0]+WHITEONE[1])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (WHITEONE[0]==1)
//DEL 		{
//DEL 			if (board[x+2][y]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		} 
//DEL 		else
//DEL 		{
//DEL 			if (board[x-2][y]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch(WHITEONE[0])
//DEL 		{
//DEL 		case 0:		
//DEL 			if (board[x-3][y]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x-2][y]==BLACK && board[x+2][y]==BLACK)//两端限制
//DEL 			{
//DEL 			} 
//DEL 			else if(board[x-2][y]==0 && board[x+2][y]==0)//两端自由
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction+=50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x+3][y]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch(WHITEONE[0])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x-4][y]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x-3][y]==0 && board[x+2][y]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x-3][y]==BLACK && board[x+2][y]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x-2][y]==0 && board[x+3][y]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x-2][y]==BLACK && board[x+3][y]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x+4][y]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction+=1000;
//DEL 	}
//DEL 
//DEL 	switch(WHITEONE[2]+WHITEONE[3])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (WHITEONE[2]==1)
//DEL 		{
//DEL 			if (board[x][y+2]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		} 
//DEL 		else
//DEL 		{
//DEL 			if (board[x][y-2]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch(WHITEONE[2])
//DEL 		{
//DEL 		case 0:		
//DEL 			if (board[x][y-3]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x][y-2]==BLACK && board[x][y+2]==BLACK)//两端限制
//DEL 			{
//DEL 			} 
//DEL 			else if(board[x][y-2]==0 && board[x][y+2]==0)//两端自由
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction+=50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x][y+3]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch(WHITEONE[2])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x][y-4]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x][y-3]==0 && board[x][y+2]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x][y-3]==BLACK && board[x][y+2]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x][y-2]==0 && board[x][y+3]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x][y-2]==BLACK && board[x][y+3]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x][y+4]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction+=1000;
//DEL 	}
//DEL 
//DEL 	switch(WHITEONE[4]+WHITEONE[5])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (WHITEONE[0]==1)
//DEL 		{
//DEL 			if (board[x+2][y+2]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		} 
//DEL 		else
//DEL 		{
//DEL 			if (board[x-2][y-2]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch(WHITEONE[4])
//DEL 		{
//DEL 		case 0:		
//DEL 			if (board[x-3][y-3]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x-2][y-2]==BLACK && board[x+2][y+2]==BLACK)//两端限制
//DEL 			{
//DEL 			} 
//DEL 			else if(board[x-2][y-2]==0 && board[x+2][y+2]==0)//两端自由
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction+=50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x+3][y+3]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch(WHITEONE[4])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x-4][y-4]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x-3][y-3]==0 && board[x+2][y+2]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x-3][y-3]==BLACK && board[x+2][y+2]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x-2][y-2]==0 && board[x+3][y+3]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x-2][y-2]==BLACK && board[x+3][y+3]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x+4][y+4]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction+=1000;
//DEL 	}
//DEL 
//DEL 	switch(WHITEONE[6]+WHITEONE[7])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (WHITEONE[6]==1)
//DEL 		{
//DEL 			if (board[x+2][y-2]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		} 
//DEL 		else
//DEL 		{
//DEL 			if (board[x-2][y+2]==BLACK)
//DEL 			{
//DEL 				Fraction+=1;
//DEL 			} 
//DEL 			else
//DEL 			{
//DEL 				Fraction+=10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch(WHITEONE[0])
//DEL 		{
//DEL 		case 0:		
//DEL 			if (board[x-3][y+3]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x-2][y+2]==BLACK && board[x+2][y-2]==BLACK)//两端限制
//DEL 			{
//DEL 			} 
//DEL 			else if(board[x-2][y+2]==0 && board[x+2][y-2]==0)//两端自由
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction+=50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x+3][y-3]==BLACK)	//限制两子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			} 
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction+=200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch(WHITEONE[6])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x-4][y+4]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x-3][y+3]==0 && board[x+2][y-2]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x-3][y+3]==BLACK && board[x+2][y-2]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x-2][y+2]==0 && board[x+3][y-3]==0)		//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else if (board[x-2][y+2]==BLACK && board[x+3][y-3]==BLACK)//两端限制
//DEL 			{
//DEL 				Fraction+=0;
//DEL 			}
//DEL 			else{
//DEL 				Fraction+=100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x+4][y-4]==0)//自由三子
//DEL 			{
//DEL 				Fraction+=500;
//DEL 			} 
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction+=100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction+=1000;
//DEL 	}
//DEL //守
//DEL switch (BLACKONE[0] + BLACKONE[1])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (BLACKONE[0] == 1)
//DEL 		{
//DEL 			if (board[x + 2][y] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		else
//DEL 		{
//DEL 			if (board[x - 2][y] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch (BLACKONE[0])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x - 3][y] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x - 2][y] == WHITE && board[x + 2][y] == WHITE)//两端限制
//DEL 			{
//DEL 			}
//DEL 			else if (board[x - 2][y] == 0 && board[x + 2][y] == 0)//两端自由
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction += 50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x + 3][y] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch (BLACKONE[0])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x - 4][y] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x - 3][y] == 0 && board[x + 2][y] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x - 3][y] == WHITE && board[x + 2][y] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x - 2][y] == 0 && board[x + 3][y] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x - 2][y] == WHITE && board[x + 3][y] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x + 4][y] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction += 1000;
//DEL 	}
//DEL 
//DEL 	switch (BLACKONE[2] + BLACKONE[3])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (BLACKONE[2] == 1)
//DEL 		{
//DEL 			if (board[x][y + 2] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		else
//DEL 		{
//DEL 			if (board[x][y - 2] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch (BLACKONE[2])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x][y - 3] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x][y - 2] == WHITE && board[x][y + 2] == WHITE)//两端限制
//DEL 			{
//DEL 			}
//DEL 			else if (board[x][y - 2] == 0 && board[x][y + 2] == 0)//两端自由
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction += 50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x][y + 3] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch (BLACKONE[2])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x][y - 4] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x][y - 3] == 0 && board[x][y + 2] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x][y - 3] == WHITE && board[x][y + 2] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x][y - 2] == 0 && board[x][y + 3] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x][y - 2] == WHITE && board[x][y + 3] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x][y + 4] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction += 1000;
//DEL 	}
//DEL 
//DEL 	switch (BLACKONE[4] + BLACKONE[5])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (BLACKONE[0] == 1)
//DEL 		{
//DEL 			if (board[x + 2][y + 2] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		else
//DEL 		{
//DEL 			if (board[x - 2][y - 2] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch (BLACKONE[4])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x - 3][y - 3] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x - 2][y - 2] == WHITE && board[x + 2][y + 2] == WHITE)//两端限制
//DEL 			{
//DEL 			}
//DEL 			else if (board[x - 2][y - 2] == 0 && board[x + 2][y + 2] == 0)//两端自由
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction += 50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x + 3][y + 3] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch (BLACKONE[4])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x - 4][y - 4] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x - 3][y - 3] == 0 && board[x + 2][y + 2] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x - 3][y - 3] == WHITE && board[x + 2][y + 2] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x - 2][y - 2] == 0 && board[x + 3][y + 3] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x - 2][y - 2] == WHITE && board[x + 3][y + 3] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x + 4][y + 4] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction += 1000;
//DEL 	}
//DEL 
//DEL 	switch (BLACKONE[6] + BLACKONE[7])
//DEL 	{
//DEL 	case 0:
//DEL 		break;
//DEL 	case 1:
//DEL 		if (BLACKONE[6] == 1)
//DEL 		{
//DEL 			if (board[x + 2][y - 2] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		else
//DEL 		{
//DEL 			if (board[x - 2][y + 2] == WHITE)
//DEL 			{
//DEL 				Fraction += 1;
//DEL 			}
//DEL 			else
//DEL 			{
//DEL 				Fraction += 10;
//DEL 			}
//DEL 		}
//DEL 		break;
//DEL 	case 2:
//DEL 		switch (BLACKONE[0])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x - 3][y + 3] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x - 2][y + 2] == WHITE && board[x + 2][y - 2] == WHITE)//两端限制
//DEL 			{
//DEL 			}
//DEL 			else if (board[x - 2][y + 2] == 0 && board[x + 2][y - 2] == 0)//两端自由
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			else		//一段限制
//DEL 			{
//DEL 				Fraction += 50;
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x + 3][y - 3] == WHITE)	//限制两子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			else		//自由两子
//DEL 			{
//DEL 				Fraction += 200;
//DEL 			}
//DEL 			break;
//DEL 		}
//DEL 	case 3:
//DEL 		switch (BLACKONE[6])
//DEL 		{
//DEL 		case 0:
//DEL 			if (board[x - 4][y + 4] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 		case 1:
//DEL 			if (board[x - 3][y + 3] == 0 && board[x + 2][y - 2] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x - 3][y + 3] == WHITE && board[x + 2][y - 2] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 2:
//DEL 			if (board[x - 2][y + 2] == 0 && board[x + 3][y - 3] == 0)		//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else if (board[x - 2][y + 2] == WHITE && board[x + 3][y - 3] == WHITE)//两端限制
//DEL 			{
//DEL 				Fraction += 0;
//DEL 			}
//DEL 			else {
//DEL 				Fraction += 100;//限制三子
//DEL 			}
//DEL 			break;
//DEL 		case 3:
//DEL 			if (board[x + 4][y - 4] == 0)//自由三子
//DEL 			{
//DEL 				Fraction += 500;
//DEL 			}
//DEL 			else//限制三子
//DEL 			{
//DEL 				Fraction += 100;
//DEL 			}
//DEL 			break;
//DEL 
//DEL 		}
//DEL 		break;
//DEL 	default:
//DEL 		Fraction += 1000;
//DEL 	}
//DEL 
//DEL 	return Fraction;
//DEL }

