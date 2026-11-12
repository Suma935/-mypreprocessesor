 
make: comment_removal.o inclusion.o macro.o project.o
	cc comment_removal.o inclusion.o macro.o project.o -o make

inclusion.o:inclusion.c
	cc -c inclusion.c
macro.o:macro.c
	cc -c macro.c
comment_removal.o:comment_removal.c
	cc -c comment_removal.c
project.o:project.c
	cc -c project.c
clear:
	 @echo "cleaning up..."
	 @rm -r *.o



