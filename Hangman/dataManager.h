#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QMainWindow>

#include <vector>

class DataManager
{
public:
    DataManager();
    void charAdd(const QChar& input);
    QString getString();

private:
    std::vector<QChar> attemptedChars;
};

#endif // DATAMANAGER_H
