#include "app.h"

App::App()
{
}

bool App::Init()
{
//    if(View.Create() == NULL ) {
//        return false;
//    }

    std::shared_ptr<ModelClass> spModel(std::make_shared<ModelClass>());
    ViewModel = std::make_shared<ViewModelClass>();
    ViewModel->SetModel(spModel);
    //binding
    // properties
    View.SetChangeNode(ViewModel->GetNode());
    //View.set_Name(ViewModel->get_CityName());
    // commands
    View.set_InsertCommand(ViewModel->get_InsertCommand());
    View.set_DeleteCommand(ViewModel->get_DeleteCommand());
    View.set_FindCommand(ViewModel->get_FindCommand());
    View.set_PreOrderCommand(ViewModel->get_PreOrderCommand());
    View.set_PostOrderCommand(ViewModel->get_PostOrderCommand());
    View.set_InOrderCommand(ViewModel->get_InOrderCommand());
    // notifications
    ViewModel->AddPropertyNotification(View.get_PropertySink());
    ViewModel->AddCommandNotification(View.get_CommandSink());

    return true;

}

void App::run()
{
    View.show();
}
