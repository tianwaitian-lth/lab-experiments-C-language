#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int val;
	struct node *next;
} node;

node* findmid(node *head,node *high)
{
	//fast slow pointer
	// Fast走两步，Slow走一步。当Fast到达 high 或其前驱时停止
    // 确保不会越界访问 fast->next->next
	node *fast=head;
	node *slow=head;
	while (fast!=high&&fast->next!=high)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

node *merge(node *l1,node *l2)
{
	//ans哑节点，方便操作
	node *ans=malloc(sizeof(node));
	ans->next=NULL;
	node *tmp=ans;
	while (l1!=NULL&&l2!=NULL)
	{
		if (l1->val<=l2->val)
		{
			tmp->next=l1;
			tmp=l1;
			l1=l1->next;
			continue;
		}
		if (l1->val>l2->val)
		{
			tmp->next=l2;
			tmp=l2;
			l2=l2->next;
		}
	}
	//connecting the remaining nodes
	tmp->next=(l1==NULL)?l2:l1;
	node *real_head = ans->next;
	free(ans);
	return real_head;
}

node* mergesort(node *head,node *tail)
{
	if (head==tail||head==NULL)
		return head;
	node *mid=findmid(head,tail);
	node *midnext=mid->next;
	//important step!break node!
	mid->next=NULL;
	node *left=mergesort(head,mid);
	node *right=mergesort(midnext,tail);
	return merge (left,right);
}
int main()
{
	int n;
	scanf("%d",&n);
	node *head=malloc(sizeof(node));
	head->next =NULL;
	node *tail=head;
	for (int i=0;i<n;i++)
	{
		if (i==0)
		{
			scanf("%d",&head->val);
			continue;
		}
		node *tmp=malloc(sizeof(node));
		scanf("%d",&tmp->val);
		tmp->next=head;
		head=tmp;
	}
	
	head=mergesort(head,tail);
	node *tmp=head;
	while (tmp!=NULL)
	{
		printf("%d",tmp->val);
		printf(tmp->next==NULL?"":" ");
		tmp=tmp->next;
	}
	while (head!=NULL)
	{
		node *p=head->next;
		free(head);
		head=p;
	}
	return 0;
}