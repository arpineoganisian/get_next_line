int main()
{
    int     fd;
    char    *line;
    int     i;
	int		count;
	count = 1;
    fd = open("test", O_RDONLY);
    while ((i = get_next_line(fd, &line)))
    {
        printf("/%d/ i is %d/ =%s=\n", count++, i, line);
        free(line);
    }
    printf("/%d/ i is %d/ =%s=\n", count, i, line);
    free(line);
    close(fd);
	while (1)
      ;
}
