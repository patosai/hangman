#include "dataManager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    font = new QFont("Monospace");
    font->setStyleHint(QFont::TypeWriter);
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

// Enter button, alternative for pressing enter key
// Redirects to below function
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

void MainWindow::on_buttonNewWord_clicked()
{
    dataManager.getNewWord();
    scene->clear();
    scene->addText(dataManager.getDisplayWord(), *font);
    ui->attemptedChars->setText("");
}


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


