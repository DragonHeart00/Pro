//
// Created by Sulaiman Kasas on 06/05/2021.
//

#include "Controller.h"

int Randomize(int minimumVal,int maximumVal){

    int value=rand()%(maximumVal-minimumVal+1)+minimumVal;
    return value ;

}


void writeToFile(char filename[],char fileMode[2],char data[3])
{
    FILE * stream;
    stream = fopen(filename, fileMode);//a
    fwrite(&data, sizeof(&data), strlen(data), stream);
    fclose(stream);
}

void newline(int linenumber){

    for (int i=0;i<linenumber;i++)
    {

        printf("\n");
    }
}

int FileCount(char filename[],int Count)
{
    FILE * stream;
    int fileCoun=0;
    char buffer[4];
    stream = fopen(filename, "r");//r
    while(fread(buffer, sizeof(char),3, stream)>0)
    {
        fileCoun++;
    }
    fclose(stream);
    return fileCoun;
}


int maximumValue(int values[],int length)
{
    int maximumV=0;

    for(int j=0;j<length;j++)
    {
        if(values[j]>maximumV)
        {
            maximumV=values[j];
        }
    }
    return maximumV;
}


void readFromFile(char filename[],char fileMode[2],char fields [][4],char Message[10])
{
    FILE * stream;

    char buffer[4];


    stream = fopen(filename,fileMode);
    if(stream!=NULL)
    {


        int readCount=0;



        while(fread(buffer,sizeof(char),3, stream)>0)
        {
            strcpy(fields[readCount],buffer);

            readCount++;

        }

        strcpy(Message,"OK");
    }
    {


    }
//fields=newFields;
    fclose(stream);

}
char * readFromFile1(char filename[],char fileMode[2],int Count){
    FILE * stream;
    char buffer[2];




    stream = fopen(filename, fileMode);
    fread(buffer, sizeof(char), Count, stream);
    char* finalSTring=buffer;
    return finalSTring;
}
void split(char splits[][50], char value[],char* splitChar)
{
    int splitsCount=0;

    char *buffer;

    buffer=strtok(value,splitChar);

    while(buffer!=NULL)
    {
        strcpy(splits[splitsCount],buffer);
        buffer=strtok(NULL,splitChar);

        splitsCount++;
    }

}
void splitV3(char splits[], char value[],char splitChar){
    int inter=0;


    while(value[inter]==splitChar && value[inter])
    {
        inter++;
        strcpy(splits,value+inter);
    }

}
void splitV2(char splits[][50], char value[],char* splitChar)
{
    int splitsCount=0;

    char *b1;
    char  *b2;
    char *b3;
    strcpy(splits[splitsCount],value);
    b2=strtok_r(value,splitChar,&b1);

    while(b2!=NULL)
    {
        strcpy(splits[splitsCount],b2);
        b2=strtok_r(NULL,splitChar,&b1);

        splitsCount++;
    }

}
bool canSplit(char data[],char splitChar){


    int strLength=strlen(data);
    bool cansPlitMe=false;
    char *pos=strchr(data,splitChar);
    if (pos!=NULL)
    {
        cansPlitMe=true;
    }
    for(int i=0;data[i]!='\0';i++)
    {
        if(data[i]==splitChar)
        {
            cansPlitMe=true;
        }
    }
    return cansPlitMe;
}
void AfterSpaceChar(char data[],char buffer[])

{

    int len=strlen(data);

    int indexMe=0;
    for (int i=0;i<len;i++)
    {
        if(data[i]==' ')
            indexMe=i;
    }

    memcpy(buffer,&data[indexMe+1],len-(indexMe+1));
    buffer[len-(indexMe+1)]='\0';
}

