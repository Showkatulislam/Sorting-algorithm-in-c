#include<stdio.h>
/*The code owner Md.Showkatul islam--1/26-2021*/
//This is swap function.
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//This Max function
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
//This is display function of array.
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
//this is calling function using switch case.
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
//This is Bubble sort which time complexity worst case O(n^2).
void Bubblesort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
}
//This is Selection sort time complexity O(n^2).
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
        swap(&a[i],&a[min]);
    }
}
//This is insertion sort time complexity O(n^2).
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
//This is Partition function for Quick sort.

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
        swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}
//This is recursive Quick sort.
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
//This is Marge function for Marging same array.
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
//This recursive Marge sort function .
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
//This index base Count sort function .This is faster sort technique.
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
