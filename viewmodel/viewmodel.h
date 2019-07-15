#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <windows.h>
#include "commands/insertnodecommand.h"
#include "commands/deletenodecommand.h"
#include "commands/findnodecommand.h"
#include "commands/preordercommand.h"
#include "commands/postordercommand.h"
#include "commands/inordercommand.h"

#include "commands/changestylecommand.h"

#include "sinks/ViewModelSink.h"
#include "../model/model.h"

using NodeColor =  enum {hidden, normal, flash, insert, destory, find};

class ViewModelClass : public Proxy_PropertyNotification<ViewModelClass>,
                    public Proxy_CommandNotification<ViewModelClass>
{
public:
    ViewModelClass();

    void SetModel(const std::shared_ptr<ModelClass>& model);

    std::shared_ptr<ICommandBase> get_InsertCommand() throw();

    std::shared_ptr<ICommandBase> get_DeleteCommand() throw();

    std::shared_ptr<ICommandBase> get_FindCommand() throw();

    std::shared_ptr<ICommandBase> get_PreOrderCommand() throw();

    std::shared_ptr<ICommandBase> get_PostOrderCommand() throw();

    std::shared_ptr<ICommandBase> get_InOrderCommand() throw();

    std::shared_ptr<ICommandBase> get_ChangeStyleCommand() throw();

    ModelClass& GetModel() throw();

    void SetFlashNode(TreeNode* Node);

    void SetNowNode(TreeNode* Node);

    std::shared_ptr<NodeState> GetNode() const throw();

    bool modelInsert(const int& num);

    bool modelDelete(const int& num);

    bool modelFind(const int& num);

    bool modelPreOrder();

    bool modelInOrder();

    bool modelPostOrder();

    bool modelChangeMode(std::string& datatype);

    void nodeFlash();

    void nodeInsert();

    void nodeFind();

    void nodeTempDelete();

    void nodeRecurDelete();

    void nodeRecurUpdate();

    void nodeChangeValue();

    void nodeLeftRotate();

    void nodeRightRotate();

private:

    TreeNode* FlashNode;

    TreeNode* NowNode;

    std::shared_ptr<NodeState> State;

    std::pair<int, int> ptrDecode(const TreeNode* const  ptr);

    std::shared_ptr<ModelClass> Model;

    std::shared_ptr<InsertNodeCommand> m_cmdInsert;

    std::shared_ptr<DeleteNodeCommand> m_cmdDelete;

    std::shared_ptr<FindNodeCommand> m_cmdFind;

    std::shared_ptr<PreOrderCommand> m_cmdPreOrder;

    std::shared_ptr<PostOrderCommand> m_cmdPostOrder;

    std::shared_ptr<InOrderCommand> m_cmdInOrder;

    std::shared_ptr<ChangeStyleCommand> m_cmdChangeStyle;

    std::shared_ptr<ViewModelSink> m_sink;

    void nodeRecurDelete_in(const TreeNode* const ptr);

    void nodeRecurUpdate_in(const TreeNode* const ptr);

};
#endif
