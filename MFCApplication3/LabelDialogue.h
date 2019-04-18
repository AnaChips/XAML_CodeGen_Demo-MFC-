#pragma once


// LabelDialogue dialog

class LabelDialogue : public CDialog
{
	DECLARE_DYNAMIC(LabelDialogue)

public:
	LabelDialogue(CWnd* pParent = NULL);   // standard constructor
	virtual ~LabelDialogue();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBackColor();
	afx_msg void OnTextColorButton();
	afx_msg void OnChooseFont();
	
	afx_msg void OnBnClickedMicro();
	afx_msg void OnBnClickedRadioSmall();
	afx_msg void OnBnClickedRadioMedim();
	afx_msg void OnBnClickedRadioLarge();
	afx_msg void OnBnClickedRadioDefault();

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
private:
	
	LOGFONT mlfont; //stores logical font
	int iBR, iBG, iBB; // colorref for Text
	int iTR, iTG, iTB; // colorref for Text
	CString mCaption; //Caption
	
	int miFontSize; //Font Choice
	int miFontFaceOption; //FontFace Choice

public:
	enum {MICRO =	0, SMALL = 1, MEDIUM, LARGE, DEFAULT};
	enum { SERIF = 0, SANS_SERIF = 1, MONOSPACE };

	int fnGetTextRed();
	int fnGetTextGreen();
	int fnGetTextBlue();
	
	void fnSetTextRed(int Red);
	void fnSetTextGreen(int Green);
	void fnSetTextBlue(int Blue);

	int fnGetBackRed();
	int fnGetBackGreen();
	int fnGetBackBlue();

	void fnSetBackRed(int Red);
	void fnSetBackGreen(int Green);
	void fnSetBackBlue(int Blue);


	void fnSetCpation(CString Caption);
	CString fnGetCaption();

	//radio button
	void fnSetFontSize(int Font);
	int fnGetFontSize();

	void fnSetFontFace(int Font);
	int fnGetFontFace();

	//display
	LOGFONT fnGetLfont();
	void fnSetFont(LOGFONT font);
	
};
