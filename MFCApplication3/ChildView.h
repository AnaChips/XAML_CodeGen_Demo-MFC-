
#define		CANVAS_HORIZONTAL_SPAN		200
#define		CANVAS_VERTICAL_SPAN		300

//custom classes

#include "Entry.h"
#include "Editor.h"
#include "Label.h"
#include "RectButton.h"
#include "Element.h"

#include "MyCanvas.h"
#include "LabelDialogue.h"

// ChildView.h : interface of the CChildView class
#pragma once

class CChildView : public CWnd
{
// Construction
public:	CChildView();

//attributes
private: CMyCanvas Canvas;


// Overrides
protected:	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:	virtual ~CChildView();

// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnAddlabel();
	afx_msg void OnAddRectButton();
	afx_msg void OnGenerateXAML();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRepaint();
	afx_msg void OnAddEditor();
	afx_msg void OnElementoptionsAddentry();
};



