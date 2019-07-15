#pragma once

#include "../common/etlbase.h"
#include "../common/treeInfo.h"

typedef enum {BST, AVL, Splay, MinH, MaxH} controlMode;

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

    //Spaly
    TreeNode* Splay_Insert(TreeNode* T, ElementType X, int Index = 1);
    TreeNode* Splay_Delete(TreeNode* T, ElementType X);
    TreeNode* Splay_Find(TreeNode* T, ElementType X);
    TreeNode* LLRotation(TreeNode* G);
    TreeNode* LRRotation(TreeNode* G);
    TreeNode* RRRotation(TreeNode* G);
    TreeNode* RLRotation(TreeNode* G);
    TreeNode* Splay(TreeNode* T, TreeNode* X);
    TreeNode* Insertion(TreeNode* T, ElementType X, TreeNode** PX, int Index);
    TreeNode* FindTree(TreeNode* T, ElementType X);

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
