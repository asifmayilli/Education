# Skiena programming challenge 2-3 solution. 

There is man named ”mabu” for switching on-off light in our University. He switches on-off the lights in a corridor. Every bulb has its own toggle switch. That is, if it is pressed then the bulb turns on. Another press will turn it off. To save power consumption (or may be he is mad or something else) he does a peculiar thing. If in a corridor there is n bulbs, he walks along the corridor back and forth n times and in i-th walk he toggles only the switches whose serial is divisable by i. He does not press any switch when coming back to his initial position. A i-th walk is defined as going down the corridor (while doing the peculiar thing) and coming back again. Now you have to determine what is the final condition of the last bulb. Is it on or off?


#Подход:
1 лампа: 1
2 лампы: 10
3 лампы: 100
4 лампы: 1001
5 ламп: 10010
6 ламп: 100100
7 ламп: 1001000

Видно, что состояние лампы на последнем месте зависит от количества всех ламп, т.е. n.

Если n имеет четное количество делителей, то он четное количество раз нажимается, в результате чего его состояние становится выключенным.
Если n имеет нечетное количество делителей, то он нечетное количество раз нажимается, в результате чего его состояние становится включенным.
