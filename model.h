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
    bool DestroyTree();
    bool PreOrder();
    bool PostOrder();
    bool InOrder();
    bool ChangeMode(std::string& Mode);
    TreeNode* GetFlashNode()const throw();
    TreeNode* GetNowNode()const throw();

private:
    controlMode globalMode;
    TreeNode* Treeptr;
    TreeNode* FlashNode;
    TreeNode* NowNode;

    //BST
    TreeNode* BST_Insert(TreeNode* T, ElementType X, int Index = 1);
    TreeNode* BST_Delete(TreeNode* T, ElementType X);
    void BST_Find(TreeNode* T, ElementType X);  //AVL

    //AVL
    TreeNode* AVL_Insert(TreeNode* T, ElementType X, int Index = 1);
    TreeNode* AVL_Delete(TreeNode* T, ElementType X);
    TreeNode* SingleLeftRotation(TreeNode* A);
    TreeNode* SingleRightRotation(TreeNode* A);
    TreeNode* DoubleLRRotation(TreeNode* A);
    TreeNode* DoubleRLRotation(TreeNode* A);


    //common
    void Tree_UpdateIndex(TreeNode* T, int Index);
    void Tree_PostOrder(TreeNode* T);
    void Tree_InOrder(TreeNode* T);
    void Tree_PreOrder(TreeNode* T);
    void Tree_DestroyTree(TreeNode* Root);
    TreeNode* FindMax(TreeNode* T);
    inline int Max(int A, int B){
        return A>B?A:B;
    }
    int GetFactor(TreeNode* T);

};
