#pragma once


class Handle
{
	int miTop, miBottom, miLeft, miRight;
	int miOffSet;
public:
	Handle();
	void fnDraw(CDC *pdc);
	void fnCalcLoc(int MidX, int MidY);
	bool Handle::OnLButtonDown(CPoint point);
	int fnGetOffSet();
	void fnSetOffSet(int OffSet);
};

class SelRect
{
	int miTop, miBottom, miLeft, miRight;

	CPoint mPrevPoint;
	bool mbMoveStarted;
	bool mbResizeStarted;
	int miHandleActive;
	bool mbVisible;
	Handle HandleArray[8];

public:
	enum { HD_INVALID = -1, HD_TOPLEFT = 0, HD_TOPMID, HD_TOPRIGHT, HD_RIGHTMID, HD_RIGHTBOTTOM, HD_BOTTOMMID, HD_BOTTOMLEFT, HD_LEFTMID, HD_OUTSIDE = 9, HD_INSIDE = 10 };

	SelRect();
	void fnDraw(CDC *pdc);
	void fnSetLoc(int Top, int Left, int Bottom, int Right);
	int fnClickOn(CPoint point);
	void fnMove(int dx, int dy, int TopBound, int LeftBound, int BottomBound, int RightBound);
	void fnResize(int HandleNo, int dx, int dy, int TopBound, int LeftBound, int BottomBound, int RightBound);

	bool fnGetMoveStarted();
	bool fnGetResizeStarted();

	void OnLButtonDown(CPoint point);
	void OnMouseMove(CPoint point, CDC * pdc, int TopBound, int LeftBound, int BottomBound, int RightBound);
	void OnLButtonUp(CPoint point);

	LPCTSTR fnAskCursorType(CPoint point);

	bool fnGetVisiablity();
	void fnSetVisiablity(bool Visiablity);

	int fnGetTop();
	int fnGetLeft();
	int fnGetBottom();
	int fnGetRight();
	
};