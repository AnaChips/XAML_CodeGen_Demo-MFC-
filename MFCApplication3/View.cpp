#include "stdafx.h"
#include "View.h"


View::View()
{
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

CString View::fnGetCaption()
{
	return mstrCaption;
}

CString View::fnGetElementType()
{
	return mstrType;
}

void View::fnTranslateFont()
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


void View::fnTranslateFontSize()
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

void View::fnShowCaption(CDC * pdc, int HCenter, int VCenter, int SingleLine)
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



//for all
void View::fnSetCaption(CString Caption)
{
	mstrCaption = Caption;
}

//Set text color -- for all
void View::fnSetTextRed(int Red)
{
	mTRed = Red;
}

void View::fnSetTextGreen(int Green)
{
	mTGreen = Green;
}

void View::fnSetTextBlue(int Blue)
{
	mTBlue = Blue;
}
int View::fnGetTextRed()
{
	return mTRed;
}
int View::fnGetTextGreen()
{
	return mTGreen;
}
int View::fnGetTextBlue()
{
	return mTBlue;
}




void View::fnSetBackRed(int Red)
{
	mbRed = Red;
}

void View::fnSetBackGreen(int Green)
{
	mbGreen = Green;
}

void View::fnSetBackBlue(int Blue)
{
	mbBlue = Blue;
}
int View::fnGetBackRed()
{
	return mbRed;
}
int View::fnGetBackGreen()
{
	return mbGreen;
}
int View::fnGetBackBlue()
{
	return mbBlue;
}


