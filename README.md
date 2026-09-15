# CS4080--HW1
CS 4080 - Homework 1
This repository contains my work for the CS 4080 homework assignment.

Java

For the Java portion of the assignment, I created and ran a basic "Hello, World!" program.

C

For the C portion, I created a "Hello, World!" program and implemented a doubly linked list using pointers. The list stores heap-allocated strings and includes functions to insert, find, and delete items.

Open Source Language Implementation

For the open-source language implementation exercise, I chose CPython, the open-source implementation of Python. I explored the CPython source code to locate the scanner and parser.

CPython uses a PEG (Parsing Expression Grammar) parser. The grammar is primarily defined in Grammar/python.gram, and parser-related code can be found in the Parser directory. The parser is generated using Python's PEG parser generator rather than traditional tools such as Lex and Yacc. The tokenization logic is implemented separately in CPython's source code.

Files
HelloWorld.java — Java Hello World program
main(9).c — C Hello World program and doubly linked list implementation
PDF document — Written responses for the homework exercises
