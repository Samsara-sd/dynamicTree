#include "inordercommand.h"

#include "../viewmodel.h"

InOrderCommand::InOrderCommand(ViewModelClass* p) throw() : m_pVM(p)
{
}

void InOrderCommand::SetParameter(const std::any& param)
{
}

void InOrderCommand::Exec()
{
    bool bResult = m_pVM->modelInOrder();
    m_pVM->Fire_OnCommandComplete("In Order", bResult);
}
