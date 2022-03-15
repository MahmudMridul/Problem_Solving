echo off
setlocal
set v=1
echo %v%
set /a v=v+1
echo %v%
for /l %%a in (expected.txt) do echo %%a
endlocal