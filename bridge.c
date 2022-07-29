 # include <stdio.h>
 # include <sys/types.h>
 # include <fontl.h>
 # include <unistd.h>
 # include <string.h>
 # include <sys/ioctl.h>
 # include <stdlib.h>
 # include "clientBridge.h"


//{ } \



void write_struct(int fd unsigned long command, struct complex_struct * struct_address) {
	if (ioctl(fd,command, struct_address)==-1){ 
		perror("Write message error at ioctl");
	}
 }


void write_message (int fd, unsigned long command, char=message){ 
	if (ioctl(fd, command, message)==-1){ 
		perror("Write message error at ioctl") 
	}

}

void read_message(int fd, unsigned long command, char*message) { 

	if (ioctl(fd, command, message)==-1){ 
		perror("Read message error at ioctl");
	}
}


void read_message_param(int fd, unsigned long command, int*value){ 
	if (ioctl(fd, command, message)==-1){ 
		perror("Read message error at ioctl");
	} else { 
		printf("Copy the message from the kernel\n")
		}
}

void write_int(int fd, unsigned long command, int*value){
	if (ioctl(fd, command, value)==-1){ 
		perror("Write message error at ioctl") 
	}

 }


void read_int(int fd, unsigned long command, int*value){ 

	if(ioctl(fd, command, value)==-1){
	perror("Read int error at ioctl");
	 } else {
		printf("Copy the int form the kernel\n")	
		 }
}


int send_empty_command(int fd, unsigned long command){
	int returned_value=ioctl(fd, command);
	if (returned_value==-1) { 
		perror("Send command error at ioctl");
		return returned_value;
	} else { 
	//printf("Command OK to the kernel\n");
	return returned_value;
	}
 }

void write_several_messages(int fd){ 
	write_message(fd, BRIDGE_W_S, "Message 2");
	write_message(fd, BRIDGE_W_S, "Message 3");
}

void read_all_messages_stack(int fd){
	char message[100];
	while(send_empty_command(fd, BRIDGE_STATE_S)>0){ 
	read_message(fd, BRIDGE_R_S, message);
	printf("%s", message);
	}

 }

void read_all_messages_list (int fd){ 
	char message[100];
	while(send_empty_command(fd, BRIDGE_STATE_L)>0){ 
		read_message(fd, BRIGE_R_L, message);
		printf("%s", message);
	}

}

void read_all_queue_messages(int fd){ 
	char message[100];
	


}





//{ } \onc cinc siet


