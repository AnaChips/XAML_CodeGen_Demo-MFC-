
#include "stdafx.h"
#include "AbsLay.h"

AbsLay::AbsLay()
{
	mstrType = "AbsoluteLayout";
}

void AbsLay::fnDraw(CDC * pdc)
{
	pdc->MoveTo(miLeft, miTop);
	pdc->LineTo(miRight, miTop);
	pdc->LineTo(miRight, miBottom);
	pdc->LineTo(miLeft, miBottom);
	pdc->LineTo(miLeft, miTop);
}
void AbsLay:: fnWriteToFile(CFile * pFile, int Top, int Left)
{

}