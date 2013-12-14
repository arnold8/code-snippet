/*
本函数用于判断输入的字符串是否是有效的ip地址字符串，例如"127.0.0.1"为有效的ip地址
ip地址有效则返回0，否则返回-1
使用本函数需要包含如下头文件
#include <string.h>
*/
int checkIPaddr(const char *ipString)
{
    int len=0,i=0;
    int tmpNum=-1;
    int countDot=0,countNum=0;            //表示小数点的个数和数字段的个数
    int lastCharIsDot=0;                //=1表示上一个字符是'.'
 
    if(ipString == NULL)
    {
        goto IPERR;
    }
//    printf(" ---> <%s> ipString=[%s]!\n",__FUNCTION__,ipString);
    len=strlen(ipString);
    //有效的ip字符串的最小长度为7(1.2.3.4)最长长度为15(255.255.255.255),必须要有4个数字段和3个点
    if(len < 7 || len > 15 || strstr((const char *)ipString,".")==0)
    {
        goto IPERR;
    }
    //先认为一开始时lastCharIsDot=1，其实等于ip字串必须要以数字开始，不能以'.'开始
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
