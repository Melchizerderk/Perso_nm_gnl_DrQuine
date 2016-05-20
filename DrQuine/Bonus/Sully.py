import sys, os
i = 5
if (i > 0) :
	if sys.argv[0] == 'Sully.py' :
		i = i + 1
	i = i - 1;File = 'Sully_%i.py' % (i);fo = open(File, 'w')
	a = "import sys, os%ci = %i%cif (i > 0) :%c%cif sys.argv[0] == 'Sully.py' :%c%c%ci = i + 1%c%ci = i - 1;File = 'Sully_%ci.py' %c (i);fo = open(File, 'w')%c%ca = %c%s%c%c%cfo.write(a %c (10,i,10,10,9,10,9,9,10,9,37,37,10,9,34,a,34,10,9,37,34,34,10));fo.close();os.system(%cpython3 %c + File)%c"
	fo.write(a % (10,i,10,10,9,10,9,9,10,9,37,37,10,9,34,a,34,10,9,37,34,34,10));fo.close();os.system("python3 " + File)
