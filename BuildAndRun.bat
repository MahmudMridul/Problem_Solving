@echo off
echo Build started
g++ main.cpp -o main && ( 
    echo Build completed
    echo Running...
    main.exe
    for /f "tokens=* delims=" %%x in (output.txt) do echo %%x
    echo Done
) || (
    echo Build failed
)

