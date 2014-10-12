#include "dataManager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGraphicsScene();
}

MainWindow::~MainWindow()
{
    delete font;
    delete scene;
    delete ui;
}

/************************************
 *  Input methods                   *
 ************************************/

// Enter button - redirects to enter key pressed on line edit
void MainWindow::on_buttonEnter_clicked()
{
    on_inputChar_returnPressed();
}

// Line edit enter function
void MainWindow::on_inputChar_returnPressed()
{
    if (ui->inputChar->text() != "")
    {
        QChar input = ui->inputChar->text().at(0);
        ui->attemptedChars->setText(input);
        updateAttemptedList(input);

        ui->inputChar->setText("");
    }
}

/************************************
 *  Display methods                 *
 ************************************/
void MainWindow::updateAttemptedList(QChar input)
{
    dataManager.charAdd(input);

    ui->attemptedChars->setText(dataManager.getString());
}

void MainWindow::setGraphicsScene()
{
    scene = new QGraphicsScene();

    font = new QFont();
    font->setPointSize(42);
    font->setUnderline(true);
    scene->addText("testing", *font);

    ui->graphicsView->setScene(scene);
}
