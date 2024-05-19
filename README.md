# LinkTech-Native-Api
自用轻量原生接口，用于 Electron / Nwjs 项目调用 Windows API

本人不会 cpp，**代码由 AI 生成**，仅供分享，轻喷

`Compiled` 目录中程序可直接下载使用

# activeWindow
- 功能：获取当前活动窗口进程路径
- 用法：`activeWindow.exe`

# keySimulator
- 功能：模拟键盘按键点击
- 用法：`keySimulator.exe alt tab`

  键位名需要小写，支持 `ctrl shift alt a-z 0-9 f1-f12 tab backspace up/down/left/right volumeup/down` 按键模拟

  在启动参数中各键位用空格分开，若按键不支持会在控制台输出，执行成功不会有输出
