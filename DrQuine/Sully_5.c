#include <stdio.h>
int main(){
char buf[10];
int i = 4;
if (i >= 0){
snprintf(buf, sizeof(buf), "Sully_%i.c", i);i--;
FILE *fd = fopen(buf, "w+");char a[]="#include <stdio.h>%cint main(){%cchar buf[10];%cint i = %i;%cif (i >= 0){%csnprintf(buf, sizeof(buf), %cSully_%ci.c%c, i);i--;%cFILE *fd = fopen(buf, %cw+%c);char a[]=%c%s%c;fprintf(fd,a,10,10,10,i,10,10,34,37,34,10,34,34,34,a,34,10);}}%c";fprintf(fd,a,10,10,10,i,10,10,34,37,34,10,34,34,34,a,34,10);}}
