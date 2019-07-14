#include "NodeCommand.h"

#include "../viewmodel.h"

NodeCommand::NodeCommand(ViewModelClass* p) throw() : m_pVM(p)
{
}

void NodeCommand::SetParameter(const std::any& param)
{
    m_param = std::any_cast<int>(param);
}


