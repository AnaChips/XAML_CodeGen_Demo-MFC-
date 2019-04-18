
#include "stdafx.h"
#include "SelRect.h"



Handle::Handle()
{
	miTop, miBottom, miLeft, miRight = 0;
	miOffSet = 05;
}
void Handle::fnDraw(CDC *pdc)
{
	pdc->MoveTo(miLeft, miTop);
	pdc->LineTo(miRight, miTop);
	pdc->LineTo(miRight, miBottom);
	pdc->LineTo(miLeft, miBottom);
	pdc->LineTo(miLeft, miTop);
}
void Handle::fnCalcLoc(int MidX, int MidY)
{

	miRight = MidX + miOffSet;
	miLeft = MidX - miOffSet;

	miTop = MidY - miOffSet;
	miBottom = MidY + miOffSet;

}
bool Handle::OnLButtonDown(CPoint point)
{
	if ((point.x > miLeft) && (point.x < miRight) && (point.y > miTop) && (point.y < miBottom))
	{
		return 1; //click inside
	}

	else //if ((point.x < miLeft) && (point.x > miRight) && (point.y < miTop) && (point.x > miBottom))
	{
		return 0; // click outside
	}
}

int Handle::fnGetOffSet()
{
	return miOffSet;
}
void Handle::fnSetOffSet(int OffSet)
{
	miOffSet = OffSet;
}

//==============================================================================================================================

SelRect::SelRect()
{
	CString str;
	str.Format(_T("SelRect Constructed \n"));
	TRACE(str);
	miTop = 100; miLeft = 10;
	miBottom = 200; miRight = 100;
	mbVisible = false;
	mbResizeStarted = false;
	mbMoveStarted = false;
	miHandleActive = HD_INVALID;
}


void SelRect::fnDraw(CDC *pdc)
{
	/*int iOldROPMode = pdc->SetROP2(R2_NOT);

	pdc->MoveTo(miLeft, miTop);
	pdc->LineTo(miRight, miTop);
	pdc->LineTo(miRight, miBottom);
	pdc->LineTo(miLeft, miBottom);
	pdc->LineTo(miLeft, miTop);

	int iXMid = (miRight + miLeft) / 2;
	int iYMid = (miBottom + miTop) / 2;

	HandleArray[0].fnCalcLoc(miLeft, miTop);
	HandleArray[1].fnCalcLoc(iXMid, miTop);
	HandleArray[2].fnCalcLoc(miRight, miTop);
	HandleArray[3].fnCalcLoc(miRight, iYMid);
	HandleArray[4].fnCalcLoc(miRight, miBottom);
	HandleArray[5].fnCalcLoc(iXMid, miBottom);
	HandleArray[6].fnCalcLoc(miLeft, miBottom);
	HandleArray[7].fnCalcLoc(miLeft, iYMid);

	for (int iCtr = 0; iCtr < 8; iCtr++)
	{
	HandleArray[iCtr].fnDraw(pdc);
	}

	pdc->SetROP2(iOldROPMode);
	*/
	CString str;
	str.Format(_T("Into fndraw for SelRect \n "));
	TRACE(str);
	int iOldROPMode = pdc->SetROP2(R2_NOT);

	if (true == mbVisible)
	{
		int iXMid = (miRight + miLeft) / 2;
		int iYMid = (miBottom + miTop) / 2;

		HandleArray[0].fnCalcLoc(miLeft, miTop);
		HandleArray[1].fnCalcLoc(iXMid, miTop);
		HandleArray[2].fnCalcLoc(miRight, miTop);
		HandleArray[3].fnCalcLoc(miRight, iYMid);
		HandleArray[4].fnCalcLoc(miRight, miBottom);
		HandleArray[5].fnCalcLoc(iXMid, miBottom);
		HandleArray[6].fnCalcLoc(miLeft, miBottom);
		HandleArray[7].fnCalcLoc(miLeft, iYMid);

		for (int iCtr = 0; iCtr < 8; iCtr++)
		{
			HandleArray[iCtr].fnDraw(pdc);
		}

		int iOffSet = HandleArray[0].fnGetOffSet();

		pdc->MoveTo((miLeft + iOffSet), miTop);
		pdc->LineTo((iXMid - iOffSet), miTop);

		pdc->MoveTo((iXMid + iOffSet), miTop);
		pdc->LineTo((miRight - iOffSet), miTop);

		pdc->MoveTo(miRight, (miTop + iOffSet));
		pdc->LineTo(miRight, (iYMid - iOffSet));

		pdc->MoveTo(miRight, (iYMid + iOffSet));
		pdc->LineTo(miRight, (miBottom - iOffSet));

		pdc->MoveTo((miRight - iOffSet), miBottom);
		pdc->LineTo((iXMid + iOffSet), miBottom);

		pdc->MoveTo((iXMid - iOffSet), miBottom);
		pdc->LineTo((miLeft + iOffSet), miBottom);

		pdc->MoveTo(miLeft, (miBottom - iOffSet));
		pdc->LineTo(miLeft, (iYMid + iOffSet));

		pdc->MoveTo(miLeft, (iYMid - iOffSet));
		pdc->LineTo(miLeft, (miTop + iOffSet));
	}
	pdc->SetROP2(iOldROPMode);
}

