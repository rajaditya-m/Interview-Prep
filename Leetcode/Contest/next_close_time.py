class Solution(object):
    def check_valid(self, m1, m2, s1, s2):
        m = m1+m2
        s = s1+s2
        im = int(m)
        iss = int(s)
        if im>=0 and im<25 and iss>=0 and iss<60:
            return True
        return False

    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        tab = [False]*10
        m,s = time.split(':')
        mins_1 = m[0]
        mins_2 = m[1]
        secs_1 = s[0]
        secs_2 = s[1]
        tab[int(mins_1)] = True
        tab[int(mins_2)] = True
        tab[int(secs_1)] = True
        tab[int(secs_2)] = True
        #change secs
        for i in range(int(secs_1)+1,9):
            if tab[i]:
                n_secs_2 = str(i)
                if self.check_valid(mins_1,mins_2,secs_1,n_secs_2):
                    return "{}{}:{}{}".format(mins_1,mins_2,secs_1,n_secs_2)
        
        

        