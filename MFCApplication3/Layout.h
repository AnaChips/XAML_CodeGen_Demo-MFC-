#pragma once

#include "stdafx.h"
#include "Element.h"
class Layout : public Element
{
public:
	CObArray mElementArray;

public:
	Layout();
	virtual void fnDraw(CDC * pdc) {};
	virtual void fnWriteToFile(CFile * pFile, int Top, int Left) {};
};