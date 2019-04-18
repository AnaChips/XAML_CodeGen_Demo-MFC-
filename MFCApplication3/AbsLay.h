#pragma once

#include "Layout.h"


class AbsLay : public Layout
{
public:
	AbsLay();
	void fnDraw(CDC * pdc);
	void fnWriteToFile(CFile * pFile, int Top, int Left);
};