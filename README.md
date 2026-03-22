# README

date/3.0.1

## 构建和运行

### 依赖安装
```bash
conan install . --build=missing
```

### 编译
```bash
cmake --preset conan-release
cmake --build build/Release
```

### 运行结果

项目编译生成 3 个可执行文件：

#### 1. cpptestdata
```
Today's date is 2026-03-22
Specific time is 2026-03-22 20:34:56
```

#### 2. date1
```
Current time: 2026-03-22 16:20:49.232179
Today's date: 2026-03-22
Specific time: 2026-03-22 12:34:56
Year: 2026, Month: Mar, Day: 22
Time: 12:34:56.000
Date after 30 days: 2026-04-21
Day of the week: Sun
Parsed date: 2023-05-15
```

#### 3. cpptestdata2
```
UTC time: 2026-03-22 16:21:00.030886
```
**注意**：此程序需要时区数据库文件。如果运行时出现 `Timezone database not found` 错误，需要下载时区数据库并配置正确路径。

## 项目说明

这是一个使用 [Howard Hinnant 的 date 库](https://github.com/HowardHinnant/date)（版本 3.0.1）的 C++ 项目，用于处理日期和时间。

- **构建系统**: CMake
- **包管理器**: Conan
- **C++ 标准**: C++17

## Date 库 API 参考

本项目使用的 [date/3.0.1](https://github.com/HowardHinnant/date) 库主要 API：

### 核心类型

| 类型 | 说明 |
|------|------|
| `system_clock::time_point` | 系统时间点 |
| `year_month_day` | 年月日日期类型 |
| `hh_mm_ss<Duration>` | 时分秒时间类型 |
| `weekday` | 星期几类型 |
| `days` / `hours` / `minutes` / `seconds` | 时间间隔类型 |
| `zoned_time` | 带时区的时间 |

### 常用函数

| 函数 | 说明 |
|------|------|
| `system_clock::now()` | 获取当前时间点 |
| `floor<days>(tp)` | 将时间点向下取整到天 |
| `sys_days(ymd)` | 将 year_month_day 转换为时间戳 |
| `year_month_day{tp}` | 从时间点构造日期 |
| `weekday{tp}` | 获取星期几 |
| `date::parse(format, ymd)` | 解析日期字符串 |
| `date::format(format, tp)` | 格式化时间输出 |
| `date::locate_zone(name)` | 加载时区信息 |
| `make_zoned(zone, tp)` | 创建带时区的时间 |

### 头文件

```cpp
#include "date/date.h"    // 基础日期时间功能
#include "date/tz.h"      // 时区功能（需要 tz 数据库）
```
