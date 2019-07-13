#include "preordercommand.h"

#include "../viewmodel.h"

PreOrderCommand::PreOrderCommand(ViewModelClass* p) throw() : m_pVM(p)
{
}

void PreOrderCommand::SetParameter(const std::any& param)
{
}

void PreOrderCommand::Exec()
{
    bool bResult = m_pVM->modelPreOrder();
    m_pVM->Fire_OnCommandComplete("Pre Order", bResult);
}



