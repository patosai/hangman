#include "dataManager.h"

#include <stdint.h> // uint8_t

DataManager::DataManager()
{
    word = "MAN-OF-WAR";
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
            returnString += " ";
    }

    return returnString;
}
