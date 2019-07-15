#ifndef INORDERCOMMAND_H
#define INORDERCOMMAND_H

#include "common/etlbase.h"
#include "common/parameters.h"

class ViewModelClass;

class InOrderCommand : public ICommandBase
{
public:
    InOrderCommand(ViewModelClass* p) throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();

protected:
    ViewModelClass* m_pVM;

};


#endif // PREORDERCOMMAND_H
