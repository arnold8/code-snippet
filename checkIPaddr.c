/*
�����������ж�������ַ����Ƿ�����Ч��ip��ַ�ַ���������"127.0.0.1"Ϊ��Ч��ip��ַ
ip��ַ��Ч�򷵻�0�����򷵻�-1
ʹ�ñ�������Ҫ��������ͷ�ļ�
#include <string.h>
*/
int checkIPaddr(const char *ipString)
{
    int len=0,i=0;
    int tmpNum=-1;
    int countDot=0,countNum=0;            //��ʾС����ĸ��������ֶεĸ���
    int lastCharIsDot=0;                //=1��ʾ��һ���ַ���'.'
 
    if(ipString == NULL)
    {
        goto IPERR;
    }
//    printf(" ---> <%s> ipString=[%s]!\n",__FUNCTION__,ipString);
    len=strlen(ipString);
    //��Ч��ip�ַ�������С����Ϊ7(1.2.3.4)�����Ϊ15(255.255.255.255),����Ҫ��4�����ֶκ�3����
    if(len < 7 || len > 15 || strstr((const char *)ipString,".")==0)
    {
        goto IPERR;
    }
    //����Ϊһ��ʼʱlastCharIsDot=1����ʵ����ip�ִ�����Ҫ�����ֿ�ʼ��������'.'��ʼ
    lastCharIsDot=1;
    for(i=0;i<len;i++)
    {
        if(ipString[i]>='0' && ipString[i]<='9')
        {
            if(lastCharIsDot)
            {
                countNum++;
                tmpNum = atoi((const char *)&ipString[i]);
                if(tmpNum<0 || tmpNum>255 || (i==0&& tmpNum==0))
                {
                    goto IPERR;
                }
            }
            lastCharIsDot = 0;
        }
        else if(ipString[i]=='.')
        {
            if(lastCharIsDot==0)
            {
                lastCharIsDot = 1;    
                countDot++;
            }    
            else
            {
                goto IPERR;
            }    
        }
        else
        {
            goto IPERR;
        }
    }
    if(countNum !=4 || countDot !=3)
    {
        goto IPERR;
    }
//    printf("ipString = [%s] is valid,countNum = [%d] ,countDot = [%d] \n",ipString,countNum,countDot);
    return 0;
IPERR:
    printf(" ---> <%s> ipString=[%s]! is err\n",__FUNCTION__,ipString);
    return -1;
}
