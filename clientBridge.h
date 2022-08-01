#ifndef CLIENT_BRIDGE_H 
//el codigo en c se puede distribuir en archivos .h y .c
// los .o son privados
// La primera linea explica que sino esta definido CLIENT_BRIDGE_H entonces lo define, finaliza con el endif 
#define CLIENT_BRIDGE_H 
// los 'define' son directivas del PREprocesador
#include <linux/ioctl.h> 
//uso de las librerias la consola reemplaza el include por el archivo que esta entre los signos <>, se quiere que en un programa el archivo solo se carge una vez
//ioctl es INPUT/OUTUT/CONTOL ofrecido por linux, define las funcionalidades _io _iow y _ior  write read
//en la macro el proceso
 
// cuando al final tiene una Q Queue
// cuando al final tiene una S Stack
// cuando al final tiene una L List
// por consola 'BRIDGE DATA VAR' para enviar mensajes al modulo

// io no recibe ni manda parametros
// ior lee
// iow escribe

// a continuacion se definen macros incluyendo ioctl
// a continuacion se expresa todo el contenido que va a estar expuesto
// todo el contenido en adelante esta definida las macros definidos los valores que se vana  utilizar
// definiendo las constantes asignadas con un numero



#define BRIDGE_CREATE_Q _IO('p', 1)
// Con esta linea creamos QUEUE
#define BRIDGE_W_HIGH_PRIOR_Q _IOW('p',2, char *)
#define BRIDGE_W_MIDDLE_PRIOR_Q _IOW('p',3, char *)
#define BRIDGE_W_LOW_PRIOR_Q _IOW('p',4, char *)
// el apuntador hace referencia al asterisco antes de char
// el asterisco lo envia por referencia 43:33
// las macros o constantes son los BRIDGE..... 45:41 
#define BRIDGE_R_HIGH_PRIOR_Q _IOR('p',5, char *)
#define BRIDGE_R_MIDDLE_PRIOR_Q _IOR('p',6, char *)
#define BRIDGE_R_LOW_PRIOR_Q _IOR('p',7, char *)
#define BRIDGE_STATE_Q _IO('p',8)
#define BRIDGE_DESTROY_Q _IO('p',9)
// se necesita garantizar que toda la memoria que se reserve se libere... 47:40
// En C no hay recolector de basura 
// liberar memoria se garantiza con DESTROY
// OJO con el uso de memoria
// MALO Manejo dinamico de la memoria-
// CAMALO Manejo dinamico de la memoria en kernel 48:40

// STATE_Q Muestra en que estado esta la memoria
// retorna enternos positivos o negativos y uno los define

#define BRIDGE_CREATE_S _IO('p',10)
// Con esta linea creamos STACK
#define BRIDGE_W_S _IOW('p',11, char *)
#define BRIDGE_R_S _IOR('p',12, char *)
#define BRIDGE_STATE_S _IO('p',13)
#define BRIDGE_DESTROY_S _IO('p',14)

#define BRIDGE_CREATE_L _IO('p',15)
// Con esta linea creamos LIST
#define BRIDGE_W_L _IOW('p', 16, char *)
#define BRIDGE_R_L _IOR('p', 17, char *)
#define BRIDGE_INVERT_L _IO('p', 18)
#define BRIDGE_ROTATE_L _IOW('p', 19, int *)
#define BRIDGE_CLEAN_L _IO('p',20)
#define BRIDGE_GREATER_VAL_L _IOR('p',21)
#define BRIDGE_END_L _IO('p', 22)
#define BRIDGE_CONCAT_L _IO('p', 23)
#define BRIDGE_STATE_L _IO('p', 24)
#define BRIDGE_DESTROY_L _IO('p', 25)

// Para el primer punto LIFO utilizamos Pila 51:00
// PILA LAST IN FIRST OUT muestra inverso


#endif
