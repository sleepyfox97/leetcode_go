int	checkSubstring(char *s){
	char ascii[256] = {};
	int i = 0;

	while (ascii[(int)(s[i])] == 0 && s[i] != '\0'){
		ascii[(int)(s[i])] = 1;
		i++;
	}
	return (i);
}


int	lengthOfLongestSubstring(char * s){
	int tmp;
	int i = 0;
	int re = 0;

	if (s[i] == '\0')
		return (0);
	while(s[i])
	{
		tmp = checkSubstring(&s[i]);
		if (re < tmp)
			re = tmp;
	i++;
	}
	return (re);
}
