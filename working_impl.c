#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"
#define MAX 1001
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))


static int larger(const char *x,const char *y)
{
for(int j=0;j<strlen(y);j++)
{
if(y[j]>x[j])
{
    return 0;
}
else if(x[j]>y[j])
{
    return 1;
    
}
}
return 1;
}





static char *copy(const char *a)
{
int b=strlen(a);
char *x=malloc(sizeof(char)*(b+1));
for(int i=0;i<=b;i++)
{
x[i]=a[i];
}
return x;
}



static void reverseString(char *a) 
{ 
int n = strlen(a); 
for (int i = 0; i < n / 2; i++) 
{
char b=a[i];
a[i]=a[n-i-1];
a[n-i-1]=b;
} 
} 

char* intal_add(const char* intal1, const char* intal2)
{
    char* temp1 = malloc(MAX*sizeof(char));
    char* temp2 = malloc(MAX*sizeof(char));
    if(strlen(intal1)>strlen(intal2))
    {
        
        strcpy(temp1,intal2);
        strcpy(temp2,intal1);
        
        
    }
    else
    {
        strcpy(temp1,intal1);
        strcpy(temp2,intal2);
    }
    char* ans = malloc(sizeof(char)*MAX);
    int n1 = strlen(temp1);
    int n2 = strlen(temp2);
    int diff = n2-n1;
    
    int carry = 0;
    int k =0;
    
    for(int i=n1-1;i>=0;i--)
    {
        int sum = (temp1[i]-'0') + (temp2[i+diff] - '0') + carry;
        ans[k] = (sum%10 +'0');
        k++;
        carry = sum/10;
        
    }
    for(int i=n2-n1-1;i>=0;i--)
    {
        int sum = (temp2[i] - '0')+carry;
        ans[k] = sum%10 + '0';
        k++;
        carry = sum/10;
        
    }
    if(carry)
    {
        ans[k] = carry + '0';
    }
    reverseString(ans);
    free(temp1);
    free(temp2);
    return ans;
    
}

int intal_compare(const char* intal1, const char* intal2)
{
    if(strlen(intal1) > strlen(intal2))
    {
        return 1;
    }
    else if(strlen(intal2) > strlen(intal1))
    {
        return -1;
    }
    else
    {
        int x = strcmp(intal1,intal2);
        if(x==0)
        {
            return 0;
        }
        else if(x>0)
        {
            return 1;
        }
        else if(x<0)
        {
            return -1;
        }
    }
    
    return 0;
    
    
}
static char* max(const char *a,const char *b)
{
char *l=copy(a);
char *m=copy(b);
if(intal_compare(l,m)==1){
return l;
}
else{
return m;
}
}

char* intal_diff(const char* intal1, const char* intal2)
{
char *intal11=copy(intal1);
char *intal22=copy(intal2);
int com=intal_compare(intal22,intal11);
if(com==0){
char *r=malloc(sizeof(char)*2);
r[0]=48;
r[1]='\0';
return r;}
if(com==1){
char *l=intal11;
intal11=intal22;
intal22=l;}
int a=strlen(intal11);
int b=strlen(intal22);
char *r;

int n=a>b?a:b;

int min=(n==a)?b:a;
r=(char *)malloc(sizeof(char)*(n+2));
reverseString(intal11);
reverseString(intal22);
int c=0;
int m=0;
for (int i=0; i<min; i++) 
{ 
int s = (intal11[i]-'0')-(intal22[i]-'0')-c;
if(s<0){
s+=10; 
c=1;}
	    
else{
c=0;}
r[m++]=48+s;
} 
  
for (int i=min; i<n; i++) 
{ 
int s = (intal11[i]-'0')-c;
if(s<0){
s+=10; 
c=1;}
else{
c=0;}
r[m++]=48+s;  
}
m--;
while(r[m]==48){
m--;}
m++;
r[m]='\0';
  
reverseString(r);
free(intal11);
free(intal22);
    
return r; 
}

int intal_max(char **arr, int n)
{
    int max_index = -1;
    char* max = "-1";
    for(int i =0;i<n;i++)
    {
        int x = intal_compare(max,arr[i]);
        if(x<0)
        {
            max_index = i;
            max = arr[i];
        }
        
        
    }
    return max_index;
}

int intal_min(char **arr, int n)
{
    int min_index = 0;
    char* min = arr[0];
    for(int i =1;i<n;i++)
    {
        int x = intal_compare(min,arr[i]);
        if(x>0)
        {
            min_index = i;
            min = arr[i];
        }
        
        
    }
    return min_index;
}

