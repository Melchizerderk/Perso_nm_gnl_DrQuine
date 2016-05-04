#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
char buf[10];char cmd[255];char cname[9];
int i = 4;
if (i >= 0){
snprintf(cname, sizeof(cname), "Sully_%i ");snprintf(buf, sizeof(buf), "Sully_%i.c", i);i--;
strcpy(cmd, "/usr/bin/clang -Wall -Werror -Wextra ");strcat(cmd, cname);strcat(cmd, buf);
FILE *fd = fopen(buf, "w+");char a[]="#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#include <unistd.h>%cint main(){%cchar buf[10];char cmd[255];char cname[9];%cint i = %i;%cif (i >= 0){%csnprintf(cname, sizeof(cname), %cSully_%ci %c);snprintf(buf, sizeof(buf), %cSully_%ci.c%c, i);i--;%cstrcpy(cmd, %c/usr/bin/clang -Wall -Werror -Wextra %c);strcat(cmd, cname);strcat(cmd, buf);%cFILE *fd = fopen(buf, %cw+%c);char a[]=%c%s%c;fprintf(fd,a,10,10,10,10,10,10,i,10,10,34,37,34,34,37,34,10,34,34,10,34,34,34,a,34,10);}system(cmd);system(cname);}%c";fprintf(fd,a,10,10,10,10,10,10,i,10,10,34,37,34,34,37,34,10,34,34,10,34,34,34,a,34,10);}system(cmd);system(cname);}
