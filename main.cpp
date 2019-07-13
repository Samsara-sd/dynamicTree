#include <QApplication>
#include "app/app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App* app = new App();
    app->Init();
    app->run();
    return a.exec();
}
