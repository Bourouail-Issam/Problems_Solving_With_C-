//#include <iostream>
//#include <vector>
//using namespace std;
//
//long long int ReadNumber()
//{
//    long long int number;
//    cout << "Enter Number ? ";
//    cin >> number;
//    return number;
//}
//
///*string NumberToText(long long int number)
//{
//    if (number == 0)
//        return "";
//
//    if (number >= 1 && number < 20) 
//    {
//        string Arr[] ={ "","One", "Two", "Three", "Four",
//        "Five", "Six", "Seven", "Eight", "Nine"  , "ten","Eleven","Thirteen",
//        "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
//
//        return Arr[number] + " ";
//    }
//    if (number >=20 && number < 99)
//    {
//        string Arr[] = { "","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ",
//        "Seventy ", "Eighty ","Ninety " };
//        return (Arr[number / 10] + NumberToText(number % 10));
//
//    }
//    if (number >= 100 && number <= 199)
//    {
//        return ( "One Hundred " + NumberToText(number % 100));
//    }
//    if (number >= 200 && number < 999)
//    {
//        return (NumberToText(number / 100) + "Hundred " + NumberToText(number % 100));
//    }
//    if (number >= 1000 && number <= 1999)
//    {
//        return ("One Thousand " + NumberToText(number % 1000));
//    }
//    if (number >= 2000 && number < 999999)
//    { 
//        return (NumberToText(number / 1000) + "Thousand " + NumberToText(number % 1000));
//    }
//    if (number >= 1000000 && number <= 1999999)
//    {
//        return ("One Million " + NumberToText(number % 1000000));
//    }
//    if (number >= 2000000 && number < 999999999)
//    {
//        return (NumberToText(number / 1000000) + "Million " + NumberToText(number % 1000000));
//    }
//    if (number >= 1000000000 && number <= 1999999999)
//    {
//        return ("One Billion " + NumberToText(number % 1000000000));
//    }
//    if (number >= 2000000000 && number < 999999999999)
//    {
//        return (NumberToText(number / 1000000000) + "Billion " + NumberToText(number % 1000000000));
//    }
//}*/

//
//int main()
//{
//    long long int number = ReadNumber();
//    cout << endl << NumberToText(number) << endl << endl;
//}


#include <iostream>
#include <string>

using namespace std;

// Function to convert digits to words
string digitToWord(int digit) {
    switch (digit) {
    case 0: return "zero";
    case 1: return "one";
    case 2: return "two";
    case 3: return "three";
    case 4: return "four";
    case 5: return "five";
    case 6: return "six";
    case 7: return "seven";
    case 8: return "eight";
    case 9: return "nine";
    default: return "";
    }
}

// Function to convert teens to words
string teenToWord(int teen) {
    switch (teen) {
    case 10: return "ten";
    case 11: return "eleven";
    case 12: return "twelve";
    case 13: return "thirteen";
    case 14: return "fourteen";
    case 15: return "fifteen";
    case 16: return "sixteen";
    case 17: return "seventeen";
    case 18: return "eighteen";
    case 19: return "nineteen";
    default: return "";
    }
}

// Function to convert tens to words
string tensToWord(int tens) {
    switch (tens) {
    case 2: return "twenty";
    case 3: return "thirty";
    case 4: return "forty";
    case 5: return "fifty";
    case 6: return "sixty";
    case 7: return "seventy";
    case 8: return "eighty";
    case 9: return "ninety";
    default: return "";
    }
}

// Function to convert a number less than 1000 to its text representation
string numberLessThan1000ToText(int number) {
    string result;

    int hundreds = number / 100;
    if (hundreds > 0) {
        result += digitToWord(hundreds) + " hundred";
        number %= 100;
        if (number > 0)
            result += " ";
    }

    if (number >= 20) {
        int tens = number / 10;
        result += tensToWord(tens);
        number %= 10;
        if (number > 0)
            result += "-";
    }
    else if (number >= 10) {
        result += teenToWord(number);
        return result;
    }

    if (number > 0)
        result += digitToWord(number);

    return result;
}

// Function to convert a number to its text representation
string numberToText(long long number) {
    if (number == 0)
        return "zero";

    string result = "";
    const char* scaleNames[] = { "", "thousand", "million", "billion" };

    int scaleIndex = 0;
    while (number > 0) {
        int part = number % 1000;
        if (part > 0) {
            string partText = numberLessThan1000ToText(part);
            if (!result.empty())
                result = partText + " " + scaleNames[scaleIndex] + " " + result;
            else
                result = partText;
        }
        number /= 1000;
        scaleIndex++;
    }
    return result;
}

int main() {
    long long number;
    cout << "Enter a number: ";
    cin >> number;

    string textRepresentation = numberToText(number);
    cout << "Text representation: " << textRepresentation << endl;

    return 0;
}
