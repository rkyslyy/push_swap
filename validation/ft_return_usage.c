#include "../swaplib.h"

int	ft_return_usage(void)
{
	ft_printf("Error\n");
	ft_printf("_________________________________________________________________________________\n");
	ft_printf("Usage: ./push_swap [values] [flags]                                              |\n");
	ft_printf("                      ^^       ^                                                 |\n");
	ft_printf("      Unique values only      -v - to print stacks after every operation         |\n");
	ft_printf("   Range of integer only      -o - to create log file containing performed ops   |\n");
	ft_printf("Digits, '-' and '+' only      -t - to display total amount of operations         |\n");
	ft_printf("                              -h - to highlight last used values and stacks      |\n");
	ft_printf("                              -r - to read instructions from EXISTIGN VALID file |\n");
	ft_printf("_________________________________________________________________________________|\n");
	return (1);
}