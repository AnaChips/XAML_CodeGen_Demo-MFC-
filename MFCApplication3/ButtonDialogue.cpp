// ButtonDialogue.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "ButtonDialogue.h"
#include "afxdialogex.h"


// ButtonDialogue dialog

IMPLEMENT_DYNAMIC(ButtonDialogue, CDialog)

ButtonDialogue::ButtonDialogue(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_BUTTON, pParent)
	, miBorderRad(0)
	, miBorderThickness(0)
	, mCaption(_T(""))
{

}

ButtonDialogue::~ButtonDialogue()
{
}

void ButtonDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, miBorderRad);
	DDX_Text(pDX, IDC_EDIT3, miBorderThickness);
	DDX_Text(pDX, IDC_EDIT1, mCaption);
	DDV_MaxChars(pDX, mCaption, 40);
}


BEGIN_MESSAGE_MAP(ButtonDialogue, CDialog)
	
	ON_BN_CLICKED(IDC_TextColorBUTTON, &ButtonDialogue::OnTextColorButton)
	ON_BN_CLICKED(IDC_FontBUTTON, &ButtonDialogue::OnChooseFont)
	ON_BN_CLICKED(IDC_BackColorBUTTON, &ButtonDialogue::OnBackColor)
	ON_BN_CLICKED(IDC_BUTTON1, &ButtonDialogue::OnBorderColor)

	ON_BN_CLICKED(IDC_RADIO_MICRO, &ButtonDialogue::OnBnClickedRadioMicro)
	ON_BN_CLICKED(IDC_RADIO_SMALL, &ButtonDialogue::OnBnClickedRadioSmall)
	ON_BN_CLICKED(IDC_RADIO_MEDIM, &ButtonDialogue::OnBnClickedRadioMedim)
	ON_BN_CLICKED(IDC_RADIO_LARGE, &ButtonDialogue::OnBnClickedRadioLarge)
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, &ButtonDialogue::OnBnClickedRadioDefault)
	
	ON_BN_CLICKED(IDC_RADIO1, &ButtonDialogue::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &ButtonDialogue::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &ButtonDialogue::OnBnClickedRadio3)
	
	
	
END_MESSAGE_MAP()


// ButtonDialogue message handlers


void ButtonDialogue::OnTextColorButton()
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
void ButtonDialogue::OnChooseFont()
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

int ButtonDialogue::fnGetBorderRad()
{
	return miBorderRad;
}

void ButtonDialogue::fnSetBorderRad(int Border_Radius)
{
	miBorderRad = Border_Radius;
}

int ButtonDialogue::fnGetBorderThickness()
{
	return miBorderThickness;
}

void ButtonDialogue::fnSetBorderThickness(int Border_Thickness)
{
	miBorderThickness = Border_Thickness;
}

LOGFONT ButtonDialogue::fnGetLfont()
{
	return mlfont;
}

void ButtonDialogue::fnSetFont(LOGFONT font)
{
	mlfont = font;
}

int ButtonDialogue::fnGetTextRed()
{
	return iTR;
}

int ButtonDialogue::fnGetTextGreen()
{
	return iTG;
}

int ButtonDialogue::fnGetTextBlue()
{
	return iTB;
}

void ButtonDialogue::fnSetTextRed(int Red)
{
	iTR = Red;
}

void ButtonDialogue::fnSetTextGreen(int Green)
{
	iTG = Green;
}

void ButtonDialogue::fnSetTextBlue(int Blue)
{
	iTB = Blue;
}

int ButtonDialogue::fnGetBackRed()
{
	return iBR;
}

int ButtonDialogue::fnGetBackGreen()
{
	return iBG;
}

int ButtonDialogue::fnGetBackBlue()
{
	return iBB;
}

void ButtonDialogue::fnSetBackRed(int Red)
{
	iBR = Red;
}

void ButtonDialogue::fnSetBackGreen(int Green)
{
	iBG = Green;
}

void ButtonDialogue::fnSetBackBlue(int Blue)
{
	iBB = Blue;
}

int ButtonDialogue::fnGetBorderRed()
{
	return miBoR;
}

int ButtonDialogue::fnGetBorderGreen()
{
	return miBoG;
}

int ButtonDialogue::fnGetBorderBlue()
{
	return miBoB;
}

void ButtonDialogue::fnSetBorderRed(int Red)
{
	miBoR = Red;
}

void ButtonDialogue::fnSetBorderGreen(int Green)
{
	miBoG = Green;
}

void ButtonDialogue::fnSetBorderBlue(int Blue)
{
	miBoB = Blue;
}



void ButtonDialogue::fnSetCpation(CString Caption)
{
	mCaption = Caption;
}

CString ButtonDialogue::fnGetCaption()
{
	return mCaption;
}

void ButtonDialogue::fnSetFontSize(int Font)
{
	miFontSize = Font;
}
int ButtonDialogue::fnGetFontSize()
{
	return miFontSize;
}
void ButtonDialogue::OnBnClickedRadioMicro()
{
	miFontSize = MICRO;
}
void ButtonDialogue::OnBnClickedRadioSmall()
{
	miFontSize = SMALL;
}
void ButtonDialogue::OnBnClickedRadioMedim()
{
	miFontSize = MEDIUM;
}
void ButtonDialogue::OnBnClickedRadioLarge()
{
	miFontSize = LARGE;
}
void ButtonDialogue::OnBnClickedRadioDefault()
{
	miFontSize = DEFAULT;
}




void ButtonDialogue::fnSetFontFace(int Font)
{
	miFontFaceOption = Font;
}
int ButtonDialogue::fnGetFontFace()
{
	return miFontFaceOption;
}
void ButtonDialogue::OnBnClickedRadio1()
{
	miFontFaceOption = SERIF;
}
void ButtonDialogue::OnBnClickedRadio2()
{
	miFontFaceOption = MONOSPACE;
}
void ButtonDialogue::OnBnClickedRadio3()
{
	miFontFaceOption = SANS_SERIF;
}



void ButtonDialogue::OnBackColor()
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


void ButtonDialogue::OnBorderColor()
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
		miBoR = GetRValue(cc.rgbResult);
		miBoG = GetGValue(cc.rgbResult);
		miBoB = GetBValue(cc.rgbResult);
	}
}

