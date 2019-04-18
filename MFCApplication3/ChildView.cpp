
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "afxext.h"
#include "stdio.h"

#include "MFCApplication3.h"

//custom classes in chlidviews.h

#include "ChildView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool gbPaint;
int giClickCtr = 0;

// CChildView
CChildView::CChildView()
{
	gbPaint = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CHAR()
	ON_COMMAND(ID_ELEMENTOPTIONS_ADDLABEL, &CChildView::OnAddlabel)
	ON_COMMAND(ID_ELEMENTOPTIONS_ADDCBUTTON, &CChildView::OnAddRectButton)
	ON_COMMAND(ID_FILE_GENERATEXAML, &CChildView::OnGenerateXAML)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_REPAINT_REPAINT, &CChildView::OnRepaint)
	ON_COMMAND(ID_ELEMENTOPTIONS_ADDEDITOR, &CChildView::OnAddEditor)
	ON_COMMAND(ID_ELEMENTOPTIONS_ADDENTRY, &CChildView::OnElementoptionsAddentry)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this);


	/*CRect ClientRect = new CRect();
	GetClientRect(ClientRect);

	int iHorMid = (ClientRect.right - ClientRect.left) / 2;
	int iVerMid = (ClientRect.bottom - ClientRect.top) / 2;
	

	int Left = (iHorMid - CANVAS_HORIZONTAL_SPAN);
	int Top = (iVerMid - CANVAS_VERTICAL_SPAN);
	int Right = (iHorMid + CANVAS_HORIZONTAL_SPAN);
	int Bottom = (iVerMid + CANVAS_VERTICAL_SPAN);

	Canvas.fnSetParams(Left, Top, Right, Bottom);
	
	
	Canvas.fnSetParams((iHorMid - CANVAS_HORIZONTAL_SPAN), (iVerMid - CANVAS_VERTICAL_SPAN), (iHorMid + CANVAS_HORIZONTAL_SPAN), (iVerMid + CANVAS_VERTICAL_SPAN));*/

	Canvas.fnDraw(&dc);

	int iElementCount = Canvas.mElementArray.GetCount();
	if (iElementCount > 0)
	{
		for (int iCtr = 0; iCtr < iElementCount; iCtr++)
		{
			Element *pElement = (Element*)Canvas.mElementArray.GetAt(iCtr);
			pElement->fnDraw(&dc);
		}
		
	}
	

	if (true == Canvas.mSelRect.fnGetVisiablity())
	{
		Canvas.mSelRect.fnDraw(&dc);
	}
	
	
	if (gbPaint == true)
	{
		CString strShow(_T("\n\n \t Into Paint \n\n"));
		TRACE(strShow);
	}
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	CRect ClientRect = new CRect();
	GetClientRect(ClientRect);

	int iHorMid = (ClientRect.right - ClientRect.left) / 2;
	int iVerMid = (ClientRect.bottom - ClientRect.top) / 2;

	Canvas.fnSetParams((iHorMid - CANVAS_HORIZONTAL_SPAN), (iVerMid - CANVAS_VERTICAL_SPAN), (iHorMid + CANVAS_HORIZONTAL_SPAN), (iVerMid + CANVAS_VERTICAL_SPAN));
	/*if (true == gbPaint)
	{
		CString str;
		str.Format(_T("%d, %d"), cx, cy);
		AfxMessageBox(str);

		Invalidate();
	}*/

}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	Canvas.fnOnLButtonDown(point);
	Invalidate();
}
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	LPCTSTR strCurType = Canvas.mSelRect.fnAskCursorType(point);
	SetCursor(LoadCursor(NULL, strCurType));

	if (true == Canvas.mSelRect.fnGetMoveStarted() || true == Canvas.mSelRect.fnGetResizeStarted())
	{
		CDC * pdc = GetDC();
		Canvas.mSelRect.OnMouseMove(point, pdc,Canvas.fnGetTop(), Canvas.fnGetLeft(), Canvas.fnGetBottom(), Canvas.fnGetRight());
		ReleaseDC(pdc);
	}
}
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	Canvas.mSelRect.OnLButtonUp(point);

	if (true == Canvas.mSelRect.fnGetVisiablity())
	{
		//bounding displacement to canvas
		Canvas.mpSelectedElement->fnSetLoc(Canvas.mSelRect.fnGetTop(), Canvas.mSelRect.fnGetLeft(), Canvas.mSelRect.fnGetBottom(), Canvas.mSelRect.fnGetRight());
		Invalidate();
	}
}







void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//AfxMessageBox(_T("Key Pressed"));
	if ( (VK_ESCAPE == nChar) && (true == Canvas.mSelRect.fnGetVisiablity()) )
	{
		Canvas.mElementArray.RemoveAt(Canvas.miElementNo);
		Canvas.mSelRect.fnSetVisiablity(false);
		Invalidate();
	}
}


