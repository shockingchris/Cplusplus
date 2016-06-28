/***********************************************************************
* Program:
*    Project 3, Mad Libs Project 
*    Brother Grimmett, CS124
* Author:
*    Chris Simmons
* Summary: 
*    This program takes words that you input and places them into the
*    madlib story.
*
*    Estimated:  10.0 hrs   
*    Actual:     10.0 hrs
*      I had an extra character that I don't know how to get rid of.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * GetFileName prompts for a file name and send the name to main to be
 * used by other functions.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cin.ignore();
}

/**********************************************************************
 * Readfile reads the file and inputs it into an array for use.
 ***********************************************************************/
float readFile(char story[][32], char fileName[])
{
   getFileName(fileName);
   
   int i = 0;
   ifstream fin;

   fin.open(fileName);
      
   if (fin.fail())
      return -1;

   while (!fin.eof())
   {
      fin >> story[i++];
   }
   
   fin.close();

   return i;
}

/**********************************************************************
 * ConvertWord checks the words and depending on what they are, it changes
 * the words around according to what you input.
 ***********************************************************************/
void convertWord(char story[][32], int numberWords)
{
   for(int i = 0; i < numberWords; i++)
      if (story[i][0] == '<')
      {
         switch (story[i][1])
         {
            case '#':
               story[i][0] = '\n';
               story[i][1] = 0;
               break;
            case '{':
               story[i][0] = ' ';
               story[i][1] = '\"';
               story[i][2] = 0;
               break;
            case '}':
               story[i][0] = '\"';
               story[i][1] = 0;
               break;
            case '0':
               story[i][0] = 0;
               break;
            default:
               int j;
               for (j = 0; story[i][j] != '>'; j++)
               {
                  if (story[i][j+1] != '_')
                  {
                     story[i][j] = story[i][j+1];
                  }
                  else
                  {
                     story[i][j] = ' ';
                  }
               }
               if (story[i][j] == '>')
                  story[i][j] = 0;
               if (story[i][j-1] == '>')
                  story[i][j-1] = 0;
               cout << "\t";
               story[i][0] = toupper(story[i][0]);
               cout << story[i];
               cout << ": ";
               cin.getline(story[i], 32);
               break;
         }
      }
}

/**********************************************************************
 * Display function checks to see if there is a punctuation and then
 * inputs accordingly.
 ***********************************************************************/
void display(char story[][32], int numberWords)
{
   cout << "\n";
   for (int i = 0; i < numberWords - 1; i++)
   {
      if ((story[i + 1][0] == '.')  || (story[i + 1][0] == ',')
          || (story[i + 1][0] == '"')  || (story[i][1] == '"')
          || (story[i + 1][1] == '"')  || (story[i][1] == '\'')
          || (story[i + 1][1] == '\'') || (story[i + 1][0] == '\'')
          || (story[i + 1][0] == '?')  || (story[i + 1][0] == '!')
          || (story[i + 1][0] == '\n') || (story[i][0] == '\n'))
         cout << story[i];
      else
         cout << story[i] << ' ';
   }
   cout << story[numberWords - 1];
   cout << "\n";
   return;
}

/**********************************************************************
 * The main function runs the functions and then plays again if asked.
 ***********************************************************************/
int main()
{
   int i = 0;
   char story[256][32];
   int numberWords;
   char fileName[32];
   bool playAgain = 1;
   char answer;

   while (playAgain)
   {
      playAgain = 0;
      numberWords = readFile(story, fileName);
      convertWord(story, numberWords);
      display(story, numberWords);
      
      cout << "Do you want to play again (y/n)? ";
      cin >> answer;
      if (answer == 'y' || answer == 'Y')
         playAgain = 1;
   }
         cout << "Thank you for playing." << endl;
      return  0;
}