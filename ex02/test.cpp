# include <iostream>

std::string check(std::string stroka)
{
	stroka.size();
	if (stroka.size() >= 10)
	{
		stroka.erase(10);
		stroka[9] = '.';
	}
	return (stroka);
} 

int main ()
{
	std :: string stroka;
	std :: cin >> stroka;
	stroka = check (stroka);
	std :: cout << stroka; 	
	return (0);
}