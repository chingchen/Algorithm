/*
	For  "."  "*"  only 
*/

bool Match(const char *text, const char *regexp) 
{
	if( *regexp == '\0')
		return true;
	if(*(regexp+1) == '*')
	{
		do{
			if(Match(text,regexp+2))
				return true;
		}while (*text !='\0' && (*regexp == *text++ || *regexp == '.' ));
	}
	if( *text != '\0' && ( *regexp == *text || *regexp == '.'))
		return Match(text+1 , regexp+1);
	return false;
}

bool MatchPartial(const char* text , const char * regexp)
{
	do
	{
		if(Match( text, regexp))
			return true;
	}while( *text++ !='\0');

	return false;
}

int main()
{
	freopen("c:\\test\\in.txt","r",stdin);

	string txt,reg;
	while( cin >> txt >> reg)
	{
		cout << MatchPartial( txt.c_str(),reg.c_str()) <<endl;
	}
}