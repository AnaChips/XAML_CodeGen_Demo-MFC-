#pragma once

#include "ButtonDialogue.h"
#include "Element.h"
class RectButton : public Element
{
private:
	int miBorderRadius;
	int miBorderWidth;

	int mBorderRed;
	int mBorderGreen;
	int mBorderBlue;

public:
	RectButton();
	enum { SERIF = 0, SANS_SERIF = 1, MONOSPACE };
	
	//Visual Rendering
	void fnDraw(CDC * pdc);
	void fnSetBorderRad(int Radius);
	void fnSetBorderWidth(int Width);

	void fnSetBorderRed(int Red);
	void fnSetBorderGreen(int Green);
	void fnSetBorderBlue(int Blue);

	int fnGetTextRed();
	int fnGetTextGreen();
	int fnGetTextBlue();

	//Dialogue
	void fnPopDialogue();

	//Code Gen
	void fnWriteToFile(CFile * pFile, int Top, int Left);

};
