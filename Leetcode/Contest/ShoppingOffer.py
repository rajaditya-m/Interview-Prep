'''
638. Shopping Offers My SubmissionsBack to Contest
User Accepted: 72
User Tried: 152
Total Accepted: 73
Total Submissions: 317
Difficulty: Medium
In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

Example 1:
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation: 
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation: 
The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
'''
def bestPrice(price, offer, needs):
    n_items = len(price)
    n_offers = len(offer)
    offers_by_item = [[] for i in range(0, n_items)]
    for i in range(0,n_items):
        for j in range(0, n_offers):
            offers_by_item[i].append((offer[j][i],j))
    sorted_offers = []
    for i in range(0, n_items):
        sorted_offers.append(sorted(offers_by_item[i],key=lambda tup:tup[0], reverse=True))
    #Now lets try to greedily get offers
    for i in range(0, n_items):
        print('Trying on item {}'.format(i))
        cur_offer = 0
        total_need = needs[i]
        use_offer = total_need/sorted_offers[i][cur_offer][0]
        if use_offer==0:
            cur_offer += 1
        else:
            print('Using Offer {}'.format(cur_offer))
            

    print(sorted_offers)

price = [2,5]
offers = [[3,0,5],[1,2,10]]
needs = [3,2]

bestPrice(price, offers, needs)