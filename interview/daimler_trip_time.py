
# trip time

# Enter your code here. Read input from STDIN. Print output to STDOUT

headLine = raw_input()
# print headLine
d_stamp = {}
d_duration = {}
d_count = {}
while True:
    inp = raw_input()
    if inp != "/n":
        row = inp.split(";")
        vin = row[0]
        stamp = long(row[1])
        #state = row[2]
        print row
        if vin not in d_stamp:
            d_stamp[vin] = stamp
            d_duration[vin] = 0
            d_count[vin] = 0
            continue
        if stamp <= d_stamp[vin]:
            continue
        if d_stamp[vin] == 0:
            d_stamp[vin] = stamp
        else:
            d_duration[vin] = stamp - d_duration[vin]
            d_stamp[vin] = 0
            d_count[vin] += 1     

    else:
        #print "here"
        break
arr =[]
for key in d_duration:
    array.apend(key, d_duration[key]/d_count[key])
array.sort()
print array 