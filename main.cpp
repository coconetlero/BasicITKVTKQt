#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow *viewerMainWindow = new MainWindow();
   
    viewerMainWindow->show();
    return app.exec();
}
