// EditorDialogue.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "EditorDialogue.h"
#include "afxdialogex.h"


// EditorDialogue dialog

IMPLEMENT_DYNAMIC(EditorDialogue, CDialog)

EditorDialogue::EditorDialogue(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_EDITOR, pParent)
{

}

EditorDialogue::~EditorDialogue()
{
}

void EditorDialogue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mCaption);
	DDV_MaxChars(pDX, mCaption, 40);
}


BEGIN_MESSAGE_MAP(EditorDialogue, CDialog)

	ON_BN_CLICKED(IDC_TextColorBUTTON, &EditorDialogue::OnTextColorButton)
	ON_BN_CLICKED(IDC_FontBUTTON, &EditorDialogue::OnChooseFont)
	ON_BN_CLICKED(IDC_BackColorBUTTON, &EditorDialogue::OnBackColor)

	ON_BN_CLICKED(IDC_RADIO_MICRO, &EditorDialogue::OnBnClickedRadioTelephonic)
	ON_BN_CLICKED(IDC_RADIO_SMALL, &EditorDialogue::OnBnClickedRadioChat)
	ON_BN_CLICKED(IDC_RADIO_MEDIM, &EditorDialogue::OnBnClickedRadioEmail)
	ON_BN_CLICKED(IDC_RADIO_LARGE, &EditorDialogue::OnBnClickedRadioNumeric)
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, &EditorDialogue::OnBnClickedRadioDefault)

END_MESSAGE_MAP()


// EditorDialogue message handlers
void EditorDialogue::OnTextColorButton()
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
void EditorDialogue::OnChooseFont()
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


LOGFONT EditorDialogue::fnGetLfont()
{
	return mlfont;
}

void EditorDialogue::fnSetFont(LOGFONT font)
{
	mlfont = font;
}

int EditorDialogue::fnGetTextRed()
{
	return iTR;
}

int EditorDialogue::fnGetTextGreen()
{
	return iTG;
}

int EditorDialogue::fnGetTextBlue()
{
	return iTB;
}

void EditorDialogue::fnSetTextRed(int Red)
{
	iTR = Red;
}

void EditorDialogue::fnSetTextGreen(int Green)
{
	iTG = Green;
}

void EditorDialogue::fnSetTextBlue(int Blue)
{
	iTB = Blue;
}

int EditorDialogue::fnGetBackRed()
{
	return iBR;
}

int EditorDialogue::fnGetBackGreen()
{
	return iBG;
}

int EditorDialogue::fnGetBackBlue()
{
	return iBB;
}

void EditorDialogue::fnSetBackRed(int Red)
{
	iBR = Red;
}

void EditorDialogue::fnSetBackGreen(int Green)
{
	iBG = Green;
}

void EditorDialogue::fnSetBackBlue(int Blue)
{
	iBB = Blue;
}

void EditorDialogue::fnSetCpation(CString Caption)
{
	mCaption = Caption;
}

CString EditorDialogue::fnGetCaption()
{
	return mCaption;
}


void EditorDialogue::OnBnClickedRadioTelephonic()
{
	miKeyboard = TELEPHONIC;
}
void EditorDialogue::OnBnClickedRadioChat()
{
	miKeyboard = CHAT;
}
void EditorDialogue::OnBnClickedRadioEmail()
{
	miKeyboard = EMAIL;
}
void EditorDialogue::OnBnClickedRadioNumeric()
{
	miKeyboard = NUMERIC;
}
void EditorDialogue::OnBnClickedRadioDefault()
{
	miKeyboard = DEFAULT;
}
void EditorDialogue::fnSetKeyboard(int Keyboard)
{
	miKeyboard = Keyboard;
}

int EditorDialogue::fnGetKeyboard()
{
	return miKeyboard;
}

void EditorDialogue::OnBackColor()
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
