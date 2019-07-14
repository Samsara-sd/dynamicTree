#ifndef FINDNODECOMMAND_H
#define FINDNODECOMMAND_H

#include "NodeCommand.h"

class ViewModelClass;

class FindNodeCommand : public NodeCommand
{
public:
    FindNodeCommand(ViewModelClass* p) throw();
    virtual void Exec();
};

#endif // FINDNODECOMMAND_H
