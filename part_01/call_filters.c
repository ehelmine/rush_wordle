#include "wordle.h"

static void	filter_yellow(char **array, char letter, int index)
{
	// checks if given letter is somewhere in the word
	// if it is there BUT it is in the given index -> it is not the right word -> memset
	// if it is not there -> memset
	// if it is there and it is not in the given index -> we i++;

	for (int i = 0; i < 2308; i++)
	{
		if (array[i][index] == letter)
			memset(array[i], 0, 5);
		else
		{
			int ii = 0;
			while (array[i][ii] != '\0' && array[i][ii] != letter)
				ii++;
			if (ii == 5)
				memset(array[i], 0, 5);
		}
	}
}

static void	filter_green(char **array, char letter, int index)
{
	// checks if given letter is in the right place

	int i;
	int x;

	x = 0;
	for (i = 0; i < 2308; i++)
	{
		if (array[i][index] != letter)
			memset(array[i], 0, 5);
	}
}

void	call_filters(t_wordle *data)
{
	int i = 0;
	while (data->green > 0)
	{
		while (data->green_buf[i] != '\0' && data->green_buf[i] == '.')
			i++;
		filter_green(data->arr, data->green_buf[i], i);
		i++;
		data->green--;
	}
	i = 0;
	while (data->yellow > 0)
	{
		while (data->yellow_buf[i] != '\0' && data->yellow_buf[i] == '.')
			i++;
		filter_yellow(data->arr, data->yellow_buf[i], i);
		i++;
		data->yellow--;
	}
	black_filter(data);
	print_list(data->arr);
}
