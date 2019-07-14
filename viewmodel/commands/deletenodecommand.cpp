#include "deletenodecommand.h"

#include "../viewmodel.h"

DeleteNodeCommand::DeleteNodeCommand(ViewModelClass* p) throw() : NodeCommand(p)
{
}

void DeleteNodeCommand::Exec()
{
    bool bResult = m_pVM->modelDelete(m_param);
    m_pVM->Fire_OnCommandComplete("Delete", bResult);
}

