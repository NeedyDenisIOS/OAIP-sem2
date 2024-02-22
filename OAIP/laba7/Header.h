#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct STACK {
	string data;
	STACK* head;
	STACK* next;
};


void AddEl(string elem, STACK* stack);
string TakeFromStack(STACK* stack);
void PrintStack(STACK* stack);
void ToFile(STACK* stack);
void FromFile(STACK* stack);
int Same(STACK* stack);
void clear(STACK* stack);