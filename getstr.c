#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findstr(char* src, char* s)
{
    char *ptr=src, *p=s;    //定义两个指针 
    char *ptr2=src+strlen(src), *prev=NULL;    //ptr2为src的末位置指针 
    int len=strlen(s), n=0;        //子串的长度和计数器 
    for(;*ptr;ptr++)    //循环整个串 
    {
        if(ptr2-ptr<len)    //如果一开始子串就大于src,则退出 
            break;
        for(prev=ptr;*prev==*p;prev++,p++)    //寻找第一个相等的位置,然后从此位置开始匹配子串 
        {
            if(*(p+1)==0||*(p+1)==10)    //如果已经到了子串的末尾 
            {
                n++;    //自增 
                p=s;    //重新指向子串 
                break;//退出 
            }
        }
    }
    return n;
}

int main(void)
{
    char a[81],b[81];        //定义两个字符数组
    int i;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    strcpy(a, "\\u4f60\\u597d\\u61\\u541b");
    strcpy(b, "\\u");
    printf("输入原字符串:[%s]", a); 
    printf("输入子字符串:[%s]",b);
    i = findstr(a,b);
    printf("找到:%d\n",i); 

    return 0; 
}
