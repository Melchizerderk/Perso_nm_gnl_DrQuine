#include <stdio.h>
#define QT 34
#define NL 10
#define FT(x)int main(){FILE *fd = fopen("Grace_kid.c", "w+"); char a[]="#include <stdio.h>%c#define QT 34%c#define NL 10%c#define FT(x)int main(){FILE *fd = fopen(%cGrace_kid.c%c, %cw+%c); char a[]=%c%s%c;fprintf(fd,a,NL,NL,NL,QT,QT,QT,QT,QT,a,NL,NL,NL,NL,9,NL,NL);%c%cFT(xxxxxxxx)%c/*%c%cUn commentaire%c*/%c";fprintf(fd,a,NL,NL,NL,QT,QT,QT,QT,QT,a,NL,NL,NL,NL,9,NL,NL);}

FT(xxxxxxxx)
/*
 	Un commentaire
*/
