@echo off

rem //
rem // This is a MS Visual C++ build script for examples from
rem // "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
rem //


rem Usage:
rem     build        - Build all examples using the most recent MS VC++ compiler
rem     build clean  - Clean all examples
rem     build test   - Test all built examples
rem     build [ msvc90 | msvc80 | msvc71 ] - Build with a given version of MS VC++

set current_dir=%cd%
set divider=----------------------------------------------

echo %divider% & cd %current_dir%\Chapter02 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter03 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter04 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter05 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter06 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter07 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter08 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter09 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter10 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter11 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter12 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter13 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter14 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter15 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter16 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter17 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter18 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter19 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter20 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter21 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter22 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter23 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter24 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter25 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter26 & call build.bat %* 
echo %divider% & cd %current_dir%\Chapter27 & call build.bat %* 

