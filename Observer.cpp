#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;

Observer::Observer()
{}

Observer::~Observer()
{}

ConcreteObserverA::ConcreteObserverA()
{}

ConcreteObserverA::~ConcreteObserverA()
{}

void ConcreteObserverA::Update(Subject* pSubject)
{
	this->state = pSubject->GetState();
	cout << "The ConcreteObserverA is " << state << std::endl;
}

ConcreteObserverB::ConcreteObserverB()
{}

ConcreteObserverB::~ConcreteObserverB()
{}

void ConcreteObserverB::Update(Subject* pSubject)
{
	this->state = pSubject->GetState();
	cout << "The ConcreteObserverB is " << state << std::endl;
}

Subject::Subject()
{}

Subject::~Subject()
{}

void Subject::Attach(Observer* pObserver)
{
	this->lst.push_back(pObserver);
	cout << "Attach an Observer\n";
}

void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(lst.begin(), lst.end(), pObserver);
	if (iter != lst.end())
	{
		lst.erase(iter);
	}
	cout << "Detach an Observer\n";
}

void Subject::Notify()
{
	list<Observer*>::iterator iter = this->lst.begin();
	for (; iter != lst.end(); iter++)
	{
		(*iter)->Update(this);
	}
}

string Subject::GetState()
{
	return this->state;
}

void Subject::SetState(string state)
{
	this->state = state;
}

ConcreteSubjectA::ConcreteSubjectA()
{}

ConcreteSubjectA::~ConcreteSubjectA()
{}

ConcreteSubjectB::ConcreteSubjectB()
{}

ConcreteSubjectB::~ConcreteSubjectB()
{}