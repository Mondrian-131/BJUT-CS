:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Copyright (c) 2008 Xilinx, Inc. All rights reserved.
:: Xilinx, Inc.
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Last Update: February 27, 2008
::
:: Driver install script for Xilinx USB Cables.
::
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
@echo off

:: Prompt user
echo.
echo. ** Please disconnect all Xilinx USB cables before proceeding.
echo. ** Press [Enter] to continue with the installation...
echo.
set /p SELECT_=
set SELECT_=

:: Check for processor type. Also, check for the WOW64 emulator just in case.

if "%PROCESSOR_ARCHITECTURE%" == "x86" (
if "%PROCESSOR_ARCHITEW6432%" == "" (

echo. ** 32-bit Processor Detected
goto X86

) else (

echo. ** 64-bit Processor Detected
goto X64

)

)

) else (

echo. ** 64-bit Processor Detected
goto X64

)

:::::::::::::::::::::::::::::::
:X86
:::::::::::::::::::::::::::::::
cd nt
goto RUN_WDREG

:::::::::::::::::::::::::::::::
:X64
:::::::::::::::::::::::::::::::
cd nt64
goto RUN_WDREG

:::::::::::::::::::::::::::::::
:RUN_WDREG
:::::::::::::::::::::::::::::::

wdreg -inf uninstall.inf -silent -log uninstall.log uninstall
wdreg -inf xusbdrvr.inf -log install_xusb.log install

echo.
echo. ** Installation Completed
echo. ** Press [ENTER] to close the window...
set /p SELECT_=
set SELECT_=

goto DONE

:::::::::::::::::::::::::::::::
:DONE
:::::::::::::::::::::::::::::::
cd ..
