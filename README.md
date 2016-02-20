# Data-sets-calculator


The user of program will use it to do some elementary calculations for
an unknown number of simple data sets (the number will be determined at
runtime, based on user input, but it is unknown at coding/compile time). The
data in each set consists of a number of floating point values, but the number of
values to be entered for each data set will be input by the user, so we do not
know in advance (i.e., at coding/compile time) how many values there will be in
each data set. Therefore, we cannot use a conventional array in C to store these
numbers, because a conventional array must have a fixed size at compile time,
which cannot be changed after the program begins running.


First, prompt the user to enter the number of data sets. The user
will enter an integer greater than 1 to indicate the number of data sets.

Then prompt the user to enter the number of floating point values in
the first data set (which the user will enter as an integer greater than 0), followed
by the floating point values themselves on the same line (newline will follow the last
floating point value on the line). Then you should prompt the user to enter the
number of values in the next data set (again, an integer > 0), followed by the
floating point values. You should repeat this process until all of the numeric data has
been input by the user. You can assume that the user will enter the input in this
format, so you do not need to check to make sure that the format of the input
meets this description, and you do not need to reject input which is not properly
formatted. You can also assume that the user’s input is correct, that is, that the
number of data sets entered is actually the number of sets in the input, and that the
integer entered first to indicate the number of values for each data set is actually
the number of floating point values which follows on the same input line.

After getting the values in each data set, your program should repeatedly
prompt the user to select one of the data sets by number, with the following
prompt:

Enter the number of the data set on which you wish to do calculations:
The user will enter an integer value, followed by newline, in response to this prompt
(the user will enter 1 for the first data set, 2 for the second, etc.), and based on the
value entered, your program must be able to access the values in the appropriate
data set in the dynamically allocated storage which you have created, and then do
what is described immediately below.


The program should repeatedly prompt the user to choose one of the
following options for a calculation based on the data set chosen by the user (ask
the user to enter one of the seven numbers, followed by enter):


1. Find the minimum value.
2. Find the maximum value.
3. Calculate the sum of all the values.
4. Calculate the average of all the values.
5. Sort the values in ascending order (i.e., from smallest to largest).
6. Select a different data set.
7. Exit the program.


After the user selects one of these options, your program should do the
necessary calculation or rearrangement of the data based on the user's choice
(or terminate the program), and output the result with an appropriate message,The maximum value in the data set is: 569.45
The results for options 1, 2, 3, and 4 should be printed out as floating point values,
and the result for option 5 should be to output the values in the data set in order,
with any two values separated by a tab (\t). All floating point output should be
printed to two digits of precision.
