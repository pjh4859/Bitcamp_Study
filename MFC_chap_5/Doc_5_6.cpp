#include "KView.h"
#include "KDocument.h"
#include <iostream>
using namespace std;
//KView(KDocument* pDoc);
//virtual ~KView();
//void SetDocument(KDocument* pDoc);
//KDocument* GetDocument();
//void SetDiplayStart(int iStart);
//void SetSelected(int iSelected);
//virtual void Draw();
KView::KView(KDocument* pDoc)
{
	m_pDocument = pDoc;
	m_iStart = 0;
	m_iDisplayStart = 0;
	m_iSelected = 0;
}

KView::~KView() {}
void KView::SetDocument(KDocument* pDoc) { m_pDocument = pDoc; }
KDocument* KView::GetDocument() { return m_pDocument; }
void KView::SetDisplayStart(int iDisplayStart) {
	m_iDisplayStart = iDisplayStart;
	m_iStart = GetDocument()->GetListBox()->SetDisplayStart(m_iDisplayStart);
}
void KView::SetSelected(int iSelected)
{
	m_iSelected = iSelected;
	GetDocument()->GetListBox()->SetDisplayStart(m_iSelected);
}
void KView::Draw()
{
	int iStart = m_iStart;
	for (KDocument::KDITOR itor = GetDocument()->GetListBox()->BeginDisplay(); itor != GetDocument()->GetListBox()->EndDisplay(); ++itor)
	{
		if (GetDocument()->GetListBox()->IsSelected(iStart))
			cout << "*";
		else
			cout << " ";
		cout << "element value = " << (*itor) << endl;
		++iStart;
	}
}