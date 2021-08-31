void	arg_split(char *input)
{
	int		begin;
	int		cur;
	int		in_quote;

	begin = 0;
	cur = 0;
	in_quote = 0;
	int		i = 0;
	while (1)
	{
		if (input[cur] == '\"' || input[cur] == '\'')
			in_quote++;
		if (input[cur] == '|' && in_quote % 2 == 0)
		{
			printf("%s\n", strndup(input + begin, cur - begin + 1 - 1));
			printf("%s\n", strndup(input + cur, 1));
			begin = cur + 1;
		}
		else if ((input[cur] == '>' || input[cur] == '<') && in_quote % 2 == 0)
		{
			if (begin != cur)
				printf("%s\n", strndup(input + begin,  cur - begin + 1 - 1));
			begin = ++cur;
			while (((input + cur)[i] != '>' && (input + cur)[i] != '|' & (input + cur)[i] != '<' && (input + cur)[i] != '\0') || in_quote % 2 == 1)
			{
				if ((input + cur)[i] == '\"' || (input + cur)[i] == '\'')
					in_quote++;
				i++;
			}
			printf("%s\n", strndup(input + cur, i));
			begin = cur + i;
			cur = cur + i - 1;
		}
		else if (input[cur] == '\0')
		{
			printf("%s", strndup(input + begin, cur - begin + 1 - 1));
			break;
		}
		cur++;
	}
}
