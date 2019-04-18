#pragma once

class Element : public CObject
{
protected:  

	//Visualization
	int miTop, miBottom, miRight, miLeft;
	CString mstrCaption;

	int mTRed, mTGreen, mTBlue; //text color
	int mbRed, mbGreen, mbBlue; //background color

	//Code Gen
	CString mstrType;

public:
	LOGFONT mlFont;
	int miFontFace;
	int miFontSize;

public:
	enum { MICRO = 0, SMALL = 1, MEDIUM, LARGE, DEFAULT };
	enum { SERIF = 0, SANS_SERIF = 1, MONOSPACE };

	Element();
	virtual void fnSetLoc(int top, int left, int bottom, int right);
	virtual void fnDraw(CDC * pdc) {};

	virtual int fnGetTop();
	virtual int fnGetLeft();
	virtual int fnGetBottom();
	virtual int fnGetRight();
	virtual int fnGetHeight();

	virtual int fnGetWidth();

	virtual CString fnGetCaption();
	virtual CString fnGetElementType();

	virtual bool OnLButtonDown(CPoint point);
	virtual void fnShowCaption(CDC * pdc, int HCenter = DT_CENTER, int VCenter = DT_VCENTER, int SingleLine = DT_SINGLELINE);


	virtual void fnSetCaption(CString Caption);

	virtual void fnSetTextRed(int Red);
	virtual void fnSetTextGreen(int Green);
	virtual void fnSetTextBlue(int Blue);
	
	virtual int fnGetTextRed();
	virtual int fnGetTextGreen();
	virtual int fnGetTextBlue();


	virtual void fnPopDialogue() {};
	virtual void fnWriteToFile(CFile * pFile, int Top, int Left) {};

	virtual void fnSetBackRed(int Red);
	virtual void fnSetBackGreen(int Green);
	virtual void fnSetBackBlue(int Blue);
	
	virtual int fnGetBackRed();
	virtual int fnGetBackGreen();
	virtual int fnGetBackBlue();

	void fnTranslateFont();
	void fnTranslateFontSize();

};