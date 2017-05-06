class Solution {
public:
     std::string fractionToDecimal(int numerator, int denominator) {
	 std::string res = "";
	 long long int nn = (long long int)numerator;
	 long long int den = (long long int)denominator;
	 if(nn<0 && den <0)
	 {
		 nn *= -1;
		 den *= -1;
		}
	 else if(numerator<0 && denominator>0){
		 res.push_back('-');
		 nn *= -1;
		}
	 else if(denominator<0 && numerator>0){
		 den *= -1;
		 res.push_back('-');
		}
	 long long int q = (long long int)nn/(long long int)den;
	 long long int  r = (long long int)nn%(long long int)den;
	 res += std::to_string(q);
	 if(r)
		 res.push_back('.');
	 nn = r;
	 std::unordered_map<int,int> repeatTable;
	 repeatTable.insert(std::pair<int,int>(nn,res.size()));
	 //assume here that den<num
	 if(r){
		
		 while(true){
		 if(nn<den)
			nn *= 10;
		 int quotient = nn/den;
		 int rem = nn%den;
		 res += std::to_string(quotient);
		 if(rem==0){
			 break;
			}
		 auto it = repeatTable.find(rem);
		 if(it!=repeatTable.end())
		 {
			 //process and quit
			 std::size_t dot = it->second;
			 std::string preDot = res.substr(0,dot);
			 std::string postDot = res.substr(dot);
			 res = preDot + std::string("(") + postDot + std::string(")");
			 break;
			}
		 else {
			 repeatTable.insert(std::pair<int,int>(rem,res.size()));
			 nn = rem;
			}
		}
		}
	 return res;
 }
};