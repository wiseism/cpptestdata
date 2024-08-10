#include <iostream>
#include <chrono>
#include "date/date.h"

using namespace std;
using namespace std::chrono;
using namespace date;

int main() {
  // 获取当前时间点
  auto now = system_clock::now();

  // 将当前时间点向下取整到天
  auto today = floor<days>(now);

  // 创建一个特定时间：今天的 12:34:56
  auto specific_time = sys_days(today) + hours(12) + minutes(34) + seconds(56);

  // 打印当前时间
  cout << "Current time: " << now << endl;

  // 打印今天的日期
  cout << "Today's date: " << today << endl;

  // 打印特定时间
  cout << "Specific time: " << specific_time << endl;

  // 获取年、月、日
  year_month_day ymd{floor<days>(specific_time)};
  cout << "Year: " << ymd.year()
       << ", Month: " << ymd.month()
       << ", Day: " << ymd.day() << endl;

  // 获取时、分、秒
  hh_mm_ss<milliseconds>  time{specific_time - floor<days>(specific_time)};
  cout << "Time: " << time << endl;

  // 日期计算：加上 30 天
  auto future_date = sys_days{today} + days{30};
  cout << "Date after 30 days: " << future_date << endl;

  // 获取星期几
  // 将时间点转换为天的整数部分
  auto days_part = floor<days>(specific_time);

  // 使用 days_part 构造 weekday
  weekday wd{days_part};
  cout << "Day of the week: " << wd << endl;

  // 解析日期字符串
  istringstream in{"2023-05-15"};
  year_month_day d;
  in >> date::parse("%F", d);
  cout << "Parsed date: " << d << endl;

  return 0;
}