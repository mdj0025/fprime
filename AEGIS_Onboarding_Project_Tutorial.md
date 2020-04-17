# AEGIS Onboarding Project
This document will help introduce/set up the development envoronment for the AEGIS mission.

By the end of this tutorial you should have the following completed:

- Install VirtualBox
- Create Linux Virtual machine in Virtual Box
- Install F Prime on Linux
- Develop a simple software state in F Prime

** Table of Contents**

[TOCM]

[TOC]

## Downloading VirtualBox
To download VirtualBox, first go [here](https://www.virtualbox.org/).
- Download proper VirtualBox for your machine
- Follow instructions on installer to complete VirtualBox installation.

## Setting up Linux VM
To properly configure a Linux machine in VirtualBox perform the following:
1. Follow this [link](http://releases.ubuntu.com/16.04/)
2. Download the 64-bit PC Desktop image
3. Open VirtualBox
4. Press the New button and give your VM a name
5. The other drop boxes should be read
	- Type: Linux
	- Version: Ubuntu
6. Adjust RAM size to 2048 MB, or more if possible. The more you give it here the smoother the VM will run. You can always experiment with it and change it at a later date.
7. Click Create a virtual hard disk now
8. Click VDI (Virtual Disk Image)
9. Click Dynamically allocated (this will not be as fast as fixed allocation but it is the better option for flexibility)
10. Select a size for the hard disk, 10-14 GB perferably
11. Click Create
12. Additional VM Settings (Not needed, but can make your life easier)
	- Right Click newly created VM and press settings
		- Navigate to Advanced tab
		- Both drop boxes should read bidirectional
	- Now go to the System tab
		 - Go to Motherboard section
			- Confirm Floppy is unchecked
		- Go to Processor section
			- Confirm Enable PAE/NX is checked
		- Now go to Display tab
			- Go to Screen section
				- Confirm Enable 3D Acceleration is checked
			- Now go to Storage Tab
				- Click Empty
				- Find the Optical Drive box and click the disk image
				- Click Choose Virtual Optical Disk File
				- Navigate to and click on the Linux .iso file that you downloaded in step 2 above
				- Click Okay
13. From the VirtualBox home screen, double-click on your Linux machine. (This will initiate the installiation of Linux, so it will take a while the first time.)
	- Once the GUI is visible, select your language and click Install Ubuntu
	- Check both boxes: Download Updates and Install third-party..
	- Click Continue
	- Check Erase disk and install Ubuntu. (This is erasing the folder that you allocated to the virtual machine. NOT your hard drive)
	- Click Install Now
	- Click Continue
	- Choose location, language, and insert machine info for username, password.. etc.
	-NOTE: Sometimes VirtualBox will not fill up your whole screen, and you won't be able to see the buttons in the bottom right of the menu. You can either drag the menu over to view the buttons, or you can press the TAB key to navigate through the options on the screen.

## Installing F Prime on Linux
This section will walk you through installing the F Prime flight software framework on your Lunix machine.
1. Go to the terminal inside of your Linux VM
2. Enter this command:
	
	`git clone https://github.com/nasa/fprime`
	
	- You may not have the git client installed so if thats the case, run this
	
	`sudo apt-get install git`
	
3. Navigate to the F Prime directory 
	`cd fprime`
4. Install the Framework
	- First ensure that pip and cheetah are installed.
	`sudo apt-get install pip`
	
	`sudo apt-get install python-cheetah`
	
	`pip install ./Fw/Python`
5. Install the Ground System
	`pip install ./Gds`
	
	- If you run into any errors here, try this and repeate the above command:
	`pip install --upgrade setuptools`
	
6. Install Cmake
	`pip install cmake`
	
7. Navigate to the Ref directory with
	`cd Ref`
	- Now that youre in the Ref directory, type the following commands:
	`fprime-util generate`
	
	`fprime-util build-all`
	
	`fprime util install`
	
8. If the above commands succeeded, you have now successfully installed F Prime on Linux. You can run the ground station GUI with the following command:
	`./scripts/run_ref.sh`
