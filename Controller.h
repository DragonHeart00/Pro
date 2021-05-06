//
// Created by Sulaiman Kasas on 06/05/2021.
//

#ifndef PRO_CONTROLLER_H
#define PRO_CONTROLLER_H
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<stdio.h>
#include <stdbool.h>
#include <ctype.h>

int Randomize(int minimumVal,int maximumVal);

void writeToFile(char filename[],char fileMode[2], char data[2]);

int FileCount(char filename[],int Count);

void splitV2(char splits[][50], char value[],char* splitChar);

void readFromFile(char filename[],char fileMode[2],char fields [][4],char Message[10]);

char * readFromFile1(char filename[],char fileMode[2],int Count);

int maximumValue(int values[],int length);

// Reading value from file
void splitV3(char splits[], char value[],char splitChar);

void split(char splits[][50], char value[],char* splitChar);
void newline(int linenumber);
void AfterSpaceChar(char data[],char buffer[]);
bool canSplit(char data[],char splitChar);
#endif //PRO_CONTROLLER_H
