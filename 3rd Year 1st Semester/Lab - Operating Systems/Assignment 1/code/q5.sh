#!/bin/bash

read -p 'Enter birthday 1: ' b1
read -p 'Enter birthday 2: ' b2

#b1=19/09/2002
#b2=21/04/2006

day1=${b1:0:2}
month1=${b1:3:2}
year1=${b1:6:4}

day2=${b2:0:2}
month2=${b2:3:2}
year2=${b2:6:4}

date1=$(date -d $month1/$day1/$year1 +%a)
date2=$(date -d $month2/$day2/$year2 +%a)

sec1=$(date -d $month1/$day1/$year1 +%s)
sec2=$(date -d $month2/$day2/$year2 +%s)

sec_cur=$(date +%s)

echo $date1 $date2

if [ $date1 == $date2 ]
then
    echo 'Equal'
else
    echo 'Not equal'
fi

#echo $sec1 $sec2

age1=$(expr $sec_cur - $sec1)
age2=$(expr $sec_cur - $sec2)


age1_min=$(expr $age1 / 60)
age2_min=$(expr $age2 / 60)

age1_hr=$(expr $age1_min / 60)
age2_hr=$(expr $age2_min / 60)

age1_day=$(expr $age1_hr / 24)
age2_day=$(expr $age2_hr / 24)

age1_month=$(expr $age1_day / 30)
age2_month=$(expr $age2_day / 30)

age1_yr=$(expr $age1_month / 12)
age2_yr=$(expr $age2_month / 12)

age1_month_new=$(expr $age1_month - $(expr $age1_yr \* 12))
age2_month_new=$(expr $age2_month - $(expr $age2_yr \* 12))

age1_day_new=$(expr $age1_day - $(expr $age1_month \* 30))
age2_day_new=$(expr $age2_day - $(expr $age2_month \* 30))

echo 'Age 1 = ' $age1_yr ' yr' $age1_month_new ' month' $age1_day_new ' day.'
echo 'Age 2 = ' $age2_yr ' yr' $age2_month_new ' month' $age2_day_new ' day.'
