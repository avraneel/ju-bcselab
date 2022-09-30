coupon = {
            'MONDAY'    : 2.5,
            'TUESDAY'   : 3.5,
            'WEDNESDAY' : 4.5,
            'THURSDAY'  : 5.5,
            'FRIDAY'    : 3.2,
            'SATURDAY'  : 12.1,
            'SUNDAY'    : 13,
}

print(coupon)

day = input("Enter day = ")
day = day.upper()
for i in coupon:
    if(i == day):
        print(i, coupon[i], sep = ' = ')