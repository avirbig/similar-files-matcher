Table of Contents
Overview ............................................................................................................................................................. 2
Task #1: Multithreaded matching ...................................................................................................................... 3

Overview
The following document lists questions to be asked ******* Employee candidates.
Important notes:
 Use coherent names in code.
 Make sure code compiles.
 For each class implement a test application which runs it.
 Deliver fully functioning application and the source code.
 Keep OOP in mind when designing the code.
 Keep performance in mind when designing the code.
 Keep boundary cases in mind when designing the code.
 Always validate user input.
 Handle exceptions.
 Use coherent notifications and readouts.
 Use any of the following programming languages: C# / C++ / Python
 All applications should be repeatable (Given the same input, the application should behave exactly
the same always, and produce the same output).
 Keep in mind input may be big (files contain a lot of data, or there could be a large quantity of files)

Task #1: Multithreaded matching
Scenario:
We have 2 directories which contain CSV files.
We need to be able to determine which CSV files in the 1st

directory are similar to CSV files in the 2nd

directory.
Definitions:
 Two directories, each containing CSV files.
 Each CSV files contains a sorted (Ascending) set of integer numbers (1 row only).
 A CSV file is considered “similar” to another CSV file if both files contain at least X of the same
numbers.
Desired function:
We want to copy all CSV files from directory “A”, which are similar to at least 1 csv file in directory “B”, to
directory “C”
Instruction:
Write a class which handles, in multi-threading, the loading, “similarity” testing and copying of files
The class should have a method which returns VOID and receives 3 strings (A,B & C, each a directory path)
and an int (X, minimal amount of equal numbers).
This method should also write a “scores.txt” file in directory C which contain a line for every copied file
from directory A. the line should like: “<name of file> <tab> <maximum intersection score>
