#include "stdafx.h"
#include "Editor.h"

Editor::Editor()
{

	mbRed = 0; mbGreen = 64; mbBlue = 128;
	mTRed = 119; mTGreen = 077; mTBlue = 189;

	mstrType = "Editor";

	mstrCaption = "MyEditor";
}

void Editor::fnDraw(CDC * pdc)
{
	CPen Pen;
	CPen* pOldPen = NULL;

	CBrush Brush;
	CBrush* pOldBrush = NULL;
	Brush.CreateSolidBrush(RGB(mbRed, mbGreen, mbBlue));


	Pen.CreatePen(PS_SOLID, 2, RGB(mbRed, mbGreen, mbBlue));
	pOldPen = (CPen*)pdc->SelectObject(&Pen);

	pOldBrush = (CBrush*)pdc->SelectObject(&Brush);
	pdc->Rectangle(miLeft, miTop, miRight, miBottom);

	pdc->SelectObject(pOldBrush);
	pdc->SelectObject(pOldPen);

	fnShowCaption(pdc);
}

void Editor::fnPopDialogue()
{
	EditorDialogue testdlg;

	testdlg.fnSetCpation(mstrCaption);

	testdlg.fnSetTextRed(mTRed);
	testdlg.fnSetTextGreen(mTGreen);
	testdlg.fnSetTextBlue(mTBlue);

	testdlg.fnSetBackRed(mbRed);
	testdlg.fnSetBackGreen(mbGreen);
	testdlg.fnSetBackBlue(mbBlue);
	testdlg.fnSetFont(mlFont);

	testdlg.fnSetKeyboard(miKeyboard);

	if (IDOK == testdlg.DoModal())
	{
		mbRed = testdlg.fnGetBackRed();
		mbGreen = testdlg.fnGetBackGreen();
		mbBlue = testdlg.fnGetBackBlue();

		mstrCaption = testdlg.fnGetCaption();

		mlFont = testdlg.fnGetLfont();

		mTRed = testdlg.fnGetTextRed();
		mTGreen = testdlg.fnGetTextGreen();
		mTBlue = testdlg.fnGetTextBlue();

		miKeyboard = testdlg.fnGetKeyboard();
	}
}

void Editor::fnWriteToFile(CFile * pFile, int Top, int Left)
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

	/*HDC hDC = GetDC(NULL);
	int c = MulDiv((-1) * mlFont.lfHeight, 72, GetDeviceCaps(hDC,LOGPIXELSY));
	strWrite.Append(_T(" FontSize = "));
	strTemp.Format(_T("%d"), c);
	strWrite.Append(strTemp);
	*/

	strWrite.Append(_T("</OnPlatform.Android> \r\n </OnPlatform>\r\n </Editor>"));

	pFile->Write(strWrite, sizeof(TCHAR)*strWrite.GetLength());
}

