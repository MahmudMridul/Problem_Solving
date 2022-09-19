@echo off
echo Build started
g++ main.cpp -o main && ( 
    echo Build completed
    echo Running...
    main.exe
    g++ checkOutput.cpp -o checkOutput
    checkOutput.exe
    for /f "tokens=* delims=" %%x in (testresult.txt) do echo %%x
) || (
    echo Build failed
)

