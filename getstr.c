#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findstr(char* src, char* s)
{
    char *ptr=src, *p=s;    //��������ָ�� 
    char *ptr2=src+strlen(src), *prev=NULL;    //ptr2Ϊsrc��ĩλ��ָ�� 
    int len=strlen(s), n=0;        //�Ӵ��ĳ��Ⱥͼ����� 
    for(;*ptr;ptr++)    //ѭ�������� 
    {
        if(ptr2-ptr<len)    //���һ��ʼ�Ӵ��ʹ���src,���˳� 
            break;
        for(prev=ptr;*prev==*p;prev++,p++)    //Ѱ�ҵ�һ����ȵ�λ��,Ȼ��Ӵ�λ�ÿ�ʼƥ���Ӵ� 
        {
            if(*(p+1)==0||*(p+1)==10)    //����Ѿ������Ӵ���ĩβ 
            {
                n++;    //���� 
                p=s;    //����ָ���Ӵ� 
                break;//�˳� 
            }
        }
    }
    return n;
}

int main(void)
{
    char a[81],b[81];        //���������ַ�����
    int i;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    strcpy(a, "\\u4f60\\u597d\\u61\\u541b");
    strcpy(b, "\\u");
    printf("����ԭ�ַ���:[%s]", a); 
    printf("�������ַ���:[%s]",b);
    i = findstr(a,b);
    printf("�ҵ�:%d\n",i); 

    return 0; 
}
