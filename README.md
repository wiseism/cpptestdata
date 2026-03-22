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
