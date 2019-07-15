#include<iostream>
#include "ViewModelTest.h"

int main(int argc, char* argv[])
{
    unsigned int uFailed = 0;

//---------------------------------------------------------------
    if( !ViewModel_Test() )
        uFailed ++;
//---------------------------------------------------------------
    if(uFailed == 0) std::cout<<"pass"<<std::endl;

    system("pause");
    return uFailed != 0 ? 1 : 0;
}
