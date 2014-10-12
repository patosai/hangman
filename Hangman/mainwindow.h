#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "dataManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonEnter_clicked();

    void on_inputChar_returnPressed();

private:
    Ui::MainWindow *ui;
    DataManager dataManager;

    QGraphicsScene *scene;
    QFont *font;

    void updateAttemptedList(QChar input);

    void setGraphicsScene();
};

#endif // MAINWINDOW_H
