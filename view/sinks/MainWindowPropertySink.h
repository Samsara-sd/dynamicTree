#pragma once

#include "common/etlbase.h"

class ViewClass;

class MainWindowPropertySink : public IPropertyNotification
{
public:
    MainWindowPropertySink(ViewClass* pW) throw();

	virtual void OnPropertyChanged(const std::string& str);

private:
    ViewClass* m_pW;
};
