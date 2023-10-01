#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;
int precedence(char ch)
{
   if(ch=='-' || ch=='+')
      return 1;
   if(ch=='*' || ch=='/')
      return 3;
   if(ch=='^')
      return 5;

   return 0;
}
int findMax(string s)
{
   int index=0;
   int prec = 0;
   for(int i=0;i<s.length();i++)
   {
      if(precedence(s[i])>prec || (precedence(s[i])==prec && prec==5))
      {
         prec=precedence(s[i]);
         index = i;
      }
   }

   return index;

}

int numBack(int index,string s)
{
   int num = 0;
   for(int i = 0;i<index;i++)
   {
      if(s[i]-'0'>=0 && s[i]-'0'<=9)
      num=num*10+s[i]-'0';
      else
      num = 0;
   }
   return num;
}

int numFront(int index,string s)
{
   int num = 0;
   for(int i = index+1;i<s.length();i++)
   {
      int a = s[i]-'0';
      if(a>=0 && a<=9)
      num = num*10+a;
      else
      return num;
   }
   return num;
}

int eval(int num1,int num2,char ch)
{
   if(ch=='+')
   {
      return num1+num2;
   }
   if(ch=='-')
   {
      return num1-num2;
   }
   if(ch=='*')
   {
      return num1*num2;
   }
   if(ch=='/')
   {
      return int(num1/num2);
   }
   if(ch=='^')
   {
      return int(pow(num1,num2));
   }
   return -1;
}

int main()
{
   string s;
   cin>>s;

   while(findMax(s)!=0)
   {
      int index = findMax(s);
      // cout<<index<<endl;
      int num1 = numBack(index,s);
      // cout<<num1<<endl;
      int num2 = numFront(index,s);
      // cout<<num2<<endl;
      int res = eval(num1,num2,s[index]);
      // cout<<res<<endl;
      
      // cout<<(to_string(num1)).length()<<endl;
      int findex = (to_string(num2)).length()+index;
      // cout<<findex<<endl;
      int bindex = index-(to_string(num1)).length();
      // cout<<bindex<<endl;
      s= s.replace(bindex,1+(to_string(num1)).length()+(to_string(num2)).length(),to_string(res));
      // cout<<s<<endl;

   }

   cout<<s;


}