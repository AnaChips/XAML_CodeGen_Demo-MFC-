#pragma once


// EditorDialogue dialog

class EditorDialogue : public CDialog
{
	DECLARE_DYNAMIC(EditorDialogue)

public:
	EditorDialogue(CWnd* pParent = NULL);   // standard constructor
	virtual ~EditorDialogue();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDITOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTextColorButton();
	afx_msg void OnChooseFont();
	afx_msg void OnBackColor();

	afx_msg void OnBnClickedRadioTelephonic();
	afx_msg void OnBnClickedRadioChat();
	afx_msg void OnBnClickedRadioEmail();
	afx_msg void OnBnClickedRadioNumeric();
	afx_msg void OnBnClickedRadioDefault();


private:
	LOGFONT mlfont; //stores logical font
	int iBR, iBG, iBB; // colorref for Background
	int iTR, iTG, iTB; // colorref for Text

	CString mCaption; //Caption

	int miKeyboard;

public:
	enum { DEFAULT = 0, CHAT = 1, EMAIL, NUMERIC, TELEPHONIC };

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

	void fnSetKeyboard(int Keyboard);
	int fnGetKeyboard();

	LOGFONT fnGetLfont();
	void fnSetFont(LOGFONT font);
};
