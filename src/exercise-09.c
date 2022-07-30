void ninethPoint(int fd){
    printf("\n9. Delete duplicates on the list.");
    printf("\nLet's add some items to the first list.\n");
    char ans[100]; // Just don't init with 0 plz
    while(strcmp(ans, "EXIT") != 0){
        printf("\nType the word you want to add to the list or EXIT.\n");
        scanf("%s", ans);
        printf("\nInput: %s\n", ans);
        if(strcmp(ans, "EXIT") != 0){
            strcat(ans,"\n");
            write_message(fd, BRIDGE_CLEAN_L, ans);
        }
    }
    printf("\nCleaned list:\n");
    read_all_messages_list(fd);
}
