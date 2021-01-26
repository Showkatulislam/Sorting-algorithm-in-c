#include<stdio.h>
void swep(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Bubblesort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
                swep(&a[j],&a[j+1]);
        }
    }
}
void Selectionsort(int a[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        swep(&a[i],&a[min]);
    }
}
void Insertionsort(int a[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        x=a[i];
        j=i-1;
        while(j>-1 && a[j]>x)
        {
           a[j+1]=a[j];
           j--;
        }
        a[j+1]=x;
    }
}

int partition(int a[],int l,int h)
{
    int pivot,i,j;
    pivot=a[l];
    i=l,j=h;
    while(i<j)
    {
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
        swep(&a[i],&a[j]);
    }
    swep(&a[l],&a[j]);
    return j;
}
void Quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        Quicksort(a,l,j);
        Quicksort(a,j+1,h);
    }
}
void Marge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];

    }
    for(;i<=mid;i++)
        b[k++]=a[i];
    for(;j<=h;j++)
        b[k++]=a[j];
    for(i=l;i<=h;i++)
        a[i]=b[i];
}
void Margesort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        Margesort(a,l,mid);
        Margesort(a,mid+1,h);
        Marge(a,l,mid,h);
    }
}
int Max(int a[],int n)
{
    int i,max;
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void Countsort(int a[],int n)
{
    int i,j,max;
    max=Max(a,n)+1;
    int c[max];
    for(i=0;i<max;i++)
        c[i]=0;
    for(i=0;i<n;i++)
        c[a[i]]++;
    i=0,j=0;
    while(i<max)
    {
        if(c[i]>0)
        {
            a[j++]=i;
            c[i]--;
        }
       else
            i++;
    }
}
void print()
{
    printf("If want to exit enter 0 time....\n");
    printf("Enter for 1 Bubble sort.O(n^2)..\n");
    printf("Enter for 2 Selection sort O(n^2).\n");
    printf("Enter for 3 Insertion sort.O(n^2).\n");
    printf("Enter for 4 Quick sort.nlogn.\n");
    printf("Enter for 5 Marge sort.nlogn;\n");
    printf("Enter for 6 Count sort..O(n).\n");
    printf("Enter for 7 Enter new array.\n");


}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void Casehandle(int a[],int n,int size)
{
   switch(n)
   {
   case 1:
    {
      Bubblesort(a,size);
      display(a,size);
      break;
    }
    case 2:
    {
      Selectionsort(a,size);
      display(a,size);
      break;
    }
    case 3:
    {
      Insertionsort(a,size);
      display(a,size);
      break;
    }
    case 4:
    {
      Quicksort(a,0,size);
      display(a,size);
      break;
    }
    case 5:
    {
      Margesort(a,0,size-1);
      display(a,size);
      break;
    }
    case 6:
    {
      Countsort(a,size);
      display(a,size);
      break;
    }

   }
}
int main()
{
   int num,size,i;
   printf("Enter the Array size\n");
   scanf("%d",&size);
   int a[size];
   printf("Enter the Array Element\n");
   for(i=0;i<size;i++)
   scanf("%d",&a[i]);
   while(1)
   {
   print();
   scanf("%d",&num);
   if(num==7)
   {
   printf("Enter the Array Element\n");
   for(i=0;i<size;i++)
   scanf("%d",&a[i]);
   }
   if(num==0)
    break;
   Casehandle(a,num,size);
   }

}
