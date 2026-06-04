@echo off
REM build.bat —— 一键编译走迷宫
REM 用法：双击此文件，或在命令行 cd 到本目录后输入 build

setlocal
set GCC=D:\mingw64\bin\gcc.exe

if not exist "%GCC%" (
    echo [ERR] %GCC% 不存在，请确认 MinGW 在 D:\mingw64 下
    pause
    exit /b 1
)

echo 正在编译...
"%GCC%" -Wall -O2 *.c -o maze.exe

if exist maze.exe (
    echo [OK] maze.exe 编译完成
    echo.
    echo 输入 maze 或双击 maze.exe 运行
) else (
    echo [FAIL] 编译失败
)

pause
