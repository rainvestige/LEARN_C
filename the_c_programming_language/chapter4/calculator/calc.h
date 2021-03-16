#define NUMBER '0'
#define FUNCTION '1'

int getch(void);
void ungetch(int);

void push(double);
double pop(void);
int getop(char []);
void print_stack_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);
int proc_math_func(char []);

void store_variables(void);
void fetch_variables(int var);
void clear_memory(void);
