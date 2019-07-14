
#include "treeInfo.h"

TreeNode::TreeNode(const TreeNode& src)
{
    Value = src.Value;
    LeftChild = src.LeftChild;
    RightChild = src.RightChild;
    Parent = src.Parent;
    Mark = src.Mark;
    Factor = src.Factor;
    Index = src.Index;
}
TreeNode::TreeNode(TreeNode&& src)
{
    Value = src.Value;
    LeftChild = src.LeftChild;
    RightChild = src.RightChild;
    Parent = src.Parent;
    Mark = src.Mark;
    Factor = src.Factor;
    Index = src.Index;
}

TreeNode& TreeNode::operator=(const TreeNode& src)
{
    if( this != &src ) {
        Value = src.Value;
        LeftChild = src.LeftChild;
        RightChild = src.RightChild;
        Parent = src.Parent;
        Mark = src.Mark;
        Factor = src.Factor;
        Index = src.Index;
    }
    return *this;
}
TreeNode& TreeNode::operator=(TreeNode&& src)
{
    if( this != &src ) {
        Value = src.Value;
        LeftChild = src.LeftChild;
        RightChild = src.RightChild;
        Parent = src.Parent;
        Mark = src.Mark;
        Factor = src.Factor;
        Index = src.Index;
    }
    return *this;
}
