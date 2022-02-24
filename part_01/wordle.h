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
	char	fornow_yellow[6];
	int		num_green;
	int		num_yellow;
}				t_wordle;

char	**word_list(void);
void	call_filters(t_wordle *data);
void	black_filter(t_wordle *data);
void	print_list(char **array);

#endif