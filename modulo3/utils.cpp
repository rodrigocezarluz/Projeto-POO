#include "utils.h"

time_t getTime(int day, int month, int year, int hh, int mm, int ss) {

    time_t now = time(0);
    struct tm* timeinfo  = std::localtime (&now);

    timeinfo->tm_mday = day;
    timeinfo->tm_mon = month-1;
    timeinfo->tm_year = year-1900;
    timeinfo->tm_hour = hh;
    timeinfo->tm_min = mm;
    timeinfo->tm_sec = ss;

    time_t converted = mktime(timeinfo);
    return converted;
}

int diffDays(time_t date1, time_t date2) {
    int days = int(std::floor(date1 / 24. / 3600.) - std::floor(date2 / 24. / 3600.));
    return days;
}