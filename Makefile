#
#		SISTEMAS DE OPERACION - PROYECTO 1
#
#		Archivo makefile para compilar el proyecto.
#
#		AUTORES:
#				Jose Acevedo 13-10006
#				Augusto Hidalgo XX-XXXXX
#

CC = gcc
CFLAGS = -Wall -Wextra

default: batalla

################ Shared library files ###############
std_lib.o: 			sharedLib/std_lib.c 			\
					sharedLib/ds.h 					
	$(CC) $(CFLAGS) -c sharedLib/std_lib.c 			

ds.o:				sharedLib/ds.c 					\
					sharedLib/ds.h
	$(CC) $(CFLAGS) -c sharedLib/ds.c

read.o: 			sharedLib/read.c				\
					sharedLib/ds.h 					
	$(CC) $(CFLAGS) -c sharedLib/read.c
#####################################################

################### Process files ###################
process_lib.o: 		Processes/process_lib.c 		\
					sharedLib/ds.h 					
	$(CC) $(CFLAGS) -c Processes/process_lib.c

process_child.o:	Processes/process_child.c 		\
					Processes/process_lib.h 		\
					sharedLib/std_lib.h 			\
					sharedLib/ds.h 					
	$(CC) $(CFLAGS) -c Processes/process_child.c

process_parent.o: 	Processes/process_parent.c 		\
					Processes/process_lib.h 		\
					sharedLib/std_lib.h 			\
					sharedLib/ds.h 					
	$(CC) $(CFLAGS) -c Processes/process_parent.c

process_main.o: 	Processes/process_main.c 		\
					Processes/process_parent.h 		\
					Processes/process_child.h 		\
					Processes/process_lib.h 		\
					sharedLib/ds.h
	$(CC) $(CFLAGS) -c Processes/process_main.c
#####################################################

#################### Thread files ###################
thread_main.o:		Threads/thread_main.c 			\
					sharedLib/ds.h
	$(CC) $(FLAGS) -c Threads/thread_main.c
#####################################################

##################### Main file #####################
main.o: 			main.c 							\
					Processes/process_main.c 		\
					Threads/thread_main.c 			\
					sharedLib/ds.h 					\
					sharedLib/read.h
	$(CC) $(FLAGS) -c main.c
#####################################################

#################### Executable file ################
batalla:			main.o 							\
					thread_main.o 					\
					process_main.o 					\
					process_parent.o 				\
					process_child.o 				\
					process_lib.o 					\
					std_lib.o 						\
					read.o 							\
					ds.o

	$(CC) $(CFLAGS) main.o 							\
					thread_main.o 					\
					process_main.o 					\
					process_parent.o 				\
					process_child.o 				\
					process_lib.o 					\
					std_lib.o   					\
					read.o       					\
					ds.o 	    					\
					-o batalla -pthread
#####################################################


clean:
	### Shared library ###
	-rm -f std_lib.o
	-rm -f ds.o
	-rm -f read.o

	### Processes ###
	-rm -f process_lib.o
	-rm -f process_child.o
	-rm -f process_parent.o
	-rm -f process_main.o

	### Threads ###
	-rm -f thread_main.o

	### Main ###
	-rm -f main.o

	### Executable ###
	-rm -f batalla