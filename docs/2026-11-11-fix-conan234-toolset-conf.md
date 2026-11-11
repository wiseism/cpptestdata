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
