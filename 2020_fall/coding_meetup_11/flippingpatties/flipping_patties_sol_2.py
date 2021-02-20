# Author: Michael Lazeroff
# Solution to Flipping Patties

import sys

n = input()
n = int(n)

my_list = []
workers = 0
for x in range(n):
    my_list.append(input().split())

# this dict will hold individual seconds as keys, and how many actions take place then
sec_dic = dict()

for i in range(len(my_list)):
       takeoff = int(my_list[i][1])
       halftime = int(my_list[i][0])
       put_on = takeoff - halftime - halftime 
       flip = takeoff - halftime

       # Increment the amount of actions that occur at a second
       if put_on in sec_dic.keys():
           sec_dic[put_on] += 1
       else:
           sec_dic[put_on] = 1
       if flip in sec_dic.keys():
           sec_dic[flip] += 1
       else:
           sec_dic[flip] = 1
       if takeoff in sec_dic.keys():
           sec_dic[takeoff] += 1
       else:
           sec_dic[takeoff] = 1
            

for i in sec_dic.keys():
    # For each second, since each worker can handle two things, the amount of workers needed 
    # for that second is going to be the ceiling division by 2
    ceil_div = -(sec_dic[i] // -2)
    # New worker amount if the current second requires more workers than currently have
    if ceil_div > workers:
        workers = ceil_div
    
print(workers)
