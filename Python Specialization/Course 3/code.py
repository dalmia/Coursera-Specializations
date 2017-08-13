import re
filename='test.txt'
inp=open(filename)
nums=list()
for line in inp:
    line=line.rstrip()
    this_nums=re.findall('[0-9]+',line)
    if(len(this_nums)>0):
        for i in this_nums:
            nums.append(i)
sum=0
for i in nums:
    sum+=int(i)

print(sum)
