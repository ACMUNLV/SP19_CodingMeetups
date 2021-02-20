//#!/usr/bin/python
//#include <iostream>
//#include <cstring>

//using namespace std;

//inf = 99999

import java.util.*;

public class Bin_BobK_RSR {
  public static final int INF = 99999;
  public static boolean isAvailable[];
  public static int nBins, bestCost, nPerOwner[], endCost[][], bestEndCost[][];

//def solve(level):
//    global isAvailable
//    global endCost
//    global bestEndCost
//    global nPerOwner
//    global bestCost

public static void solve(int level) {
  int spaceNeeded, c;

  //  if level == 0:
  //      for owner in xrange(5):
  //          if isAvailable[owner]:
  //              isAvailable[owner] = False
  //              for b in xrange(nBins):
  //                  bestEndCost[0][b] = endCost[owner][b]
  //              solve(1)
  //              isAvailable[owner] = True

  if (level == 0) {
    for (int o=0;o<5;o++) {
      isAvailable[o] = false;
      for (int b=0;b<nBins;b++)
        bestEndCost[0][b] = endCost[o][b];
      solve(1);
      isAvailable[o] = true;
    }
  }

  //  elif level == 5:
  //      for b in xrange(nBins):
  //          if bestEndCost[4][b] < bestCost:
  //              bestCost = bestEndCost[4][b]

  else if (level == 5) {
    for (int b=0;b<nBins;b++)
      if (bestEndCost[4][b] < bestCost)
        bestCost = bestEndCost[4][b];
  }

  //  else:
  //      for owner in xrange(5):
  //          if isAvailable[owner]:
  //              isAvailable[owner] = False
  //              spaceNeeded = 0
  //              for o2 in xrange(5):
  //                  if not isAvailable[o2]:
  //                      spaceNeeded += nPerOwner[o2]
  //              for b in xrange(nBins):
  //                  bestEndCost[level][b] = inf
  //                  if b >= spaceNeeded - 1:
  //                      for b2 in xrange(b-nPerOwner[owner]+1):
  //                          c = bestEndCost[level-1][b2] + endCost[owner][b]
  //                          if c < bestEndCost[level][b]:
  //                              bestEndCost[level][b] = c
  //              solve(level+1)
  //              isAvailable[owner] = True

  else {
    for (int o=0;o<5;o++)
      if (isAvailable[o]) {
        isAvailable[o] = false;
        spaceNeeded = 0;
        for (int o2=0;o2<5;o2++)
          if (!isAvailable[o2])
            spaceNeeded += nPerOwner[o2];
        for (int b=0;b<nBins;b++) {
          bestEndCost[level][b] = INF;
          if (b >= spaceNeeded - 1)
            for (int b2=0;b2<b-nPerOwner[o]+1;b2++) {
              c = bestEndCost[level-1][b2] + endCost[o][b];
              if (c < bestEndCost[level][b])
                bestEndCost[level][b] = c;
            }
        }
        solve(level+1);
        isAvailable[o] = true;
      }
  }
}

//#    print bestEndCost


//owners = ['A','E','I','O','U']

public static void main(String[] args) {
  isAvailable = new boolean[5];
  bestCost = INF;
  nPerOwner = new int[5];
  endCost = new int[5][150];
  bestEndCost = new int[5][150];
  //char bins[], newBins[];
  String bins, newBins;
  //bins = new char[160];
  //newBins = new char[160];
  int nDeletes, d, c, costs[], totalCost[];
  costs = new int[150];
  totalCost = new int[5];

    //bins = list(raw_input())
    //nBins = len(bins)
  Scanner in = new Scanner(System.in);
  bins = in.nextLine();
  //cin >> bins;
  nBins = bins.length();

  //costs = []
  //while len(costs) < nBins:
  //    line = map(int,raw_input().split())
  //    costs += line

  for (int i=0;i<nBins;i++)
    costs[i] = in.nextInt();
    //cin >> costs[i];

  //  nDeletes = int(raw_input())
  //  dList = []
  //  while len(dList) < nDeletes:
  //      line = map(int,raw_input().split())
  //      dList += line
  //  #for i in xrange(nDeletes):
  //  for d in dList:
  //  #    d = int(raw_input())
  //      bins[d-1] = 'X'
  //      costs[d-1] = 0

  nDeletes = in.nextInt();
  //cin >> nDeletes;
  for (int i=0;i<nDeletes;i++) {
    //cin >> d;
    d = in.nextInt();
    bins = bins.substring(0,d-1)+'X'+bins.substring(d);
    costs[d-1] = 0;
  }

  newBins = in.nextLine();
  newBins = in.nextLine();
  //newBins = list(raw_input())
  //cin >> newBins;

  //for b in xrange(nBins):
  //    if bins[b] == 'A':
  //        bins[b] = 0
  //        totalCost[0] += costs[b]
  //        nPerOwner[0] += 1
  //    if bins[b] == 'E':
  //        bins[b] = 1
  //        totalCost[1] += costs[b]
  //        nPerOwner[1] += 1
  //    if bins[b] == 'I':
  //        bins[b] = 2
  //        totalCost[2] += costs[b]
  //        nPerOwner[2] += 1
  //    if bins[b] == 'O':
  //        bins[b] = 3
  //        totalCost[3] += costs[b]
  //        nPerOwner[3] += 1
  //    if bins[b] == 'U':
  //        bins[b] = 4
  //        totalCost[4] += costs[b]
  //        nPerOwner[4] += 1

  // had to create a new array here since String != char[] in Java
  int myBins[] = new int[nBins];
  Arrays.fill(myBins,-1); // or something other than 0-4

  for (int b=0;b<nBins;b++)
    for (int o=0;o<5;o++)
      if (bins.charAt(b) == "AEIOU".charAt(o)) {
        myBins[b] = o;
        totalCost[o] += costs[b];
        nPerOwner[o]++;
      }

  //for b in newBins:
  //    if b == 'A':
  //        nPerOwner[0] += 1
  //    if b == 'E':
  //        nPerOwner[1] += 1
  //    if b == 'I':
  //        nPerOwner[2] += 1
  //    if b == 'O':
  //        nPerOwner[3] += 1
  //    if b == 'U':
  //        nPerOwner[4] += 1

  for (int b=0;b < newBins.length();b++)
    for (int o=0;o<5;o++)
      if (newBins.charAt(b) == "AEIOU".charAt(o))
        nPerOwner[o]++;

  //endCost = []
  //bestEndCost = []

  //for owner in xrange(5):
  //    endCost.append([inf]*nBins)
  //    bestEndCost.append([0]*nBins)
  //    for e in xrange(nBins):
  //        if e >= nPerOwner[owner]-1:
  //            c = totalCost[owner]
  //            for b in xrange(nPerOwner[owner]):
  //                if bins[e-b] == owner:
  //                    c -= costs[e-b]
  //            endCost[owner][e] = c

  for (int o=0;o<5;o++) {
    for (int i=0;i<nBins;i++)
      endCost[o][i] = INF;
    for (int e=0;e<nBins;e++)
      if (e >= nPerOwner[o] - 1) {
        c = totalCost[o];
        for (int b=0;b<nPerOwner[o];b++)
          if (myBins[e-b] == o)
            c -= costs[e-b];
        endCost[o][e] = c;
      }
  }

  //isAvailable = [True]*5
  for (int i=0;i<5;i++)
    isAvailable[i] = true;

  //bestCost = inf
/*
for (int o=0;o<5;o++) {
  for (int b=0;b<nBins;b++)
    cout << endCost[o][b] << ' ';
  cout << endl;
}

for (int i=0;i<5;i++)
  cout << nPerOwner[i] << ' ';
  cout << endl;
*/
  //solve(0)
  solve(0);

  //print bestCost
  //cout << bestCost << endl;
  System.out.println(bestCost);

}

}
