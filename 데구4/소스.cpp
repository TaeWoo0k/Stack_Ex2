#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct stackNode
{
	element data;
	struct stackNode *link;

}stackNode;	//���� ��带 ����ü�� �����Ѵ�.

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

	if (top == NULL)	//top�� null���̶�°��� ������ ����ٴ� ���̴�.
	{
		printf("\n\n Stack is Empty!  \n");
		return 0;
	}

	else	//������ ����ִ°� �ƴ϶��	
	{
		item = temp->data;	//item�� data�ʵ忡 �ִ´�
		top = temp->link;	//temp�� ��ũ�ʵ忡 top�� ����Ǿ��ִ� �ּҸ� �����Ѵ�.
		free(temp);		//temp�� �����͸� ��ȯ�Ѵ�.
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
		item = top->data;	//��尡 ����� �ƴ϶�� item�� data�ʵ忡 �ְ�
		return item;	//item�� ��ȯ�Ѵ�.
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
		top = top->link; //top�� ���� ���� �̵��Ѵ�.
		free(temp);		// �����͸� ��ȯ�Ѵ�.	
	}
}

void printStack()
{
	stackNode*p = top;
	printf("\n STACK [");
	while (p)
	{//p�� ��ũ�ʵ忡 null���ڰ� �������� �׳�尡 ������ ����� ���̴�. 
		printf("%d", p->data);//����Ǿ��ִ� �����͸� ����Ѵ�.
		p = p->link;	//���� ���� �̵��Ѵ�.
	}
	printf("]");
}

int testPair(char*exp)
{
	char symbol, open_pair;
	int i, length = strlen(exp);//strlen�Լ��� ���ڿ��� ���̸� ��Ÿ���� �Լ�.
	top = NULL;

	for (i = 0; i < length; i++)
	{//���ڿ��� ���������� i�� ������Ų��
		symbol = exp[i];
		switch (symbol)
		{
		case'(':	//(�� �Է�������
		case'[':	//[�� �Է�������
		case'{':	//{�� �Է�������
			push(symbol); break;//(,{.[�� �ԷµǸ� �� ��ȣ�� push�ϰ� �ݺ����� ���´�.
		case')':	//)�� �Է�������
		case']':	//]�� �Է�������
		case'}':	//}�� �Է�������
			if (top == NULL)return 0;	//��尡 ����ִٸ� 0�� return�Ѵ�
			else
			{
				open_pair = pop();	
				if ((open_pair == '('&&symbol != ')') ||
					(open_pair == '['&&symbol != ']') ||
					(open_pair == '{'&&symbol != '}'))
					//������ȣ�� ������ȣ�� �ٸ��� 0�� ��ȯ�Ѵ�.
					return 0;
				else break;
			}
		}		
	}
	if(top == NULL)return 1;
	//�ݺ����� �� ���Ҵٸ� ������ ���°��̱� ������ 1�� ��ȯ�Ѵ�.
	else return 0;	
}

void main()
{
	char*express = "30*4-[{24-5+(3+4)}+1]";//�Է��� �� 
	printf("%s", express);//�Է��� ���� ����Ѵ�.
	if (testPair(express) == 1)//1�� ��ȯ�Ǿ��ٸ� ������ �´°������� �´ٰ� ���
		printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�!");
	else
	{		//�ƴ϶�� Ʋ�ȴٰ� ���


		printf("\n\n ������ ��ȣ�� Ʋ�Ƚ��ϴ�!");
	}
	getchar();
}
/*
element evalPostfix(char *exp)
{
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;
	top = NULL; //top�� ó���� null�� �ʱ�ȭ�Ѵ�.

	for (i = 0; i < length; i++)
	{
		symbol = exp[i];
		if (symbol != '+'&&symbol != '-'&&symbol != '*'&&symbol != '/')
		{//��Ģ������ �ϳ��� ���ٸ�
			value = symbol - '0';	
			push(value);	//value�� push�Ѵ�.
		}
		else
		{
			opr2 = pop();
			opr1 = pop();
			switch (symbol){
			case '+':push(opr1 + opr2); break;	//+�� �ִٸ� opr1��opr2�� ���Ѱ��� push�Ѵ�
			case '-':push(opr1 - opr2); break;	//-�� �ִٸ� opr1��opr2�� ������ push�Ѵ�
			case '*':push(opr1 * opr2); break;	//*�� �ִٸ� opr1��opr2�� ���Ѱ��� push�Ѵ�
			case '/':push(opr1 / opr2); break;	//�������� �ִٸ� opr1��opr2�� �������� push�Ѵ�
			}
		}
	}
	return pop();
}

void main()
{
	int result;
	char*express = "34+21+*53-32---";
	printf("���� ǥ��� : %s", express);

	result = evalPostfix(express);
	printf("\n\n ������ =>%d", result);

	getchar();
}*/