#include "mainwindow.h"
#include "automate.h"
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AutoCell fenetre;

    fenetre.show();
    return app.exec();
}
