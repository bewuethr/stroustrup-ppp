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

if "%1" == "clean" del *.obj *.exe build.log *.out && goto END
if "%1" == "test"  goto TEST
if "%1" == "msvc90" shift &&   call :SET_VS_VARS msvc90 && goto PROCEED
if "%1" == "msvc80" shift &&   call :SET_VS_VARS msvc80 && goto PROCEED
if "%1" == "msvc71" shift &&   call :SET_VS_VARS msvc71 && goto PROCEED

rem Use the highest version available
if not "%VS90COMNTOOLS%" == "" call :SET_VS_VARS msvc90 && goto PROCEED
if not "%VS80COMNTOOLS%" == "" call :SET_VS_VARS msvc80 && goto PROCEED
if not "%VS71COMNTOOLS%" == "" call :SET_VS_VARS msvc71 && goto PROCEED

echo ERROR: Unable to find installation of MS Visual C++ on this computer
goto END

:SET_VS_VARS

if not "%VSVARSCOMPLETE%"=="" goto END
if "%1" == "msvc90" call "%VS90COMNTOOLS%vsvars32.bat" > build.log && echo Using MS Visual C++ 9.0
if "%1" == "msvc80" call "%VS80COMNTOOLS%vsvars32.bat" > build.log && echo Using MS Visual C++ 8.0
if "%1" == "msvc71" call "%VS71COMNTOOLS%vsvars32.bat" > build.log && echo Using MS Visual C++ 7.1
set VSVARSCOMPLETE=1
goto END

:PROCEED

set CLFLAGS=/W4 /EHsc /O2 /Za

if "%1" == "" goto BUILD_ALL

:BUILD_ARG

rem Iterate through all the arguments that were passed and build them
for %%i in (%1) do call :SUB_BUILD_FILE "%%i"
shift
if "%1" == "" goto END
goto BUILD_ARG

:BUILD_ALL

rem User didn't provide any arguments, assume all .cpp files in the current folder
for %%i in (*.cpp *.cxx *.c) do call :SUB_BUILD_FILE "%%i"
echo Build log has been saved to build.log
goto END

:TEST

for %%i in (*.exe) do call :SUB_TEST_FILE "%%i"
goto END

:SUB_TEST_FILE

set execution=%~n1
set execution=%execution:~-5%
if "%execution%"=="crash" goto END
echo.
echo ======================================== [ %1 ]
if not exist %~n1.*in %1
if     exist %~n1.*in for %%i in (%~n1.*in) do echo. && echo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ { "%%i" } && type "%%i" && echo. && echo ---------------------------------------- && %1 < "%%i"
goto END

:SUB_BUILD_FILE

rem Subroutine that builds a particular file
echo Building %1
echo ======================================== [ %1 ] >> build.log
set requirelink=%~n1
set requirelink=%requirelink:~-7%
if not "%requirelink%"=="no-link" cl.exe    %CLFLAGS% %1 /link >> build.log 2>&1 && if ERRORLEVEL 1 echo Error(s): %ERRORLEVEL%
if     "%requirelink%"=="no-link" cl.exe /c %CLFLAGS% %1       >> build.log 2>&1 && if ERRORLEVEL 1 echo Error(s): %ERRORLEVEL%
if exist %~n1.obj del %~n1.obj
if exist %~n1.exe.manifest del %~n1.exe.manifest

:END
     