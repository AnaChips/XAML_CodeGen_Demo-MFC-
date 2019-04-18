// EntryDialogue.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "EntryDialogue.h"
#include "afxdialogex.h"


// EntryDialogue dialog

IMPLEMENT_DYNAMIC(EntryDialogue, CDialog)

EntryDialogue::EntryDialogue(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_ENTRY, pParent)
{

}

EntryDialogue::~EntryDialogue()
{
}

void EntryDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mCaption);
	DDV_MaxChars(pDX, mCaption, 40);
}


BEGIN_MESSAGE_MAP(EntryDialogue, CDialog)

	ON_BN_CLICKED(IDC_TextColorBUTTON, &EntryDialogue::OnTextColorButton)
	ON_BN_CLICKED(IDC_BackColorBUTTON, &EntryDialogue::OnBackColor)

	ON_BN_CLICKED(IDC_RADIO_YES, &EntryDialogue::OnBnClickedRadioYes)
	ON_BN_CLICKED(IDC_RADIO_NO, &EntryDialogue::OnBnClickedRadioNo)
END_MESSAGE_MAP()


// EntryDialogue message handlers
void EntryDialogue::OnTextColorButton()
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

LOGFONT EntryDialogue::fnGetLfont()
{
	return mlfont;
}

void EntryDialogue::fnSetFont(LOGFONT font)
{
	mlfont = font;
}

int EntryDialogue::fnGetTextRed()
{
	return iTR;
}

int EntryDialogue::fnGetTextGreen()
{
	return iTG;
}

int EntryDialogue::fnGetTextBlue()
{
	return iTB;
}

void EntryDialogue::fnSetTextRed(int Red)
{
	iTR = Red;
}

void EntryDialogue::fnSetTextGreen(int Green)
{
	iTG = Green;
}

void EntryDialogue::fnSetTextBlue(int Blue)
{
	iTB = Blue;
}

int EntryDialogue::fnGetBackRed()
{
	return iBR;
}

int EntryDialogue::fnGetBackGreen()
{
	return iBG;
}

int EntryDialogue::fnGetBackBlue()
{
	return iBB;
}

void EntryDialogue::fnSetBackRed(int Red)
{
	iBR = Red;
}

void EntryDialogue::fnSetBackGreen(int Green)
{
	iBG = Green;
}

void EntryDialogue::fnSetBackBlue(int Blue)
{
	iBB = Blue;
}

void EntryDialogue::fnSetCpation(CString Caption)
{
	mCaption = Caption;
}

CString EntryDialogue::fnGetCaption()
{
	return mCaption;
}


void EntryDialogue::OnBnClickedRadioTelephonic()
{
	miKeyboard = TELEPHONIC;
}
void EntryDialogue::OnBnClickedRadioChat()
{
	miKeyboard = CHAT;
}
void EntryDialogue::OnBnClickedRadioEmail()
{
	miKeyboard = EMAIL;
}
void EntryDialogue::OnBnClickedRadioNumeric()
{
	miKeyboard = NUMERIC;
}
void EntryDialogue::OnBnClickedRadioDefault()
{
	miKeyboard = DEFAULT;
}

void EntryDialogue::fnSetKeyboard(int Keyboard)
{
	miKeyboard = Keyboard;
}
int EntryDialogue::fnGetKeyboard()
{
	return miKeyboard;
}


void EntryDialogue::fnSetPassword(int Password)
{
	miPassword = Password;
}
int EntryDialogue::fnGetPassword()
{
	return miPassword;
}



void EntryDialogue::OnBackColor()
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


void EntryDialogue::OnBnClickedRadioYes()
{
	miPassword = YES;
}


void EntryDialogue::OnBnClickedRadioNo()
{
	miPassword = NO;
}
