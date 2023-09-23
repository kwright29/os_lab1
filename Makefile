# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author> Khloe Wright
list: list.c main.c 
	gcc -o list list.c main.c