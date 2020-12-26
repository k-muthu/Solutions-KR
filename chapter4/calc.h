#define NUMBER '0'	/* signal that a number was found */
#define FUNCTION '1'	/* signal that a math library function was found */
#define VARIABLE '2'	/* signal that a variable is found */
#define PRINT 26	/* variable that holds the value of whatever is printed */

double myatof(char []);
void push(double);
double pop(void);
int mygetop(char []);
int getch(void);
void ungetch(int);
