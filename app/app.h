#ifndef APP_H
#define APP_H

#include "view/view.h"
#include "viewmodel/viewmodel.h"

class App
{
    private:
        ViewClass View;
        std::shared_ptr<ViewModelClass> ViewModel;
    public:
        App();
        bool Init();
        void run();
};

#endif // APP_H
