#Commentaire hors fonction
def funcplus():
	return;
def main():
	string = "#Commentaire hors fonction%cdef funcplus():%c%creturn;%cdef main():%c%cstring = %c%s%c%c%cprint(string %c(10,10,9,10,10,9,34,string,34,10,9,37,10,9,10,10,9))%c%c#Commentaire dans fonction%cif __name__ == '__main__':%c%cmain()"
	print(string %(10,10,9,10,10,9,34,string,34,10,9,37,10,9,10,10,9))
	#Commentaire dans fonction
if __name__ == '__main__':
	main()
