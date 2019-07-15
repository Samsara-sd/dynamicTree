#include "ViewModelTest.h"

#include "../common/etlbase.h"
#include "../viewmodel/viewmodel.h"
#include "../model/model.h"

std::shared_ptr<ViewModelClass> vmdl(std::make_shared<ViewModelClass>());
std::shared_ptr<ModelClass> model(std::make_shared<ModelClass>());

void Test_BST()
{
    //case 1 BST Insert
    bool bRet = vmdl->modelInsert(20);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(15);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(25);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(12);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(10);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(11);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(22);
    if( !bRet )
        throw int(1);
    bRet = vmdl->modelInsert(28);
    if( !bRet )
        throw int(1);

    //case 2 BST Find
    bRet = vmdl->modelFind(28);
    if( !bRet )
        throw int(2);
    bRet = vmdl->modelFind(29);//29 is not exist
    if( bRet )
        throw int(2);

    //case 3 BST delete
    bRet = vmdl->modelFind(28);
    if( !bRet )
        throw int(3);
    bRet = vmdl->modelDelete(28);
    if( !bRet )
        throw int(3);
    bRet = vmdl->modelFind(28);
    if( bRet )
        throw int(3);

    bRet = vmdl->modelFind(20);
    if( !bRet )
        throw int(3);
    bRet = vmdl->modelDelete(20);
    if( !bRet )
        throw int(3);
    bRet = vmdl->modelFind(20);
    if( bRet )
        throw int(3);

    bRet = vmdl->modelFind(10);
    if( !bRet )
        throw int(3);
    bRet = vmdl->modelDelete(10);
    if( !bRet )
        throw int(3);
    bRet = vmdl->modelFind(10);
    if( bRet )
        throw int(3);

    bRet = vmdl->modelDelete(33);
    if( bRet )
        throw int(3);  //33 is not exist
}

void Test_AVL()
{
    //case 5 AVL Insert
    bool bRet;
    for(int i = 5; i <= 15; i++)
    {
        bRet = vmdl->modelInsert(i);
        if( !bRet )
            throw int(5);
    }
    bRet = vmdl->modelInsert(0);
    if( !bRet )
        throw int(5);

    bRet = vmdl->modelInsert(18);
    if( !bRet )
        throw int(5);

    bRet = vmdl->modelInsert(17);
    if( !bRet )
        throw int(5);

    bRet = vmdl->modelInsert(16);
    if( !bRet )
        throw int(5);

    bRet = vmdl->modelInsert(1);
    if( !bRet )
        throw int(5);

    bRet = vmdl->modelInsert(2);
    if( !bRet )
        throw int(5);

    bRet = vmdl->modelInsert(3);
    if( !bRet )
        throw int(5);

    //case 6 AVL Find
    bRet = vmdl->modelFind(18);
    if( !bRet )
        throw int(6);
    bRet = vmdl->modelFind(1);
    if( !bRet )
        throw int(6);
    bRet = vmdl->modelFind(33);//33 is not exist
    if( bRet )
        throw int(6);

    //case 7 AVL delete
    bRet = vmdl->modelFind(18);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelDelete(18);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelFind(18);
    if( bRet )
        throw int(7);

    bRet = vmdl->modelFind(15);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelDelete(15);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelFind(15);
    if( bRet )
        throw int(7);

    bRet = vmdl->modelFind(1);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelDelete(1);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelFind(1);
    if( bRet )
        throw int(7);

    bRet = vmdl->modelFind(5);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelDelete(5);
    if( !bRet )
        throw int(7);
    bRet = vmdl->modelFind(5);
    if( bRet )
        throw int(7);


    bRet = vmdl->modelDelete(33);
    if( bRet )
        throw int(7);  //33 is not exist
}

void Test_SPlayTree()
{
    //case 8 SPlayTree Insert
    bool bRet;
    for(int i = 14; i <= 30; i++)
    {
        bRet = vmdl->modelInsert(i);
        if( !bRet )
            throw int(8);
    }
    bRet = vmdl->modelInsert(0);
    if( !bRet )
        throw int(8);

    //case 9 SPlayTree Find
    bRet = vmdl->modelFind(28);
    if( !bRet )
        throw int(9);
    bRet = vmdl->modelFind(14);
    if( !bRet )
        throw int(9);
    bRet = vmdl->modelFind(33);//33 is not exist
    if( bRet )
        throw int(9);
    bRet = vmdl->modelFind(14);//33 is not exist
    if( !bRet )
        throw int(9);

    //case 10 SPlayTree delete
    bRet = vmdl->modelFind(28);
    if( !bRet )
        throw int(10);
    bRet = vmdl->modelDelete(28);
    if( !bRet )
        throw int(10);
    bRet = vmdl->modelFind(28);
    if( bRet )
        throw int(10);

    bRet = vmdl->modelFind(14);
    if( !bRet )
        throw int(10);
    bRet = vmdl->modelDelete(14);
    if( !bRet )
        throw int(10);
    bRet = vmdl->modelFind(14);
    if( bRet )
        throw int(10);

    bRet = vmdl->modelFind(22);
    if( !bRet )
        throw int(10);
    bRet = vmdl->modelDelete(22);
    if( !bRet )
        throw int(10);
    bRet = vmdl->modelFind(22);
    if( bRet )
        throw int(10);

    bRet = vmdl->modelDelete(33);
    if( bRet )
        throw int(10);  //33 is not exist


}

bool ViewModel_Test() throw()
{
    try {

        vmdl->SetModel(model);

        //change Data Structure
        std::string Data_Structure = "Binary Search Tree";
        bool bRet = vmdl->modelChangeMode(Data_Structure);
        if( !bRet )
            throw int(4);

        Test_BST();

        //change Data Structure
        Data_Structure = "AVL Tree";
        bRet = vmdl->modelChangeMode(Data_Structure);
        if( !bRet )
            throw int(4);

        Test_AVL();

        //change Data Structure
        Data_Structure = "SPlay Tree";
        bRet = vmdl->modelChangeMode(Data_Structure);
        if( !bRet )
            throw int(4);

        Test_SPlayTree();

        //Pre Order
        bRet = vmdl->modelPreOrder();
        if( !bRet )
            throw int(11);

        //In Order
        bRet = vmdl->modelInOrder();
        if( !bRet )
            throw int(12);

        //Post Order
        bRet = vmdl->modelPostOrder();
        if( !bRet )
            throw int(13);

    }
    catch (int& v) {
        printf("case %d error\n", v);
        return false;
    }
    catch (...) {
        printf("exception\n");
        return false;
    }
    return true;
}
