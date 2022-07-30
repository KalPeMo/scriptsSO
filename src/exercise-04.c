void forthPoint(int fd){
    printf("\n4. Multi-level Queue.");
    printf("\nLet's add some items.\n");
    char ans[100]; // Just don't init with 0 plz
    int x = 0;
    while(strcmp(ans, "EXIT") != 0){
        printf("\nType the word you want to add to the queue or EXIT.\n");
        scanf("%s", ans);
        printf("\nInput: %s\n", ans);
        if(strcmp(ans, "EXIT") == 0){
            break;
        }
        printf("\nWhat's the priority? Type the number to choose one:\n");
        printf(" 1. High priority.\n 2. Medium priority.\n 3. Low priority.\n ");
        scanf("%d", &x);
        switch(x){
            case 1:
                write_message(fd, BRIDGE_W_HIGH_PRIOR_Q, ans);
                printf("\n%s Element succesfully added to the high priority queue.\n", &ans[0]);
                break;
            case 2:
                write_message(fd, BRIDGE_W_MIDDLE_PRIOR_Q, ans);
                printf("\n%s Element succesfully added to the medium priority queue", &ans[0]);
                break;
            case 3:
                write_message(fd, BRIDGE_W_LOW_PRIOR_Q, ans);
                printf("\n%s Element succesfully added to the low priority queue", &ans[0]);
                break;
        }
    }
    printf("\nThe items printed in according to their priority\n");
    read_all_queue_messages(fd);
}
