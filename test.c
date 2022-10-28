#include <stdio.h>
#include "incl/minishell.h"

enum fruits {
	APPLE = 0,
	MANGO,
	ORANGE,
	BANANA,
	MAX_FRUITS,
};



//static const char * const fruit_names[] = {
//		[APPLE] = "Apple",
//		[MANGO] = "Mango",
//		[ORANGE] = "Orange",
//		[BANANA] = "Banana"
//};

void	ft_add_front(struct s_env **head, char *str)
{
	//add a node at the beginning of the list
	struct s_env	*new;

	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_front: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_data(new, str);
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
}

struct	s_test
{
	const char	**tokens;
	int				val;
	struct s_cmd	*next;
	struct s_cmd	*prev;
};

int main(void)
{
	int i = 0;
	struct s_test	*env_head = NULL;

	ft_add_front(head, );

	printf("The name of fruit is %s\n", fruit_names[APPLE]);
	printf("The name of fruit is %s\n", fruit_names[BANANA]);
	printf("The name of fruit is %s\n", fruit_names[MANGO]);

	/*  Using for loop */
	printf("\nUsing loop to retrieve strings\n\n");
	for(i =  0;  i < MAX_FRUITS; i++)
		printf("The name of fruit is %s\n", fruit_names[i]);

	return 0;
}