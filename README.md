Lab7
====

Analog to Digital Converting

Required Functionality: Use the ADC subsystem to light LEDs based on the presence of a wall. The presence of a wall next to the left sensor should light LED1 on your Launchpad board. The presence of a wall next to the right sensor should light LED2 on your Launchpad board. Demonstrate that the LEDs do not light until they come into close proximity with a wall.
      
--Required Functionality checked off by Dr York

B Functionality: Create a standalone library for your ATD code and release it on Github. This should be separate from your lab code. It should have a thoughtful interface and README, capable of being reused in the robot maze laboratory.
      
--Committed at 2311 7 December 2014: in the header file ATD.h, and implemented in ATC.c, an example of the library being
used is in the main.c file.

A Functionality: Since each robot's sensors are a little bit different, you need to fully characterize the sensor for your robot. Create a table and graphical plot that shows the ATD values for a variety of distances from a maze wall. This table/graph must be generated for each IR sensor. Use these values to determine how the IR sensors work so you can properly use them to solve the maze.
      
--Committed at 2311 7 December 2014: in the "Lab7ExcelFile.xlsx"


#Required and B Functionality

For required functionaltiy, the goal was to get the IR sensors to function properly and to light up LED lights based on whether or not a piece of paper is in front of the sensor.

For the left sensor turn the left LED on, for the right sensor turn the right LED on, for the middle sensor turn both of the LEDs on. This is mainly to make sure that the sensors are operating correctly and whether or not we did the analog to digital conversion correctly.

When I accomplished required functionality to make the sensors operate correctly and turn on the LED lights, I finished B functionality at the same time.

First I started with the header file to make the methods I would use to check the distance from an object, or how hight he voltage level was for each sensor. The three methods are below:

```
	unsigned int readLeftSensor();
	unsigned int readRightSensor();
	unsigned int readMiddleSensor();
```

The methods return an unsigned int that is the voltage level converted to an `int` to determine whether or not an object was in front of the sensor.
