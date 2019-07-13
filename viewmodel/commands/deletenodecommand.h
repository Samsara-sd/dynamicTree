#ifndef DELETENODECOMMAND_H
#define DELETENODECOMMAND_H

#include "NodeCommand.h"

class ViewModelClass;

class DeleteNodeCommand : public NodeCommand
{
public:
    DeleteNodeCommand(ViewModelClass* p) throw();
    virtual void Exec();
};

#endif // DELETENODECOMMAND_H
