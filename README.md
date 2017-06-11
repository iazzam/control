# Control System

# Waterloop pod Control System

**Table of Contents**

- [About](#about)
- [How to Contribute](#how-to-contribute)
- [How to Code in CLion](#how-to-code-in-clion)
- [Control](#main-Control)
- [Levitation](#levitation)

## About
This repository contains code for the pod subsystems and the main control which will bring all the systems together.
As new subsystems are added, more code will be added to this repo. Anyone working on controls, work in this repository.

## How to Contribute
Anyone who is willing to work on this can clone this repo and then work on sub branch for your part.
Once finished with your part, you can make a pull request and I will review the code and then we can
merge it to the main branch. When working on a new system, do following:

* Make a separate folder insider src folder for your particular system. All the code for that system goes in that folder.
* Create a README file for your particular sensor and document as well as you can.
* At the end add a brief description about your sensor into the main README file in the repo. If you need help with
  how to do this, look at sensors repo.
* For testing you can create your main.cpp file but make sure there are not multiple main files. In order to avoid this,
  add your main file to `.gitignore`. This way everyone can have their separate main files.

## How to Code in CLion
This project is created in Clion using a library called `platformio`. In order for you to use this, follow the following steps:
* Install Clion. You can get one for free using student account.
* Install Platformio based on your machine. Click on [`install`](http://docs.platformio.org/en/latest/installation.html)
  and follow the instructions.
* Go to the project folder and using system terminal type `platformio init --ide clion --board megaatmega2560`. This `board` option
  can be different based on what board you are using. Click on [`available boards`](http://docs.platformio.org/en/latest/platforms/atmelavr.html)
  to learn more.
* Every time you add a library or copy paste some files or change the structure, you have to follow the above
  step.
* Import this project in CLion and you are good to go.
* For further help regarding this let Deep Dhillon know.
  
## Main Control
This directory will contain the code that will bind all the systems together. This will also contain project wide files
and can be accessed by other subsystems. For further documentation read [`Control`](https://github.com/teamwaterloop/control/tree/master/src/Control/CONTROL_README.md) 


## Levitation
This library contains code for the functionality of Levitation on the pod. For further documentation read [`Levitation`](https://github.com/teamwaterloop/control/tree/master/src/Lev/LEV_README.md)

