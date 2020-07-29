#define NUMBER '0'
#define VARIABLE 'v'

int getop(char s[]);
void push(double number);
double pop(void);
void printtop(void);
void clearstack(void);
void swaptop2(void);
void duplicatestack(void);
int getch(void);
void ungetch(int c);