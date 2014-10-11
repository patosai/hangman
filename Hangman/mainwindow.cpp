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

void MainWindow::on_buttonEnter_clicked()
{
    on_inputChar_returnPressed();
}

void MainWindow::on_inputChar_returnPressed()
{
    QChar input = ui->inputChar->text().at(0);
    ui->attemptedChars->setText(input);

    ui->inputChar->setText("");
}
