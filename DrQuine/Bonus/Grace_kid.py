QT = 34
NL = 10
PR = 37
fo = open('Grace_kid.py', 'w')
a = "QT = 34%cNL = 10%cPR = 37%cfo = open('Grace_kid.py', 'w')%ca = %c%s%c%cfo.write(a %c (NL,NL,NL,NL,QT,a,QT,NL,PR,NL))%c"
fo.write(a % (NL,NL,NL,NL,QT,a,QT,NL,PR,NL))
