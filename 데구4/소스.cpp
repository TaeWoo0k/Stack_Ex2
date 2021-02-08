#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct stackNode
{
	element data;
	struct stackNode *link;

}stackNode;	//스택 노드를 구조체로 선언한다.

stackNode*top;

void push(element item)
{
	stackNode*temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()
{
	element item;
	stackNode* temp = top;

	if (top == NULL)	//top이 null값이라는것은 스택이 비었다는 것이다.
	{
		printf("\n\n Stack is Empty!  \n");
		return 0;
	}

	else	//스택이 비어있는게 아니라면	
	{
		item = temp->data;	//item을 data필드에 넣는다
		top = temp->link;	//temp의 링크필드에 top에 저장되어있는 주소를 저장한다.
		free(temp);		//temp의 데이터를 반환한다.
		return item;
	}
}

element peek()
{
	element item;
	if (top == NULL)
	{
		printf("\n\n Stack is empty ! \n");
		return 0;
	}
	else
	{
		item = top->data;	//노드가 빈것이 아니라면 item을 data필드에 넣고
		return item;	//item을 반환한다.
	}
}

void del()
{
	stackNode*temp;
	if (top == NULL)
	{
		printf("\n\n Stack is Empty ! \n");
	}
	else
	{
		temp = top;
		top = top->link; //top을 이전 노드로 이동한다.
		free(temp);		// 데이터를 반환한다.	
	}
}

void printStack()
{
	stackNode*p = top;
	printf("\n STACK [");
	while (p)
	{//p의 링크필드에 null문자가 있을때는 그노드가 마지막 노드인 것이다. 
		printf("%d", p->data);//저장되어있는 데이터를 출력한다.
		p = p->link;	//다음 노드로 이동한다.
	}
	printf("]");
}

int testPair(char*exp)
{
	char symbol, open_pair;
	int i, length = strlen(exp);//strlen함수는 문자열의 길이를 나타내는 함수.
	top = NULL;

	for (i = 0; i < length; i++)
	{//문자열이 끝날때까지 i를 증가시킨다
		symbol = exp[i];
		switch (symbol)
		{
		case'(':	//(를 입력했을때
		case'[':	//[를 입력했을때
		case'{':	//{를 입력했을때
			push(symbol); break;//(,{.[가 입력되면 그 괄호를 push하고 반복문을 나온다.
		case')':	//)를 입력했을때
		case']':	//]를 입력했을때
		case'}':	//}를 입력했을때
			if (top == NULL)return 0;	//노드가 비어있다면 0을 return한다
			else
			{
				open_pair = pop();	
				if ((open_pair == '('&&symbol != ')') ||
					(open_pair == '['&&symbol != ']') ||
					(open_pair == '{'&&symbol != '}'))
					//열린괄호와 닫힌괄호가 다르면 0을 반환한다.
					return 0;
				else break;
			}
		}		
	}
	if(top == NULL)return 1;
	//반복문이 다 돌았다면 문제가 없는것이기 때문에 1을 반환한다.
	else return 0;	
}

void main()
{
	char*express = "30*4-[{24-5+(3+4)}+1]";//입력할 값 
	printf("%s", express);//입력할 값을 출력한다.
	if (testPair(express) == 1)//1이 반환되었다면 수식이 맞는것임으로 맞다고 출력
		printf("\n\n 수식의 괄호가 맞게 사용되었습니다!");
	else
	{		//아니라면 틀렸다고 출력


		printf("\n\n 수식의 괄호가 틀렸습니다!");
	}
	getchar();
}
/*
element evalPostfix(char *exp)
{
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;
	top = NULL; //top은 처음에 null로 초기화한다.

	for (i = 0; i < length; i++)
	{
		symbol = exp[i];
		if (symbol != '+'&&symbol != '-'&&symbol != '*'&&symbol != '/')
		{//사칙연산중 하나도 없다면
			value = symbol - '0';	
			push(value);	//value를 push한다.
		}
		else
		{
			opr2 = pop();
			opr1 = pop();
			switch (symbol){
			case '+':push(opr1 + opr2); break;	//+가 있다면 opr1과opr2를 더한값을 push한다
			case '-':push(opr1 - opr2); break;	//-가 있다면 opr1과opr2를 뺀값을 push한다
			case '*':push(opr1 * opr2); break;	//*가 있다면 opr1과opr2를 곱한값을 push한다
			case '/':push(opr1 / opr2); break;	//나눗셈이 있다면 opr1과opr2를 나눈값을 push한다
			}
		}
	}
	return pop();
}

void main()
{
	int result;
	char*express = "34+21+*53-32---";
	printf("후위 표기식 : %s", express);

	result = evalPostfix(express);
	printf("\n\n 연산결과 =>%d", result);

	getchar();
}*/