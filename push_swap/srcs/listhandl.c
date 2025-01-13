#include <push_swap.h>

static int clear(t_dlist **stack);
/*this function start with checking how many argc he have if it was 1 
thats mean there is no argument passed to the program so it will exit 
if 2 that mean the user send all the inputs in one string like ./push_swap "1 3 5 0 ..."
if more than 2 that mean the user send the inputs seperated like ./push_swap 1 4 6 0.
so if argc 2 we use ft_split to create the 2d array of inputs if it was more we will
create the array manually .
in case of manual creation the (argv[0]=./push_swap ) so we dont need it that why we do 
tmp[i-1] = argv[i] and the i start from 1 so we can ignore the argv[0];
*/
char **spliter(int arc, char **arv)
{
	char **tmp;
	int i;

	if (arc <= 1)
		ft_exit(0, NULL);
	else if (arc == 2)
		tmp = ft_split(arv[1], ' ');
	else
	{
		i = 0;
		tmp = (char **)malloc(sizeof(char *) * arc);
		if (!tmp)
			ft_exit(1, NULL);
		while (++i < arc)
		{
			tmp[i - 1] = ft_strdup(arv[i]);
			if (!tmp[i - 1])
				ft_exit(2, tmp);
		}
		tmp[i - 1] = NULL;
	}
	if (!tmp)
		ft_exit(1, NULL);
	return (tmp);
}

/*this function work as follow at first it will check if not null then 
it will check the inputs if it was just number like this 83 2 ... 
inputs like this will rejected 9878j7 8874fs ++7 ... all these will rejected
then ft_is_in_bound will check that the numbers are with int_max and int_min reange
then ft_is_uniqenum will check if the number is duplicat in the inputs or not
those 3 functions you can find them in libft/srcs/ .
*/
void handler(char **inputs)
{
	int i;

	i = 0;
	if(inputs[0]==NULL)
		ft_exit(2,inputs);
	while (inputs[i])
	{
		if ((ft_is_numric(inputs[i])))
			ft_exit(2, inputs);
		i++;
	}
	if ((ft_is_in_bound(inputs)))
		ft_exit(2, inputs);
	if ((ft_is_uniquenum(inputs)))
		ft_exit(2, inputs);
}

/*this function have flages to do as follow 
if flag = 0 means no argument passed to program so just exit without print message.
if flag = 1 means there is error happened before create the 2d array so exit with 
printing error message but there is nothing to free .
if flag =2 mean free the passed array and print error message then exit .
if flag =3 mean free the passed array and exit sucsessfully without error message
"mean the program ended normally".
*/
void ft_exit(int flag, char **str)
{
	int i;

	i = 0;
	if (flag == 1 || flag == 0)
	{
		if (flag == 1)
			ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
	{
		if (str)
		{
			while (str[i])
				free(str[i++]);
			free(str);
		}
		if (flag == 2)
			ft_putstr_fd("Error\n", 2);
		if (flag == 3)
			exit(0);
		exit(1);
	}
}

/*inserter will create linked list from the inputs of 2d array but sence they
are sorted as string we use atol (same as atoi but return long insted of int)(you can use atoi its the same result)
to convert them and connect them to each other if any error happen inserter will clear the created list then return 1
otherwise the inserter will send the linked list to sorter function .*/
int inserter(char **inputs)
{
	int i;
	int num;
	t_dlist *stack;
	t_dlist *item;

	i = 0;
	if (!inputs)
		return (1);
	num = ft_atol(inputs[i++]);
	stack = ft_dlstnew(num);
	if (!stack)
		return (1);
	while (inputs[i])
	{
		num = ft_atol(inputs[i]);
		item = ft_dlstnew(num);
		if (!item)
			return (clear(&stack));
		ft_dlstadd_back(&stack, item);
		i++;
	}
	sorter(stack);
	return (0);
}

/*just clearing the created linked list for saving lines*/
static int clear(t_dlist **stack)
{
	ft_dlstclear(&(*stack), NULL);
	return (1);
}
