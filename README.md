# Measure-unknown-resistor-using-Arduino
In this tutorial i use a voltage divider circuit and Arduino Uno to measure an unkwown resistance. The output of voltage divider is connected to analog port A0, so the input goes from 0 to 1023. 

With function analogRead() the program reads the analog values and stores them to variable sensorValue. The next step is to convert them to voltage. Then, function resistance() uses voltage as input and returns the calculated resistance.

Finally the resistance is displayed to lcd 16x2
