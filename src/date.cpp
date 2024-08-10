#include "date/date.h"
#include "date/tz.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
    using namespace date;
    using namespace std::chrono;

    // 获取当前的系统时间
    auto now = system_clock::now();

    // 转换为UTC时间点
    // 使用 system_clock::duration 进行转换
    auto now_c = time_point_cast<system_clock::duration>(now);

    // 如果你使用 date 库，需要这样转换
    auto now_date = date::floor<system_clock::duration>(now);
    // 输出UTC时间
    std::cout << "UTC time: " << format("%F %T", now_c) << '\n';

    // 假设我们要转换到纽约时区
    // 加载时区信息
    const auto Zone_America_New_York = date::locate_zone("America/New_York");

    // 转换时间到指定时区
    auto zoned_time = make_zoned(Zone_America_New_York, now);

    std::cout << "Current time in New York: " << zoned_time << '\n';
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