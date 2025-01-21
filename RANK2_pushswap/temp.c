#include "push_swap.h"

// int is_valid_number(char *str) //
// {
//     int i;
	
// 	i = 0;
//     while (str[i] == ' ' || str[i] == '\t')
//         i++;
//     if (str[i] == '+' || str[i] == '-')
//         i++;
//     if (!str[i])
//         return 0;
//     while (str[i])
//     {
//         if (str[i] < '0' || str[i] > '9')
//             return 0;
//         i++;
//     }
//     return (1);
// }

// int main()
// {
    
    
//     printf("%d\n", is_valid_number("1234a"));
// }


int is_integer(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j + 1] != '\0')
            j++;
        while (av[i][j])
        {
            if (!ft_is_digit(av[i][j]))
			{
				printf("Error\n");
				return (0);
			} 
            j++;
        }
        i++;
    }
    return (1);
}

int main()
{
    
}