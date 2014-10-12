#include "dataManagement.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 *  Input methods
 */

// Enter button - redirects to enter key pressed on line edit
void MainWindow::on_buttonEnter_clicked()
{
    on_inputChar_returnPressed();
}

// Line edit enter function
void MainWindow::on_inputChar_returnPressed()
{
    QChar input = ui->inputChar->text().at(0);
    ui->attemptedChars->setText(input);
    updateAttemptedList(input);

    ui->inputChar->setText("");
}

/*
 *  Display methods
 */
void MainWindow::updateAttemptedList(QChar input)
{
    DataManagement::charAdd(input);

    ui->attemptedChars->setText(DataManagement::getString());
}

/*
 *  Helper functions
 */

