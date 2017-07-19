class LogSystem(object):
    def __init__(self):
        self.storage = {}
    def put(self, id, timestamp):
        yrStr, mnthStr, dayStr, hourStr, minStr, secStr = timestamp.split(':')
        yr = int(yrStr)
        mnth = int(mnthStr)
        day = int(dayStr)
        hour = int(hourStr)
        mint = int(minStr)
        sec = int(secStr)
        if yr not in self.storage:
            self.storage[yr] = {}
        if mnth not in self.storage[yr]:
            self.storage[yr][mnth] = {}
        if day not in self.storage[yr][mnth]:
            self.storage[yr][mnth][day] = {}
        if hour not in self.storage[yr][mnth][day]:
            self.storage[yr][mnth][day][hour] = {}
        if mint not in self.storage[yr][mnth][day][hour]:
            self.storage[yr][mnth][day][hour][mint] = {}
        if sec not in self.storage[yr][mnth][day][hour][mint]:
            self.storage[yr][mnth][day][hour][mint][sec] = []
        self.storage[yr][mnth][day][hour][mint][sec].append(id)

    def rByGated(self, s, e, gated):
            result = []
            syrStr, smnthStr, sdayStr, shourStr, sminStr, ssecStr = s.split(':')
            syr = int(syrStr)
            smnth = int(smnthStr)
            sday = int(sdayStr)
            shour = int(shourStr)
            smin = int(sminStr)
            ssec = int(ssecStr)
            eyrStr, emnthStr, edayStr, ehourStr, eminStr, esecStr = e.split(':')
            eyr = int(eyrStr)
            emnth = int(emnthStr)
            eday = int(edayStr)
            ehour = int(ehourStr)
            emin = int(eminStr)  
            esec = int(esecStr)                  
            res = []
            for key,val in self.storage.items(): #y
                if key >= syr and key<= eyr:
                    for key2,val2 in val.items(): #m
                        if gated<2 or (key2 >= smnth and key2 <= emnth):
                            for key3, val3 in val2.items(): #d
                                if gated <3 or (key3 >= sday and key3 <= eday):
                                    for key4, val4 in val3.items(): #h
                                        if gated<4 or (key4 >= shour and key4 <= ehour):
                                            for key5, val5 in val4.items(): #m
                                                if gated<5 or (key5 >= smin and key5 <= emin):
                                                    for key6, val6 in val5.items(): #s
                                                        if gated <6 or (key6 >= ssec and key6 <= esec):
                                                            for items in val6:
                                                                res.append(items)
            return res

    def retrieve(self, s, e, gra):
        gated = 1
        if gra=='Month':
            gated = 2
        elif gra=='Day':
            gated = 3
        elif gra=='Hour':
            gated = 4
        elif gra=='Minute':
            gated = 5
        elif gra=='Second':
            gated = 6
        return self.rByGated(s,e, gated)


obj = LogSystem()
obj.put(1, "2017:01:01:23:59:59")
obj.put(2, "2017:01:01:22:59:59")
obj.put(3, "2016:01:01:00:00:00")
print(obj.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"))
print(obj.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"))

