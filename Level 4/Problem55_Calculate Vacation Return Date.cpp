#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stMyDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
bool IsLeapYear(short Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}
short NumberDaysInMonth(short Year, short Month) {
    if (Month <= 0 || Month > 12)
        return 0;
    short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberDaysinMonth[Month - 1]);
}
bool IsLastDayInMonth(stMyDate Date)
{
    return (Date.Day == NumberDaysInMonth(Date.Year, Date.Month));
}
stMyDate IncreaseDateByOneDay(stMyDate Date) {

    if (IsLastDayInMonth(Date))
    {
        if (12 == Date.Month) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return  Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(stMyDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool isWeekEnd(stMyDate Date)
{
    short DanIndex = DayOfWeekOrder(Date);
    return (5 == DanIndex || 6 == DanIndex);
}
bool isBusinessDay(stMyDate Date)
{
    return !isWeekEnd(Date);
}

string DayShortName(short WeekDay)
{
    string NameDaysWeek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDaysWeek[WeekDay];
}

// solution 1
stMyDate CalculateVacationReturnDateSolution1(stMyDate DateFrom, short vacationDays)
{
    short WeekEndCounter = 0;
    
    while (isWeekEnd(DateFrom))
        DateFrom = IncreaseDateByOneDay(DateFrom);
    
    for (short i = 1; i <= vacationDays + WeekEndCounter; i++)
    {
        if (isWeekEnd(DateFrom))
            WeekEndCounter++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    while (isWeekEnd(DateFrom))
        DateFrom = IncreaseDateByOneDay(DateFrom);

    return DateFrom;
}

// solution 2
stMyDate CalculateVacationReturnDate(stMyDate DateFrom, short vacationDays)
{
    short daysVacationCount = 0;
    while (daysVacationCount < vacationDays)
    {
        if (isBusinessDay(DateFrom))
            daysVacationCount++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    while (isWeekEnd(DateFrom))
        DateFrom = IncreaseDateByOneDay(DateFrom);

    return DateFrom;
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year : ";
    cin >> Year;
    return Year;
}
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month : ";
    cin >> Month;
    return Month;
}
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day : ";
    cin >> Day;
    return Day;
}
stMyDate ReadFullDate() {
    stMyDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
short ReadVacationDays() {
    short days;
    cout << "Please enter vacation days ? ";
    cin >> days;
    return days;
}

int main()
{
    //------------------------
    cout << "Vacation Starts : \n";
    stMyDate Date1 = ReadFullDate();

    //------------------------
    cout << "\n\n";
    short vacationDays = ReadVacationDays();
    //------------------------
    stMyDate DateReturn = CalculateVacationReturnDate(Date1, vacationDays);

    cout << "\n\nReturn Date : " << DayShortName(DayOfWeekOrder(DateReturn)) << " , ";
    printf("%d/%d/%d\n\n", DateReturn.Day, DateReturn.Month, DateReturn.Year);

    system("pause>0");
    return 0;
}