void SelRect::fnSetLoc(int Top, int Left, int Bottom, int Right)
{
	CString str;
	str.Format(_T("Into fnSetLoc of SelRect \n"));
	TRACE(str);
	miTop = Top;
	miLeft = Left;
	miRight = Right;
	miBottom = Bottom;
}

int SelRect::fnClickOn(CPoint point)
{
	int itoReturn = -1;

	if (1 == HandleArray[0].OnLButtonDown(point))
	{
		itoReturn = HD_TOPLEFT; // click on handle 0
	}
	else if (1 == HandleArray[1].OnLButtonDown(point))
	{
		itoReturn = HD_TOPMID; // click on handle 1
	}
	else if (1 == HandleArray[2].OnLButtonDown(point))
	{
		itoReturn = HD_TOPRIGHT; // click on handle 2
	}
	else if (1 == HandleArray[3].OnLButtonDown(point))
	{
		itoReturn = HD_RIGHTMID; // click on handle 3
	}
	else if (1 == HandleArray[4].OnLButtonDown(point))
	{
		itoReturn = HD_RIGHTBOTTOM; // click on handle 4
	}
	else if (1 == HandleArray[5].OnLButtonDown(point))
	{
		itoReturn = HD_BOTTOMMID; // click on handle 5
	}
	else if (1 == HandleArray[6].OnLButtonDown(point))
	{
		itoReturn = HD_BOTTOMLEFT; // click on handle 6
	}
	else if (1 == HandleArray[7].OnLButtonDown(point))
	{
		itoReturn = HD_LEFTMID; // click on handle 7
	}
	else if ((point.x > miLeft) && (point.x < miRight) && (point.y > miTop) && (point.y < miBottom))
	{
		itoReturn = HD_INSIDE; //click inside
	}

	else
	{
		itoReturn = HD_OUTSIDE; // click not on handles or inside rect
	}
	return itoReturn;
}


void SelRect::fnMove(int dx, int dy, int TopBound, int LeftBound, int BottomBound, int RightBound)
{
	/*miLeft += dx;
	miTop += dy;
	miRight += dx;
	miBottom += dy;
	*/

	if (((miLeft + dx) > LeftBound) && ((miRight + dx) < RightBound) && ((miTop + dy) > TopBound) && ((miBottom + dy) < BottomBound))
	{
		miLeft = miLeft + dx;
		miRight = miRight + dx;

		miTop = miTop + dy;
		miBottom = miBottom + dy;
	}
}

void SelRect::fnResize(int HandleNo, int dx, int dy, int TopBound, int LeftBound, int BottomBound, int RightBound)
{

	int iMinSize = 40; // must be positive always
	if (HandleNo == HD_TOPLEFT)
	{
		if (((miTop + dy) < (miBottom - iMinSize)) && ((miLeft + dx) < (miRight - iMinSize)) && ((miTop + dy) > TopBound) && ((miLeft + dx) > LeftBound))
		{
			miTop += dy;
			miLeft += dx;
		}

	}
	else if (HandleNo == HD_TOPMID)
	{
		CString str;
		str.Format(_T("\n TopMid Handle selected, miTop = %d, dy = %d, miBottom = %d, iMinsize = %d, TopBound = %d \n"), miTop, dy, miBottom, iMinSize, TopBound);
		TRACE(str);

		if ( ((miTop + dy) < (miBottom - iMinSize)) && ((miTop + dy) > TopBound))
		{
			miTop += dy;
		}

	}
	else if (HandleNo == HD_TOPRIGHT)
	{
		if (((miTop + dy) < (miBottom - iMinSize)) && ((miRight + dx) > (miLeft + iMinSize)) && ((miTop + dy) > TopBound) && ((miRight + dx) < RightBound))
		{
			miTop += dy;
			miRight += dx;
		}
	}
	else if (HandleNo == HD_RIGHTMID)
	{
		if (  ((miRight + dx) > (miLeft + iMinSize)) && ((miRight + dx) < RightBound) )
		{
			miRight += dx;
		}
	}
	else if (HandleNo == HD_RIGHTBOTTOM)
	{
		if (((miRight + dx) > (miLeft + iMinSize)) && ((miBottom + dy) > (miTop + iMinSize)) && ((miRight + dx) < RightBound) && ((miBottom + dy) < BottomBound))
		{
			miRight += dx;
			miBottom += dy;
		}

	}
	else if (HandleNo == HD_BOTTOMMID)
	{
		if ( ((miBottom + dy) > (miTop + iMinSize)) && ((miBottom + dy) < BottomBound) )
		{
			miBottom += dy;
		}
	}
	else if (HandleNo == HD_BOTTOMLEFT)
	{
		if (((miBottom + dy) > (miTop + iMinSize)) && ((miLeft + dx) < (miRight - iMinSize)) && ((miBottom + dy) < BottomBound) && ((miLeft + dx) > LeftBound))
		{
			miBottom += dy;
			miLeft += dx;
		}
	}
	else if (HandleNo == HD_LEFTMID)
	{
		if ( ((miLeft + dx) < (miRight - iMinSize)) && ((miLeft + dx) > LeftBound) )
		{
			miLeft += dx;
		}
	}
}



