#!/usr/bin/python

def solve(level):
    global isAvailable
    global endCost
    global bestEndCost
    global nPerOwner
    global bestCost

    if level == 0:
        for owner in xrange(5):
            if isAvailable[owner]:
                isAvailable[owner] = False
                for b in xrange(nBins):
                    bestEndCost[0][b] = endCost[owner][b]
                solve(1)
                isAvailable[owner] = True
    elif level == 5:
        for b in xrange(nBins):
            if bestEndCost[4][b] < bestCost:
                bestCost = bestEndCost[4][b]
    else:
        for owner in xrange(5):
            if isAvailable[owner]:
                isAvailable[owner] = False
                spaceNeeded = 0
                for o2 in xrange(5):
                    if not isAvailable[o2]:
                        spaceNeeded += nPerOwner[o2]
                for b in xrange(nBins):
                    bestEndCost[level][b] = inf
                    if b >= spaceNeeded - 1:
                        for b2 in xrange(b-nPerOwner[owner]+1):
                            c = bestEndCost[level-1][b2] + endCost[owner][b]
                            if c < bestEndCost[level][b]:
                                bestEndCost[level][b] = c
                solve(level+1)
                isAvailable[owner] = True

#    print bestEndCost

owners = ['A','E','I','O','U']

inf = 99999

bins = list(raw_input())
nBins = len(bins)

#costs = []
#while len(costs) < nBins:
#    line = map(int,raw_input().split())
#    costs += line
costs = map(int,raw_input().split())
#nDeletes = int(raw_input())
#dList = []
#while len(dList) < nDeletes:
#    line = map(int,raw_input().split())
#    dList += line
#for i in xrange(nDeletes):
dList = map(int,raw_input().split())
for d in dList[1:]:
#    d = int(raw_input())
    bins[d-1] = 'X'
    costs[d-1] = 0

newBins = list(raw_input())

#print bins
#print costs
#print newBins

totalCost = [0]*5
nPerOwner = [0]*5

for b in xrange(nBins):
    if bins[b] == 'A':
        bins[b] = 0
        totalCost[0] += costs[b]
        nPerOwner[0] += 1
    if bins[b] == 'E':
        bins[b] = 1
        totalCost[1] += costs[b]
        nPerOwner[1] += 1
    if bins[b] == 'I':
        bins[b] = 2
        totalCost[2] += costs[b]
        nPerOwner[2] += 1
    if bins[b] == 'O':
        bins[b] = 3
        totalCost[3] += costs[b]
        nPerOwner[3] += 1
    if bins[b] == 'U':
        bins[b] = 4
        totalCost[4] += costs[b]
        nPerOwner[4] += 1

for b in newBins:
    if b == 'A':
        nPerOwner[0] += 1
    if b == 'E':
        nPerOwner[1] += 1
    if b == 'I':
        nPerOwner[2] += 1
    if b == 'O':
        nPerOwner[3] += 1
    if b == 'U':
        nPerOwner[4] += 1

#print totalCost
#print nPerOwner

endCost = []
bestEndCost = []

for owner in xrange(5):
    endCost.append([inf]*nBins)
    bestEndCost.append([0]*nBins)
    for e in xrange(nBins):
        if e >= nPerOwner[owner]-1:
            c = totalCost[owner]
            for b in xrange(nPerOwner[owner]):
                if bins[e-b] == owner:
                    c -= costs[e-b]
            endCost[owner][e] = c

#print endCost

isAvailable = [True]*5
bestCost = inf

solve(0)

print bestCost
