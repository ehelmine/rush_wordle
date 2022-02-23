#ifndef WORDLE_H
# define WORDLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_wordle
{
	char	green_buf[7];
	int 	green;
	char	yellow_buf[7];
	int 	yellow;
	char	black_buf[7];
	int 	black;
	char 	**arr;
	char	total_green[6];
	int		num_green;
}				t_wordle;

#endif