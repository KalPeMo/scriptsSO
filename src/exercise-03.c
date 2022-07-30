int thirdPoint(int fd){
    char filePath[100];
    printf("\n3. Checks if a code is balanced.");
    printf("\n   Input the file path: ");
    scanf("%s", filePath);
    printf("\n file path: %s\n", filePath);

    FILE *filePointer;
    char ch;
    filePointer = fopen(filePath, "r");
    if (filePointer == NULL){
        printf("File is not available \n");
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
