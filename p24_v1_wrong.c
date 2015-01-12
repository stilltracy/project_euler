#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	int value;
	struct list * next;
	struct list * prev;
}* int_list;
static int_list init_list()
{
	int_list list=(int_list)malloc(sizeof(struct list));
	list->value=0;
	list->next=NULL;
	for (int i=1;i<=9;i++)
	{
		int_list prev=list;
		list=(int_list)malloc(sizeof(struct list));
		list->value=i;
		list->next=prev;
		prev->prev=list;
	}
	list->prev=NULL;
	return list;
}
int_list nextPermutation(int_list list, int int_ptr)
{
	int_list head=list;
	int_list ptr=list;
	for(int i=0;i<int_ptr;i++)
	{
		ptr=ptr->next;
                //printf("%d,%d\n",int_ptr,ptr->value);

	}
	for( int_list cur=ptr->next;cur!=NULL;cur=cur->next)
	{
		if(cur->value<ptr->value)
		{
			if(ptr->prev==NULL)
			{
				head=ptr->next;
			}	
			else
			{
				ptr->prev->next=ptr->next;
			}
			ptr->next->prev=ptr->prev;
			if(cur->next!=NULL)
			{
				cur->next->prev=ptr;
			}
			ptr->next=cur->next;
                        cur->next=ptr;
                        ptr->prev=cur;

			return head;	
		}	
	}
	return NULL;
}
static void print_int_list(int_list list )
{
	for( int_list cur=list;cur!=NULL;cur=cur->next)
	{
		printf("%d",cur->value );
	}
}
void main(int argc, char * argv[])
{
	int index=atoi(argv[1]);
	int_list list =init_list();
	printf("%7d:",1);
	print_int_list(list);
	printf("\n");
	int int_ptr=0;
	for(int i=0;i<index;i++)
	{
		int_list new_list=nextPermutation(list,int_ptr);
		if(new_list==NULL)
		{
		
			int_ptr++;
			if(int_ptr>=10)
			{
				printf("no more permutation: %d.\n", i);
				exit(0);
			}
			list=nextPermutation(list,int_ptr);
		}
		else
		{
			list=new_list;
		}
		printf("%7d:",i+1);
		print_int_list(list);
		printf("\n");
	}
/*
	printf("%7d:",index+1);
	print_int_list(list);
	printf("\n");
*/
}
