#pragma once


// ButtonDialogue dialog

class ButtonDialogue : public CDialog
{
	DECLARE_DYNAMIC(ButtonDialogue)

public:
	ButtonDialogue(CWnd* pParent = NULL);   // standard constructor
	virtual ~ButtonDialogue();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BUTTON };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTextColorButton();
	afx_msg void OnChooseFont();
	afx_msg void OnBackColor();
	afx_msg void OnBorderColor();

	afx_msg void OnBnClickedRadioMicro();
	afx_msg void OnBnClickedRadioSmall();
	afx_msg void OnBnClickedRadioMedim();
	afx_msg void OnBnClickedRadioLarge();
	afx_msg void OnBnClickedRadioDefault();

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();		
	afx_msg void OnBnClickedRadio3();



private:
	// Adjusts the edges of the button
	int miBorderRad;
	// Adjusts the Border Thickness of the Label
	int miBorderThickness;
	LOGFONT mlfont; //stores logical font
	int iBR, iBG, iBB; // colorref for Background
	int iTR, iTG, iTB; // colorref for Text
	int miBoR, miBoG, miBoB; //colorref for Border

	CString mCaption; //Caption

	int miFontSize; //Font Choice
	int miFontFaceOption; //FontFace Choice

public:
	enum { MICRO = 0, SMALL = 1, MEDIUM, LARGE, DEFAULT };
	enum { SERIF = 0, SANS_SERIF = 1, MONOSPACE };
	
	int fnGetBorderRad();
	void fnSetBorderRad(int Border_Radius);

	int fnGetBorderThickness();
	void fnSetBorderThickness(int Border_Thickness);

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

	int fnGetBorderRed();
	int fnGetBorderGreen();
	int fnGetBorderBlue();

	void fnSetBorderRed(int Red);
	void fnSetBorderGreen(int Green);
	void fnSetBorderBlue(int Blue);


	void fnSetCpation(CString Caption);
	CString fnGetCaption();

	void fnSetFontSize(int Font);
	int fnGetFontSize();

	void fnSetFontFace(int Font);
	int fnGetFontFace();

	//font button
	LOGFONT fnGetLfont();
	void fnSetFont(LOGFONT font);
};