int intal_search(char **arr, int n, const char* key)
{
    for(int i=0;i<n;i++)
    {
        if(intal_compare(arr[i],key)==0)
        {
            return i;
        }
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    //char* low = arr[0];
    int l = 0;
    int r = n-1;
    //char* high = arr[n-1];
    while(l<=r)
    {
        int mid = l + ((r-l)/2);
        if(intal_compare(arr[mid],key)==0)
        {
            return mid;
        }
        else if(intal_compare(arr[mid],key)==1)
        {
            r = mid -1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
char* intal_mod(const char *a,const char *b)
{
if(intal_compare(a,b)==-1){char *l=copy(a);return l;}
int diffbits=strlen(a)-strlen(b);
int remobit=(larger(a,b)==1)?0:1;
diffbits-=remobit;
if(diffbits>0){
char *extended=malloc(sizeof(char)*(strlen(b)+diffbits+1));
for(int i=0;i<strlen(b);i++){
extended[i]=b[i];}
int m=strlen(b);
for(int i=0;i<diffbits;i++){
extended[i+m]=48;}
extended[diffbits+m]='\0';
extended=intal_diff(a,extended);
return intal_mod(extended,b);}
return intal_mod(intal_diff(a,b),b);
}


char* intal_multiply(const char* intal1, const char* intal2)
{
if(intal1[0]==48||intal2[0]==48){
char *r=(char*)malloc(sizeof(char)*2);
r[0]=48;
r[1]='\0';
return r;}
int a=strlen(intal1);
int b=strlen(intal2);
    char *rult = malloc(sizeof(char)*(a+b+2));  
    int i_n1 = 0;  
    int i_n2 = 0;  
    int i;
    for(int i=0;i<a+b+2;i++){
		rult[i]=48;}
    for (i = a - 1; i >= 0; i--)  
    {  
        int c = 0;  
        int n1 = intal1[i] - '0';
        i_n2 = 0;            
        for (int j = b - 1; j >= 0; j--)  
        {  
            int n2 = intal2[j] - '0';  
  
            int s = n1 * n2 + (rult[i_n1 + i_n2]-'0') + c;  
            c = s / 10;  
            rult[i_n1 + i_n2] = 48+(s % 10);  
  
            i_n2++;  
        }  
  
        if (c > 0)  
            rult[i_n1 + i_n2] = 48+rult[i_n1+i_n2]-'0'+c;  
  
        i_n1++;  
    }
int v=i_n1+i_n2;
v--;
while(rult[v]==48){
v--;}

    rult[v+1]='\0';
     
  reverseString(rult);
    return rult;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
    if(intal_compare(intal1,"0")==0)
    {
        char* temp = malloc(MAX*sizeof(char));
        strcpy(temp,intal2);
        return temp;
    }
    return intal_gcd(intal_mod(intal2,intal1),intal1);
    
}

char* intal_factorial(unsigned int n)//can we use sprintf?
{
    char* res = malloc(sizeof(char)*MAX);
    res = "1";
    for(int i=2;i<=n;i++)
    {
        char* x = malloc(sizeof(char)*(n+1));
        sprintf(x, "%d", i);
        res = intal_multiply(res,x);
    }
    
    return res;
    
}
static void merge(char** arr,int l,int m,int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    char** L = (char**)malloc(sizeof(char*)*n1);
    for(int i=0;i<n1;i++)
    {
        L[i] = (char*)malloc(sizeof(char)*MAX);
    }
    char** R = (char**)malloc(sizeof(char*)*n2);
    for(int i=0;i<n2;i++)
    {
        R[i] = (char*)malloc(sizeof(char)*MAX);
    }
    
    
    for(i=0;i<n1;i++)
    {
        strcpy(L[i],arr[l+i]);
    }
    for(j=0;j<n2;j++)
    {
        strcpy(R[j],arr[m+1+j]);
    }
    i = 0;
    j = 0;
    k = l;
    
    while(i<n1 && j<n2)
    {
        if(intal_compare(L[i],R[j]) == -1 || intal_compare(L[i],R[j]) == 0)
        {
            strcpy(arr[k],L[i]);
            i++;
        }
        else
        {
            strcpy(arr[k],R[j]);
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        strcpy(arr[k],L[i]);//strcpy
        i++;
        k++;
    }
    while (j < n2)
    {
        strcpy(arr[k],R[j]);
        j++;
        k++;
    }
    
}

static void mergesort1(char**arr,int l,int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        mergesort1(arr,l,m);
        mergesort1(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void intal_sort(char **arr, int n)
{
    int l = 0;
    int r = n-1;
    
    mergesort1(arr,l,r);
}

static char* coin_row(char** arr,int index,int n)
{
if (index==n)
return "0";
if (index==n-1)
return arr[index];
if (index==n-2)
return max(arr[index],arr[index+1]);
return max(intal_add(arr[index],coin_row(arr,index+2,n)),coin_row(arr,index+1,n));
}

char* coin_row_problem(char **arr, int n)
{
return coin_row(arr,0,n);
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    char** a = (char**)malloc(sizeof(char)*(k+1));
    for(int i=0;i<k+1;i++)
    {
        a[i] = (char*)malloc(sizeof(char)*MAX);
        a[i] = "0";
    }
    a[0] = "1";
    for(int i=1;i<=n;i++)
    {
        int z = min(i,k);
        for(int j =z;j>0;j--)
        {
            a[j] = intal_add(a[j],a[j-1]);
        }
    }
    
    return a[k];
    
}

char* intal_fibonacci(unsigned int n)
{
    char* a = malloc(sizeof(char)*MAX);
    char* b = malloc(sizeof(char)*MAX);
    strcpy(a,"0");
    strcpy(b,"1");
    char*c = malloc(sizeof(char)*MAX);
    if(n==0)
    {
        return a;
    }
    for(int i = 2;i<=n;i++)
    {
        
        c = intal_add(a,b);
        strcpy(a,b);
        strcpy(b,c);
    }
    return b;
}
char * intal_pow(const char *intal1,unsigned int n)
{ 
    if (n == 0){ 
char *v=malloc(sizeof(char)*2);
v[1]='\0';
v[0]=49;
return v;} 
    else if (n%2 == 0){ 
        return intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2));} 
    else{
return intal_multiply(intal1,intal_multiply(intal_pow(intal1, n/2),intal_pow(intal1, n/2)));} 
} 
