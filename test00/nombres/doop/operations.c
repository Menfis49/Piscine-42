int	add(int a, int b)
{
	return (a + b);
}
int	sous(int a, int b)
{
	return (a - b);
}
int	mult(int a, int b)
{
	return (a * b);
}
int	ftdiv(int a, int b)
{
	return (a / b);
}
int	mod(int a, int b)
{
	return (a % b);
}
int	ft_atoi(char *str)
{
	int i;
	int sign = 1;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			sign *= (-1);
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
	}
	return (sign * result);
}
