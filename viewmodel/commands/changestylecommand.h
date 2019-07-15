#ifndef CHANGESTYLECOMMAND_H
#define CHANGESTYLECOMMAND_H

#include "../common/etlbase.h"
#include "../common/parameters.h"

class ViewModelClass;

class ChangeStyleCommand : public ICommandBase
{
public:
    ChangeStyleCommand(ViewModelClass* p) throw();
    virtual void SetParameter(const std::any& param);
    virtual void Exec();

    ViewModelClass* m_pVM;
    std::string datatype;
};

#endif // CHANGESTYLECOMMAND_H
