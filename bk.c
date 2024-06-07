#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getTitleFromAdd(const char* command, char* out_title)
{
    char *temp1 = strstr(command," [");
    char *temp2 = strstr(temp1,"] [");
    size_t title_length = temp2 - (temp1 + 2);
    char temp[title_length + 1];
    strncpy(temp, temp1 + 2, title_length);
    temp[title_length] = '\0';
    printf("%s\n",temp);
    strcpy(out_title, temp);
}

char tempn[200];
char raw_title[200];
char raw_description[200];
char raw_time[200];
char command[200] = "Add [Course Intro to Programming] [Room 701-H6] [07:00|01/10/2023-12:00|01/10/2023]";

int main()
{
    getTitleFromAdd(command, raw_title);
    printf("%s\n", raw_title);
    cout << typeid(raw_title).name();
    return 0;
}