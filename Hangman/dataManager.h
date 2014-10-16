#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QMainWindow>

#include <vector>

class DataManager
{
public:
    DataManager();

    void charAdd(const QChar& input);
    void getNewWord();
    QString getAttemptedLetters();
    QString getWord();
    QString getDisplayWord();

private:
    std::vector<QChar> attemptedChars;
    QString word;
};

#endif // DATAMANAGER_H
