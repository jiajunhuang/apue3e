build:
	gcc -o bin/ls ls.c
	gcc -o bin/echo echo.c
	gcc -o bin/exec exec.c
	gcc -o bin/errno errno.c
	gcc -o bin/uidgid uidgid.c
	gcc -o bin/signal signal.c
	gcc -o bin/lseek lseek.c
	gcc -o bin/read_write read_write.c
