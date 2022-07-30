void eighthPoint(int fd){
    printf("\n8. Rotate list to right.");
    printf("\nLet's add some items to the first list.\n");
    char ans[100]; // Just don't init with 0 plz
    while(strcmp(ans, "EXIT") != 0){
        printf("\nType the word you want to add to the list or EXIT.\n");
        scanf("%s", ans);
        printf("\nInput: %s\n", ans);
        if(strcmp(ans, "EXIT") != 0){
            // CREATE LIST ITEMS LOGIC
            strcat(ans,"\n");
            write_message(fd, BRIDGE_W_L, ans);
        }
    }
    printf("Rotated list.\n");
    send_empty_command(fd, BRIDGE_ROTATE_L);
    read_all_messages_list(fd);
}
