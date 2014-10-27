#include "mainwindow.h"
#include <QApplication>

#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = QFileDialog::getOpenFileName();
    if ( !path.isNull() )
    {
        MainWindow w(path);
        w.show();

        return a.exec();
    }
    else
        return 0;

}
