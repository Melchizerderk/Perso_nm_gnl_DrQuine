#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int ac, char **av){
ac+=0;char buf[10];char cmd[255];char ex[10];
int i = 5;
if (i >= 0){
snprintf(buf, sizeof(buf), "Sully_%i.c", i);i--;
strcpy(cmd, "gcc -o ");strncat(cmd, buf, 7);strcat(cmd, " ");strcat(cmd, buf);strcpy(ex, "./");strncat(ex, buf, 7);
if(strcmp(av[0], "./a.out") != 0){i++;}
FILE *fd = fopen(buf, "w+");char a[]="#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#include <unistd.h>%cint main(int ac, char **av){%cac+=0;char buf[10];char cmd[255];char ex[10];%cint i = %i;%cif (i >= 0){%csnprintf(buf, sizeof(buf), %cSully_%ci.c%c, i);i--;%cstrcpy(cmd, %cgcc -o %c);strncat(cmd, buf, 7);strcat(cmd, %c %c);strcat(cmd, buf);strcpy(ex, %c./%c);strncat(ex, buf, 7);%cif(strcmp(av[0], %c./a.out%c) != 0){i++;}%cFILE *fd = fopen(buf, %cw+%c);char a[]=%c%s%c;fprintf(fd,a,10,10,10,10,10,10,i,10,10,34,37,34,10,34,34,34,34,34,34,10,34,34,10,34,34,34,a,34,10);fclose(fd);system(cmd);system(ex);}}%c";fprintf(fd,a,10,10,10,10,10,10,i,10,10,34,37,34,10,34,34,34,34,34,34,10,34,34,10,34,34,34,a,34,10);fclose(fd);system(cmd);system(ex);}}
