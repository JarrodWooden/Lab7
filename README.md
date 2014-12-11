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

To complete the analog to digital conversion the code below was used:

```
		ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
		ADC10CTL1 = INCH_2;                       // input A2 (left sensor)
		ADC10AE0 |= BIT2;                         // PA.1 ADC option select
		ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK

		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

		while(ADC10CTL1 & ADC10BUSY);

		return ADC10MEM;
```

The only change between methods is what in channel to read based on the pin output used to connect the sensor readings to the MSP430. For example, INCH_2 and BIT2 to read the left sensor. The important part of the code is the while statement that essentially "waits" for the analog to digital conversion. Using a while statement to wait for the conversion instead of an interrupt that will wait for the completion of the conversion will alow for the user of the library to use other interrupts in their main program and not have to worry about interrupt priorities while they are coding.

#A Functionality

For A Functionality, the students needed to measure the voltages the sensor reads when it is certain distances from the wall.

The voltage reading can be converted into a hex reading by dividing the output voltage by 5V divided by 2^10 levels (to get volts per level) and then the output is what level that voltage reading is on in decimal; THEN, the decimal level can be converted into hex in excel and can be used in the program for comparing the ADC to whatever voltage level in hex to determine how far away from a wall the sensor is.

*Note: the voltage were read using a multimeter plugged up to the output of each sensor.

The excel file is posted under lab seven as well.

#Have a great Air Force Day!!!
