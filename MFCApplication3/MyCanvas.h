#pragma once

#include "SelRect.h"
#include "Element.h"

class CMyCanvas
{
public:
	int miTop, miBottom, miLeft, miRight;
	int miElementNo;
	Element * mpSelectedElement;
	SelRect mSelRect;

public:
	CObArray mElementArray;


	CMyCanvas();
	void fnDraw(CDC *pdc);
	void fnSetParams(int Left, int Top, int Right, int Bottom);
	void fnOnLButtonDown(CPoint point);
	int fnGetTop();
	int fnGetLeft();
	int fnGetBottom();
	int fnGetRight();

	~CMyCanvas() {};
};