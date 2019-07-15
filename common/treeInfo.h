#pragma once
using ElementType = int;

#include <string>
#include <vector>

class TreeNode
{
    public:
        TreeNode(ElementType X = 0, int index = 1)
        {
            Value = X;
            LeftChild = RightChild = Parent = nullptr;
            Mark = false;
            Factor = 0;
            Index = index;
        }

        ElementType Value;
        TreeNode* LeftChild;
        TreeNode* RightChild;
        TreeNode* Parent;
        bool Mark;
        int Factor;
        int Index;
};
