#include "wordle.h"

void	print_best_option(char **array, float **val_arr)
{
	int i;
	float big;
	int index;

	i = 0;
	index = -1;
	big = 0;
	while (i < 2308)
	{
		while (array[i] != NULL && array[i][0] == '\0')
			i++;
		if (array[i] == NULL)
			break ;
		if (val_arr[i][0] > big)
		{
			big = val_arr[i][0];
			index = i;
		}
		i++;
	}
	if (index == -1)
	{
		printf("I don't have any other words to try! I'm sorry!\n");
		exit (1);
	}
	printf("\nTRY INPUT: %s\n\n", array[index]);
}