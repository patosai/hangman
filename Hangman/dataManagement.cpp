#include "dataManagement.h"
#include <math.h>

std::vector<QChar> attemptedChars;

// Binary search + add to QString
void DataManagement::charAdd(const QChar& input)
{
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
            return;
        }
    }

    // If the character is to be placed at end of vector
    attemptedChars.push_back(input);
}

QString DataManagement::getString()
{
    QString returnString;
    for (int i = 0; i < attemptedChars.size(); i++)
    {
        returnString += attemptedChars.at(i);
    }
    return returnString;
}
