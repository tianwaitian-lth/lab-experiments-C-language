//计算器-栈实现
#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
typedef  int  DataType;  
enum  symbol {NUM, OP, EQ,OTHER};	//符号类型
enum  oper {EPT,ADD, MIN, MUL, DIV,  LEFT, RIGHT };		//运算类型
int Priority[] = {-1,0,0,1,1,2,2};
union sym {
    DataType num;
    enum oper op;
} ;		//符号值 
DataType Num_stack[MAXSIZE];	//数据栈
enum oper Op_stack[MAXSIZE];	//符号栈
int Ntop=-1;	//数据栈顶指示器，初始为空栈
int Otop=-1;	//运算符栈顶指示器，初始为空栈
enum symbol getSym( union sym *item);	//从标准输入中获取一个符号（数据、运算符及等号等），并返回符号类型
void operate(enum oper op );	//操作运算符，弹出比当前运算符优先级高的进行计算，并将其入栈
void compute(enum oper op );	//进行实际计算
void pushNum(DataType num);
DataType popNum();
void pushOp(enum oper op);
enum oper  popOp();
enum oper  topOp();

int main()
{
    union sym item;
    enum symbol s;
    while( (s = getSym(&item)) != EQ) {
        if(s == NUM)  
                pushNum(item.num);
        else if(s == OP)
                operate(item.op);
        else {
            printf("Error in the expression!\n");
            return 1;
		}
    }
	while(Otop >=0)	//将栈中运算符弹出进行计算
		compute(popOp());
    if(Ntop == 0)	//输出计算结果
        printf("%d\n", popNum());
    else
        printf("Error in the expression!\n");
    return 0;
}

enum symbol getSym( union sym *item)
{
    int  c, n;
    while((c = getchar()) != '=') {
        if(c >= '0' && c <= '9'){
            for(n = 0; c >= '0' && c <= '9'; c= getchar())
                n = n*10 + c-'0'; 
            ungetc(c, stdin);
            item->num = n;
            return NUM;
        } 
        else 
            switch(c)  {
                case '+': item->op = ADD; return OP;
                case '-': item->op = MIN; return OP;
                case '*': item->op = MUL; return OP;
                case '/': item->op = DIV; return OP;
                case '(': item->op = LEFT; return OP;
                case ')': item->op = RIGHT; return OP;
                case ' ': case '\t': case '\n': break;
                default: return OTHER;
            }          
    }
    return EQ;
}

void operate(enum oper op )
{
    enum oper t;
    if(op != RIGHT){ //弹出比当前符号优先级高的进行计算，并将当前符号进栈
        while(Priority[op] <= Priority[topOp()] && topOp() != LEFT)
            compute(popOp());
        pushOp(op);
    }
    else //当前符号是右括号，将栈中左括号前的所有运算符出栈进行计算，并弹出左括号
        while((t = popOp()) != LEFT)
            compute(t);
}

void compute(enum oper op )
{
    DataType  tmp;
    switch(op) {
        case ADD:
            pushNum(popNum() + popNum()); break;
        case MIN: 
            tmp = popNum();
            pushNum(popNum() - tmp); break;
        case  MUL: 
            pushNum(popNum() * popNum()); break;
        case DIV: 
            tmp = popNum();
            pushNum(popNum() / tmp); break;
    }
} 

void pushNum(DataType num)
{
    if(Ntop == MAXSIZE-1) {
        printf("Data stack is full!\n");
        exit(1);
    }
    Num_stack[++Ntop] = num;
}

DataType popNum()
{
    if(Ntop == -1) {
        printf("Error in the expression!\n");
        exit(1);
    }
    return Num_stack[Ntop--] ;
}

void pushOp(enum oper op)
{
    if(Ntop == MAXSIZE-1) {
        printf("Operator stack is full!\n");
        exit(1);
    }
    Op_stack[++Otop] = op;
}

enum oper  popOp()
{
    if(Otop != -1){ 
        return Op_stack[Otop--] ; 
    } 
    return EPT;
}

enum oper  topOp()
{
    return Op_stack[Otop];
}


