class Solution {
public:
    std::vector<int> findEvalRes(std::vector<int> num, std::vector<char> operand)
{
	std::vector<int> res;
	if (operand.size() == 0 && num.size() == 1)
	{
		res.push_back(num[0]);
	}
	else
	{
		int size = num.size();
		for (int i = 1; i < size; i++)
		{
			std::vector<int> div1(i);
			std::vector<int> div2(size - i);
			std::vector<char> opdiv1(i - 1);
			std::vector<char> opdiv2(size - i - 1);
			std::copy(num.begin(), num.begin() + i, div1.begin());
			std::copy(num.begin() + i, num.end(), div2.begin());
			std::copy(operand.begin(), operand.begin() + (i - 1), opdiv1.begin());
			std::copy(operand.begin() + i, operand.end(), opdiv2.begin());

			//recursion calls
			std::vector<int> r1 = findEvalRes(div1, opdiv1);
			std::vector<int> r2 = findEvalRes(div2, opdiv2);

			char op = operand[i - 1];
			for (int j = 0; j < r1.size(); j++)
			{
				int lhs = r1[j];
				for (int k = 0; k < r2.size(); k++)
				{
					int rhs = r2[k];
					if (op == '+')
						res.push_back(lhs + rhs);
					else if (op == '-')
						res.push_back(lhs - rhs);
					else
						res.push_back(lhs*rhs);
				}
			}
		}
	}
	return res;
}

std::vector<int> diffWaysToCompute(std::string input)
{
	std::vector<int> n;
	std::vector<char> o;
	char *dup = strdup(input.c_str());
	char *p = strtok(dup, "*+-");
	while (p) {
		int num = atoi(p);
		n.push_back(num);
		p = strtok(NULL, "*+-");
	}
	for (int i = 0; i < input.size();i++)
	{
		if (input[i] == '*' || input[i] == '+' || input[i] == '-')
		{
			o.push_back(input[i]);
		}
	}
	return findEvalRes(n, o);
}

};