#include<stdio.h>
int binarysearch(int a[],int n,int key)
{
    int top=0;
    int bottom,mid;
    while(top<=bottom)
    {
        mid=(top+bottom)/2;
        if(a[mid]==key)
        return mid;
        else
        if (key<a[mid])
        {
            bottom =mid-1;
        }
        else
        {
         top=mid+1;

        }
    }//while
    return (-1);

}// int
void main()
{
    int i,n,key,pos,a[5];
    printf("\n How many element in list:");
    scanf("%d",&n);
    printf("\n Enter the element");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\n %2d %5d",i, a[i]);
    printf("\n Enter the element to search");
    scanf("%d",&key);
    pos=binarysearch(a,n,key);
    if(pos==-1)
    printf("\n Element is not found");
    else
    printf("\n %d Element found at %d position",i,pos);
}
