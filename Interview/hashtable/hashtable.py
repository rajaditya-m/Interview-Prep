class X_Hashtable:
    def __init__(self):
        self._i = 16
        self._mask = ~(~0 << self._i)
        self.compute_table_size()
        self._total_elems = 0
        self._load_factor = 0
        self._table = [[None,None,None] for _ in range(self._table_size)] #(hash, key, value)

    def compute_table_size(self):
        self._table_size = 2 ** self._i

    def hash_function(self, item):
        return item & self._mask 

    def increment_and_update_stats(self):
        self._total_elems += 1
        self._load_factor = float(self._total_elems) / float(self._table_size)
        if self._load_factor > 0.66:
            print('Rehashing the table since load factor has exceeded the limit')

    def insert(self, key, value):
        original_hash_value = self.hash_function(key)
        j = original_hash_value
        insertion_success = False
        stat_num_probes = 0
        while not insertion_success:
            if self._table[j][0] == None:
                self._table[j][0] = original_hash_value, 
                self._table[table_idx][1] = key
                self._table[table_idx][2] = value
                insertion_success = True
            elif self._table[table_idx][0] == original_hash_value and self._table[table_idx][1] == key:
                insertion_success = True
                self._table[table_idx][2] = value
            else:
                stat_num_probes += 1
                j = (5 * j + 1)
        if stat_num_probes>2:
            print('Inserted {} into table with {} probes'.format(key,stat_num_probes))
        self.increment_and_update_stats()
    
    def search(self, key):
        original_hash_value = self.hash_function(key)
        j = original_hash_value
        search_success = False
        value = None
        stat_num_probes = 0
        while not search_success:
            table_idx = self.get_table_index(j)
            if self._table[table_idx][0] == None:
                search_success = False
            elif self._table[table_idx][0] == original_hash_value and self._table[table_idx][1] == key:
                search_success = True
                value = self._table[table_idx][2]
            else:
                stat_num_probes += 1
                j = (5 * j + 1)   
        return [search_success, value]

htable = X_Hashtable()

import random

nos_inserts = 10000
limit = 20000
vset = set()
vlist = []
for i in range(nos_inserts):
    key = random.randint(1,limit)
    vset.add(key)
    vlist.append(key)
    htable.insert(key,None)    
print('I COM')
nos_searches = 1000
for i in range(nos_searches):
    pos_or_neg = random.random()
    if pos_or_neg<=0.5:
        #positive case
        idx = random.randint(0,nos_inserts-1)
        key_to_search = vlist[idx]
        succ, _ = htable.search(key_to_search)
        if not succ:
            print('SEARCH FAILED - ITEM EXPECTED TO BE PRESENT NOT FOUND')
    else:
        invalid_key_found = False
        invalid_key = None
        while not invalid_key_found:
            rand_num = random.randint(1,limit)
            if rand_num not in vset:
                invalid_key = rand_num
                invalid_key_found = True
        
        succ, _ = htable.search(invalid_key)
        if succ:
            print('SEARCH FAILED - ITEM NOT EXPECTED TO BE PRESENT FOUND')