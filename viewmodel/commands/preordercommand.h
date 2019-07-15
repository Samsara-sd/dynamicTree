#ifndef PREORDERCOMMAND_H
#define PREORDERCOMMAND_H

#include "../common/etlbase.h"
#include "../common/parameters.h"

class ViewModelClass;

class PreOrderCommand : public ICommandBase
{
public:
    PreOrderCommand(ViewModelClass* p) throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();

protected:
    ViewModelClass* m_pVM;

};


#endif // PREORDERCOMMAND_H
