#include <stdio.h>  
#include <windows.h>  
#include <assert.h>  
#include <string.h>  
  
char *my_strcpy( char *dst, const char *scr )  
{  
    char *ret = dst;//���淵�ص�ַ  
  
    assert(dst);  
    assert(scr);  
  
    while( *dst++ = *scr++ );//ʵ�ֿ���  
  
    return ret;  
}  
  
char *my_strncpy( char *dst, const char *scr, unsigned int n )  
{  
    char *ret = dst;  
    int i = n - 1;  
  
    assert(dst);  
    assert(scr);  
    assert( n <= strlen(scr) );  
    assert( n <= strlen(dst) );  
  
    while( i > 0 )//���򿽱�  
    {  
        dst++;  
        scr++;  
        i--;  
    }  
  
    while( ( n-- > 0 ) && ( *dst-- = *scr-- ) );//���򿽱�n��  
      
    return ret;  
}  
  
char *my_strcat( char *dst, const char *scr )  
{  
    char *ret = dst;  
  
    assert(dst);  
    assert(scr);  
  
    while( '\0' != *dst )  
        dst++;//�ҵ�dst��β  
  
    while( *dst++ = *scr++ );//ʵ������  
  
    return ret;  
}  
  
char *my_strncat( char *dst, const char *scr, int n )  
{  
    char *ret=dst;  
  
    while(*dst)//�ҵ�dst��β  
        dst++;  
  
    while( ( n-- > 0 ) && ( *dst++ = *scr++ ) );//����n��  
    *dst = '\0';  
  
    return ret;  
}  
  
int my_strcmp( const char *dst, const char *scr )  
{  
    assert(dst);  
    assert(scr);  
    while( '\0' != *dst && '\0' != *scr )  
    {  
        if( *dst == *scr )  
        {  
            dst++;  
            scr++;  
        }  
        else if(*dst > *scr)  
        {  
            return 1;  
        }  
        else  
        {  
            return -1;  
        }  
    }  
    if( *dst != '\0' && *scr == '\0')  
    {  
        return 1;  
    }  
    if( *dst == '\0' && *scr != '\0')  
    {  
        return -1;  
    }  
  
    return 0;  
}  
  
int my_strncmp( const char *dst, const char *scr, int n )  
{  
    assert(dst);  
    assert(scr);  
    while( n>0 && '\0' != *dst && '\0' != *scr )  
    {  
        if( *dst == *scr )  
        {  
            dst++;  
            scr++;  
        }  
        else if(*dst > *scr)  
        {  
            return 1;  
        }  
        else  
        {  
            return -1;  
        }  
        n--;  
    }  
    if( *dst != '\0' && *scr == '\0')  
    {  
        return 1;  
    }  
    if( *dst == '\0' && *scr != '\0')  
    {  
        return -1;  
    }  
  
    return 0;  
}  
  
void *my_memcpy( void *dst, const void *scr, int n )  
{  
    void *ret = dst;  
    assert(dst);  
    assert(scr);  
    if( NULL == dst || NULL == scr )  
    {  
        return dst;  
    }  
    while(n--)  
    {  
        *(char*)dst = *(char*)scr;  
        dst = (char*)dst + 1;  
        scr = (char*)scr + 1;  
    }  
    return ret;  
}  
  
void *my_memmove( void *dst, const void *scr, int n )  
{  
    void *ret = dst;  
    int i = n - 1;  
  
    assert(dst);  
    assert(scr);  
  
    if( NULL == dst || NULL == scr )  
    {  
        return dst;  
    }  
  
    while( i > 0 )//���򿽱�  
    {  
        dst = (char*)dst + 1;  
        scr = (char*)scr + 1;  
        i--;  
    }  
  
    while(n--)  
    {  
        *(char*)dst = *(char*)scr;  
        dst = (char*)dst - 1;  
        scr = (char*)scr - 1;  
    }  
    return ret;  
}  
  
char *mystrstr( const char *str1,const char *str2)  
{  
    const char *p = str1;  
    const char *q = str2;  
    const char *s = NULL;  
  
    assert(str1);  
    assert(str2);  
    if('\0' == *q)//���ַ���Ϊ���򷵻�ĸ�ַ���  
    {  
        return (char*)p;  
    }  
    while(*p)  
    {  
        s = p;  
        while( *p && *q && *p == *q )  
        {//                                               
            p++;  
            q++;  
        }  
        if('\0' == *q)//���ַ���ָ��\0����˵��ĸ�ַ����������ַ���  
        {  
            return (char *)s;  
        }  
        p = s+1;//�����ĸ�ַ�����һ��Ԫ�رȽ�  
        q = str2;  
    }  
    return NULL;//ֱ��str1ָ���ʱ��δ�ҵ��򷵻ؿ�  
}  