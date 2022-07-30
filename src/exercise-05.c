void fifthPoint(int fd){
    printf("\n5. Destroy list or stack.");
    int ans;
    printf("\nType 1 to destroy the list or 2 to destroy the stack.\n");
    scanf("%d", &ans);
    if(ans == 1){
        send_empty_command(fd, BRIDGE_DESTROY_L);
        read_all_messages_list(fd);
        printf("\nDone\n");
    } else if (ans == 2){
        send_empty_command(fd, BRIDGE_DESTROY_S);
        read_all_messages_stack(fd);
        printf("\nDone\n");
    } else {
        printf("\nERROR\n");
    }
}
