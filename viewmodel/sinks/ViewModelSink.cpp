#include "ViewModelSink.h"

#include "../viewmodel.h"

ViewModelSink::ViewModelSink(ViewModelClass* p) throw() : m_pVM(p)
{
}

void ViewModelSink::OnPropertyChanged(const std::string& str)
{
    if( str == "Node_Flash" ) {
        m_pVM->SetFlashNode(m_pVM->GetModel().GetFlashNode());
        m_pVM->nodeFlash();
	}
    else if( str == "Node_Insert" ) {
        m_pVM->SetNowNode(m_pVM->GetModel().GetNowNode());
        m_pVM->nodeInsert();
    }
    else if( str == "Node_Find" ) {
        m_pVM->SetNowNode(m_pVM->GetModel().GetNowNode());
        m_pVM->nodeFind();
    }
    else if( str == "Node_Delete" ) {
        m_pVM->SetNowNode(m_pVM->GetModel().GetNowNode());
        m_pVM->nodeTempDelete();
    }
    else if( str == "Node_ChangeValue" ) {
        m_pVM->SetNowNode(m_pVM->GetModel().GetNowNode());
        m_pVM->nodeChangeValue();
    }
    else if( str == "Node_RecurDelete" ) {
        m_pVM->SetNowNode(m_pVM->GetModel().GetNowNode());
        m_pVM->nodeRecurDelete();
    }
    else if( str == "Node_RecurUpdate" ) {
        m_pVM->SetNowNode(m_pVM->GetModel().GetNowNode());
        m_pVM->nodeRecurUpdate();
    }

    else if( str == "Left_Rotation" ) {
        m_pVM->SetFlashNode(m_pVM->GetModel().GetFlashNode());
        m_pVM->nodeLeftRotate();
    }
    else if( str == "Right_Rotation" ) {
        m_pVM->SetFlashNode(m_pVM->GetModel().GetFlashNode());
        m_pVM->nodeRightRotate();
    }


}
