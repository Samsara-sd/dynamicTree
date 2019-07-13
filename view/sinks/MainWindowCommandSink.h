#pragma once

#include "common/etlbase.h"

class ViewClass;

class MainWindowCommandSink : public ICommandNotification
{
public:
    MainWindowCommandSink(ViewClass* pW) throw();

	virtual void OnCommandComplete(const std::string& str, bool bOK);

private:
    ViewClass* m_pW;
};
