#include "insertnodecommand.h"

#include "../viewmodel.h"

InsertNodeCommand::InsertNodeCommand(ViewModelClass* p) throw() : NodeCommand(p)
{
}

void InsertNodeCommand::Exec()
{
    bool bResult = m_pVM->modelInsert(m_param);
    m_pVM->Fire_OnCommandComplete("Insert", bResult);
}