bool SelRect::fnGetMoveStarted()
{
	return mbMoveStarted;
}

bool SelRect::fnGetResizeStarted()
{
	return mbResizeStarted;
}



void SelRect::OnLButtonDown(CPoint point)
{
	int iClickOn = fnClickOn(point);
	if (HD_INSIDE == iClickOn)
	{
		mPrevPoint = point;
		mbMoveStarted = true;
	}
	else
	{
		if ((HD_TOPMID == iClickOn) || (HD_RIGHTMID == iClickOn) || (HD_BOTTOMMID == iClickOn) || (HD_LEFTMID == iClickOn) || (HD_TOPLEFT == iClickOn) || (HD_TOPRIGHT == iClickOn) || (HD_BOTTOMLEFT == iClickOn) || (HD_RIGHTBOTTOM == iClickOn))
		{
			miHandleActive = iClickOn;
			mPrevPoint = point;
			mbResizeStarted = true;

			CString str;
			str.Format(_T("Resize :  %d\n "), mbResizeStarted);
			TRACE(str);
		}
	}
}

void SelRect::OnMouseMove(CPoint point, CDC * pdc, int TopBound, int LeftBound, int BottomBound, int RightBound)
{
	if (true == mbMoveStarted)
	{
		fnDraw(pdc);
		int iDx = point.x - mPrevPoint.x;
		int iDy = point.y - mPrevPoint.y;
		fnMove(iDx, iDy, TopBound, LeftBound, BottomBound, RightBound);
		fnDraw(pdc);
		mPrevPoint = point;
	}
	else if (true == mbResizeStarted)
	{
		fnDraw(pdc);
		int iDx = point.x - mPrevPoint.x;
		int iDy = point.y - mPrevPoint.y;
		fnResize(miHandleActive, iDx, iDy, TopBound, LeftBound, BottomBound, RightBound);
		fnDraw(pdc);
		mPrevPoint = point;

		CString str;
		str.Format(_T("Into else if of SelRect::OnMouseMove. dx = %d, dy = %d \n"), iDx, iDy);
		TRACE(str);
	}
}

void SelRect::OnLButtonUp(CPoint point)
{
	if (true == mbMoveStarted)
	{
		mbMoveStarted = false;
	}
	else if (true == mbResizeStarted)
	{
		miHandleActive = HD_INVALID;
		mbResizeStarted = false;

		CString str;
		str.Format(_T("Into else if of SelRect::OnLButtonUp. Top = %d, Left = %d, Bottom = %d, Right = %d \n"), miTop, miLeft, miBottom, miRight);
		TRACE(str);
	}
}

LPCTSTR SelRect::fnAskCursorType(CPoint point)
{
	int iClick = fnClickOn(point);
	if ((HD_TOPMID == iClick) || (HD_BOTTOMMID == iClick))
	{
		return IDC_SIZENS;
	}
	else if ((HD_RIGHTMID == iClick) || (HD_LEFTMID == iClick))
	{
		return IDC_SIZEWE;
	}
	else if ((HD_TOPLEFT == iClick) || (HD_RIGHTBOTTOM == iClick))
	{
		return IDC_SIZENWSE;
	}
	else if ((HD_TOPRIGHT == iClick) || (HD_BOTTOMLEFT == iClick))
	{
		return IDC_SIZENESW;
	}
	else if (HD_INSIDE == iClick)
	{
		return IDC_HAND;
	}
	else
	{
		return IDC_ARROW;
	}
}

bool SelRect::fnGetVisiablity()
{
	return mbVisible;
}

void SelRect::fnSetVisiablity(bool Visiablity)
{
	mbVisible = Visiablity;
}

int SelRect::fnGetTop()
{
	return miTop;
}

int SelRect::fnGetLeft()
{
	return miLeft;
}

int SelRect::fnGetBottom()
{
	return miBottom;
}

int SelRect::fnGetRight()
{
	return miRight;
}