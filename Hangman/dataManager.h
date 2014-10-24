#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QMainWindow>

#include <vector>

class DataManager
{
public:
    DataManager();

    void charAdd(const QChar& input);
    void fillWordList(QString fileName);
    void getNewWord();
    QString getAttemptedLetters();
    int getNumAttempts();
    int getAttemptsLeft();
    void updateAttemptsLeft(QChar input);
    QString getWord();
    QString getDisplayWord();
    void giveUp();
    bool hasGivenUp();
    void reset();

private:
    int numAttempts, numAttemptsLeft;
    bool showWord;
    std::vector<QString> wordList;
    std::vector<QChar> attemptedChars;
    QString word;
};

#endif // DATAMANAGER_H
