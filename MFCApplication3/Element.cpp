#include "stdafx.h"
#include "Element.h"


Element::Element()
{
	miTop = 0;
	miLeft = 0;
	miBottom = 0;
	miRight = 0;

	mTRed = 0;
	mTGreen = 64;
	mTBlue = 128;

	//Control font
	miFontFace = SANS_SERIF;
	miFontSize = DEFAULT;


	//Log Font Initialization => For Visualization
	ZeroMemory(&mlFont, sizeof(mlFont));
	//initialize mlfont
	mlFont.lfHeight = -20;
	mlFont.lfWeight = 800;
	mlFont.lfOutPrecision = 3;
	mlFont.lfClipPrecision = 2;
	mlFont.lfQuality = 1;
	mlFont.lfPitchAndFamily = 34;
	lstrcpy(mlFont.lfFaceName, _T("Arial"));
}
void Element::fnSetLoc(int top, int left, int bottom, int right)
{
	miLeft = left;
	miTop = top;
	miRight = right;
	miBottom = bottom;
}


int Element::fnGetTop()
{
	return miTop;
}

int Element::fnGetLeft()
{
	return miLeft;
}

int Element::fnGetBottom()
{
	return miBottom;
}

int Element::fnGetRight()
{
	return miRight;
}

int Element::fnGetHeight()
{
	int iHeight = miBottom - miTop;
	return iHeight;
}

int Element::fnGetWidth()
{
	return (miRight - miLeft);
}

CString Element::fnGetCaption()
{
	return mstrCaption;
}

CString Element::fnGetElementType()
{
	return mstrType;
}

void Element::fnTranslateFont()
{
	if (miFontFace == SANS_SERIF)
	{
		lstrcpy(mlFont.lfFaceName, _T("Arial"));
	}
	else if (miFontFace == SERIF)
	{
		lstrcpy(mlFont.lfFaceName, _T("Baskerville Old Face"));
	}
}


void Element::fnTranslateFontSize()
{
	HDC hDC = GetDC(NULL);
	int iPointSize = 9;
	
	if (miFontSize == MICRO)
	{
		iPointSize = 9;
	}
	else if (miFontSize == SMALL)
	{
		iPointSize = 37;
	}
	else if (miFontSize == MEDIUM)
	{
		iPointSize = 57;
	}
	else if (miFontSize == LARGE)
	{
		iPointSize = 67;
	}
	else if (miFontSize == DEFAULT)
	{
		iPointSize = 27;
	}
	mlFont.lfHeight = (-1) * (MulDiv(iPointSize, 72, GetDeviceCaps(hDC, LOGPIXELSY)));
}

void Element::fnShowCaption(CDC * pdc, int HCenter ,int VCenter, int SingleLine)
{
	fnTranslateFont();
	fnTranslateFontSize();

	CRect rText;
	rText.left = miLeft; rText.right = miRight;
	rText.top = miTop; rText.bottom = miBottom;

	CFont MyFont, *pOldFont = NULL;
	MyFont.CreateFontIndirect(&mlFont);
	pOldFont = (CFont *)pdc->SelectObject(&MyFont);

	pdc->SetBkMode(TRANSPARENT);

	//define color 
	COLORREF cOldColor = pdc->SetTextColor(RGB(mTRed, mTGreen, mTBlue));
	
	//draw text
	pdc->DrawText(mstrCaption, rText, HCenter | VCenter | SingleLine);
	
	//reset values
	pdc->SetTextColor(cOldColor);
	pdc->SelectObject(pOldFont);
}

bool Element::OnLButtonDown(CPoint point)
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

//for all
void Element::fnSetCaption(CString Caption)
{
	mstrCaption = Caption;
}

//Set text color -- for all
void Element::fnSetTextRed(int Red)
{
	mTRed = Red;
}

void Element::fnSetTextGreen(int Green)
{
	mTGreen = Green;
}

void Element::fnSetTextBlue(int Blue)
{
	mTBlue = Blue;
}
int Element::fnGetTextRed()
{
	return mTRed;
}
int Element::fnGetTextGreen()
{
	return mTGreen;
}
int Element::fnGetTextBlue()
{
	return mTBlue;
}




void Element::fnSetBackRed(int Red)
{
	mbRed = Red;
}

void Element::fnSetBackGreen(int Green)
{
	mbGreen = Green;
}

void Element::fnSetBackBlue(int Blue)
{
	mbBlue = Blue;
}
int Element::fnGetBackRed()
{
	return mbRed;
}
int Element::fnGetBackGreen()
{
	return mbGreen;
}
int Element::fnGetBackBlue()
{
	return mbBlue;
}


