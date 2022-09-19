@echo off

set fileName=%1

echo Build started
g++ %fileName% -o currentFile && ( 
    echo Build completed
    echo Running...
    currentFile.exe
) || (
    echo Build failed
)

