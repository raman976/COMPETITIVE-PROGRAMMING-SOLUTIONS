// 1185. Day of the Week
// Solved
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Given a date, return the corresponding day of the week for that date.

// The input is given as three integers representing the day, month and year respectively.

// Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

// Note: January 1, 1971 was a Friday.

 

// Example 1:

// Input: day = 31, month = 8, year = 2019
// Output: "Saturday"

// Example 2:

// Input: day = 18, month = 7, year = 1999
// Output: "Sunday"

// Example 3:

// Input: day = 15, month = 8, year = 1993
// Output: "Sunday"

 

// Constraints:

//     The given dates are valid dates between the years 1971 and 2100.

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // count total days from 1971 to year-1
        int total = 0;

        for (int y = 1971; y < year; y++) {
            total += 365;
            if (isLeap(y)) total += 1;
        }

        // add days for previous months in the same year
        for (int m = 1; m < month; m++) {
            total += monthDays[m - 1];
            if (m == 2 && isLeap(year)) total += 1;
        }

        // add the days in the current month
        total += day - 1;

        // final result
        return days[total % 7];
    }

    bool isLeap(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
};
