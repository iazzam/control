[![Build Status](https://travis-ci.org/teamwaterloop/control.svg?branch=master)](https://travis-ci.org/teamwaterloop/control)

# Waterloop pod Control System

**Table of Contents**

- [About](#about)
- [How to Contribute](#how-to-contribute)
- [How to Code using platformIo](#how-to-code-using-platformio)
- [Communication Pipeline](#communication-pipeline)

---

## About
This repository contains code for the pod subsystems and the main control which will bring all the systems together.
It also integrates sensors from Sensors repo. Anyone working on controls, work in this repository.

---

## How to Contribute
Anyone who is willing to work on this can clone this repo and then work on sub branch for your part.
Once finished with your part, you can make a pull request and after review the code we can
merge it to the main branch. When working on a new system, do following:

**What to Do**
* Make a separate folder insider src folder for your particular system. All the code for that system goes in that folder.
* If you need any library, add it inside lib folder.
* For testing you can create your main.cpp file but make sure there are not multiple main files. In order to avoid this,
  add your main file to `.gitignore`. This way everyone can have their separate main files.
 

---

## How to Code using platformIo
This project is created using a library called `platformio`. In order for you to use this, follow the following steps:

* Install Platformio based on your machine. Click on [**``install``**](http://docs.platformio.org/en/latest/installation.html)
  and follow the instructions.
* For writing code, you have two options:
    
**Use PlatformIo IDE (Atom)**
* For those who wants to use Atom and integrate platformIo to it, follow this [**``link``**](http://docs.platformio.org/en/latest/ide/atom.html).

**Use Clion IDE**
* For those who wants to use Clion IDE, follow this [**``link``**](http://docs.platformio.org/en/latest/ide/clion.html).

---

## Communication Pipeline

We will be communication with Raspberry Pi back and forth using Serial. Below is the information about it:

* We will have our data in JSON format therefore use JsonHandler library to encode and decode data
* To send data to Raspberry Pi, we will write it to Serial. To work with Serial, use WSerial library

Information about each command and sensor output is listed [**``here``**](http://htmlpreview.github.io/?https://github.com/teamwaterloop/communication-system/blob/master/communication_format.html).