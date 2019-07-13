#include "model.h"


ModelClass::ModelClass(): globalMode(controlMode::BST), Treeptr(nullptr)
{
}

bool ModelClass::ChangeMode(std::string& Mode)
{
    if(Mode == "Binary Search Tree"){
        globalMode = controlMode::BST;
    }
    else if (Mode == "AVL Tree") {
        globalMode = controlMode::AVL;
    }
    else {
        globalMode = controlMode::Splay;
    }
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
        case controlMode::AVL:
        {
            Treeptr = AVL_Insert(Treeptr, value);
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
        case controlMode::AVL:
        {
            Treeptr = AVL_Delete(Treeptr, value);
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
        case controlMode::AVL:
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
    Tree_PreOrder(Treeptr);

    return true;
}

bool ModelClass::PostOrder()
{
    Tree_PostOrder(Treeptr);

    return true;
}

bool ModelClass::InOrder()
{
    Tree_InOrder(Treeptr);

    return true;
}

TreeNode* ModelClass::AVL_Insert(TreeNode* T, ElementType X, int Index)
{
    if(T == nullptr){
        T = new TreeNode(X, Index);
        NowNode = T;
        Fire_OnPropertyChanged("Node_Insert");
    }
    else {
        FlashNode = T;
        Fire_OnPropertyChanged("Node_Flash");
        if(T->Value > X){
            T->LeftChild = AVL_Insert(T->LeftChild, X, Index*2);
            if((GetFactor(T->LeftChild)-GetFactor(T->RightChild)) == 2){
                if(X < T->LeftChild->Value)
                    T = SingleLeftRotation(T);
                else
                    T = DoubleLRRotation(T);
            }
        }
        else {
            T->RightChild = AVL_Insert(T->RightChild, X, Index*2+1);
            if((GetFactor(T->LeftChild)-GetFactor(T->RightChild)) == -2){
                if(X >= T->RightChild->Value)
                    T = SingleRightRotation(T);
                else
                    T = DoubleRLRotation(T);
            }
        }
    }
    T->Factor = Max(GetFactor(T->LeftChild), GetFactor(T->RightChild))+1;
    return T;
}

TreeNode* ModelClass::AVL_Delete(TreeNode* T, ElementType X)
{
    if(T == nullptr){
        throw "No such element!";
    }
    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    if(T->Value > X){
        T->LeftChild = AVL_Delete(T->LeftChild, X);
        if((GetFactor(T->LeftChild) - GetFactor(T->RightChild)) == -2){
            if(T->RightChild->LeftChild == nullptr||
                    (GetFactor(T->RightChild->LeftChild) - GetFactor(T->RightChild->RightChild)) == -1){
                T = SingleRightRotation(T);
            }
            else {
                T = DoubleRLRotation(T);
            }
        }
    }
    else if (T->Value < X) {
        T->RightChild = AVL_Delete(T->RightChild, X);
        if((GetFactor(T->LeftChild) - GetFactor(T->RightChild)) == 2){
            if(T->LeftChild->RightChild == nullptr||
                    (GetFactor(T->LeftChild->LeftChild) - GetFactor(T->LeftChild->RightChild)) == 1){
                T = SingleLeftRotation(T);
            }
            else {
                T = DoubleLRRotation(T);
            }
        }
    }
    else {
        NowNode = T;
        Fire_OnPropertyChanged("Node_Delete");

        if(T->LeftChild != nullptr && T->RightChild != nullptr){
            T->Value = (FindMax(T->LeftChild))->Value;
            T->LeftChild = AVL_Delete(T->LeftChild, T->Value);
            if((GetFactor(T->LeftChild) - GetFactor(T->RightChild)) == -2){
                if(T->RightChild->LeftChild == nullptr||
                        (GetFactor(T->RightChild->LeftChild) - GetFactor(T->RightChild->RightChild)) == -1){
                    T = SingleRightRotation(T);
                }
                else {
                    T = DoubleRLRotation(T);
                }
            }

            NowNode = T;
            Fire_OnPropertyChanged("Node_ChangeValue");
        }
        else {
            TreeNode* TempTreeNode = T;
            T = (T->LeftChild != nullptr)? T->LeftChild : T->RightChild;

            NowNode = TempTreeNode;
            Fire_OnPropertyChanged("Node_RecurDelete");

            if(T!=nullptr){
                Tree_UpdateIndex(T,T->Index/2);

                NowNode = T;
                Fire_OnPropertyChanged("Node_RecurUpdate");
            }
            delete TempTreeNode;
        }
    }

    return T;
}

TreeNode* ModelClass::SingleLeftRotation(TreeNode* A)
{
    FlashNode = A;
    Fire_OnPropertyChanged("Left_Rotation");
    TreeNode* B = A->LeftChild;
    TreeNode* TempNode = B->RightChild;

    if(A->Parent!=nullptr){
        if(A == A->Parent->LeftChild){
            A->Parent->LeftChild = B;
        }
        else {
            A->Parent->RightChild = B;
        }
    }
    B->Parent = A->Parent;
    A->Parent = B;
    if(TempNode!= nullptr){
        TempNode->Parent = A;
    }

    NowNode = TempNode;
    Fire_OnPropertyChanged("Node_RecurDelete");

    B->RightChild = nullptr;

    NowNode = A;
    Fire_OnPropertyChanged("Node_RecurDelete");

    B->RightChild = A;
    A->LeftChild = nullptr;
    Tree_UpdateIndex(B, A->Index);

    NowNode = B;
    Fire_OnPropertyChanged("Node_RecurUpdate");

    A->LeftChild = TempNode;
    Tree_UpdateIndex(TempNode, A->Index * 2);

    NowNode = TempNode;
    Fire_OnPropertyChanged("Node_RecurUpdate");

    A->Factor = Max(GetFactor(A->LeftChild), GetFactor(B->RightChild)) + 1;
    B->Factor = Max(GetFactor(A->LeftChild), GetFactor(B->RightChild)) + 1;

    return B;
}
TreeNode* ModelClass::SingleRightRotation(TreeNode* A)
{
    FlashNode = A;
    Fire_OnPropertyChanged("Left_Rotation");
    TreeNode* B = A->RightChild;
    TreeNode* TempNode = B->LeftChild;

    if(A->Parent!=nullptr){
        if(A == A->Parent->LeftChild){
            A->Parent->LeftChild = B;
        }
        else {
            A->Parent->RightChild = B;
        }
    }
    B->Parent = A->Parent;
    A->Parent = B;
    if(TempNode!= nullptr){
        TempNode->Parent = A;
    }

    NowNode = TempNode;
    Fire_OnPropertyChanged("Node_RecurDelete");

    B->LeftChild = nullptr;

    NowNode = A;
    Fire_OnPropertyChanged("Node_RecurDelete");

    B->LeftChild = A;
    A->RightChild = nullptr;
    Tree_UpdateIndex(B, A->Index);

    NowNode = B;
    Fire_OnPropertyChanged("Node_RecurUpdate");

    A->RightChild = TempNode;
    Tree_UpdateIndex(TempNode, A->Index * 2+1);

    NowNode = TempNode;
    Fire_OnPropertyChanged("Node_RecurUpdate");

    A->Factor = Max(GetFactor(A->LeftChild), GetFactor(B->RightChild)) + 1;
    B->Factor = Max(GetFactor(A->LeftChild), GetFactor(B->RightChild)) + 1;

    return B;
}

TreeNode* ModelClass::DoubleLRRotation(TreeNode* A)
{
    A->LeftChild = SingleRightRotation(A->LeftChild);
    return SingleLeftRotation(A);
}

TreeNode* ModelClass::DoubleRLRotation(TreeNode* A)
{
    A->RightChild = SingleLeftRotation(A->RightChild);
    return SingleRightRotation(A);
}

int ModelClass::GetFactor(TreeNode *T)
{
    if(T == nullptr)
        return -1;
    return T->Factor;
}

void ModelClass::Tree_DestroyTree(TreeNode* Root)
{
    if (Root == nullptr)
        return;
    Tree_DestroyTree(Root->LeftChild);
    Tree_DestroyTree(Root->RightChild);
    delete Root;
    Root = nullptr;
}

void ModelClass::Tree_PostOrder(TreeNode* T)
{
    if (T == nullptr)
        return;
    Tree_PostOrder(T->LeftChild);
    Tree_PostOrder(T->RightChild);
    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");
}

void ModelClass::Tree_PreOrder(TreeNode* T)
{
    if (T == nullptr)
        return;

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    Tree_PreOrder(T->LeftChild);
    Tree_PreOrder(T->RightChild);
}

void ModelClass::Tree_InOrder(TreeNode* T)
{
    if (T == nullptr)
        return;
    Tree_InOrder(T->LeftChild);

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    Tree_InOrder(T->RightChild);
}

void ModelClass::Tree_UpdateIndex(TreeNode* T, int Index)
{
    if (T == nullptr)
        return;
    T->Index = Index;
    Tree_UpdateIndex(T->LeftChild, Index * 2);
    Tree_UpdateIndex(T->RightChild, Index * 2 + 1);
}

TreeNode* ModelClass::FindMax(TreeNode* T)
{
    if (T->RightChild != nullptr)
        return FindMax(T->RightChild);
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

        return;
    }

    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

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
            T->Value = (FindMax(T->LeftChild))->Value;
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
                Tree_UpdateIndex(T, T->Index / 2);	//update the index of the nodes

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

    }
    else
    {
        FlashNode = T;
        Fire_OnPropertyChanged("Node_Flash");

        if (T->Value > X)
        {
            T->LeftChild = BST_Insert(T->LeftChild, X, Index*2);
        }
        else
            T->RightChild = BST_Insert(T->RightChild, X, Index*2+1);
    }
    return T;
}


