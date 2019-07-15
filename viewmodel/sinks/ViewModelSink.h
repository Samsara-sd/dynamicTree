#ifndef VIEWMODELSINK_H
#define VIEWMODELSINK_H


#include "common/etlbase.h"

class ViewModelClass;

class ViewModelSink : public IPropertyNotification
{
public:
    ViewModelSink(ViewModelClass* p) throw();

	virtual void OnPropertyChanged(const std::string& str);

private:
    ViewModelClass* m_pVM;
};

#endif
