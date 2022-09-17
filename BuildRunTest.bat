@echo off
echo Build started
g++ main.cpp -o main && ( 
    echo Build completed
    echo Running...
    main.exe
    echo =====OUTPUT=====
    for /f "tokens=* delims=" %%x in (output.txt) do echo %%x
    echo ================
    g++ checkOutput.cpp -o checkOutput
    checkOutput.exe
    echo ======TEST======
    for /f "tokens=* delims=" %%x in (testresult.txt) do echo %%x
    echo ================
) || (
    echo Build failed
)

