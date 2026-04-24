*******************************************************************************
** ©2005-2008 Xilinx, Inc. All Rights Reserved.
** Proprietary information of Xilinx, Inc.
*******************************************************************************
**   ____  ____ 
**  /   /\/   / 
** /___/  \  /   Vendor: Xilinx 
** \   \   \/    Version: 1.3 
**  \   \        Filename: readme.txt 
**  /   /        Date Last Modified:  Feb 27, 2008 
** /___/   /\    Date Created: Feb 27, 2008 
** \   \  /  \ 
**  \___\/\___\ 
** 
** Product: Xilinx USB Cables
:: 
** Purpose:
**     Installation package for installating Xilinx USB cables on supported Windows
**     operating system.
**
** Reference: 
**     UG344: Xilinx USB Cable Installation Guide 
**
** Revision History:
**     1.0  - Jan 21, 2008: Initial Xilinx-internal release
**     1.1  - Feb 12, 2008: Changed xusbdrvr.inf DriverVer to 10/01/2007 2.0.0.2
**                          Added 'Disconnect USB Cable' prompt
**     1.2  - Feb 19, 2008: Chanaged wdreg uninstall to silent
**     1.3  - Feb 27, 2008: Added this readme file
**                          Moved disclaimer text to this readme
**                          Initial customer release
**
*******************************************************************************
**
** DISCLAIMER
**          
** THE LICENSED SOFTWARE IS PROVIDED TO LICENSEE “AS-IS” WITHOUT WARRANTY 
** OF ANY KIND AND WITHOUT ANY REPRESENTATION BY XILINX IN REGARD TO THE 
** EFFECTIVENESS OR FITNESS OF THE LICENSED SOFTWARE. LICENSEE ACKNOWLEDGES
** THAT THE LICENSED SOFTWARE IS FOR THE PURPOSE OF XILINX USB CABLE DRIVER
** INSTALLATION AND THAT XILINX DOES NOT WARRANT SUCH CAPABILITIES. LICENSEE 
** AGREES THAT IT SHALL BE SOLELY RESPONSIBLE FOR TESTING SUCH CAPABILITIES 
** TO ENSURE IT MEETS THE REQUIREMENTS DESIRED BY LICENSEE OR ITS CUSTOMERS 
** AND FOR ANY FAILURE TO MEET SUCH REQUIREMENTS.
**
** XILINX MAKES NO REPRESENTATIONS OR WARRANTIES, WHETHER EXPRESS OR IMPLIED, 
** STATUTORY OR OTHERWISE, INCLUDING, WITHOUT LIMITATION, IMPLIED WARRANTIES 
** OF MERCHANTABILITY, NONINFRINGEMENT, OR FITNESS FOR A PARTICULAR PURPOSE. 
** IN NO EVENT WILL XILINX BE LIABLE FOR ANY LOSS OF DATA, LOST PROFITS, OR FOR 
** ANY SPECIAL, INCIDENTAL, CONSEQUENTIAL, OR INDIRECT DAMAGES ARISING FROM 
** YOUR USE OF THIS SOFTWARE. 
**
*******************************************************************************

A step-by-step procedure for using this installer is provided. 

The latest revision of this installer package is available at:

  https://secure.xilinx.com/webreg/clickthrough.do?cid=100840

First-time users should review UG344 "USB Cable Installation Guide" 
prior to running this installer. The latest revision of UG344 is available
at:
 
  http://www.xilinx.com/bvdocs/userguides/ug344.pdf

*******************************************************************************

Running the cable installer:

NOTE: Administrator privileges are requried to perform some of the steps
      described here.

1. Disconnect all Xilinx USB cables from the host computer.

2. Extract the contents of the ZIP file. 

3. The extraction creates a folder named install_xusb. Open this folder and 
   double-click on install_xusb.bat to start the installation. While the installer 
   is running, a DOS terminal window opens and displays installation status messages. 
   Warning messages can be safely ignored.

   Caution! Do not attempt to close this terminal window while the installer is running.

3. (Windows Vista only) While the installer is running, a Windows Security dialog box
   may appear. In this case, check the box next to Always trust software from "Xilinx" 
   and then click [Install].

4. When the installation is complete, connect the Xilinx USB cable to the desired USB
   port.
   
   (Windows XP Professional) Follow the Found New Hardware wizard when it appears.

   (Windows Vista or Windows Professional 2000) Installation is complete and no other
   actions are required.

   If the STATUS indicator on the cable illuminates, then the driver installation completed
   successfully.

