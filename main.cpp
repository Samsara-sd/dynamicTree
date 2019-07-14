#include <QApplication>
#include "app/app.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(images);
    QApplication a(argc, argv);
    App* app = new App();
    app->Init();
    app->run();
    return a.exec();
}
