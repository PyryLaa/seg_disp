Program to control a 5011AS 7-segment CC display with STM32F407 Discovery board, using the SN74HC595 shift register.
Connection between the shift register and display is made so the display's A anode is connected to the register's Qa output, B anode to Qb output etc.
The decimal point is connected to Qh.

TODO:
1. Implement a more accurate delay by using the hw clock and it's overflow reg
2. Add a button to control the decimal point
3. idk
