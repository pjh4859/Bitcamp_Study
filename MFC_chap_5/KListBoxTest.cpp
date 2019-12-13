#if 1
#include<iostream>
//#include"KListBox.h"
#include<assert.h>
#include"KDocument.h"
#include"KView.h"

class CWinApp
{
private:
	KDocument* m_pDoc;
	KView* m_pView;

public:
	CWinApp()
	{
		m_pDoc = new KDocument();
		m_pView = new KView(m_pDoc);
		m_pDoc->SetView(m_pView);
	}

	CWinApp(const CWinApp& right)
	{
		assert(!"fail");
	}

	~CWinApp()
	{
		delete m_pDoc;
		delete m_pView;
	}

	void InitInstance()
	{
		for (int i = 0; i < 20; ++i)
		{

			m_pDoc->Insert(i);
		}
	}

	void OnDraw()
	{
		m_pView->SetDisplayStart(15);
		m_pView->SetSelected(17);
		m_pView->Draw();
	}
};

CWinApp theApp;

int main()
{
	theApp.InitInstance();
	theApp.OnDraw();
	return 0;
}
#endif

//using std::cout;
//using std::endl;
//int main()
//{
//	KListBox<int> kListBox;
//
//	for (int i = 0; i < 20; ++i)
//	{
//		kListBox.Insert(i);
//	}
//
//	int iStart = kListBox.SetDisplayStart(15);
//	kListBox.SetSelected(17);
//	for (KListBox<int>::VITOR itor = kListBox.BeginDisplay();
//		itor != kListBox.EndDisplay(); ++itor)
//	{
//		if (kListBox.IsSelected(iStart))
//			cout << "*";
//		else
//			cout << " ";
//		cout << "element value=" << (*itor) << endl;
//		++iStart;
//	}
//}
