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
	Composite *p = new Composite("总公司");
	Composite *pM = new Composite("南京分公司");
	p->add(pM);
	pM->add(new Leaf("技术部"));
	pM->add(new Leaf("销售部"));
	Composite *pS = new Composite("上海分公司");
	p->add(pS);
	pS->add(new Leaf("技术部"));
	pS->add(new Leaf("销售部"));
	p->add(new Leaf("技术部"));
	p->add(new Leaf("销售部"));
	p->display(1);
	system("pause");


};
