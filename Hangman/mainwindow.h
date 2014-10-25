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

    void on_buttonNewWord_clicked();

    void on_buttonResign_clicked();

    void on_buttonHint_clicked();

private:
    Ui::MainWindow *ui;
    DataManager dataManager;

    QGraphicsScene *scene;
    QFont *font;

    void redrawAttemptedCharBox();
    void redrawWord();
    void redrawNumAttempts();
    void redrawNumAttemptsLeft();
    void update(QChar input);
};

#endif // MAINWINDOW_H
