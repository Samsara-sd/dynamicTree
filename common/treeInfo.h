#pragma once
using ElementType = int;

#include <string>
#include <vector>
#include <QtDebug>

class TreeNode
{
    public:
        TreeNode(ElementType X = 0, int index = 1)
        {
            qDebug()<<"create tree node"<<endl;
            Value = X;
            LeftChild = RightChild = Parent = nullptr;
            Mark = false;
            Factor = 0;
            Index = index;
        }

        TreeNode(const TreeNode& src);
        TreeNode(TreeNode&& src);

        TreeNode& operator=(const TreeNode& src);
        TreeNode& operator=(TreeNode&& src);

        ElementType Value;
        TreeNode* LeftChild;
        TreeNode* RightChild;
        TreeNode* Parent;
        bool Mark;
        int Factor;
        int Index;
};
