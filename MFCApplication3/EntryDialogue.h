#pragma once


// EntryDialogue dialog

class EntryDialogue : public CDialog
{
	DECLARE_DYNAMIC(EntryDialogue)

public:
	EntryDialogue(CWnd* pParent = NULL);   // standard constructor
	virtual ~EntryDialogue();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENTRY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTextColorButton();
	afx_msg void OnBackColor();

	afx_msg void OnBnClickedRadioTelephonic();
	afx_msg void OnBnClickedRadioChat();
	afx_msg void OnBnClickedRadioEmail();
	afx_msg void OnBnClickedRadioNumeric();
	afx_msg void OnBnClickedRadioDefault();


	afx_msg void OnBnClickedRadioYes();
	afx_msg void OnBnClickedRadioNo();


private:
	LOGFONT mlfont; //stores logical font
	int iBR, iBG, iBB; // colorref for Background
	int iTR, iTG, iTB; // colorref for Text

	CString mCaption; //Caption

	int miPassword;
	int miKeyboard;

public:
	enum { DEFAULT = 0, CHAT = 1, EMAIL, NUMERIC, TELEPHONIC };
	enum { YES = 0, NO = 1 };

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

	void fnSetPassword(int Password);
	int fnGetPassword();

	void fnSetKeyboard(int Keyboard);
	int fnGetKeyboard();


	LOGFONT fnGetLfont();
	void fnSetFont(LOGFONT font);

};
