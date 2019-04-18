#pragma once

#include"stdafx.h"
#include "Element.h"

class View : public Element
{
protected:

	//Visualization
	CString mstrCaption;

	int mTRed, mTGreen, mTBlue; //text color
	int mbRed, mbGreen, mbBlue; //background color

public:
	LOGFONT mlFont;
	int miFontFace;
	int miFontSize;

public:
	enum { MICRO = 0, SMALL = 1, MEDIUM, LARGE, DEFAULT };
	enum { SERIF = 0, SANS_SERIF = 1, MONOSPACE };

	View();
	
	virtual void fnDraw(CDC * pdc) {};

	virtual CString fnGetCaption();
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

	virtual void fnTranslateFont();
	virtual void fnTranslateFontSize();

};