#include "findnodecommand.h"

#include "../viewmodel.h"

FindNodeCommand::FindNodeCommand(ViewModelClass* p) throw() : NodeCommand(p)
{
}

void FindNodeCommand::Exec()
{
    bool bResult = m_pVM->modelFind(m_param);
    m_pVM->Fire_OnCommandComplete("Find", bResult);
}
