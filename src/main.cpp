#include "date/date.h" // 注意：这取决于你的项目如何设置包含路径
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
int main() {
    using namespace date;
    using namespace std::chrono;
    auto now = system_clock::now();
    auto today = floor<days>(now);

    // 打印今天的日期
    std::cout << "Today's date is " << year_month_day(today) << '\n';

    // 创建一个具体的日期和时间点
    auto specific_time = sys_days(today) + hours(12) + minutes(34) + seconds(56);

    // 将其转换回 system_clock::time_point
    auto tp = system_clock::from_time_t(time_t(specific_time.time_since_epoch().count()));
    std::time_t time = std::chrono::system_clock::to_time_t(tp);

    // 打印该时间点
    std::cout << "Specific time is " << std::put_time(std::localtime(&time), "%F %T") << '\n';

    return 0;
}