#include "dataManager.h"

#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>

#include <stdint.h> // uint8_t

DataManager::DataManager()
{
    numAttempts = 0;
    showWord = false;

    QString path = QFileDialog::getOpenFileName();
    if ( !path.isNull() )
    {
        fillWordList(path);
        getNewWord();
    }
    else
    {
        word = "ERROR";
    }

    resetNumAttempted();
}

// Binary search + add to QString
void DataManager::charAdd(const QChar& charInput, bool b)
{
    // Check if character is valid (A-Z)
    if ( !charInput.isLetter() )
        return;

    QChar input = charInput.toUpper();

    for (std::vector<QChar>::iterator it = attemptedChars.begin();
         it < attemptedChars.end();
         it++)
    {
        // Detect if character was already entered
        if (input == *it)
            return;

        // Compare characters
        if (input < *it)
        {
            attemptedChars.insert(it, input);
            numAttempts++;
            if (b)
                updateAttemptsLeft(input);
            return;
        }
    }

    // If the character is to be placed at end of vector
    attemptedChars.push_back(input);
    numAttempts++;

    if (b)
        updateAttemptsLeft(input);
}

void DataManager::fillWordList(QString fileName)
{
    QString temp;
    QFile fileStream(fileName);
    if (!fileStream.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "File Error", fileStream.errorString());
        return;
    }
    QTextStream textStream(&fileStream);
    textStream >> temp;
    while (!textStream.atEnd())
    {
        temp = temp.toUpper();
        wordList.push_back(temp);
        textStream >> temp;
    }
    fileStream.close();
}

QString DataManager::getAttemptedLetters()
{
    QString returnString;
    for (uint8_t i = 0; i < attemptedChars.size(); i++)
    {
        returnString += attemptedChars.at(i);
    }
    return returnString;
}

QString DataManager::getWord()
{
    return word;
}

QString DataManager::getDisplayWord()
{
    if (showWord) return word;

    QString returnString;

    for (uint8_t i = 0; i < word.length(); i++)
    {
        bool found = false;
        for (uint8_t j = 0; j < attemptedChars.size(); j++)
        {
            if (word.at(i) == attemptedChars.at(j))
            {
                returnString += attemptedChars.at(j);
                found = true;
                break;
            }
        }
        if (word.at(i) == '-')
            returnString += "-";
        else if (!found)
        {
            returnString += " ";
        }
    }

    return returnString;
}

void DataManager::getNewWord()
{
    int randomIndex = rand() % wordList.size();
    word = wordList.at(randomIndex);
    attemptedChars.clear();
}

void DataManager::giveUp()
{
    showWord = true;
}

bool DataManager::hasGivenUp()
{
    return showWord;
}

int DataManager::getNumAttempts()
{
    return numAttempts;
}

int DataManager::getAttemptsLeft()
{
    return numAttemptsLeft;
}

void DataManager::reset()
{
    numAttempts = 0;
    resetNumAttempted();
    getNewWord();
    showWord = false;
}

void DataManager::updateAttemptsLeft(QChar input)
{
    // Check if character is not in word
    bool remove = true;
    for (int i = 0; i < word.size(); i++)
    {
        if (word.at(i) == input)
        {
            remove = false;
        }
    }
    if (remove)
        numAttemptsLeft--;

    if (numAttemptsLeft <= 0)
        giveUp();
}

void DataManager::resetNumAttempted()
{
    numAttemptsLeft = 5 + int(word.size()/26.0 * 10);
}

void DataManager::getHint()
{
    QChar hintChar;
    do
    {
        hintChar= QChar('A' + char(qrand() % ('Z' - 'A')));
    } while (hasBeenGuessed(hintChar) || word.indexOf(hintChar) == -1);
    charAdd(hintChar, false);
}

bool DataManager::hasBeenGuessed(const QChar& input)
{
    for (uint8_t j = 0; j < attemptedChars.size(); j++)
    {
        if (input == attemptedChars.at(j))
        {
            return true;
        }
    }
    return false;
}
