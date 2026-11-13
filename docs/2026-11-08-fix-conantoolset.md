# 修复记录：conan CI 依赖解析与 toolset 失败（2026-11-08）

## 失败信息
- 仓库：wiseism/cpptestdata
- Workflows：conan2（ubuntu）/ conan2 win 2022 / conan2 macos / CMake on a single platform
- 失败 run：
  - [41938320680](https://github.com/wiseism/cpptestdata/actions/runs/41938320680)（ubuntu）
  - [41938320684](https://github.com/wiseism/cpptestdata/actions/runs/41938320684)（win）
  - [41938320689](https://github.com/wiseism/cpptestdata/actions/runs/41938320689)（single platform）
  - [42182128348 类似的历史 mac 失败，另一 workflow 先行修复]

## 错误日志摘录
```
# ubuntu (41938320680)
ERROR: Invalid setting '15' is not a valid 'settings.compiler.version' value.
Possible values are [... '13.2']
# win (41938320684)
conanvcvars.bat: Activating environment ... vcvars_ver=14.3
[ERROR:vcvars.bat] Toolset directory for version '14.3' was not found.
ERROR: nasm/2.16.01: Error in build() method, line 84
# single platform (41938320689)
CMake Error at CMakeLists.txt:5 (find_package):
  Could not find a package configuration file provided by "date" ...
```

## 原因分析
1. ubuntu：`pip3 install conan==2.0.16` 的 settings 列表止步 GCC 13，
   ubuntu-26.04 runner 默认 GCC 15 → `compiler.version=15` 无效。
2. win：windows-latest 已迁移 VS2026 镜像，只带 MSVC 14.44 (v143/17.14) 工具集，
   conan 依据 settings 定到 14.3 → 目录不存在 → 依赖（nasm/libjpeg-turbo）构建失败。
3. single platform：CMakeLists `find_package(date CONFIG REQUIRED)` 需要 conan
   提供 date 包，workflow 却直接 `cmake -B build`（未安装依赖）。

## 修复内容
1. `conan2_ubuntu.yml`：`pip3 install -U conan`（最新版含 GCC15+ settings）。
2. `conan2_win.yml`：conan 升级 + profile 追加
   `[conf] tools.microsoft:msvc_toolset_version=14.44`。
3. `cmake-single-platform.yml`：整体改为 conan 流程
   （install conan → `conan install` → `cmake --preset conan-debug` → build/Debug）。
4. macos workflow（brew conan 为最新版）保留原逻辑。

## 验证
| run id | 结果 |
| --- | --- |
| 43223185762 (win) / 43223185669 (macos) | ✅ success |

| 42443847578 (conan2(ubuntu)) | ✅ success |

| 42443847569 (conan2(ubuntu)) | ✅ success |

| 42443847548 (conan2 macos) | ✅ success |

| 42443847578 (CMake single platform conan 流程) | ✅ success |
