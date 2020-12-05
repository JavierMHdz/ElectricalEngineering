
done = False
all_nums = []
while not done:
   text = raw_input("Enter an int (1 per line) or a -1 to quit ")
   num = int(text)
   
   if num == -1:
      done = True
   else:
      all_nums.append(num)

print "Sum is " + str(sum(all_nums))
print "Min is " + str(min(all_nums))
print "Max is " + str(max(all_nums))
min_num = min(all_nums)
max_num  = max(all_nums)

all_nums.remove(min_num)
all_nums.remove(max_num)
all_nums.sort()
print str(all_nums)
