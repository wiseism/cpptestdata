# 修复 conan2 win：msvc_toolset_version conf 已被 conan 2.34 移除

## 失败信息
- Run 42443847623（conan2 win 2022）`conan install`：
  `ERROR: [conf] 'tools.microsoft:msvc_toolset_version' does not exist in configuration list`
  → CMakePresets 未生成 → 后续 preset/目录步骤全部失败。

## 原因分析
- workflow 往 default profile 追加 `[conf] tools.microsoft:msvc_toolset_version=14.44`，
  但新版 conan（2.34.0）已移除该配置项，未知 conf 直接报错。
- `compiler.version=194` 已自动映射 toolset v143/14.4X，无需再显式指定。

## 修复内容
- `.github/workflows/conan2_win.yml`：删除 profile 追加 `[conf]` 与
  `tools.microsoft:msvc_toolset_version=14.44` 的两行。

## 验证记录
| Run | 结果 |
|---|---|
| 42443847623 (修复前) | failure — 未知 conf |
| 待 re-run | 待填 |

| 42443847578 (conan2(ubuntu), conan 升级修复) | ✅ success |

## 补记: conan 2.34 preset 命名
- CMakeToolchain 仅生成 conan-default（不再有 conan-debug），四个 workflow 统一改用 conan-default preset。

## 补记: conan 2.34 布局变化
- cmake_layout 构建目录变为 build（非 build/Debug），四个 workflow --build 路径修正。

## 补记: preset 命名不稳定
- 不同 conan 版本只生成 conan-default 或 conan-debug 之一，改用 conan_toolchain.cmake 直接 configure（版本无关）。
