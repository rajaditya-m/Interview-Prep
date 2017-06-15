class Solution:
    def SNAP_JobScheduling(self, fileName):
        jobMap = {}
        contextStack = []
        curJob = None
        startTime = -1
        f = open(fileName, 'r')
        for line in f:
            jobName, startBool, timeStr = line.split(' ')
            time = int(timeStr)
            if jobName not in jobMap:
                jobMap[jobName] = []
            if curJob == jobName:
                if startBool == 'true':
                    contextStack.append(jobName)
                else:
                    if contextStack:
                        nextJob = contextStack.pop()
                        if nextJob != curJob:
                            jobMap[curJob].append([startTime, time])
                            curJob = nextJob
                            startTime = time
                    else:
                        jobMap[curJob].append([startTime, time])
                        curJob = None
                        startTime = -1
            else:
                if curJob:
                    jobMap[curJob].append([startTime, time])
                    contextStack.append(curJob)
                curJob = jobName
                startTime = time
        return jobMap
                

obj = Solution()
file = '/home/rajaditya/Projects/Interview/Interview/Random_Onsites/SNAP_JobScheduling_data.txt'
print(obj.SNAP_JobScheduling(file))