
#include "Command.h"

int main()
{
	
	Commander *p = new Commander(new InputCommand("[empty]"));
	p->ExecuteCommand(new InputCommand("1234"));
	p->ExecuteCommand(new InputCommand("567"));
	p->ExecuteCommand(new InputCommand("xxx"));
	p->Undo();
	p->Undo();
	p->ExecuteCommand(new InputCommand("insert"));
	p->Undo();
	p->Undo();
	p->Undo();
	p->Redo();
	p->Redo();
	p->Redo();
	p->ExecuteCommand(new InputCommand("insert again"));
	p->Undo();
	p->Redo();
	p->Redo();
	p->Redo();
	delete p;
	system("pause");
	return 0;
}