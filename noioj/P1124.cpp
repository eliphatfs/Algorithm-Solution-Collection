#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define OP 1
#define OV 2
using namespace std;

struct node
{
    int type;
    char ov;
    double op;
    node * prev;
    node * next;
    node()
    {
        op = type = ov = 0;
        prev = next = NULL;
    }
};

double calc(string expr)
{
    int len = expr.length();
    node * first = new node();
    node * now = first;
    char buf[16] = "";
    char nbuf[1024] = "";
    string exprin;
    int need;
    node * newnode;
    for (int i=0; i<len; i++)
    {
        char cur = expr[i];
        switch (cur)
        {
            case '(':
                nbuf[0] = '\0';
                need = 1;
                ++i;
                while (true)
                {
                    if (expr[i] == ')') --need;
                    else if (expr[i] == '(') ++need;
                    if (need > 0) sprintf(nbuf, "%s%c", nbuf, expr[i]);
                    else break;
                    ++i;
                }
                newnode = new node();
                newnode->type = OP;
                exprin = nbuf;
                newnode->op = calc(exprin);
                now->next = newnode;
                newnode->prev = now;
                now = newnode;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                if (strlen(buf) > 0)
                {
                    newnode = new node();
                    newnode->type = OP;
                    sscanf(buf, "%lf", &newnode->op);
                    now->next = newnode;
                    newnode->prev = now;
                    now = newnode;
                    buf[0] = '\0';
                }
                
                newnode = new node();
                newnode->type = OV;
                newnode->ov = cur;
                now->next = newnode;
                newnode->prev = now;
                now = newnode;
                break;

            default:
                sprintf(buf, "%s%c", buf, cur);
                break;
        }
    }
    if (strlen(buf) > 0)
    {
        newnode = new node();
        newnode->type = OP;
        sscanf(buf, "%lf", &newnode->op);
        now->next = newnode;
        newnode->prev = now;
        now = newnode;
        buf[0] = '\0';
    }
    
    now = first;
    while (now->next != NULL)
    {
        if (now->type == OV)
        {
            if (now->ov == '*')
            {
                double nop = now->prev->op * now->next->op;
                
                now->type = OP;
                now->op = nop;
                
                if (now->prev->prev != NULL)
                {
                    now->prev->prev->next = now;
                    now->prev = now->prev->prev;
                }
                if (now->next->next != NULL)
                {
                    now->next->next->prev = now;
                    now->next = now->next->next;
                }
            }
            else if (now->ov == '/')
            {
                double nop = now->prev->op / now->next->op;
                
                now->type = OP;
                now->op = nop;
                
                if (now->prev->prev != NULL)
                {
                    now->prev->prev->next = now;
                    now->prev = now->prev->prev;
                }
                if (now->next->next != NULL)
                {
                    now->next->next->prev = now;
                    now->next = now->next->next;
                }
            }
        }
        now = now->next;
    }
    now = first;
    while (now->next != NULL)
    {
        if (now->type == OV)
        {
            if (now->ov == '+')
            {
                double nop = now->prev->op + now->next->op;
                
                now->type = OP;
                now->op = nop;
                
                if (now->prev->prev != NULL)
                {
                    now->prev->prev->next = now;
                    now->prev = now->prev->prev;
                }
                if (now->next->next != NULL)
                {
                    now->next->next->prev = now;
                    now->next = now->next->next;
                }
            }
            else if (now->ov == '-')
            {
                double nop = now->prev->op - now->next->op;
                
                now->type = OP;
                now->op = nop;
                
                if (now->prev->prev != NULL)
                {
                    now->prev->prev->next = now;
                    now->prev = now->prev->prev;
                }
                if (now->next->next != NULL)
                {
                    now->next->next->prev = now;
                    now->next = now->next->next;
                }
            }
        }
        now = now->next;
    }
    return first->next->op;
}

int main()
{
    string input;
    cin>>input;
    printf("%.2lf", calc(input));
    //cin.get(),cin.get();
    return 0;
}
