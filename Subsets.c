#include<stdio.h>
int flag=0;
void subset(int n,int set[],int m,int partial[],int positions[],int size,int sum,int index)
{
      if(sum==m)
        {
                flag=flag+1;
                printf("Subset %d : {",flag);

                for(int i=0;i<size;i++)
                {
                        printf("%d",partial[i]);
                        if(i<size-1)
                                printf(",");
                }
                printf("}\n");
                printf("Subset %d with item positions: {", flag);
        for (int i = 0; i < size; i++) {
            printf("x%d", positions[i]); 
            if (i < size - 1) printf(", ");
        }
     printf("} -> {");
        for (int i = 0; i < size; i++) {
            printf("%d", partial[i]);
            if (i < size - 1) printf(", ");
        }

        printf("}\n");
                return;
        }
        if(index>=n)
                return;
        partial[size]=set[index];
        positions[size] = index + 1;
        subset(n,set,m,partial,positions,size+1,sum+set[index],index+1);
        subset(n,set,m,partial,positions,size,sum,index+1);
}
int main()
{
        int n,m;
        printf("Enter n = ");
        scanf("%d",&n);
        int set[n];
        int partial[n],positions[n];
        printf("Enter elements: ");
        for(int i=0;i<n;i++){
                scanf("%d",&set[i]);
        }
        printf("Enter m = ");
        scanf("%d",&m);
        subset(n,set,m,partial,positions,0,0,0);
         if(flag==0){
                printf("No subsets");
        }
        return 0;
}

