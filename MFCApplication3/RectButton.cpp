#include "stdafx.h"
#include "RectButton.h"

RectButton::RectButton()
{
	miBorderRadius = 2;
	miBorderWidth = 2;
	
	mbRed = 0; mbGreen = 64; mbBlue = 128;
	mTRed = 119; mTGreen = 077; mTBlue = 189;
	mBorderRed = 119; mBorderGreen = 077; mBorderBlue = 189;

	//mBorder = RGB(119, 77, 189);


	mstrType = "Button";

	mstrCaption = "MyButton";

}

void RectButton::fnDraw(CDC * pdc)
{
	CPen Pen;
	CPen* pOldPen = NULL;

	CBrush Brush;
	CBrush* pOldBrush = NULL;
	Brush.CreateSolidBrush(RGB(mbRed, mbGreen, mbBlue));


	Pen.CreatePen(PS_SOLID, miBorderWidth, RGB(mBorderRed, mBorderGreen, mBorderBlue));
	pOldPen = (CPen*)pdc->SelectObject(&Pen);



	pOldBrush = (CBrush*)pdc->SelectObject(&Brush);
	pdc->RoundRect(miLeft, miTop, miRight, miBottom, miBorderRadius, miBorderRadius);

	pdc->SelectObject(pOldBrush);
	pdc->SelectObject(pOldPen);

	fnShowCaption(pdc);
}

void RectButton::fnSetBorderRad(int Radius)
{
	miBorderRadius = Radius;
}

void RectButton::fnSetBorderWidth(int Width)
{
	miBorderWidth = Width;
}

void RectButton::fnPopDialogue()
{
	ButtonDialogue testdlg;
	
	testdlg.fnSetBorderThickness(miBorderWidth);
	testdlg.fnSetBorderRad(miBorderRadius);

	testdlg.fnSetCpation(mstrCaption);
	testdlg.fnSetTextRed(mTRed);
	testdlg.fnSetTextGreen(mTGreen);
	testdlg.fnSetTextBlue(mTBlue);

	testdlg.fnSetBackRed(mbRed);
	testdlg.fnSetBackGreen(mbGreen);
	testdlg.fnSetBackBlue(mbBlue);

	testdlg.fnSetFont(mlFont);
	
	testdlg.fnSetFontFace(miFontFace);
	testdlg.fnSetFontSize(miFontSize);

	testdlg.fnSetBorderRed(mBorderRed);
	testdlg.fnSetBorderGreen(mBorderGreen);
	testdlg.fnSetBorderBlue(mBorderBlue);


	if (IDOK == testdlg.DoModal())
	{
		miBorderWidth = testdlg.fnGetBorderThickness();
		miBorderRadius = testdlg.fnGetBorderRad();

		mbRed = testdlg.fnGetBackRed();
		mbGreen = testdlg.fnGetBackGreen();
		mbBlue = testdlg.fnGetBackBlue();

		mstrCaption = testdlg.fnGetCaption();

		mTRed = testdlg.fnGetTextRed();
		mTGreen = testdlg.fnGetTextGreen();
		mTBlue = testdlg.fnGetTextBlue();

		mlFont = testdlg.fnGetLfont();
		miFontFace = testdlg.fnGetFontFace();
		miFontSize = testdlg.fnGetFontSize();

		mBorderRed = testdlg.fnGetBorderRed();
		mBorderGreen = testdlg.fnGetBorderGreen();
		mBorderBlue = testdlg.fnGetBorderBlue();
	}
}

void RectButton::fnSetBorderRed(int Red)
{
	mBorderRed = Red;
}

void RectButton::fnSetBorderGreen(int Green)
{
	mBorderGreen = Green;
}

void RectButton::fnSetBorderBlue(int Blue)
{
	mBorderBlue = Blue;
}
int RectButton::fnGetTextRed()
{
	return mBorderRed;
}
int RectButton::fnGetTextGreen()
{
	return mBorderGreen;
}
int RectButton::fnGetTextBlue()
{
	return mBorderBlue;
}

void RectButton::fnWriteToFile(CFile * pFile, int Top, int Left)
{
	CString strWrite;
	CString strTemp;

	strWrite.Format(_T("\t<"));
	strWrite.Append(mstrType);
	strWrite.Append(_T(" Text = \""));
	strWrite.Append(mstrCaption);
	strWrite.Append(_T("\""));

	//layout bounds
	strWrite.Append(_T(" AbsoluteLayout.LayoutBounds = \""));
	strTemp.Format(_T("%d"), (miLeft - Left));
	strWrite.Append(strTemp);
	strWrite.Append(_T(","));

	strTemp.Format(_T("%d"), (miTop - Top));
	strWrite.Append(strTemp);
	strWrite.Append(_T(","));


	strTemp.Format(_T("%d"), this->fnGetWidth());
	strWrite.Append(strTemp);
	strWrite.Append(_T(","));

	strTemp.Format(_T("%d"), this->fnGetHeight());
	strWrite.Append(strTemp);
	strWrite.Append(_T("\" "));


	//Text Color
	strWrite.Append(_T(" TextColor = \"#"));
	strTemp.Format(_T("%x%x%x\""), mTRed, mTGreen, mTBlue);
	strWrite.Append(strTemp);

	strWrite.Append(_T(" BackgroundColor = \"#"));
	strTemp.Format(_T("%x%x%x\""), mbRed, mbGreen, mbBlue);
	strWrite.Append(strTemp);

	strWrite.Append(_T(" BorderColor = \"#"));
	strTemp.Format(_T("%x%x%x\""), mBorderRed, mBorderGreen, mBorderBlue);
	strWrite.Append(strTemp);

	

	strWrite.Append(this->mstrCaption);	 
	strWrite.Append(_T("/>"));

	pFile->Write(strWrite, sizeof(TCHAR)*strWrite.GetLength());
}
