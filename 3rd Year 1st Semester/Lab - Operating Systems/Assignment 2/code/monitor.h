#ifndef monitor_h
#define monitor_h

#define N 7
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N

void initialization();
void test(int i);
void take_chopsticks(int i);
void put_chopsticks(int i);

#endif
