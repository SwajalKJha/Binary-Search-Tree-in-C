#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};
void insert(struct node **, int );
void delete(struct node **, int );
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int main()
{
	struct node *root = NULL;
	int choice, element, de_element;
	while (1) 
	{
		printf("\n*************************\n");
		printf(" 1. Insert Node\n 2. Delete Node\n 3. In-Order\n 4. Pre-Order\n 5. Post-Order\n 6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
				printf("Enter Value to be Inserted: ");
				scanf("%d", &element);
				insert(&root, element);
				break;
			case 2: 
				printf("Enter Value to be Deleted: ");
				scanf("%d", &de_element);
				delete(&root, de_element);
				break;
			case 3:
				printf("In-Order: ");
				inorder(root);
				break;
			case 4:
				printf("Pre-Order: ");
				preorder(root);
				break;
			case 5:
				printf("Post-Order: ");
				postorder(root);
				break;
			case 6:	
				exit(1);
			default:
				printf("Invalid Choice\n");
		}
	}	
}

void insert(struct node **p, int element)
{
	if(*p == NULL)
	{
		*p = (struct node *)malloc(sizeof(struct node));
		if(*p == NULL)
		{
			printf("Malloc failed...\n");
			return;
		}
		(*p)->data = element;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
	else
	{
		if((*p)->data < element)
		{
			insert(&((*p)->right),element); // if element is large
		}
		else
		{
			insert(&((*p)->left),element); // if element is small
		}
	}
}
void delete(struct node **p, int de_element)
{
	
}
void inorder(struct node *p)
{
	if(p != NULL)
	{
		inorder(p->left);
		printf("%d ",p->data);
		inorder(p->right);
	}
}
void preorder(struct node *p)
{
	if(p != NULL)
	{
		printf("%d ",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct node *p)
{
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->data);
	}
}
