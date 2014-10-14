#include "dataManager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    font = new QFont();
    font->setPointSize(42);
    font->setUnderline(true);
    scene->addText(dataManager.getDisplayWord(), *font);

    ui->graphicsView->setScene(scene);
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

// Enter button - redirects to below function
void MainWindow::on_buttonEnter_clicked()
{
    on_inputChar_returnPressed();
}

// Character guess enter function
void MainWindow::on_inputChar_returnPressed()
{
    if (ui->inputChar->text() != "")
    {
        QChar input = ui->inputChar->text().at(0);
        ui->attemptedChars->setText(input);
        update(input);

        ui->inputChar->setText("");
    }
}

// Updates string in graphics scene


/************************************
 *  Display methods                 *
 ************************************/

void MainWindow::update(QChar input)
{
    // Add input character to database
    dataManager.charAdd(input);

    // Update attempted character box
    ui->attemptedChars->setText(dataManager.getAttemptedLetters());

    // Redraw big box to display word
    scene->clear();
    scene->addText(dataManager.getDisplayWord(), *font);
}


