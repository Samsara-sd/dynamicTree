#include "postordercommand.h"

#include "../viewmodel.h"

PostOrderCommand::PostOrderCommand(ViewModelClass* p) throw() : m_pVM(p)
{
}

void PostOrderCommand::SetParameter(const std::any& param)
{
}

void PostOrderCommand::Exec()
{
    bool bResult = m_pVM->modelPostOrder();
    m_pVM->Fire_OnCommandComplete("Post Order", bResult);
}
