/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:45:23 by msavelie          #+#    #+#             */
/*   Updated: 2024/05/11 14:45:23 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int i = 0;
	int		fd;
	char	*line;

	// LINE WITH 100 000 chars
	printf("*****\t1 line with 100 000 characters\t*****\n");
	fd = open("bigfile.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main: %s\n\n", line);
	close(fd);

	// EMPTY LINE
	printf("*****\tEmpty line\t*****\n");
	fd = open("empty.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main: %s\n\n", line);
	close(fd);

	// Line with 500 chars
	printf("*****\tLine with 500 chars\t*****\n");
	fd = open("500.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main: %s\n\n", line);
	close(fd);

	// File with 4 lines
	printf("*****\tFile with 4 lines\t*****\n");
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (i < 3)
	{
		printf("main: %s\n", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("main: %s\n\n", line);
	close(fd);

	// File with 5 big lines
	printf("*****\tFile with 5 big lines\t*****\n");
	fd = open("5biglines.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (i < 4)
	{
		printf("main: %s\n", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	printf("main: %s\n\n", line);
	close(fd);


	// FIRST TIMEOUT IN FRANCINETTE WITHOUT \n
	printf("*****\tFIRST TIMEOUT IN FRANCINETTE WITHOUT \\n\t*****\n");
	fd = open("timeout1.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main: %s\n\n", line);
	close(fd);

	// SECOND TIMEOUT IN FRANCINETTE WITH \n
	printf("*****\tSECOND TIMEOUT IN FRANCINETTE WITH \\n\t*****\n");
	fd = open("timeout2.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main: %s\n\n", line);
	close(fd);

	// 3 Multiple FD
	printf("*****\t3 Multiple FD\t*****\n");
	int fd_arr[5];
	fd_arr[0] = open("test1.txt", O_RDONLY);
	fd_arr[1] = open("test2.txt", O_RDONLY);
	fd_arr[2] = open("test3.txt", O_RDONLY);
	line = get_next_line(fd_arr[0]);
	printf("main: %s\n\n", line);
	line = get_next_line(fd_arr[1]);
	printf("main: %s\n\n", line);
	line = get_next_line(fd_arr[2]);
	printf("main: %s\n\n", line);
	close(fd_arr[0]);
	close(fd_arr[1]);
	close(fd_arr[2]);

	// 5 Multiple fd_arr
	printf("*****\t5 Multiple fd_arr\t*****\n");
	fd_arr[0] = open("test1.txt", O_RDONLY);
	fd_arr[1] = open("test2.txt", O_RDONLY);
	fd_arr[2] = open("test3.txt", O_RDONLY);
	fd_arr[3] = open("test4.txt", O_RDONLY);
	fd_arr[4] = open("test5.txt", O_RDONLY);

	line = get_next_line(fd_arr[0]);
	printf("main: %s\n\n", line);
	line = get_next_line(fd_arr[1]);
	printf("main: %s\n\n", line);
	line = get_next_line(fd_arr[2]);
	printf("main: %s\n\n", line);
	line = get_next_line(fd_arr[3]);
	printf("main: %s\n\n", line);
	line = get_next_line(fd_arr[4]);
	printf("main: %s\n\n", line);
	close(fd_arr[0]);
	close(fd_arr[1]);
	close(fd_arr[2]);
	close(fd_arr[3]);
	close(fd_arr[4]);


	return (0);
}
