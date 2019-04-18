#pragma once

#include "LabelDialogue.h"
#include "Element.h"


class Label : public Element
{
private:
	int miBorderWidth;

public:

	enum { SERIF = 0, SANS_SERIF = 1, MONOSPACE };


	Label();
	void fnDraw(CDC * pdc);
	void fnSetBorderWidth(int Width);
	

	//Dialogue
	void fnPopDialogue();

	//XAML
	void fnWriteToFile(CFile * pFile, int Top, int Left);

};