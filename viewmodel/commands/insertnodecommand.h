#ifndef INSERTNODECOMMAND_H
#define INSERTNODECOMMAND_H

#include "NodeCommand.h"

class ViewModelClass;

class InsertNodeCommand : public NodeCommand
{
public:
    InsertNodeCommand(ViewModelClass* p) throw();
    virtual void Exec();
};


#endif // INSERTNODECOMMAND_H
