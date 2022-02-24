
#include "wordle.h"

float	*get_value(char *str)
{
	int i = 0;
	int	*check;
	float *value;

	check = (int *)malloc(sizeof(int) * 26);
	if (!check)
	{
		printf("Malloc fail\n");
		exit (1);
	}
	memset(check, 0, 26);
	value = (float *)malloc(sizeof(float) * 1);
	if (!value)
	{
		printf("Malloc fail\n");
		exit (1);
	}
	value[0] = 0;
	while (i < 5)
	{
		if (str[i] == 'a' && check[str[i] - 97] == 0)
		{
//			value[0] += 25;
			value[0] += 43.31;
			check[0] = 1;
		}
		else if (str[i] == 'b' && check[str[i] - 97] == 0)
		{
//			value[0] += 10;
			value[0] += 10.56;
			check[1] = 1;
		}
		else if (str[i] == 'c' && check[str[i] - 97] == 0)
		{
//			value[0] += 17;
			value[0] += 23.13;
			check[2] = 1;
		}
		else if (str[i] == 'd' && check[str[i] - 97] == 0)
		{
//			value[0] += 15;
			value[0] += 17.25;
			check[3] = 1;
		}
		else if (str[i] == 'e' && check[str[i] - 97] == 0)
		{
//			value[0] += 26;
			value[0] += 56.88;
			check[4] = 1;
		}
		else if (str[i] == 'f' && check[str[i] - 97] == 0)
		{
//			value[0] += 9;
			value[0] += 9.24;
			check[5] = 1;
		}
		else if (str[i] == 'g' && check[str[i] - 97] == 0)
		{
//			value[0] += 11;
			value[0] += 12.59;
			check[6] = 1;
		}
		else if (str[i] == 'h' && check[str[i] - 97] == 0)
		{
//			value[0] += 12;
			value[0] += 15.31;
			check[7] = 1;
		}
		else if (str[i] == 'i' && check[str[i] - 97] == 0)
		{
//			value[0] += 23;
			value[0] += 38.45;
			check[8] = 1;
		}
		else if (str[i] == 'j' && check[str[i] - 97] == 0)
		{
//			value[0] += 2;
			value[0] += 1.00;
			check[9] = 1;
		}
		else if (str[i] == 'k' && check[str[i] - 97] == 0)
		{
//			value[0] += 6;
			value[0] += 5.97;
			check[10] = 1;
		}
		else if (str[i] == 'l' && check[str[i] - 97] == 0)
		{
//			value[0] += 18;
			value[0] += 27.98;
			check[11] = 1;
		}
		else if (str[i] == 'm' && check[str[i] - 97] == 0)
		{
//			value[0] += 13;
			value[0] += 15.36;
			check[12] = 1;
		}
		else if (str[i] == 'n' && check[str[i] - 97] == 0)
		{
//			value[0] += 20;
			value[0] += 33.92;
			check[13] = 1;
		}
		else if (str[i] == 'o' && check[str[i] - 97] == 0)
		{
//			value[0] += 22;
			value[0] += 36.51;
			check[14] = 1;
		}
		else if (str[i] == 'p' && check[str[i] - 97] == 0)
		{
//			value[0] += 14;
			value[0] += 16.14;
			check[15] = 1;
		}
		else if (str[i] == 'q' && check[str[i] - 97] == 0)
		{
//			value[0] += 1;
			value[0] += 1.00;
			check[16] = 1;
		}
		else if (str[i] == 'r' && check[str[i] - 97] == 0)
		{
//			value[0] += 24;
			value[0] += 38.64;
			check[17] = 1;
		}
		else if (str[i] == 's' && check[str[i] - 97] == 0)
		{
//			value[0] += 19;
			value[0] += 29.23;
			check[18] = 1;
		}
		else if (str[i] == 't' && check[str[i] - 97] == 0)
		{
//			value[0] += 21;
			value[0] += 35.43;
			check[19] = 1;
		}
		else if (str[i] == 'u' && check[str[i] - 97] == 0)
		{
//			value[0] += 16;
			value[0] += 18.51;
			check[20] = 1;
		}
		else if (str[i] == 'v' && check[str[i] - 97] == 0)
		{
//			value[0] += 5;
			value[0] += 5.13;
			check[21] = 1;
		}
		else if (str[i] == 'w' && check[str[i] - 97] == 0)
		{
//			value[0] += 7;
			value[0] += 6.57;
			check[22] = 1;
		}
		else if (str[i] == 'x' && check[str[i] - 97] == 0)
		{
//			value[0] += 4;
			value[0] += 1.48;
			check[23] = 1;
		}
		else if (str[i] == 'y' && check[str[i] - 97] == 0)
		{
//			value[0] += 8;
			value[0] += 9.06;
			check[24] = 1;
		}
		else if (str[i] == 'z' && check[str[i] - 97] == 0)
		{
//			value[0] += 3;
			value[0] += 1.39;
			check[25] = 1;
		}
		i++;
	}
	return (value);
}
/*
E	11.1607%	56.88	M	3.0129%	15.36
A	8.4966%		43.31	H	3.0034%	15.31
R	7.5809%		38.64	G	2.4705%	12.59
I	7.5448%		38.45	B	2.0720%	10.56
O	7.1635%		36.51	F	1.8121%	9.24
T	6.9509%		35.43	Y	1.7779%	9.06
N	6.6544%		33.92	W	1.2899%	6.57
S	5.7351%		29.23	K	1.1016%	5.97
L	5.4893%		27.98	V	1.0074%	5.13
C	4.5388%		23.13	X	0.2902%	1.48
U	3.6308%		18.51	Z	0.2722%	1.39
D	3.3844%		17.25	J	0.1965%	1.00
P	3.1671%		16.14	Q	0.1962%	(1)*/

void	count_values(int loop, t_wordle *data)
{
	int i = 0;
	int x = 0;
	float big;
	char *ptr;

	data->value_arr = (float **)malloc(sizeof(float *) * 2308);
	if (!data->value_arr)
	{
		write(2, "Malloc fail\n", 12);
		exit (1);
	}
	while (data->arr[x] != NULL)
	{
		data->value_arr[x] = get_value(data->arr[x]);
		if (x == 0)
			big = data->value_arr[x][0];
		else if (x > 0 && data->value_arr[x][0] > big)
		{
			big = data->value_arr[x][0];
			ptr = data->arr[x];
		}
//		printf("%s %f\n", data->arr[x], data->value_arr[x][0]);
		x++;
	}
	printf("\nGIVE AS INPUT: %s\n\n", ptr);
}
