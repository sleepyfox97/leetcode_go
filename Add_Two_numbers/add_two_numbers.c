#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
};

//実質的に何桁の足し算であってもlistで持つことによって可能にするプログラム．
//l1.l2に一桁目から順番に前から数字をいれていって，任意桁の数字を保存
//一桁ずつ足し算して，繰り上がる場合には，nextにおいてプラス1するようにする．

#include <stdlib.h>

struct ListNode *ft_lstnew(int i){
	struct ListNode *new;

	new = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (new == NULL)
		return (NULL);
	new->val = i;
	new->next = NULL;
	return (new);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *re = NULL;
	struct ListNode *tmp1;
	struct ListNode *tmp2;
	int re_val;
	int re_mvup = 0;

	re = NULL;
	while (l1 != NULL || l2 != NULL)
	{
		re_val = 0;
		if (l1)
			re_val += l1->val;
		if (l2)
			re_val += l2->val;
		re_val += re_mvup;
		re_mvup = re_val / 10;
		re_val = re_val % 10;
		tmp1 = ft_lstnew(re_val);
		if (re == NULL)
		{
			re = tmp1;
			tmp2 = tmp1;
		}
		else
		{
			tmp2->next = tmp1;
			tmp2 = tmp1;
		}
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}
	if (re_mvup == 1)
	{
		tmp1 = ft_lstnew(1);
		tmp2->next = tmp1;
	}
	return(re);
}