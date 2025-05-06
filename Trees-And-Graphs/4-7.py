from collections import defaultdict

projs = ["a", "b", "c", "d", "e", "f"]

deps = [["a", "d"], ["f", "b"], ["b", "d"], ["f", "a"], ["d", "c"]]

adjDic = {}

for i in projs:
        adjDic[i] = []
    
for i in deps:
    adjDic[i[1]].append(i[0])

visited = []


def calculateBuildOrder(node):
    visited.append(node)


    for i in adjDic[node]:
        if(i not in visited):
            calculateBuildOrder(i)



    
        


calculateBuildOrder("a")
print(visited)


