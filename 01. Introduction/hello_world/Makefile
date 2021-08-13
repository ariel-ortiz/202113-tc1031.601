# Archivo para construir el programa Hola Mundo
# Autor: Ariel Ortiz

CC = g++

# Encargado de hacer el "linking" (enlace)
hello: hello.o
	$(CC) hello.o -o hello

# Encargado de compilar
hello.o: hello.cpp
	$(CC) -c hello.cpp

clean:
	rm -f hello hello.o
