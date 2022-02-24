#include "wordle.h"

static int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

static int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

static void	give_indexes(t_wordle *data)
{
	int i = 0;
	while (data->green_buf[i])
	{
		if (ft_isalpha(data->green_buf[i]))
		{
			++data->green;
			data->total_green[data->num_green++] = data->green_buf[i];
		}
		++i;
	}
	i = 0;
	while (data->yellow_buf[i])
	{
		if (ft_isalpha(data->yellow_buf[i]))
		{
			++data->yellow;
			data->fornow_yellow[data->num_yellow++] = data->yellow_buf[i];
		}
		++i;
	}
	i = 0;
	while (data->black_buf[i])
	{
		if (ft_isalpha(data->black_buf[i]))
			++data->black;
		++i;
	}
}

static int	check_input(t_wordle *data)
{
	int i = 0;

	while (i < 5)
	{
		if ((data->yellow_buf[i] != '.' && data->black_buf[i] != '.') || (data->yellow_buf[i] != '.'
			&& data->green_buf[i] != '.') || (data->black_buf[i] != '.' && data->green_buf[i] != '.'))
		{
			printf("\n\033[0;31mError!, in input. Please don't put letters into the same indexes in different lines. Please try again.\033[0;37m\n\n");
				return (-1);
		}
		i++;
	}
	return (1);
}

static int	check_str(char *str)
{
	int i = 0;
	while (i < 5)
	{
		if (str[i] != '.' && ft_isalpha(str[i]) == 0)
		{
			printf("\n\033[0;31mError in input. Use only alphabets or dots as input.\033[0;37m\n\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < 5)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (1);
}

int main(void)
{
	t_wordle	data;
	int			loop = 0;

	memset(&data, 0, sizeof(t_wordle));
	data.arr = word_list();
	while (loop < 6)
	{
		printf("%s\n", "any \033[0;32mGREEN\033[0m letters?, usage: <..al.>");
		scanf("%s", data.green_buf);
		if (check_str(data.green_buf) == -1)
			continue ;
		if (strlen(data.green_buf) != 5)
		{
			printf("\n\033[0;31mError: not correct input. please try again.\033[0;37m\n\n");
			continue ;
		}
		printf("%s\n", "any \033[1;33mYELLOW\033[0m letters?, usage: <r....>");
		scanf("%s", data.yellow_buf);
		if (check_str(data.yellow_buf) == -1)
			continue ;
		if (strlen(data.yellow_buf) != 5)
		{
			printf("\n\033[0;31mError: not correct input. please try again.\033[0;37m\n\n");
			continue ;
		}	
		printf("%s\n", "any \033[0;30mBLACK\033[0m letters?, usage: <.e..y>");
		scanf("%s", data.black_buf);
		if (check_str(data.black_buf) == -1)
			continue ;
		if (strlen(data.black_buf) != 5)
		{
			printf("\n\033[0;31mError: not correct input. please try again.\033[0;37m\n\n");
			continue ;
		}
		if (check_input(&data) == -1)
			continue ;
		give_indexes(&data);
		call_filters(&data);
		++loop;
	}
	int i = 0;
	while (data.arr[i] != NULL)
	{
		free(data.arr[i]);
		data.arr[i] = NULL;
		i++;
	}
	data.arr = NULL;
	return (0);
}

	