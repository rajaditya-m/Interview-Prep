#ifndef __GENERAL_BST_H_
#define __GENERAL_BST_H_

namespace General 
{
	template<class T>
	class BST: public TreeNode
	{
		BST* search(const T &key)
		{
			if(root)
			{
				if(key<data)
				{
					return search()
				}
			}
			return NULL;
		}
	};
}


#endif