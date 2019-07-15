#include "viewmodel.h"

ViewModelClass::ViewModelClass() : State(std::make_shared<NodeState>()),
                                m_cmdInsert(std::make_shared<InsertNodeCommand>(this)),
                                m_cmdDelete(std::make_shared<DeleteNodeCommand>(this)),
                                m_cmdFind(std::make_shared<FindNodeCommand>(this)),
                                m_cmdPreOrder(std::make_shared<PreOrderCommand>(this)),
                                m_cmdPostOrder(std::make_shared<PostOrderCommand>(this)),
                                m_cmdInOrder(std::make_shared<InOrderCommand>(this)),
                                m_cmdChangeStyle(std::make_shared<ChangeStyleCommand>(this)),
                                m_sink(std::make_shared<ViewModelSink>(this))
{
}

std::pair<int, int> ViewModelClass::ptrDecode(const TreeNode* const  ptr)
{
    int level = 1, order = 1;
    while(2 * order <= ptr->Index) {
        level += 1;
        order *= 2;
    }
    return std::make_pair(level, ptr->Index - order + 1);
}

void ViewModelClass::SetModel(const std::shared_ptr<ModelClass>& model)
{

    Model = model;
    Model->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
}


std::shared_ptr<ICommandBase> ViewModelClass::get_InsertCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdInsert);
}

std::shared_ptr<ICommandBase> ViewModelClass::get_DeleteCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdDelete);
}

std::shared_ptr<ICommandBase> ViewModelClass::get_FindCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdFind);
}

std::shared_ptr<ICommandBase> ViewModelClass::get_PreOrderCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdPreOrder);
}

std::shared_ptr<ICommandBase> ViewModelClass::get_PostOrderCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdPostOrder);
}

std::shared_ptr<ICommandBase> ViewModelClass::get_InOrderCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdInOrder);
}


std::shared_ptr<ICommandBase> ViewModelClass::get_ChangeStyleCommand() throw()
{
    return std::static_pointer_cast<ICommandBase>(m_cmdChangeStyle);
}

ModelClass& ViewModelClass::GetModel() throw()
{
    return *Model;
}

void ViewModelClass::SetFlashNode(TreeNode* Node)
{
    FlashNode = Node;
}

void ViewModelClass::SetNowNode(TreeNode* Node)
{
    NowNode = Node;
}

std::shared_ptr<NodeState> ViewModelClass::GetNode() const throw()
{
    return State;
}

bool ViewModelClass::modelInsert(const int& num)
{
    return Model->Insert(num);
}


bool ViewModelClass::modelDelete(const int& num)
{
    try
    {
        return Model->Delete(num);
    }
    catch(const char* arr)
    {
        return false;
    }

}

bool ViewModelClass::modelFind(const int& num)
{

    try
    {
        return Model->Find(num);
    }
    catch(const char* arr)
    {
        return false;
    }

}

bool ViewModelClass::modelPreOrder()
{
    return Model->PreOrder();
}

bool ViewModelClass::modelInOrder()
{
    return Model->InOrder();
}

bool ViewModelClass::modelPostOrder()
{
    return Model->PostOrder();
}


bool ViewModelClass::modelChangeMode(std::string& datatype)
{
    return Model->ChangeMode(datatype);
}


void ViewModelClass::nodeFlash()
{
    auto location = ptrDecode(FlashNode);
    int num = location.first;

    State->set_row(num);
    State->set_order(location.second);
    State->set_num(FlashNode->Value);
    State->set_state(NodeColor::flash);

    Fire_OnPropertyChanged("Change_Node");

    //sleep(600);

    State->set_state(NodeColor::normal);
    Fire_OnPropertyChanged("Change_Node");

}

void ViewModelClass::nodeInsert()
{
    auto location = ptrDecode(NowNode);
    int num = location.first;

    State->set_row(num);
    State->set_order(location.second);
    State->set_num(NowNode->Value);
    State->set_state(NodeColor::insert);

    Fire_OnPropertyChanged("Change_Node");

    //sleep(1500);

    State->set_state(NodeColor::normal);
    Fire_OnPropertyChanged("Change_Node");

}

void ViewModelClass::nodeFind()
{
    auto location = ptrDecode(NowNode);
    int num = location.first;

    State->set_row(num);
    State->set_order(location.second);
    State->set_num(NowNode->Value);
    State->set_state(NodeColor::find);

    Fire_OnPropertyChanged("Change_Node");

    //sleep(1500);

    State->set_state(NodeColor::normal);
    Fire_OnPropertyChanged("Change_Node");

}

void ViewModelClass::nodeTempDelete()
{
    auto location = ptrDecode(NowNode);
    int num = location.first;

    State->set_row(num);
    State->set_order(location.second);
    State->set_num(NowNode->Value);
    State->set_state(NodeColor::destory);

    Fire_OnPropertyChanged("Change_Node");

    //sleep(1000);

}

void ViewModelClass::nodeRecurDelete()
{
    nodeRecurDelete_in(NowNode);
}

void ViewModelClass::nodeRecurUpdate()
{
    nodeRecurUpdate_in(NowNode);
}

void ViewModelClass::nodeRecurDelete_in(const TreeNode* const ptr)
{
    if(ptr != nullptr)
    {
        auto location = ptrDecode(ptr);
        int num = location.first;

        State->set_row(num);
        State->set_order(location.second);
        State->set_num(ptr->Value);
        State->set_state(NodeColor::hidden);

        Fire_OnPropertyChanged("Change_Node");

        if(ptr->LeftChild != nullptr)
        {
            nodeRecurDelete_in(ptr->LeftChild);
        }
        if(ptr->RightChild != nullptr)
        {
            nodeRecurDelete_in(ptr->RightChild);
        }
    }
}

void ViewModelClass::nodeRecurUpdate_in(const TreeNode* const ptr)
{

    if(ptr != nullptr)
    {
        auto location = ptrDecode(ptr);
        int num = location.first;

        State->set_row(num);
        State->set_order(location.second);
        State->set_num(ptr->Value);
        State->set_state(NodeColor::normal);

        Fire_OnPropertyChanged("Change_Node");

        if(ptr->LeftChild != nullptr)
        {
            nodeRecurUpdate_in(ptr->LeftChild);
        }
        if(ptr->RightChild != nullptr)
        {
            nodeRecurUpdate_in(ptr->RightChild);
        }
    }
}

void ViewModelClass::nodeChangeValue()
{
    auto location = ptrDecode(NowNode);
    int num = location.first;

    State->set_row(num);
    State->set_order(location.second);
    State->set_num(NowNode->Value);
    State->set_state(NodeColor::normal);

    Fire_OnPropertyChanged("Change_Node");

    //sleep(1000);
}


void ViewModelClass::nodeLeftRotate()
{
    auto location = ptrDecode(FlashNode);
    int num = location.first;
    State->set_row(num);
    State->set_order(location.second);
    State->set_num(FlashNode->Value);
    State->set_state(2);
    Fire_OnPropertyChanged("Rotate_Node");
    //sleep(1000);
    State->set_state(0);
    Fire_OnPropertyChanged("Rotate_Node");
}

void ViewModelClass::nodeRightRotate()
{
    auto location = ptrDecode(FlashNode);
    int num = location.first;

    State->set_row(num);
    State->set_order(location.second);
    State->set_num(FlashNode->Value);
    State->set_state(1);

    Fire_OnPropertyChanged("Rotate_Node");

   // //sleep(1000);

    State->set_state(0);
    Fire_OnPropertyChanged("Rotate_Node");
}


