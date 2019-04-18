#pragma once
#pragma once

#include "EntryDialogue.h"
#include "Element.h"
class Entry : public Element
{
private:

	int miPassword;
	int miKeyboard;

public:
	Entry();
	enum { DEFAULT = 0, CHAT = 1, EMAIL, NUMERIC, TELEPHONIC };

	void fnDraw(CDC * pdc);

	//Dialogue
	void fnPopDialogue();

	//XAML
	void fnWriteToFile(CFile * pFile, int Top, int Left);

};
