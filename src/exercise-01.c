void firstPoint(int fd) {
    char filePath[100];
    printf("\n1. Reverse the lines of a text file.");
    printf("\n   Input the file path: ");
    scanf("%s", filePath);

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        perror("First point open file.");
    }

    printf("\n File content:\n");
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
        write_message(fd, BRIDGE_W_S, line);
    }
    printf("\n Reversed file:\n");
    read_all_messages_stack(fd);

    fclose(fp);
    if (line)
        free(line);
}
