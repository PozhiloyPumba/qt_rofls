#include "mainWindow/mainWindow.hpp"
#include "mouseTracker/mouseTracker.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}