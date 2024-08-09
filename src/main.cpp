#include "date/date.h" // 注意：这取决于你的项目如何设置包含路径
#include <iostream>

int main() {
    using namespace date;
    using namespace std::chrono;

    // 获取当前系统时间
    auto now = system_clock::now();

    // 将 system_clock::time_point 转换为 time_t，然后转换为 local_days
    auto today = floor<days>(system_clock::to_time_t(now));

    // 打印今天的日期
    std::cout << "Today's date is " << year_month_day(today) << '\n';

    // 创建一个具体的日期和时间点
    auto specific_time = sys_days(today) + 12h + 34min + 56s;

    // 将其转换回 system_clock::time_point
    auto tp = system_clock::from_time_t(time_t(specific_time.time_since_epoch().count()));

    // 打印该时间点
    std::cout << "Specific time is " << put_time(std::localtime(&tp.time_since_epoch().count()), "%F %T") << '\n';

    return 0;
}