class Solution {
public:
 bool canWinNim(int n)
{
	int x = n%4;
	if(!x)
		return false;
	return true;
}
};