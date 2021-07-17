/*
Para el Archivo del ejercicio (a) 
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream openFile(string path);
int countWords(string sentence);
bool letter(int var);
void showWordsOf(ifstream file);

int main()
{
    showWordsOf(openFile("QuotesOfBjarne.txt"));
    return 0;
}

ifstream openFile(string path)
{
    ifstream in;
    in.open("QuotesOfBjarne.txt");

    if (!in)
    {
        cerr << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return in;
}

int countWords(string sentence)
{
    int i = 0, counter = 0;
    bool found_word = false;
    
    while (i < sentence.length())
    {
        if (letter(sentence[i]) && found_word == false)
        {
            found_word = true;
            counter ++;

           }else if (letter(sentence[i]) == false)
            {   
                if (found_word == true)
                {
                    found_word = false;
                }
            }
        i++;
        
    }
    return counter;
}
bool letter(int var)
{
    string alphabet = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZáéíóúÁÉÍÓÚäëïöüÄËÏÖÜàèìòùÀÈÌÒÙ";
    
    int i = 0;
    bool ret;

    while (i < (int) alphabet.length())
    {
        if (var == alphabet[i])
        {
            ret = true;
            return ret;
        }else
        {
            ret = false;
        }

        i++;
    }
    return ret;
}

void showWordsOf(ifstream file)
{
    int sentecesNumber = 0;
    int totalWords = 0;

    while (!file.eof())
    {
        string sentence;
        getline(file, sentence);
        int wordsPerSetence = countWords(sentence);
        cout << "La frase número " << sentecesNumber + 1 << " tiene " << wordsPerSetence << " palabras" << endl;

        totalWords += wordsPerSetence;
        sentecesNumber++;
    }

    cout << "Cantidad total de palabras " << totalWords << endl;
    float averageOfWords = float(totalWords) / float(sentecesNumber);
    cout << "Promedio de palabras por línea " << averageOfWords << endl;
}