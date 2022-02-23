#include "wordle.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	give_g_indexes(t_wordle *data)
{
	int ig = 0;
	int i = 0;
	int count = 0;

	while(i < 5)
		data->arr_g[i++] = 9;
	i = 0;
	data->ga = '.', data->gb = '.', data->gc = '.', data->gd = '.', data->ge = '.';

	while (data->green_buf[ig])
	{
		if (ft_isalpha(data->green_buf[ig]))
		{
			data->arr_g[i++] = ig;
			++data->amount_of_g_chars;
			if (!count)
				data->ga = data->green_buf[ig];
			else if (count == 1)
				data->gb = data->green_buf[ig];
			else if (count == 2)
				data->gc = data->green_buf[ig];
			else if (count == 3)
				data->gd = data->green_buf[ig];
			else if (count == 4)
				data->ge = data->green_buf[ig];
		}
		else 
			i++;
		++ig;
		count++;
		
	}

	//for show
	printf("\n\nGREEN:\n");
	for (int f = 0; f < 5; f++)
		printf("arr_g= %d\n", data->arr_g[f]);
	printf("\namount_of_g_chars= %d\n", data->amount_of_g_chars);
	printf("\nvalue of ga= %c\n", data->ga);
	printf("value of gb= %c\n", data->gb);
	printf("value of gc= %c\n", data->gc);
	printf("value of gd= %c\n", data->gd);
	printf("value of ge= %c\n", data->ge);

}

void	give_y_indexes(t_wordle *data)
{
	int ig = 0;
	int i = 0;
	int count = 0;

	while(i < 5)
		data->arr_y[i++] = 9;
	i = 0;
	data->ya = '.', data->yb = '.', data->yc = '.', data->yd = '.', data->ye = '.';

	while (data->yellow_buf[ig])
	{
		if (ft_isalpha(data->yellow_buf[ig]))
		{
			data->arr_y[i++] = ig;
			++data->amount_of_y_chars;
			if (!count)
				data->ya = data->yellow_buf[ig];
			else if (count == 1)
				data->yb = data->yellow_buf[ig];
			else if (count == 2)
				data->yc = data->yellow_buf[ig];
			else if (count == 3)
				data->yd = data->yellow_buf[ig];
			else if (count == 4)
				data->ye = data->yellow_buf[ig];	
		}
		else 
			i++;
		++ig;
		count++;
		
	}

	//for show
	printf("\n\nYELLOW:\n");
	for (int f = 0; f < 5; f++)
		printf("arr_y= %d\n", data->arr_y[f]);
	printf("\namount_of_y_chars= %d\n", data->amount_of_y_chars);
	printf("\nvalue of ya= %c\n", data->ya);
	printf("value of yb= %c\n", data->yb);
	printf("value of yc= %c\n", data->yc);
	printf("value of yd= %c\n", data->yd);
	printf("value of ye= %c\n", data->ye);

}

void	give_b_indexes(t_wordle *data)
{
	int ig = 0;
	int i = 0;
	int count = 0;

	while(i < 5)
		data->arr_b[i++] = 9;
	i = 0;
	data->ba = '.', data->bb = '.', data->bc = '.', data->bd = '.', data->be = '.';

	while (data->black_buf[ig])
	{
		if (ft_isalpha(data->black_buf[ig]))
		{
			data->arr_b[i++] = ig;
			++data->amount_of_b_chars;
			if (!count)
				data->ba = data->black_buf[ig];
			else if (count == 1)
				data->bb = data->black_buf[ig];
			else if (count == 2)
				data->bc = data->black_buf[ig];
			else if (count == 3)
				data->bd = data->black_buf[ig];
			else if (count == 4)
				data->be = data->black_buf[ig];
		}
		else 
			i++;
		++ig;
		count++;
		
	}

	//for show
	printf("\n\nBLACK:\n");
	for (int f = 0; f < 5; f++)
		printf("arr_b= %d\n", data->arr_b[f]);
	printf("\namount_of_b_chars= %d\n", data->amount_of_b_chars);
	printf("\nvalue of ba= %c\n", data->ba);
	printf("value of bb= %c\n", data->bb);
	printf("value of bc= %c\n", data->bc);
	printf("value of bd= %c\n", data->bd);
	printf("value of be= %c\n", data->be);

}

int main(void)
{
	t_wordle	data;	

	memset(&data, 0, sizeof(t_wordle));
	char	*g_question = "any \033[0;32mGREEN\033[0m letters?, usage: <..al.>";  

	printf("%s\n", g_question);
	scanf("%s", data.green_buf);
	
	
	
	char *y_question = "any \033[1;33mYELLOW\033[0m letters?, usage: <r....>";

	printf("%s\n", y_question);
	scanf("%s", data.yellow_buf);
	


	char	*b_question = "any \033[0;30mBLACK\033[0m letters?, usage: <.e..y>";

	printf("%s\n", b_question);
	scanf("%s", data.black_buf);

	//only for show
	/* printf("\n\ngreen_buf=	%s\n", green_buf);
	printf("yellow_buf=	%s\n", yellow_buf);
	printf("black_buf=	%s\n\n\n", black_buf); */

	give_g_indexes(&data);
	give_y_indexes(&data);
	give_b_indexes(&data);

	return (0);
}
