@echo off
echo Build started
g++ main.cpp -o main && ( 
    echo Build completed
    echo running...
    main.exe
) || (
    echo Build failed
)

