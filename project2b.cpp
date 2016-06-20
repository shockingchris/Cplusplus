/********************************************************
* Program:
*    Project 2, Month Calendar
*    Brother Grimmett, CS124
* Author:
*  Chris Simmons
* Summary:
*   This program will take the input of the month and the
*   input of the year and if it is suitable it will print
*   out the month calendar.
********************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function will get a desired month from the user and wont allow
 * them to put in a number that doesnt correspond with a month
 ***********************************************************************/
int getMonth()
{
   int month = 0;
   do
   {
      cout << "Enter a month number: ";
      cin >> month;
      if (month < 1 || month > 12)
         cout << "Month must be between 1 and 12.\n";
      else
         return month;
   }while (month < 1 || month > 12);
}

/**********************************************************************
 * this function will prompt the user for a year later than 1753
 * if they try to put in something less it will let them try again
 ***********************************************************************/
int getYear()
{
   int year = 0;
   do
   {
      cout << "Enter year: ";
      cin >> year;
      if (year < 1753)
         cout << "Year must be 1753 or later.\n";
      else
         return year;
   }while (year < 1753);
}

/**********************************************************************
 * this function will calculate if the year the user input is leap year so
 * that i can get the right number of days for the year and the month
 * If the year is modulo 400, 100, or 4 equal 0 then it will return true
 * and the function that gets the days of the year will return 366 days
 ***********************************************************************/
bool isLeapYear(int year)
{
   return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

/**********************************************************************
 * gives the number of days in the year based off user input and the leap
 * year function
 ***********************************************************************/
int getDaysYear(int year)
{
   if (isLeapYear(year))
      return 366;
   else
      return 365;
}

/**********************************************************************
 * This function will take the user input and return the right amount of
 * days for that month. Even the extra 29 for feb on leap years
 ***********************************************************************/
int getDaysMonth(int month, int year)
{
   if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
   else if (month == 2)
   {
      if (isLeapYear(year))
         return 29;
      else
         return 28;
   }
   else
      return 31;
}

/**********************************************************************
 * this function adds the number of years from 1753 to the year the user
 * inputs and sets that into count and then it adds that to the number of
 * days in the year the user input. Then it adds the month number the user
 * input to the number of days in that month and then that is divided by
 * 7 and the remainder is used as the offset which will tell display()
 * what day to start on when it displays the days of the month.
 * Pseudocode for this function
 *
 ***********************************************************************/
int computeOffset(int month, int year)
{
   int count = 0;
   int i = 0;
   int offset = 0;

   for (i = 1753; i < year; i++)
   {
      count = count + getDaysYear(i);
   }

   for (i = 1; i < month; i++)
   {
      count = count + getDaysMonth(i, year);
   }

   offset = count % 7;

   return offset;
}

/**********************************************************************
 * This will take the number the user put in for the month and convert it
 * into the written way of recognizing the month so it can be displayed
 ***********************************************************************/
void displayHeader(int month, int year)
{
   if (month == 1)
      cout << "January, " << year << endl;
   else if (month == 2)
      cout << "February, " << year << endl;
   else if (month == 3)
      cout << "March, " << year << endl;
   else if (month == 4)
      cout << "April, " << year << endl;
   else if (month == 5)
      cout << "May, " << year << endl;
   else if (month == 6)
      cout << "June, " << year << endl;
   else if (month == 7)
      cout << "July, " << year << endl;
   else if (month == 8)
      cout << "August, " << year << endl;
   else if (month == 9)
      cout << "September, " << year << endl;
   else if (month == 10)
      cout << "October, " << year << endl;
   else if (month == 11)
      cout << "November, " << year << endl;
   else if (month == 12)
      cout << "December, " << year << endl;

   return;
}

/**********************************************************************
 * this function uses the getDaysMonth to know how many days to display,
 * it shows the days of the week under the displayHeader function which
 * it calls and it uses the offset function to know what day of the week
 * to start on and then it aligns those through the set width command and
 * two for loops with if statements.
 * Pseudocode for this function this one was really tough to do depending
 * on what you do this code  might not even help you
 *
 ***********************************************************************/
void displayTable(int month, int year)
{
   int daysMonth = getDaysMonth(month, year);
   int offset = computeOffset(month, year);
   displayHeader(month, year);

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   int i;

   if (offset < 6)
   {
      for (i = 0; i < offset + 1; i++)
      {
         cout << "    ";
      }
   }


   for (i = 1; i <= daysMonth; i++)
   {
      cout << setw(4) << i;
      if (((((offset + 1) + i)) % 7) == 0)
         cout << endl;
   }

   if ((offset + i) % 7 != 0)
      cout << endl;

   return;
}

/**********************************************************************
 * This runs all the main functions in the program. Great for organizing
 ***********************************************************************/
int main()
{
   int month;
   int year;


   month = getMonth();
   year = getYear();
   cout << endl;
   displayTable(month, year);

   return 0;
}
