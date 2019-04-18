#pragma once

#include "EditorDialogue.h"
#include "Element.h"
class Editor : public Element
{
private:
	int miKeyboard;
public:
	Editor();
	enum { DEFAULT = 0, CHAT = 1, EMAIL, NUMERIC, TELEPHONIC };

	void fnDraw(CDC * pdc);

	//Dialogue
	void fnPopDialogue();

	//XAML
	void fnWriteToFile(CFile * pFile, int Top, int Left);

};
