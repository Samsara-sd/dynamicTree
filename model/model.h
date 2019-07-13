#pragma once

#include "common/etlbase.h"
#include "common/treeInfo.h"
#include "common/common.h"


class ModelClass : public Proxy_PropertyNotification<ModelClass>
{
public:

    ModelClass();

    bool Insert(const int& value);
    bool Delete(const int& value);
    bool Find(const int& value);
    bool PreOrder();
    bool PostOrder();
    bool InOrder();
    TreeNode* GetFlashNode()const throw();
    TreeNode* GetNowNode()const throw();

private:
    controlMode globalMode;
    TreeNode* Treeptr;
    TreeNode* FlashNode;
    TreeNode* NowNode;

    TreeNode* BST_Insert(TreeNode* T, ElementType X, int Index = 1);
    TreeNode* BST_Delete(TreeNode* T, ElementType X);
    void BST_Find(TreeNode* T, ElementType X);
    TreeNode* BST_FindMax(TreeNode* T);
    void BST_UpdateIndex(TreeNode* T, int Index);
    void BST_PostOrder(TreeNode* T);
    void BST_InOrder(TreeNode* T);
    void BST_PreOrder(TreeNode* T);

};
