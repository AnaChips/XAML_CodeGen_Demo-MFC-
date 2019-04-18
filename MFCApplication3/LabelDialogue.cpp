// LabelDialogue.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "LabelDialogue.h"
#include "afxdialogex.h"


// LabelDialogue dialog

IMPLEMENT_DYNAMIC(LabelDialogue, CDialog)

LabelDialogue::LabelDialogue(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, mCaption(_T(""))
{

}

LabelDialogue::~LabelDialogue()
{
}

void LabelDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mCaption);
	DDV_MaxChars(pDX, mCaption, 40);
}


BEGIN_MESSAGE_MAP(LabelDialogue, CDialog)
	ON_BN_CLICKED(IDC_BackColorBUTTON, &LabelDialogue::OnBackColor)
	ON_BN_CLICKED(IDC_TextColorBUTTON, &LabelDialogue::OnTextColorButton)
	ON_BN_CLICKED(IDC_FontBUTTON, &LabelDialogue::OnChooseFont)
	ON_BN_CLICKED(IDC_RADIO_MICRO, &LabelDialogue::OnBnClickedMicro)
	ON_BN_CLICKED(IDC_RADIO_SMALL, &LabelDialogue::OnBnClickedRadioSmall)
	ON_BN_CLICKED(IDC_RADIO_MEDIM, &LabelDialogue::OnBnClickedRadioMedim)
	ON_BN_CLICKED(IDC_RADIO_LARGE, &LabelDialogue::OnBnClickedRadioLarge)
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, &LabelDialogue::OnBnClickedRadioDefault)
	ON_BN_CLICKED(IDC_RADIO1, &LabelDialogue::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &LabelDialogue::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &LabelDialogue::OnBnClickedRadio3)
END_MESSAGE_MAP()


// LabelDialogue message handlers


void LabelDialogue::OnBackColor()
{
	CHOOSECOLOR cc;                 // common dialog box structure 
	COLORREF acrCustClr[16]; // array of custom colors 

	ZeroMemory(&cc, sizeof(cc));
	cc.lStructSize = sizeof(cc);
	cc.hwndOwner = this->m_hWnd;
	cc.lpCustColors = (LPDWORD)acrCustClr;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;

	if (ChooseColor(&cc) == TRUE)
	{
		iBR = GetRValue(cc.rgbResult);
		iBG = GetGValue(cc.rgbResult);
		iBB = GetBValue(cc.rgbResult);
	}
}
void LabelDialogue::OnTextColorButton()
{
	CHOOSECOLOR cc;                 // common dialog box structure 
	COLORREF acrCustClr[16]; // array of custom colors 

	ZeroMemory(&cc, sizeof(cc));
	cc.lStructSize = sizeof(cc);
	cc.hwndOwner = this->m_hWnd;
	cc.lpCustColors = (LPDWORD)acrCustClr;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;

	if (ChooseColor(&cc) == TRUE)
	{
		iTR = GetRValue(cc.rgbResult);
		iTG = GetGValue(cc.rgbResult);
		iTB = GetBValue(cc.rgbResult);
	}
}
void LabelDialogue::OnChooseFont()
{
	CHOOSEFONT cf;            // common dialog box structure

	ZeroMemory(&cf, sizeof(cf));
	cf.lStructSize = sizeof(CHOOSEFONT);
	cf.hwndOwner = this->m_hWnd;
	cf.lpLogFont = &mlfont;
	cf.Flags = CF_SCREENFONTS | CF_LIMITSIZE | CF_FORCEFONTEXIST | CF_INITTOLOGFONTSTRUCT | CF_TTONLY;
	cf.nSizeMin = 8;
	cf.nSizeMax = 72;
	cf.iPointSize = 120;
	if (ChooseFont(&cf) == TRUE)
	{
	}
}

LOGFONT LabelDialogue::fnGetLfont()
{
	return mlfont;
}

void LabelDialogue::fnSetFont(LOGFONT font)
{
	mlfont = font;
}

int LabelDialogue::fnGetTextRed()
{
	return iTR;
}

int LabelDialogue::fnGetTextGreen()
{
	return iTG;
}

int LabelDialogue::fnGetTextBlue()
{
	return iTB;
}

void LabelDialogue::fnSetTextRed(int Red)
{
	iTR = Red;
}

void LabelDialogue::fnSetTextGreen(int Green)
{
	iTG = Green;
}

void LabelDialogue::fnSetTextBlue(int Blue)
{
	iTB = Blue;
}

int LabelDialogue::fnGetBackRed()
{
	return iBR;
}

int LabelDialogue::fnGetBackGreen()
{
	return iBG;
}

int LabelDialogue::fnGetBackBlue()
{
	return iBB;
}

void LabelDialogue::fnSetBackRed(int Red)
{
	iBR = Red;
}

void LabelDialogue::fnSetBackGreen(int Green)
{
	iBG = Green;
}

void LabelDialogue::fnSetBackBlue(int Blue)
{
	iBB = Blue;
}

void LabelDialogue::fnSetCpation(CString Caption)
{
	mCaption = Caption;
}

CString LabelDialogue::fnGetCaption()
{
	return mCaption;
}


void LabelDialogue::fnSetFontSize(int Font)
{
	miFontSize = Font;
}
int LabelDialogue::fnGetFontSize()
{
	return miFontSize;
}
void LabelDialogue::OnBnClickedMicro()
{
	miFontSize = MICRO;
}
void LabelDialogue::OnBnClickedRadioSmall()
{
	miFontSize = SMALL;
}
void LabelDialogue::OnBnClickedRadioMedim()
{
	miFontSize = MEDIUM;
}
void LabelDialogue::OnBnClickedRadioLarge()
{
	miFontSize = LARGE;
}
void LabelDialogue::OnBnClickedRadioDefault()
{
	miFontSize = DEFAULT;
}






void LabelDialogue::fnSetFontFace(int Font)
{
	miFontFaceOption = Font;
}

int LabelDialogue::fnGetFontFace()
{
	return miFontFaceOption;
}
void LabelDialogue::OnBnClickedRadio1()
{
	miFontFaceOption = SERIF;
}

void LabelDialogue::OnBnClickedRadio2()
{
	miFontFaceOption = MONOSPACE;
}
void LabelDialogue::OnBnClickedRadio3()
{
	miFontFaceOption = SANS_SERIF;
}
