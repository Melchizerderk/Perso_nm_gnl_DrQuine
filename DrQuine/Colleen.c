/*
  Commentaire hors fonction
 */

#include <stdio.h>

void funcplus(){}

int main()
{
	char a[]="/*%c%cCommentaire hors fonction*/#include <stdio.h> void funcplus(){};%cint main(){char*a=%c%s%c;printf(a,10,34,a,34);/*Salut Colleen dans le main*/}";printf(a,10,34,a,34);
	/*
	  Salut Colleen dans le main
	 */
}
