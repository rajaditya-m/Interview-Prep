#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <iterator>
#include <cstring>
#include <algorithm>

bool populateCorrespondenceTable(char cipher2dict[256],char dict2cipher[256],std::string cipher,std::string dict)
{
	for (unsigned i=0; i<cipher.length(); ++i)
  	{
    	if(cipher2dict[cipher.at(i)]=='A' && dict2cipher[dict.at(i)]=='A')
    	{
    		cipher2dict[cipher.at(i)] = dict.at(i);
    		dict2cipher[dict.at(i)] = cipher.at(i);
    	}
    	else if(cipher2dict[cipher.at(i)]!=dict.at(i))
    		return false;
  	}
  	return true;
}

void fillWithNeg(char x[256])
{
	for(int i=0;i<256;i++)
		x[i] = 'A';
}

bool backTrack(std::multimap<int,std::string> &table,char cipher2dict[256],char dict2cipher[256],std::vector<std::string> &tokens,std::vector<std::string> &answer)
{
	if(tokens.empty())
		return true;

	std::string firstToken = tokens.front();
	int firstTokLen = firstToken.length();
	std::vector<std::string> copytokenvec(tokens);
	copytokenvec.erase(copytokenvec.begin());

	//Build a new correspondecne table
	std::pair <std::multimap<int,std::string>::iterator, std::multimap<int,std::string>::iterator> ret;
	std::multimap<int,std::string>::iterator loopIt;
	ret = table.equal_range(firstTokLen);

	bool result = false;

	for(loopIt=ret.first;loopIt!=ret.second;loopIt++)
	{
		char newCors[256];
		char newCors2[256];
		memcpy(newCors,cipher2dict,256*sizeof(char));
		memcpy(newCors2,dict2cipher,256*sizeof(char));
		bool goAhead = populateCorrespondenceTable(newCors,newCors2,firstToken,loopIt->second);
		if(goAhead)
		{
				result = backTrack(table,newCors,newCors2,copytokenvec,answer);
				if(result)
				{	
					answer.push_back(loopIt->second);
					break;
				}
		}
		
	}
	return result;
}

int main()
{
	std::string line;
	std::multimap<int,std::string> table;
	char correspondence[256];
	memset(correspondence,0,256*sizeof(char));
	char pMode = 'U';
	while(getline(std::cin,line))
	{
		if(!line.compare("//dict"))
		{
			pMode = 'D';
			continue;
		}
		else if(!line.compare("//secret"))
		{
			pMode = 'C';
			continue;
		}
		if(pMode=='D')
		{
			// std::cout << "Added to dictionart : " << line << "\n";
			int len = line.length();
			table.insert(std::pair<int,std::string>(len,line));
		}
		else if(pMode == 'C')
		{
			std::vector<std::string> tokens;
			std::istringstream iss(line);
			copy(std::istream_iterator<std::string>(iss),std::istream_iterator<std::string>(),std::back_inserter<std::vector<std::string> >(tokens));
			
			char initCTab[256];
			fillWithNeg(initCTab);
			char initCTab2[256];
			fillWithNeg(initCTab2);
			// memset(initCTab,0,256*sizeof(char));
			std::vector<std::string> answer;
			backTrack(table,initCTab,initCTab2,tokens,answer);
			reverse(answer.begin(),answer.end());

			std::vector<std::string>::iterator itt;
			std::cout << line << " = " ;
			for(itt=answer.begin();itt!=answer.end();itt++)
				std::cout << *itt << " ";
			std::cout << "\n";
			
		}	
	}
	return 0;
}