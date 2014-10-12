#include "dataManager.h"

#include <stdint.h> // uint8_t

DataManager::DataManager()
{

}

// Binary search + add to QString
void DataManager::charAdd(const QChar& charInput)
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
            return;
        }
    }

    // If the character is to be placed at end of vector
    attemptedChars.push_back(input);
}

QString DataManager::getString()
{
    QString returnString;
    for (uint8_t i = 0; i < attemptedChars.size(); i++)
    {
        returnString += attemptedChars.at(i);
    }
    return returnString;
}
