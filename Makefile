build:
	gcc -o bin/ls ls.c
	gcc -o bin/echo echo.c
	gcc -o bin/exec exec.c
	gcc -o bin/errno errno.c
	gcc -o bin/uidgid uidgid.c
	gcc -o bin/signal signal.c
	gcc -o bin/lseek lseek.c
	gcc -o bin/read_write read_write.c
	gcc -o bin/lstat lstat.c
	gcc -o bin/umask umask.c
	gcc -o bin/chdir chdir.c
	gcc -o bin/time time.c
	gcc -o bin/atexit atexit.c
	gcc -o bin/fork fork.c
	gcc -o bin/waitpid waitpid.c
