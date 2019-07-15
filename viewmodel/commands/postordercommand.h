#ifndef POSTORDERCOMMAND_H
#define POSTORDERCOMMAND_H

#include "common/etlbase.h"
#include "common/parameters.h"

class ViewModelClass;

class PostOrderCommand : public ICommandBase
{
public:
    PostOrderCommand(ViewModelClass* p) throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();

protected:
    ViewModelClass* m_pVM;

};


#endif // PREORDERCOMMAND_H
