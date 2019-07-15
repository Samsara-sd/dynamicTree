#include "MainWindowCommandSink.h"

#include "../view.h"

#include <QMessageBox>

MainWindowCommandSink::MainWindowCommandSink(ViewClass* pW) throw() : m_pW(pW)
{
}

void MainWindowCommandSink::OnCommandComplete(const std::string& str, bool bOK)
{
    if( str == "Insert" ) {
        if( !bOK );
	}
    else if( str == "Find" || str == "Delete" )
    {
        if( !bOK )
        {
            QMessageBox box;
            box.setWindowTitle("Find Error");
            box.setText("The value has not been found in the current tree.");
            int res = box.exec();
        }
    }
}
