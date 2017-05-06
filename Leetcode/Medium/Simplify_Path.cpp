class Solution {
public:
   std::string simplifyPath(std::string path)
{
	bool hastokens = true;
	std::stack<std::string> stuff;
	while(hastokens)
	{
		int idx = path.find('/');
		if(idx!=std::string::npos)
		{
			std::string nowtok = path.substr(0,idx);
			if(!nowtok.empty())
			{
				if(!nowtok.compare("."))
				{
					//Do nothing 
				}
				else if(!nowtok.compare(".."))
				{
				    if(!stuff.empty())
					    stuff.pop();
				}
				else
				{
					stuff.push(nowtok);
				}
			}
			//	std::cout << nowtok << "\n";
			path = path.substr(idx+1);
		}
		else
		{
			if(!path.empty())
			{
				if(!path.compare("."))
				{
					//Do nothing 
				}
				else if(!path.compare(".."))
				{
				    if(!stuff.empty())
					    stuff.pop();
				}
				else
				{
					stuff.push(path);
				}
			}
			//	std::cout << path << "\n";
			hastokens = false;
		}
	}
	std::stack<std::string> auxstack;
	while(!stuff.empty())
	{
		auxstack.push(stuff.top());
		stuff.pop();
	}
	std::string result = "";
	while(!auxstack.empty())
	{
		std::string x = auxstack.top();
		result += ("/" + x);
		auxstack.pop();
	}
	if(result.empty())
	    result = "/";
	return result;
}
};
