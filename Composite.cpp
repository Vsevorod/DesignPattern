#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Component
{
public:
	string m_strName;
	Component(string strName)
	{
		this->m_strName = strName;
	}
	virtual void add(Component *com) = 0;
	virtual void display(int nDepth) = 0;

};
class Leaf :public Component
{
public:
	Leaf(string strName) :Component(strName){ }
	virtual void add(Component *com){ cout << "can't add leaf" << endl; }
	virtual void display(int nDepth)
	{
		string strTemp;
		for (int i = 0; i < nDepth; i++)
		{
			strTemp += "-";
		}
		strTemp += this->m_strName;
		cout << strTemp << endl;

	}

};

class Composite :public Component
{
public:
	Composite(string strName) :Component(strName){}
	virtual void add(Component *com){ m_pCom.push_back(com); }
	virtual void display(int nDepth)
	{
		string strTemp;
		for (int i = 0; i < nDepth; i++)
		{
			strTemp += "-";
		}
		strTemp += this->m_strName;
		cout << strTemp << endl;
		vector<Component*>::iterator it = m_pCom.begin();
		while (it != m_pCom.end())
		{
			(*it)->display(nDepth + 2);
			++it;
		}
		
	}


private:
	vector<Component*>m_pCom;
};


int main()
{
	Composite *p = new Composite("�ܹ�˾");
	Composite *pM = new Composite("�Ͼ��ֹ�˾");
	p->add(pM);
	pM->add(new Leaf("������"));
	pM->add(new Leaf("���۲�"));
	Composite *pS = new Composite("�Ϻ��ֹ�˾");
	p->add(pS);
	pS->add(new Leaf("������"));
	pS->add(new Leaf("���۲�"));
	p->add(new Leaf("������"));
	p->add(new Leaf("���۲�"));
	p->display(1);
	system("pause");


};
