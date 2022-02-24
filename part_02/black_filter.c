#include "wordle.h"

void	remove_words_that_have_letter_anywhere_else_except_in_green_index(char **array, \
		int green_index, char letter, float **val_arr)
{
	// remove all the words that have the letter anywhere else except in the
	// green index
	printf("here2\n");
	int i;
	int ii;
	for (i = 0; i < 2308; i++)
	{
		if (array[i][0] != '\0')
		{
			for (ii = 0; ii < 5; ii++)
			{
				if (array[i][ii] == letter && ii != green_index)
				{
					printf("arr %s\n", array[i]);
					memset(array[i], 0, 5);
					val_arr[i][0] = -1;
					break ;
				}
			}
		}
	}
}

void	remove_words_black_letter_in_spesific_index(char **array, char letter, int index,
		float **val_arr)
{
	// remove all the words that have black letter in spesific index
	int i;
printf("here1\n");
	for (i = 0; i < 2308; i++)
	{
		if (array[i][0] != '\0')
		{
			if (array[i][index] == letter)
			{
				memset(array[i], 0, 5);
				val_arr[i][0] = -1;
				break ;
			}
		}
	}
}

void	remove_words_that_have_black_letter(char **array, char letter, float **val_arr)
{
	// remove all the words that have black letter anywhere in it
	int i;
	int ii;

	for (i = 0; i < 2308; i++)
	{
		if (array[i][0] != '\0')
		{
			for (ii = 0; ii < 5; ii++)
			{
				if (array[i][ii] == letter)
				{
					memset(array[i], 0, 5);
					val_arr[i][0] = -1;
					break ;
				}
			}
		}
	}
}

void	black_filter(t_wordle *data)
{
	int i = 0;
	while (data->black > 0)
	{
		while (data->black_buf[i] != '\0' && data->black_buf[i] == '.')
			i++;
		int x = 0;
		int y = 0;
		// we check if the letter we have in black list exists in the green letter list as well
		while (data->total_green[x] != '\0' && data->total_green[x] != data->black_buf[i])
			x++;
		// then we check if the letter we have in black list exists in the yellow letter list as well
		while (data->fornow_yellow[y] != '\0' && data->fornow_yellow[y] != data->black_buf[i])
			y++;
		if (data->total_green[x] == '\0')
		{
			// if we didn't find the black letter in the green list, we come here
			if (data->fornow_yellow[y] == '\0')
			// if we didn't find the black letter in the yellow list, we come here
				remove_words_that_have_black_letter(data->arr, data->black_buf[i], data->value_arr);
			else
			// if we found the black letter in the yellow list, we come here
				remove_words_black_letter_in_spesific_index(data->arr, data->black_buf[i], i, data->value_arr);
		}
		else
		{
			// if we found the black letter in the green list, we come here
			if (data->fornow_yellow[y] != '\0')
			// if we found the black letter also in the yellow list, we come here
				remove_words_black_letter_in_spesific_index(data->arr, data->black_buf[i], i, data->value_arr);
			else
			{
				// if we didn't find the black letter in the yellow list, we come here
				int k = 0;
				while (data->green_buf[y] != '\0' && data->green_buf[k] != data->black_buf[i])
					k++;
				remove_words_that_have_letter_anywhere_else_except_in_green_index(data->arr, k, data->black_buf[i], data->value_arr);
			}
		}
		i++;
		data->black--;
	}
}