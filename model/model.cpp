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
    Tree_DestroyTree(Treeptr);
    Treeptr = nullptr;
    return true;
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
        case controlMode::Splay:
        {
            Treeptr = Splay_Insert(Treeptr, value);
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
        case controlMode::Splay:
        {
            Treeptr = Splay_Delete(Treeptr, value);
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
        case controlMode::Splay:
        {
            Treeptr = Splay_Find(Treeptr, value);
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

TreeNode* ModelClass::Splay_Insert(TreeNode *T, ElementType X, int Index)
{
    TreeNode* PX;
    T = Insertion(T, X, &PX, Index);
    T = PX = Splay(T, PX);
    return T;
}

TreeNode* ModelClass::Insertion(TreeNode* T, ElementType X, TreeNode** PX, int Index)
{
    if (T == nullptr) {
        T = new TreeNode(X, Index);
        *PX = T;

        NowNode = T;
        Fire_OnPropertyChanged("Node_Insert");
    }
    else {
        FlashNode = T;
        Fire_OnPropertyChanged("Node_Flash");

        if (X < T->Value)
        {
            T->LeftChild = Insertion(T->LeftChild, X, PX, Index * 2);
            T->LeftChild->Parent = T;
        }
        else
        {
            T->RightChild = Insertion(T->RightChild, X, PX, Index * 2 + 1);
            T->RightChild->Parent = T;
        }
    }
    return T;
}

TreeNode* ModelClass::Splay_Delete(TreeNode* T, ElementType X)
{
    if (T == nullptr) {
        throw "NO such element!";
    }
    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    T = Splay_Find(T, X);

    NowNode = T;
    Fire_OnPropertyChanged("Node_Delete");
    TreeNode* Temp = FindMax(T->LeftChild);
    if (Temp == nullptr)
    {
        Temp = T;
        T = T->RightChild;

        NowNode = Temp;
        Fire_OnPropertyChanged("Node_RecurDelete");

        if (T != nullptr) {
            Tree_UpdateIndex(T, T->Index / 2);
            NowNode = T;
            Fire_OnPropertyChanged("Node_RecurUpdate");
        }
        if (T != nullptr && Temp != nullptr)
            T->Parent = Temp->Parent;
    }
    else
    {
        T->Value = Temp->Value;

        NowNode = T;
        Fire_OnPropertyChanged("Node_ChangeValue");

        NowNode = T->LeftChild;
        Fire_OnPropertyChanged("Node_RecurDelete");

        if (Temp->LeftChild != nullptr)
            Temp->LeftChild->Parent = Temp->Parent;
        if (Temp->Parent != nullptr) {
            if (Temp == Temp->Parent->LeftChild)
                Temp->Parent->LeftChild = Temp->LeftChild;
            else
                Temp->Parent->RightChild = Temp->LeftChild;
        }
        Tree_UpdateIndex(T->LeftChild, 2);

        NowNode = T->LeftChild;
        Fire_OnPropertyChanged("Node_RecurUpdate");
    }
    delete Temp;
    return T;
}

TreeNode* ModelClass::Splay_Find(TreeNode* T, ElementType X)
{
    TreeNode* TX = FindTree(T, X);
    TX = Splay(T, TX);
    return TX;
}

TreeNode* ModelClass::FindTree(TreeNode* T, ElementType X)
{
    if (T == nullptr){
        throw "No such element!";
    }
    TreeNode* TreeX;
    if (T->Value == X) {
        TreeX = T;

        NowNode = T;
        Fire_OnPropertyChanged("Node_Find");
        return TreeX;
    }
    FlashNode = T;
    Fire_OnPropertyChanged("Node_Flash");

    if (T->Value < X)
        TreeX = FindTree(T->RightChild, X);
    else
        TreeX = FindTree(T->LeftChild, X);
    return TreeX;
}

TreeNode* ModelClass::Splay(TreeNode* T, TreeNode* X)
{
    if (T == nullptr)
        return nullptr;
    TreeNode *P, *G;	//ParentTree, GrandParentTree
    P = X->Parent;
    while (P != nullptr)
    {
        G = P->Parent;
        if (X == P->LeftChild)
        {
            if (G == nullptr)
                X = SingleLeftRotation(P);
            else if (P == G->LeftChild)
                X = LLRotation(G);
            else
                X = RLRotation(G);
        }
        else
        {
            if (G == nullptr)
            {
                X = SingleRightRotation(P);
            }
            else if (P == G->RightChild)
            {
                X = RRRotation(G);
            }
            else
            {
                X = LRRotation(G);
            }
        }
        P = X->Parent;
    }
    return X;
}


TreeNode* ModelClass::LLRotation(TreeNode* G)
{
    return SingleLeftRotation(SingleLeftRotation(G));
}

TreeNode* ModelClass::LRRotation(TreeNode* G)
{
    return SingleLeftRotation(SingleRightRotation(G->LeftChild)->Parent);
}

TreeNode* ModelClass::RRRotation(TreeNode* G)
{
    return SingleRightRotation(SingleRightRotation(G));
}

TreeNode* ModelClass::RLRotation(TreeNode* G)
{
    return SingleRightRotation(SingleLeftRotation(G->RightChild)->Parent);
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
    if(T != nullptr) T->Factor = Max(GetFactor(T->LeftChild), GetFactor(T->RightChild))+1;
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
    if(T != nullptr){
        T->Factor = Max(GetFactor(T->LeftChild), GetFactor(T->RightChild))+1;
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
        NowNode = TempNode;
        Fire_OnPropertyChanged("Node_RecurDelete");
    }

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

    if(TempNode != nullptr){
        NowNode = TempNode;
        Fire_OnPropertyChanged("Node_RecurUpdate");
    }

    A->Factor = Max(GetFactor(A->LeftChild), GetFactor(A->RightChild)) + 1;
    B->Factor = Max(GetFactor(B->LeftChild), GetFactor(B->RightChild)) + 1;

    return B;
}
TreeNode* ModelClass::SingleRightRotation(TreeNode* A)
{
    FlashNode = A;
    Fire_OnPropertyChanged("Right_Rotation");   //draw an arc
    TreeNode* B = A->RightChild;
    TreeNode* TempNode = B->LeftChild;

    if(A->Parent!=nullptr){ //update A's Parent's subtree
        if(A == A->Parent->LeftChild){
            A->Parent->LeftChild = B;
        }
        else {
            A->Parent->RightChild = B;
        }
    }
    B->Parent = A->Parent;  //update B's parent
    A->Parent = B;
    if(TempNode!= nullptr){ //update TempNode's parent
        TempNode->Parent = A;
        NowNode = TempNode; //erase TempNode
        Fire_OnPropertyChanged("Node_RecurDelete");
    }

    B->LeftChild = nullptr;

    NowNode = A;
    Fire_OnPropertyChanged("Node_RecurDelete"); //erase A and its subTree

    B->LeftChild = A;
    A->RightChild = nullptr;
    Tree_UpdateIndex(B, A->Index);

    NowNode = B;
    Fire_OnPropertyChanged("Node_RecurUpdate");

    A->RightChild = TempNode;
    Tree_UpdateIndex(TempNode, A->Index * 2+1);
    if(TempNode != nullptr)
    {
        NowNode = TempNode;
        Fire_OnPropertyChanged("Node_RecurUpdate");
    }

    A->Factor = Max(GetFactor(A->LeftChild), GetFactor(A->RightChild)) + 1;
    B->Factor = Max(GetFactor(B->LeftChild), GetFactor(B->RightChild)) + 1;

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


