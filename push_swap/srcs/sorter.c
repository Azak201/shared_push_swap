
#include <push_swap.h>

static void get_index(t_dlist **stack_a);
static void radix_sort(t_dlist **stack_a, t_dlist **stack_b, int size);
static int get_max_bit(int size);

/*this funciton count the inputs and send the list to defferent sorting function depend on its size
 if more than 5 inputs the list will be sent to radix sort otherwise it will sent to deferent funtion
 after sorting it will free the linked list then return 0 to inserter then the inserter will return 0
 which means that every thing goes well.*/
int sorter(t_dlist *stack_a)
{
	t_dlist *stack_b;
	int size;

	stack_b = NULL;
	get_index(&stack_a);
	size = ft_dlstsize(stack_a);
	if (size == 0 || size == 1)
		;
	else if (is_sorted(stack_a) == 0)
		;
	else if (size == 2)
		handle2(&stack_a, 1);
	else if (size == 3)
		handle3(&stack_a);
	else if (size == 4)
		handle4(&stack_a, &stack_b);
	else if (size == 5)
		handle5(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b, size);
	ft_dlstclear(&stack_a, NULL);
	return (0);
}

/*هاد الي بيجيب الاندكس الي متوقع زي ما شرحت على الورق لانه راديكس بتتعاملش مع السالب*/
static void get_index(t_dlist **stack_a)
{
	t_dlist *tmp;
	t_dlist *hold;
	int counter;

	hold = *stack_a;
	while (hold)
	{
		counter = 0;
		tmp = *stack_a;
		while (tmp)
		{
			if ((hold->content) > (tmp->content))
				counter++;
			tmp = tmp->next;
		}
		hold->index = counter;
		hold = hold->next;
	}
}
/*this is the radix sort funciton that use the bitwise operator to check on bits if it 0 or 1*/ 
static void radix_sort(t_dlist **stack_a, t_dlist **stack_b, int size)
{
	int i;
	int j;
	int bits;
	t_dlist *tmp;

	i = 0;
	bits = get_max_bit(size);
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *stack_a;
			if ((((tmp->index) >> i) & 1) == 1)
				rotate_a(&(*stack_a));
			else
				push_b(&(*stack_a), &(*stack_b));
		}
		while (*(stack_b))
			push_a(&(*stack_a), &(*stack_b));
		i++;
	}
}
/*هاد الفنكشن بيجيب اكبر اندكس عندي بالليست وبيعد الرقم تاعه كم بيت فيه 
مثال الاندكس 5 بالباينري 101 يعني 3 بتات فيه وهيك
اقرائي عن ال 
bitwise operator (>>) */ 
static int get_max_bit(int size)
{
	int i;

	i = 0;
	while ((size >> i) != 0)
		i++;
	return (i);
}
