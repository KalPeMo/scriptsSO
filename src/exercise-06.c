void sixthPoint(int fd)
{
    printf("\n6. Invert list.");
    printf("\nLet's add some items.\n");
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
    printf("\nInverted list:\n");
    send_empty_command(fd, BRIDGE_INVERT_L);
    read_all_messages_list(fd);
}
