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
    QString getWord();
    QString getDisplayWord();
    void giveUp();
    bool hasGivenUp();

private:
    bool showWord;
    std::vector<QString> wordList;
    std::vector<QChar> attemptedChars;
    QString word;
};

#endif // DATAMANAGER_H
