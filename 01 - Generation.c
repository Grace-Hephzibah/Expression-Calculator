#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{

		char exp[50];
		char stack_operator[50], op;
		int l, s_top_operator, s_top_operand;
		float stack_operand[50], val1, val2, result;

		//Initialize
		s_top_operand = -1;
		s_top_operator = -1;
		printf("Enter the expression : \n");

		fflush(stdout); // This is not an important expression
		// Just so that printf() can work before scanf()

		//scanf("\n");
		scanf("%s", exp);
		//char exp[] = "((9-8)+5)";
		l = strlen(exp);

		for (int i = 0; i < l; i++)
		{
			// Open Parenthesis --> Ignore
			if (exp[i] == '(')
			{
				continue;
			}

			// Operator --> Push into operator stack
			else if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/'))
			{
				// Push
				if (s_top_operator > l)
					printf("OverFlow");
				else
				{
					stack_operator[++s_top_operator] = exp[i];
				}
			}

			// Operand --> Push into operand stack
			else if (isdigit(exp[i]))
			{

				if (s_top_operand > l)
					printf("OverFlow");

				else
				{
					stack_operand[++s_top_operand] = (float)(exp[i] - '0');
				}
			}

			// Close Parenthesis --> Operator_Stack [ 1 pop] and Operand_Stack [2 pop]
			else if (exp[i] == ')')
			{
				val2 = stack_operand[s_top_operand--];
				val1 = stack_operand[s_top_operand--];
				op = stack_operator[s_top_operator--];

				if (op == '+')
					result = val1 + val2;

				else if (op == '-')
					result = val1 - val2;

				else if (op == '*')
					result = val1 * val2;

				else if (op == '/')
					result = val1 / val2;

				stack_operand[++s_top_operand] = result;
			}
		}

		printf("%.2f", stack_operand[s_top_operand]);

		return 0;
}
