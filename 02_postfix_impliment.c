#include<stdio.h>
#include<conio.h>
struct stack{
    float arr[10];
    int tos;
};
void push(struct stack *,float);
float pop(struct stack *);
int isoprand(char);
float evaluate(float,float,char);
float solve(char[]);


int main (){
    char postfix[20];
float ans;
printf("enter valid postfix expression");
scanf("%s",postfix);
ans=solve(postfix);
printf("Result=%.2f",ans);
return 0;
}
float solve(char postfix[])
{
    struct stack s;
    int i;
    char ch;
    float op1,op2,res;
    s.tos=-1;
    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isoprand(ch)==1)
        {
            push(&s,ch-48);
        }
        else{
            op2=pop(&s);
            op1=pop(&s);
            res=evaluate(op1,op2,ch);
            push(&s,res);
        }
    }
    res=pop(&s);
    return res;
}
int isoprand(char ch){
    if(ch>='0'&&ch<='9')
    return 1;
    else
      return 0;

}
float evaluate(float op1,float op2,char ch)
{
    switch(ch){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '$': return pow(op1,op2);
        case '%': return fmod(op1,op2);
        default: return 0;
    }
}
void push(struct stack *p,float res)
{
    p->tos=p->tos+1;
    p->arr[p->tos]=res;
   return res;
}
float pop(struct stack *p){
    float x;
    x=p->arr[p->tos];
    p->tos=p->tos-1;
    return x;
    }
