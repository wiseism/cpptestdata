#include "date/date.h"
#include "date/tz.h"
#include <iostream>
#include <sstream>

int main() {
    using namespace date;
    using namespace std::chrono;

    // 获取当前的系统时间
    auto now = system_clock::now();

    // 转换为UTC时间点
    auto now_c = time_point_cast<system_clock::duration, date::utc_clock>(now);

    // 输出UTC时间
    std::cout << "UTC time: " << format("%F %T", now_c) << '\n';

    // 假设我们要转换到纽约时区
    const auto Zone_America_New_York = load_tz("America/New_York");
    auto ztp = make_zoned(Zone_America_New_York, now_c);

    // 输出纽约的本地时间
    std::cout << "New York time: " << format("%Y-%m-%d %H:%M:%S %Z%z", ztp) << '\n';

    // 格式化并包含时区缩写和偏移
    std::ostringstream oss;
    oss << format("%Y-%m-%d %H:%M:%S %Z%z", ztp);
    std::string formatted_time = oss.str();
    std::cout << "Formatted New York time: " << formatted_time << '\n';

    return 0;
}