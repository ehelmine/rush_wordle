#ifndef WORDLE_H
# define WORDLE_H

#include <stdio.h>
#include <string.h>

typedef struct s_wordle
{
	char	green_buf[6];
	int		arr_g[5];
	int		amount_of_g_chars;
	char	ga;
	char	gb;
	char	gc;
	char	gd;
	char	ge;
	char	yellow_buf[6];
	int		arr_y[5];
	int		amount_of_y_chars;
	char	ya;
	char	yb;
	char	yc;
	char	yd;
	char	ye;
	char	black_buf[6];
	int		arr_b[5];
	int		amount_of_b_chars;
	char	ba;
	char	bb;
	char	bc;
	char	bd;
	char	be;
}				t_wordle;

#endif