void CChildView::OnAddlabel()
{
	int iOffSet = 50;
	giClickCtr = Canvas.mElementArray.GetSize();
	Element* pElement = new Label();
	
	//pElement->fnSetCaption(_T("label"));
	
	
	int iTop = Canvas.miTop + (iOffSet * giClickCtr);
	giClickCtr++;

	int iBottom = Canvas.miTop + (giClickCtr * iOffSet);

	pElement->fnSetLoc(iTop, Canvas.miLeft, iBottom, Canvas.miLeft + 70);

	Canvas.mElementArray.Add(pElement);

	Invalidate();	
}

void CChildView::OnAddRectButton()
{

	{
		int iOffSet = 50;
		giClickCtr = Canvas.mElementArray.GetSize();
		Element* pButton = new RectButton();

		pButton->fnSetCaption(_T("Button"));

		int iTop = Canvas.miTop + (iOffSet *  giClickCtr);
		giClickCtr++;

		int iBottom = Canvas.miTop + (giClickCtr * iOffSet);

		pButton->fnSetLoc(iTop, Canvas.miLeft, iBottom, Canvas.miLeft + 70);

		Canvas.mElementArray.Add(pButton);

		Invalidate();
	}
}


void CChildView::OnAddEditor()
{
	int iOffSet = 50;
	giClickCtr = Canvas.mElementArray.GetSize();
	Element* pEditor = new Editor();

	pEditor->fnSetCaption(_T("Editor"));

	int iTop = Canvas.miTop + (iOffSet *  giClickCtr);
	giClickCtr++;

	int iBottom = Canvas.miTop + (giClickCtr * iOffSet);

	pEditor->fnSetLoc(iTop, Canvas.miLeft, iBottom, Canvas.miLeft + 70);

	Canvas.mElementArray.Add(pEditor);

	Invalidate();
}

void CChildView::OnElementoptionsAddentry()
{
	int iOffSet = 50;
	giClickCtr = Canvas.mElementArray.GetSize();
	Element* pEntry = new Entry();

	pEntry->fnSetCaption(_T("Entry"));

	int iTop = Canvas.miTop + (iOffSet *  giClickCtr);
	giClickCtr++;

	int iBottom = Canvas.miTop + (giClickCtr * iOffSet);

	pEntry->fnSetLoc(iTop, Canvas.miLeft, iBottom, Canvas.miLeft + 70);

	Canvas.mElementArray.Add(pEntry);

	Invalidate();
}
void CChildView::OnGenerateXAML()
{
	CString strOutFile = _T("E:\\Semister V studies\\BE Project\\Written files\\Output.txt");
	CFile OutFile;
	if (OutFile.Open(strOutFile, CFile::modeCreate | CFile::modeWrite))
	{
		CString strTemp = (_T("<?xml version= \"1.0\" encoding=\"utf - 8\" ?> \r\n"));
		CString strTop;

		//strTemp.Format(_T("<?xml version= \"1.0\" encoding=\"utf - 8\" ?> \r\n"));
		strTemp.Append(_T("<ContentPage xmlns=\"http://xamarin.com/schemas/2014/forms\" \r\n"));
		strTemp.Append(_T("\t xmlns:x=\"http://schemas.microsoft.com/winfx/2009/xaml\" \r\n"));
		strTemp.Append(_T("\t xmlns:local=\"clr-namespace:App1\" \r\n"));
		strTemp.Append(_T("\t x:Class = \"App1.MainPage\"> \r\n"));
		strTemp.Append(_T("\t <ContentPage.Content> \r\n"));
		strTemp.Append(_T("\t <AbsoluteLayout AbsoluteLayout.LayoutFlags = \"None\"> \r\n"));
		
		OutFile.Write(strTemp, sizeof(TCHAR)*strTemp.GetLength());
		strTemp.Empty();
		
		int iLimit = Canvas.mElementArray.GetCount();
		for (int iCtr = 0; iCtr < iLimit; iCtr++)
		{
			Element* pTempElement = (Element*)Canvas.mElementArray.GetAt(iCtr);
			pTempElement->fnWriteToFile(&OutFile, Canvas.fnGetTop(), Canvas.fnGetLeft());
		}


		strTemp.Append(_T("\t</AbsoluteLayout> \r\n"));
		strTemp.Append(_T("\t</ContentPage.Content> \r\n"));
		strTemp.Append(_T("\t</ContentPage> \r\n"));
		OutFile.Write(strTemp, sizeof(TCHAR)*strTemp.GetLength());
	}
	OutFile.Close();
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{


	if( (true == Canvas.mSelRect.fnGetVisiablity()) && (Canvas.mSelRect.HD_INSIDE == Canvas.mSelRect.fnClickOn(point)) )
	{
		Canvas.mpSelectedElement->fnPopDialogue();
		gbPaint = true;
		Invalidate();
	}
}


void CChildView::OnRepaint()
{
	
	Element *Test = (Entry*)Canvas.mElementArray.GetAt(0);
	CString strShow = Test->fnGetCaption();
	/*strShow.Format(_T("%d"), Test->mlFont.lfHeight);
	strShow.Append(_T("\t"));
	strShow.Append(Test->mlFont.lfFaceName);
	*/

	AfxMessageBox(strShow);
}




