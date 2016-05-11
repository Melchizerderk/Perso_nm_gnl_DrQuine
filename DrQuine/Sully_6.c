#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int ac, char **av){
ac+=0;char buf[10];char cmd[255];
int i = 5;
if (i >= 0){
snprintf(buf, sizeof(buf), "Sully_%i.c", i);i--;
strcpy(cmd, "/usr/bin/clang -Wall -Werror -Wextra ");strcat(cmd, buf);
FILE *fd = fopen(buf, "w+");char a[]="#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#include <unistd.h>%cint main(int ac, char **av){%cac+=0;char buf[10];char cmd[255];%cint i = %i;%cif (i >= 0){%csnprintf(buf, sizeof(buf), %cSully_%ci.c%c, i);i--;%cstrcpy(cmd, %c/usr/bin/clang -Wall -Werror -Wextra %c);strcat(cmd, buf);%cFILE *fd = fopen(buf, %cw+%c);char a[]=%c%s%c;fprintf(fd,a,10,10,10,10,10,10,i,10,10,34,37,34,10,34,34,10,34,34,34,a,34,34,34,10);}system(cmd);system(%c./a.out%c);}%c";fprintf(fd,a,10,10,10,10,10,10,i,10,10,34,37,34,10,34,34,10,34,34,34,a,34,34,34,10);}system(cmd);system("./a.out");}
