 # include <stdio.h>
 # include <sys/types.h>
 # include <unistd.h>
 # include <string.h>
 # include <sys/ioctl.h>
 # include <stdlib.h>
 
void write_struct(int fd, unsigned long command, struct complex_struct * struct_address) {
	if (ioctl(fd,command, struct_address)==-1){ 
		perror("Write message error at ioctl");
	}
}

void write_message (int fd, unsigned long command, char*message){ 
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
	if (ioctl(fd, command, value)==-1){ 
		perror("Read message error at ioctl");
	} else { 
		printf("Copy the message from the kernel\n")
		}
}

void write_int(int fd, unsigned long command, int*value){
	if (ioctl(fd, command, value)==-1){ 
		perror("Write int error at ioctl") 
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
	printf("Command OK to the kernel\n");
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
	int  response = send_empty_command(fd, BRIDGE_STATE_Q);
	while (response>0){
		if(response==1)
		read_message(fd, BRIDGE_R_HIGH_PRIOR_Q, message){ 
			printf("%s\n", message);
		 } else if(response==2) { 
			 read_message(fd, BRIDGE_R_MIDDLE_PRIOR_Q, message){ 
				 printf("%s\n", message);
			 } else if (response==3){
				 read_message(fd, BRIDGE_R_LOW_PRIOR_Q, message);
				 printf("%s\n", message);
			  }
			  response=send_empty_command(fd, BRIDGE_STATE_Q);
		 }
	  }
}


void primerPunto(int fd){
	char filePath[100];
	printf("\n1. Reversar las lineas de un archivo");
	printf("\n. Ingrese la ruta del archivo: ");
	scanf("%s", filePath);

	FILE=fp;
	char*line=NULL;
	size_t len=0;
	ssize_t read;

	fp=fopen(filePath,"r");
	if (fp==NULL) { 
		perror("Error al abrir archivo en el primer punto");
	}

	printf("\n. Contenido del archivo: \n");
	while ((read=getline(%line, %len, fp))!=1){
		printf("%s",line);
		write_message(fd, BRIDGE_W_S, line);

	}
	printf("\n. Contenido reversado del archivos: \n");
	read_all_messages_stack(fd);

	fclose(fp);
	if(line)
		free(line);
}

void segundoPunto(int fd){
}

int tercerPunto(int fd){
    char filePath[100];
    printf("\n3. Revisar si el archivo esta balanceado en apertura y clausura de signos de agrupacion (){}:");
    printf("\n   Ingrese la ruta del archivo ");
    scanf("%s", filePath);
    printf("\n Ruta del archivo: %s\n", filePath);

    FILE *filePointer;
    char ch;
    filePointer = fopen(filePath, "r");
    if (filePointer == NULL){
        printf("No se encontro archivo \n");
        return -1;
    } else {
        read_all_messages_stack(fd);
        while ((ch = fgetc(filePointer)) != EOF){
            if(ch == '(' || ch == '{'){
                char msgIn[2] = {ch, '\0'};
                write_message(fd, BRIDGE_W_S, msgIn);
            }
            else if(ch == ')'){
                if(send_empty_command(fd, BRIDGE_STATE_S) > 0){
                    char msgOut[2];
                    read_message(fd, BRIDGE_R_S, msgOut);
                    if(msgOut[0] != '('){
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else if(ch == '}'){
                if(send_empty_command(fd, BRIDGE_STATE_S) > 0){
                    char msgOut[2];
                    read_message(fd, BRIDGE_R_S, msgOut);
                    if(msgOut[0] != '{'){
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        }
        if(send_empty_command(fd, BRIDGE_STATE_S) > 0){
            return 0;
        } else {
            return 1;
        }
    }
    fclose(filePointer);
}

void cuartoPunto(int fd){
}
void quintoPunto(int fd){
}
void sextoPunto(int fd){
}
void septimoPunto(int fd){
}
void octavoPunto(int fd){
}
void novenoPunto(int fd){
}
void decimoPunto(int fd){
}

void onceavoPunto(int fd){
}

void doceavoPunto(int fd){
}

void treceavoPunto(int fd){
}

void catorceavoPunto(int fd){
}

void quinceavoPunto(int fd){
}



void menu(int fd){
	int x=100;// no debe iniciar en cero
	while(x!=0){
		printf("\n MENU");
		printf("\n0. Exit");
		printf("\nIngresar el numero que desea probar del 1 al 10:");
		scanf("%d",&x);
		switch(x){
			case 1:
				primerPunto(fd);
				break;
			case 2:
				segundoPunto(fd); //revisar el codigo
				break;
			case 3:
				int result=tercerPunto(fd);
				if(result==1){
					printf("\nEl archivo esta balanceado");
				} else if(result==0) {
					printf("\nEl archivo esta sin balancar");
				} else if (result==-1){
					printf("\nERROR\n");
				}
				break;
			case 4:
				cuartoPunto(fd);
				break;
			case 5:
				quintoPunto(fd);
				break;
			case 6:
				sextoPunto(fd);
				break;
			case 7:
				septimoPunto(fd);
				break;
			case 8:
				octavoPunto(fd);
				break;
			case 9:
				novenoPunto(fd);
				break;
			case 10:
				decimoPunto(fd);
				break;
			case 11:
				onceavoPunto(fd);
				break;
			case 12:
				doceavoPunto(fd);
				break;
			case 13:
				treceavoPunto(fd);
				break;
			case 14:
				catorceavoPunto(fd);
				break;
			case 15:
				quinceavoPunto(fd);
				break;

			default:
				if(x!=0){
					printf("\nError: error de segmentacion: /\n");
				}else {
					printf("\nBye. \n");
				}

				break;
		
		}
		printf("\nThe selected option was:");
		printf("%d\n",x);

	}

}

//{ } \doc cuar t r[100]
