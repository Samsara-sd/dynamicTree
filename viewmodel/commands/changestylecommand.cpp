#include "changestylecommand.h"

#include "../viewmodel.h"

ChangeStyleCommand::ChangeStyleCommand(ViewModelClass* p) throw() : m_pVM(p)
{

}

void ChangeStyleCommand::SetParameter(const std::any &param)
{
    datatype = std::any_cast<std::string>(param);
}

void ChangeStyleCommand::Exec()
{
    bool bResult = m_pVM->modelChangeMode(datatype);
    m_pVM->Fire_OnCommandComplete("ChangeType", bResult);
    return;
}
