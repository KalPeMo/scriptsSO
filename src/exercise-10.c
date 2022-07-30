void tenthPoint(int fd){
    printf("\n10. Return the greatest value on the list.");
    printf("\nLet's add some items to the first list.\n");
    char ans[100]; // Just don't init with 0 plz
    while(strcmp(ans, "EXIT") != 0){
        printf("\nType the word you want to add to the list or EXIT.\n");
        scanf("%s", ans);
        printf("\nInput: %s\n", ans);
        if(strcmp(ans, "EXIT") != 0){
            write_message(fd, BRIDGE_CLEAN_L, ans);
        }
    }
    //printf("\nSu lista depurada:\n");
    //read_all_messages_list(fd);
    char  major[100];
    read_message(fd, BRIDGE_R_L, major);
   
    do{
        char input[100];
        read_message(fd, BRIDGE_R_L, input);
        
        if(strcmp(input,major) > 0)
        {

            memcpy(major, input,strlen(input)+1);

        }
    }while(send_empty_command(fd, BRIDGE_STATE_L)!=0);
    printf("\nThe greatest value is: %s\n", major);
}
