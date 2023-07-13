#include <string>
#include <stdexcept>
using namespace std;
void throw_less(int value, int less, string message) {
    if (value < less)
        throw domain_error(message + " is too small"s);
}
void throw_more(int value, int more, string message) {
    if (value < more)
        throw domain_error(message + " is too big"s);
}
constexpr auto MIN_YEAR_ = 1;;
constexpr auto MAX_YEAR_ = 1000;
constexpr auto MIN_MONTH_ = 1;
constexpr auto MAX_MONTH_ = 12;
constexpr auto MIN_MONTH_ = 1;
constexpr auto MAX_MONTH_ = 12;
constexpr auto MIN_DAY_ = 0;
constexpr auto MIN_HOUR_ = 0;
constexpr auto MAX_HOUR_ = 23;
constexpr auto MIN_MINUTE_ = 0;
constexpr auto MAX_MINUTE_ = 59;
constexpr auto MIN_SECOND_ = 0;
constexpr auto MAX_SECOND_ = 59;
void CheckDateTimeValidity(const DateTime& dt) {
    const bool is_leap_year = (dt.year % 4 == 0) && !(dt.year % 100 == 0 && dt.year % 400 != 0);
    const array month_lengths = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    static const int MAX_DAY_ = month_lengths[dt.month - 1];
    throw_less(dt.year, MIN_YEAR_, "year");
    throw_more(dt.year, MAX_YEAR_, "year");
    throw_less(dt.month, MIN_MONTH_, "month");
    throw_more(dt.month, MAX_MONTH_, "month");
    throw_less(dt.day, MIN_DAY_, "day");
    throw_more(dt.day, MAX_DAY_, "day");
    throw_less(dt.hour, MIN_HOUR_, "hour");
    throw_more(dt.hour, MAX_HOUR_, "hour");
    throw_less(dt.minute, MIN_MINUTE_, "minute");
    throw_more(dt.minute, MAX_MINUTE_, "minute");
    throw_less(dt.second, MIN_SECOND_, "second");
    throw_more(dt.second, MAX_SECOND_, "second");
}