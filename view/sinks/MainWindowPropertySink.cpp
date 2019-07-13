#include "MainWindowPropertySink.h"

#include "../view.h"

MainWindowPropertySink::MainWindowPropertySink(ViewClass* pW) throw() : m_pW(pW)
{
}

void MainWindowPropertySink::OnPropertyChanged(const std::string& str)
{
    if( str == "Change_Node" ) {
        m_pW->changeNodeFunction();
	}
}
