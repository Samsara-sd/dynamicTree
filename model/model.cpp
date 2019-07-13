#include "model.h"


ModelClass::ModelClass(): globalMode(controlMode::BST), Treeptr(nullptr)
{
}

TreeNode* ModelClass::GetFlashNode() const throw()
{
    return FlashNode;
}

TreeNode* ModelClass::GetNowNode() const throw()
{
    return NowNode;
}

bool ModelClass::Insert(const int& value)
{
    switch (globalMode)
    {
        case controlMode::BST:
        {
            Treeptr = BST_Insert(Treeptr, value);
            break;
        }
        default:
        {
            break;
        }
    }

    return true;
}

bool ModelClass::Delete(const int& value)
{
    switch (globalMode)
    {
        case controlMode::BST:
        {
            Treeptr = BST_Delete(Treeptr, value);
            break;
        }
        default:
        {
            break;
        }
    }

    return true;
}

bool ModelClass::Find(const int& value)
{
    switch (globalMode)
    {
        case controlMode::BST:
        {
            BST_Find(Treeptr, value);
            break;
        }
        default:
        {
            break;
        }
    }
    return true;
}

bool ModelClass::PreOrder()
{
    switch (globalMode)
    {
        case controlMode::BST:
        {
            BST_PreOrder(Treeptr);
            break;
        }
        default:
        {
            break;
        }
    }
    return true;
}

bool ModelClass::PostOrder()
{
    switch (globalMode)
    {
        case controlMode::BST:
        {
            BST_PostOrder(Treeptr);
            break;
        }
        default:
        {
            break;
        }
    }
    return true;
}

bool ModelClass::InOrder()
{
    switch (globalMode)
    {
        case controlMode::BST:
        {
            BST_InOrder(Treeptr);
            break;
        }
        default:
        {
            break;
        }
    }
    return true;
}

//void ModelClass::DestroyTree(TreeNode* Root)
//{
//    if (Root == nullptr)
//        return;
//    BST_DestroyTree(Root->LeftChild);
//    BST_DestroyTree(Root->RightChild);
//    delete Root;
//    Root = nullptr;
//}

void ModelClass::BST_PostOrder(TreeNode* T)
{
    if (T == nullptr)
        return;
    BST_PostOrder(T->LeftChild);
    BST_PostOrder(T->RightChild);
    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");
    //viewModel::nodeFlash(T);	//	read the node(falshing on the interface)
}

void ModelClass::BST_PreOrder(TreeNode* T)
{
    if (T == nullptr)
        return;

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    //viewModel::nodeFlash(T);	//	read the node(falshing on the interface)
    BST_PreOrder(T->LeftChild);
    BST_PreOrder(T->RightChild);
}

void ModelClass::BST_InOrder(TreeNode* T)
{
    if (T == nullptr)
        return;
    BST_InOrder(T->LeftChild);

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    //viewModel::nodeFlash(T);	//	read the node(falshing on the interface)
    BST_InOrder(T->RightChild);
}

void ModelClass::BST_UpdateIndex(TreeNode* T, int Index)
{
    if (T == nullptr)
        return;
    T->Index = Index;
    BST_UpdateIndex(T->LeftChild, Index * 2);
    BST_UpdateIndex(T->RightChild, Index * 2 + 1);
}

TreeNode* ModelClass::BST_FindMax(TreeNode* T)
{
    if (T->RightChild != nullptr)
        return BST_FindMax(T->RightChild);
//	NodeIterFlash(T)	//find the max node, falsh the node on the interface
    return T;
}

void ModelClass::BST_Find(TreeNode* T, ElementType X)
{
    if (T == nullptr) {
        throw "No such element";	//throw an excepion
    }
    if (T->Value == X) {

        NowNode = T;
        Fire_OnPropertyChanged("Node_Find");

        //viewModel::nodeFind(T);
        return;
    }

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    //viewModel::nodeFlash(T);	//flash every node we visit
    if (T->Value < X)
        BST_Find(T->RightChild, X);
    else
        BST_Find(T->LeftChild, X);
}

TreeNode* ModelClass::BST_Delete(TreeNode* T, ElementType X)
{
    if (T == nullptr) {
        throw "No such element";	//throw an exception
    }

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    if (T->Value < X)
        T->RightChild = BST_Delete(T->RightChild, X);
    else if (T->Value > X)
        T->LeftChild = BST_Delete(T->LeftChild, X);
    else
    {
        NowNode = T;
        Fire_OnPropertyChanged("Node_Delete");

        if (T->LeftChild != nullptr && T->RightChild != nullptr)
        {
            T->Value = (BST_FindMax(T->LeftChild))->Value;
            T->LeftChild = BST_Delete(T->LeftChild, T->Value);

            NowNode = T;
            Fire_OnPropertyChanged("Node_ChangeValue");

        }
        else
        {
            TreeNode* TempTreeNode = T;
            T = (T->LeftChild != nullptr) ? T->LeftChild : T->RightChild;

            NowNode = TempTreeNode;
            Fire_OnPropertyChanged("Node_RecurDelete");

            if (T != nullptr)
            {
                BST_UpdateIndex(T, T->Index / 2);	//update the index of the nodes

                NowNode = T;
                Fire_OnPropertyChanged("Node_RecurUpdate");
            }
            delete TempTreeNode;
        }
    }
    return T;
}

TreeNode* ModelClass::BST_Insert(TreeNode* T, ElementType X, int Index)
{
    if (T == nullptr)
    {

        T = new TreeNode(X, Index);

        NowNode = T;

        Fire_OnPropertyChanged("Node_Insert");

        //viewModel::nodeInsert(T);
    }
    else
    {
        FlashNode = T;
        Fire_OnPropertyChanged("Node_Flash");

        //viewModel::nodeFlash(T);//flash the node we visit
        if (T->Value > X)
        {
            T->LeftChild = BST_Insert(T->LeftChild, X, Index*2);
        }
        else
            T->RightChild = BST_Insert(T->RightChild, X, Index*2+1);
    }
    return T;
}


