 for (int i = 0; i < infix.length(); i++)
   {
      token = infix[i];
      switch(token)
      {
         case ' ': break;
         case '(': //left
            opStack.push(token);
            break;
         case ')': //right
            for (;;)
            {
               assert(!opStack.empty());
               topToken = opStack.top();
               opStack.pop();
               if (topToken == '(') break;
               postfix.append(BLANK + topToken);
            }
            break;
         case '+': //plus
         case '-': //minus
         case '*': //multiply
         case '/': //divide
         case '%': //modulus
            for (;;)
            {
               if (opStack.empty() || opStack.top() == '(' ||
                   (token == '*' || token == '/' || token == '%') &&
                   (opStack.top() == '+' || opStack.top() == '-'))
               {
                  //cout << opStack.top();
                  opStack.push(token);
                  break;
               }
               else
               {
                  //cout << opStack.top();
                  topToken = opStack.top();
                  opStack.pop();
                  postfix.append(BLANK + topToken);
               }
            }
            break;
case '^': //exponent
            for (;;)
            {
               if (opStack.empty() || opStack.top() == '(' ||
                   (token == '^') &&  (opStack.top() == '+' ||
                                       opStack.top() == '-' ||
                                       opStack.top() == '*' ||
                                       opStack.top() == '%' ||
                                       opStack.top() == '^'))
               {
                  //cout << opStack.top();
                  opStack.push(token);
                  break;
               }
               else
               {
                  //cout << opStack.top();
                  topToken = opStack.top();
                  opStack.pop();
                  postfix.append(BLANK + topToken);
               }
            }
            break;
default: //number or character
            postfix.append(BLANK + token);
            for (;;)
            {
               if (!isalnum(infix[i + 1]) && infix[i + 1] != '.') break;
               i++;
               token = infix[i];
               postfix.append(1, token);
            }
      }
   }

   //Pops off the operators in the stack.
   for (;;)
   {
      if(opStack.empty()) break;

      topToken = opStack.top();
      opStack.pop();
      if (topToken != ')')
      {
         postfix.append(BLANK + topToken);
      }
      else
      {
         cout << "ERROR!\n";
         break;
      }
   }
   return postfix;
}
