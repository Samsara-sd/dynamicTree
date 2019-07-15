#pragma once

#include "../common/etlbase.h"
#include "../common/parameters.h"

class ViewModelClass;

class NodeCommand : public ICommandBase
{
public:
    NodeCommand(ViewModelClass* p) throw();
	virtual void SetParameter(const std::any& param);

protected:
    ViewModelClass* m_pVM;
    int m_param;
};
