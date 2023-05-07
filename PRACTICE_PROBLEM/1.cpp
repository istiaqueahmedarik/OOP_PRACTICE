/*
    1. FileHandler Class - Problem on Copy Constructor.
Our task is to design a class that handles the file opening and closing for us.
a. Find and print the number of vowels in a given text file.
b. Print the content of the text file.
Write down a class named FileHandler. It will have the following skeleton.
class FileHandler {
FILE * fp;
char name[100];
public:
};
The constructor will receive the filename and initialize the file pointer as well as
the name (of the file). The destructor will close the file.
Sample Code for opening a file:
FILE * fp = fopen(“input.txt”, “r”);
Sample Code for closing a file:
fclose(fp);
The class will have two friend functions.
a. void printContent(FileHandler fh)
Prints the content of the file pointed by the filepointer in fh.
b. void printVowelCount(FileHandler fh)
Prints the total number of vowels in the file.
Sample code for reading from a file:
char line[100]; //Let, each line-length <100
while(!feof(fp)) {
fgets(line, 100, fp); //read one line
printf("%s", line); //print the line
}
*/

#include <bits/stdc++.h>
using namespace std;

class FileHandler
{
    FILE *fp;
    char name[100];

public:
    FileHandler(char *filename)
    {
        fp = fopen(filename, "r");
        strcpy(name, filename);
    }
    FileHandler(const FileHandler &fh)
    {
        fp = fopen(fh.name, "r");
        strcpy(name, fh.name);
    }
    ~FileHandler()
    {
        fclose(fp);
    }
    friend void printContent(FileHandler fh);
    friend void printVowelCount(FileHandler fh);
};

void printContent(FileHandler fh)
{
    char line[100];
    while (!feof(fh.fp))
    {
        fgets(line, 100, fh.fp);
        printf("%s", line);
    }
}

void printVowelCount(FileHandler fh)
{
    char line[100];
    int count = 0;
    while (!feof(fh.fp))
    {
        fgets(line, 100, fh.fp);
        for (int i = 0; line[i]; i++)
        {
            if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u')
                count++;
        }
    }
    printf("Total number of vowels: %d\n", count);
}

int main()
{
    FileHandler fh("input.txt");
    printContent(fh);
    printVowelCount(fh);
    return 0;
}