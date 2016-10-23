
string getHint(string secret, string guess) 
{
	int hash[10] = {0};
	int bulls = 0;
	int cows = 0;
	
	for (int i = 0; i < secret.size(); i++)
	{
		if (secret[i] == guess[i])
		{
			bulls++;
		}
		else
		{
			hash[secret[i] - '0']++;
		}
	}
	
	for (int i = 0; i < secret.size(); i++)
	{
		if ((secret[i] != guess[i]) && (hash[guess[i] - '0'] > 0))
		{
			cows++;
			hash[guess[i] - '0']--;
		}
	}
	
	return to_string(bulls) + "A" + to_string(cows) + "B";
}
