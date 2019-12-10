#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct rb_node
{
	unsigned long rb_parent_color;         //패팅이있어서 뒤에 두비트 남음 RBtree 옵티마이져
	struct rb_node* rb_right;
	struct rb_node* rb_left;
	//int color;            //하나로 묶기
}RB_NODE;

RB_NODE* root = 0;

#define SZ(a)   ( sizeof(a) / sizeof(a[0]) )
#define RB_BLACK   0
#define RB_RED      1

#define rb_parent(r)    ( (RB_NODE*)(r->rb_parent_color & ~3) )
#define rb_color(r)     ( (r)->rb_parent_color & 1)
#define rb_is_red(r)    (rb_color(r))
#define rb_set_black(r) do{r->rb_parent_color &= ~1;}while(0)
#define rb_set_red(r)   do{ (r)->rb_parent_color |= 1; }while(0)

void rb_set_parent(RB_NODE* child, RB_NODE* parent)
{
	child->rb_parent_color = (child->rb_parent_color & 3) | (unsigned long)parent;
}

void rotate_left(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* right = node->rb_right;
	//RB_NODE* parent = node->parent;
	//RB_NODE* parent = (RB_NODE*)(node->rb_parent_color & ~3);
	RB_NODE* parent = rb_parent(node);


	if (node->rb_right = right->rb_left)
	{
		//right->rb_left->parent = node;
		//right->rb_left->rb_parent_color = node;
		rb_set_parent(right->rb_left, node);
	}

	right->rb_left = node;
	rb_set_parent(right, parent);

	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = right;
		else
			parent->rb_right = right;
	}
	else
		*root = right;

	rb_set_parent(node, right);
}


void rotate_right(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* left = node->rb_left;
	//RB_NODE* parent = node->rb_parent_color;
	RB_NODE* parent = rb_parent(node);


	if (node->rb_left = left->rb_right)
		//left->rb_right->rb_parent_color = node;
		rb_set_parent(left->rb_right, node);
	left->rb_right = node;
	//left->rb_parent_color = parent;
	rb_set_parent(left, parent);

	if (parent)
	{
		if (node == parent->rb_right)
			parent->rb_right = left;
		else
			parent->rb_left = left;
	}
	else
		*root = left;
	rb_set_parent(node, left);
}


void insert_color(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* parent, * gparent, * uncle, * temp;

	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);
		if (parent == gparent->rb_right)
		{
			uncle = gparent->rb_left;
			if (uncle && (rb_is_red(uncle)))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			if (parent->rb_left == node)
			{
				rotate_right(parent, root);
				temp = parent;
				parent = node;
				node = temp;

			}
			rb_set_black(parent);
			rb_set_red(gparent);
			rotate_left(gparent, root);
		}
		else
		{
			uncle = gparent->rb_right;
			if (uncle && (rb_is_red(uncle)))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			if (parent->rb_right == node)
			{
				rotate_left(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			rb_set_black(parent);
			rb_set_red(gparent);
			rotate_right(gparent, root);
		}
	}
	rb_set_black((*root));
	//(*root)->color = RB_BLACK;
}

typedef struct
{
	int data;
	RB_NODE tree;
}DATA;

typedef struct
{
	int data;
	int color;
}INFO;

typedef struct _arg
{
	RB_NODE* temp;
	INFO(*a)[10];
	int* row;
	int* col;
}ARG;

#define offset(type, member) \
         ( (unsigned long) &(  ((type*)0)->member  ) )
#define rb_entry(ptr,type,member)       (type*)( (char*)ptr - offset(type,member) )

void insert_data(RB_NODE** root, int data)
{
	DATA* temp;
	RB_NODE** p = root;
	RB_NODE* parent = NULL;
	temp = (DATA*)malloc(sizeof(DATA));
	temp->data = data;
	//temp->tree.color = RB_RED;
	rb_set_red(&temp->tree);
	temp->tree.rb_left = temp->tree.rb_right = 0;
	DATA* s;

	while (*p)
	{
		parent = *p;
		s = rb_entry(parent, DATA, tree);

		if (s->data > data)
			p = &(*p)->rb_left;
		else if (s->data < data)
			p = &(*p)->rb_right;
		else
			return;
	}

	//temp->tree.parent = parent;
	rb_set_parent(&temp->tree, parent);
	*p = &(temp->tree);
	insert_color(&temp->tree, root);
}

void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++* (arg.row);
	ar.temp = arg.temp->rb_left;
	__display(ar);
	arg.a[*(arg.row)][(*(arg.col))].data = (rb_entry(arg.temp, DATA, tree))->data;
	//arg.a[*(arg.row)][(*(arg.col))++].color = arg.temp->color;
	arg.a[*(arg.row)][(*(arg.col))++].color = rb_color(arg.temp);
	ar.temp = arg.temp->rb_right;
	__display(ar);
	--* (arg.row);

}

void display(RB_NODE* temp)
{
	int i, j, row = -1, col = 0;
	INFO a[10][10] = { 0, };
	ARG arg;
	arg.temp = temp; arg.row = &row; arg.col = &col; arg.a = a;
	system("cls");
	__display(arg);
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (a[i][j].data != 0) {
				if (a[i][j].color == RB_RED)
					printf("<%d>", a[i][j].data);
				else
					printf("[%d]", a[i][j].data);

			}
			else
				printf("%3c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main()
{
	int i;
	RB_NODE* root = 0;
	display(root);
	for (i = 0; i < 10; i++)
	{
		insert_data(&root, i + 1);
		display(root);
	}
	return 0;
}


#endif