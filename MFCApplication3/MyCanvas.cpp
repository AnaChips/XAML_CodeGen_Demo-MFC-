
#include "stdafx.h"
#include "MyCanvas.h"

//custom classes
#include "Element.h"


CMyCanvas::CMyCanvas()
{
	mpSelectedElement = NULL;
	miElementNo = 0;
}

void CMyCanvas::fnDraw(CDC *pdc)
{
	//pdc->Rectangle(miLeft, miTop, miRight, miBottom);
	pdc->MoveTo(miLeft, miTop);
	pdc->LineTo(miRight, miTop);
	pdc->LineTo(miRight, miBottom);
	pdc->LineTo(miLeft, miBottom);
	pdc->LineTo(miLeft, miTop);
}

void CMyCanvas::fnSetParams(int Left, int Top, int Right, int Bottom)
{
	miTop = Top;
	miBottom = Bottom;
	miLeft = Left;
	miRight = Right;
}

void CMyCanvas::fnOnLButtonDown(CPoint point)
{
	int iElementCount = mElementArray.GetCount();


	if (true == mSelRect.fnGetVisiablity()) // OverLay Rect is visiable
	{
		int iClick = mSelRect.fnClickOn(point);
		if (mSelRect.HD_OUTSIDE == iClick)
		{
			mSelRect.fnSetVisiablity(false);
		}
		else
		{
			/*CString str;
			str.Format(_T("OverLay Rect visible. Into else of  CMyCanvas::fnOnLButtonDown for Overlay rect visible \n"));
			TRACE(str);
			*/
			mSelRect.OnLButtonDown(point);
		}
		CString strType;
		strType.Format(_T("%d", ((Element*)Canvas.mpSelectedElement)->miType));
		AfxMessageBox(strType);
	}
	
	else //OverLay Rect not visible
	{
		/*CString str;
		str.Format(_T("OverLay Rect is not visible. Inot else of  CMyCanvas::fnOnLButtonDown \n "));
		TRACE(str);*/

		for (int iCtr = 0; iCtr < iElementCount; iCtr++)
		{
			Element *pElement = (Element*)mElementArray.GetAt(iCtr);
			miElementNo = iCtr;
			bool bIsClicked = pElement->OnLButtonDown(point);
			if (true == bIsClicked)
			{
				mpSelectedElement = pElement;
				/*CString str;
				str.Format(_T("mpElement : Top : %d, Left : %d Right : %d, Bottom : %d \n"), mpSelectedElement->fnGetTop(), mpSelectedElement->fnGetLeft(), mpSelectedElement->fnGetBottom(), mpSelectedElement->fnGetRight());
				TRACE(str);
				*/
				bool bVisiblity = mSelRect.fnGetVisiablity();
				if (false == bVisiblity)
				{
					mSelRect.fnSetLoc(pElement->fnGetTop(), pElement->fnGetLeft(), pElement->fnGetBottom(), pElement->fnGetRight()); //draw select rect

					mSelRect.fnSetVisiablity(true);
					iCtr = iElementCount;
				}
			}
		}
	}
}

int CMyCanvas::fnGetTop()
{
	return miTop;
}

int CMyCanvas::fnGetLeft()
{
	return miLeft;
}

int CMyCanvas::fnGetBottom()
{
	return miBottom;
}

int CMyCanvas::fnGetRight()
{
	return miRight;
}