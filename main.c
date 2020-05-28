#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1001
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))
static char *strrev(char *str) // ask rahul
{
    char *p1, *p2;
    
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
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
//998 + 998
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
    strrev(ans);
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
//stripping off 0's
char* intal_diff(const char* intal1, const char* intal2)
{
    char* temp1 = malloc(MAX*sizeof(char));
    char* temp2 = malloc(MAX*sizeof(char));
    if(intal_compare(intal1,intal2)==-1)
    {
        strcpy(temp1,intal2);
        strcpy(temp2,intal1);
    }
    else
    {
        strcpy(temp1,intal1);
        strcpy(temp2,intal2);
        
    }
    
    char* ans = malloc(MAX*sizeof(char));
    int n1 = strlen(temp1);
    int n2 = strlen(temp2);
    int diff = n1 - n2;
    int carry = 0;
    int k =0;
    for(int i=n2-1;i>=0;i--)
    {
        int sub = (temp1[i+diff] - '0') - (temp2[i] - '0') - carry;
        if(sub<0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans[k] = sub + '0';
        k++;
        
    }
    for(int i=n1-n2-1;i>=0;i--)
    {
        if(temp1[i] == '0'&&carry)
        {
            ans[k] = '9';
            k++;
            continue;
        }
        int sub = (temp1[i] - '0') - carry;
        if(i>0 || sub>0)
        {
            ans[k] = sub + '0';
            k++;
        }
        carry = 0;
    }
    int i = strlen(ans) - 1;
    while (i>=0 && ans[i] == '0')
    {
        i--;
        
    }
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
        return "0";
    else
    {
        char* fin_result = malloc((n1+n2)*sizeof(char));
        int j=0;
        while(i>=0)
        {
            fin_result[j] = ans[i];
            j++;
            i--;
        }
        free(ans);
        return fin_result;
    }
    
    
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

char* intal_multiply(const char* intal1, const char* intal2)
{
    long long int len1 = strlen(intal1);
    long long int len2 = strlen(intal2);
    
    char* result = malloc((len1+len2+1)*sizeof(char));
    for(int i=0;i<len1+len2;i++)
    {
        result[i] = '0';
    }
    
    long long int i_n1 = 0;
    long long int i_n2 = 0;
    
    for(long long int i=len2-1;i>=0;i--)
    {
        int carry = 0;
        int n1 = intal2[i] - '0';
        
        i_n2 = 0;
        
        for(long long int j = len1-1;j>=0;j--)
        {
            int n2 = intal1[j] - '0';
            int sum = (n1*n2) + (result[i_n1 + i_n2] - '0') + carry;
            
            result[i_n1 + i_n2] = sum%10 + '0';
            carry = sum/10;
            i_n2++;
        }
        if(carry>0)
        {
            int x = (result[i_n1+i_n2] - '0') + carry;
            result[i_n1+i_n2] = x + '0';
        }
        
        i_n1++;
        
    }
    int i = strlen(result) - 1;
    while (i>=0 && result[i] == '0')
    {
        i--;
        
    }
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
        return "0";
    else
    {
        char* fin_result = malloc((len1+len2)*sizeof(char));
        int j=0;
        while(i>=0)
        {
            fin_result[j] = result[i];
            j++;
            i--;
        }
        free(result);
        return fin_result;
    }
    
}
char* intal_pow(const char* intal1, unsigned int n)
{  char* res = malloc(sizeof(char)*(strlen(intal1)*n+1));
    
    for(int i=0;i<strlen(res);i++)
    {
        res[i] = '0';
    }
    if(n==0)
    {
        return "1";
    }
    res = intal_pow(intal1,n/2);
    if(n%2 == 0)
        return intal_multiply(res,res);
    else
    {
        char*temp = intal_multiply(res,intal1);
        return intal_multiply(temp,res);
    }
    
}

char* intal_mod(const char* a, const char* b)
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


char* coin_row_problem(char **arr, int n)
{
    if(n==0)
    {
        return "0";
    }
    char* prev = malloc(sizeof(char)*MAX);
    char* curr = malloc(sizeof(char)*MAX);
    char* next = malloc(sizeof(char)*MAX);
    char* temp = malloc(sizeof(char)*MAX);
    
    strcpy(prev,"0");
    strcpy(curr,arr[0]);
    
    for(int i=2;i<=n;i++)
    {
        temp = intal_add(prev,arr[i-1]);
        if(intal_compare(temp,curr)==1)
        {
            strcpy(next,temp);
        }
        else
        {
            strcpy(next,curr);
        }
        strcpy(prev,curr);
        strcpy(curr,next);
    }
    free(prev);
    free(next);
    free(temp);
    return curr;
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













int main()
{
    
    /*char* a = malloc(1001*sizeof(char));
     char* b = malloc(1001*sizeof(char));
     strcpy(a,"123456");
     strcpy(b,"7000000");
     char* result = intal_add(a,b);
     
     for(int i =0;i<strlen(result);i++)
     {
     printf("%c",result[i]);
     }
     printf("\n");
     //int res2 = intal_compare(a,b);
     char* res3 = intal_diff(a,b);
     
     //printf("%d",res2);
     for(int i =0;i<strlen(res3);i++)
     {
     printf("%c",res3[i]);
     }*/
    int n = 12;
    char **a = (char**) malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        a[i] = (char*) malloc(1001 * sizeof(char));
    }
    strcpy(a[0], "1234512345123451234512345");
    strcpy(a[1], "543215432154321543215432154321");
    strcpy(a[2], "100");
    strcpy(a[3], "12345");
    strcpy(a[4], "12000");
    strcpy(a[5], "1000000000000000000000000000000");
    strcpy(a[6], "265252859812191058636308480000000");
    strcpy(a[7], "265252859812191058636308480000000");
    strcpy(a[8], "5432154321543215432154321");
    strcpy(a[9], "3");
    strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
    char* result1;
    result1 = intal_gcd(a[3], a[4]);
    /*if(!result1) {
     printf("Test intal_mod FAILED.\n");
     } else {
     if(0 == strcmp(result1, "1")) {
     printf("Test intal_mod PASSED\n");
     } else {
     printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
     }
     free(result1);
     }*/
    //result1 = intal_diff(a[2],a[0]);
    
    
    //int res = intal_min(a,5);
    //printf("%d ",res);
    //int res5 = intal_binsearch(a,5,"700");
    //printf("%d",res5);
    //char* res6 = intal_multiply(a[0],a[1]);
    for(int i=0;i<strlen(result1);i++)
    {
        printf("%c",result1[i]);
    }
    //unsigned int y = 100;
    /*char* res7 = intal_factorial(y);
     for(int i=0;i<strlen(res7);i++)
     {
     printf("%c",res7[i]);
     }*/
    /*char* res8 = intal_fibonacci(y);
     for(int i=0;i<strlen(res8);i++)
     {
     printf("%c",res8[i]);
     }*/
    /*int n = 12;
     char **a = (char**) malloc(n * sizeof(char*));
     for(int i = 0; i < n; i++) {
     a[i] = (char*) malloc(1001 * sizeof(char));
     }
     
     strcpy(a[0], "1234512345123451234512345");
     strcpy(a[1], "543215432154321543215432154321");
     strcpy(a[2], "0");
     strcpy(a[3], "1234512345123451234512345");
     strcpy(a[4], "1234512345123451234512344");
     strcpy(a[5], "12");
     strcpy(a[6], "265252859812191058636308480000000");
     strcpy(a[7], "265252859812191058636308480000000");
     strcpy(a[8], "5432154321543215432154321");
     strcpy(a[9], "3");
     strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
     strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
     char *result1;
     
     result1 = coin_row_problem(a, n);
     if(!result1) {
     printf("Test coin_row_problem FAILED.\n");
     } else {
     if(0 == strcmp("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987", result1)) {
     printf("Test coin_row_problem PASSED\n");
     } else {
     printf("Test coin_row_problem FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987");
     }
     free(result1);
     }*/
    
    
    
    
    
    
    
    
    
    
    return 0;
    
}
