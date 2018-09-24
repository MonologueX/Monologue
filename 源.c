#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <windows.h>
#include <stddef.h>
#include <stdint.h>

#define SeqListMaxSize 1000
#define TEST_HEADER printf("\n============%s============\n", __FUNCTION__);

//struct Student
//{
//	char *name;
//	int score;
//}Stu;
//int StudentGreater(Student a, Student b)
//{
//	return a.score > b.score ? 1 : 0;
//}

typedef char SeqListType;

typedef struct SeqList
{
	SeqListType data[SeqListMaxSize];
	size_t size;//32λ 4���ֽ� 64λ
}SeqList;
//��ʼ��
void SeqListInit(SeqList* seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}

	seqlist->size = 0;
}
//β��
void SeqListPushBack(SeqList* seqlist, SeqListType value)
{
	if (seqlist == NULL)
	{
		//�Ƿ�����
		return;
	}
	if (seqlist->size >= SeqListMaxSize){
		return;
	}
	seqlist->data[seqlist->size] = value;
	++seqlist->size;
	return;
}
//βɾ
void SeqListPopBack(SeqList* seqlist)
{
	if (seqlist == NULL)
	{
		//�Ƿ�����
		return;
	}
	if (seqlist->size == 0)
	{
		return;
	}
	--seqlist->size;
	return;
}
//ͷ��
void SeqListPushFront(SeqList* seqlist, SeqListType value)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{
		return;
	}
	++seqlist->size;
	size_t i = seqlist->size - 1;
	for (; i > 0; --i)
	{
		seqlist->data[i] = seqlist->data[i - 1];
	}
	seqlist->data[0] = value;
	return;
}
//ͷɾ
void SeqListPopFront(SeqList* seqlist)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	if (seqlist->size == 0)
	{
		//��˳���
		return;
	}
	size_t i = 0;
	for (; i < seqlist->size - 1; ++i)
	{
		seqlist->data[i] = seqlist->data[i + 1];
	}
	--seqlist->size;
	return;
}

//�м��
void SeqListInsert(SeqList* seqlist, size_t pos, SeqListType value)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	if (pos > seqlist->size)
	{
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{
		return;
	}
	if (pos == 0)
	{
		SeqListPushFront(seqlist, value);
		return;
	}
	++seqlist->size;
	size_t i = seqlist->size - 1;
	for (; i - 1 >= pos; --i)
	{
		seqlist->data[i] = seqlist->data[i - 1];
	}
	seqlist->data[pos] = value;
	return;
}
//�м�ɾ
void SeqListErase(SeqList* seqlist, size_t pos)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	if (seqlist->size == 0)
	{
		return;
	}
	if (pos >= seqlist->size)
	{
		//posԽ��
		return;
	}
	size_t i = pos;
	for (; i < seqlist->size - 1; ++i)
	{
		seqlist->data[i] = seqlist->data[i + 1];
	}
	--seqlist->size;
	return;
}
//
int SeqListGet(SeqList* seqlist, size_t pos, SeqListType *value)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return 0;
	}
	if (pos >= seqlist->size)
	{
		return 0;
	}
	*value = seqlist->data[pos];
	return 1;
}
//
int SeqListSet(SeqList* seqlist, size_t pos, SeqListType value)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return 0;
	}
	if (pos >= seqlist->size)
	{
		return 0;
	}
	seqlist->data[pos] = value;
	return 1;
}
//���ݸ�����ֵ�����Ҷ�Ӧ���±�
size_t SeqListFind(SeqList* seqlist, SeqListType to_find)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return 0;
	}

	size_t i = 0;
	for (; i < seqlist->size; i++)
	{
		if (to_find == seqlist->data[i])
			return i;
	}
	return -1;
}
//ɾ������ֵ��Ԫ��
void SeqListRemove(SeqList *seqlist, SeqListType to_remove)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	size_t pos = SeqListFind(seqlist, to_remove);
	if (pos == (size_t)-1)
	{
		return;
	}
	SeqListErase(seqlist, pos);
	return;
}
void SeqListRemoveAll(SeqList *seqlist, SeqListType to_remove)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	while (1)
	{
		size_t pos = SeqListFind(seqlist, to_remove);
		if (pos == (size_t)-1)
		{
			break;
		}
		SeqListErase(seqlist, pos);
	}
}

void Swap(SeqListType* a, SeqListType* b)
{
	SeqListType tmp = *a;
	*a = *b;
	*b = tmp;
}

//ð������
void SeqListBubbleSort(SeqList* seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t count = 0;
	for (; count < seqlist->size; ++count)
	{
		size_t cur = 0;
		for (; cur < seqlist->size - 1 - count; ++cur)
		{
			if (seqlist->data[cur]>seqlist->data[cur+1])
			{
				Swap(&seqlist->data[cur], &seqlist->data[cur + 1]);
			}
		}
	}
	return;
}

typedef int(*Cmp)(SeqListType a, SeqListType b);
int Greater(SeqListType a, SeqListType b)
{
	return a > b ? 1 : 0;
}
int less(SeqListType a, SeqListType b)
{
	return a < b ? 1 : 0;
}
void SeqListBubbleSortEX(SeqList* seqlist,Cmp cmp)
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t count = 0;
	for (; count < seqlist->size; ++count)
	{
		size_t cur = 0;
		for (; cur < seqlist->size - 1 - count; ++cur)
		{
			if (!(seqlist->data[cur]>seqlist->data[cur + 1]))
			{
				Swap(&seqlist->data[cur], &seqlist->data[cur + 1]);
			}
		}
	}
	return;
}

//void 
//{
//
//}
/////////////////////////////////
//���Դ���
/////////////////////////////////
void SeqListPrintfChar(SeqList* seqlist, const char*msg)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����");
		return;
	}
	printf("[%s]\n", msg);
	size_t i = 0;
	for (; i < seqlist->size; ++i)
	{
		printf("[%c]", seqlist->data[i]);
	}
	printf("\n");
}
void TestInit()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	printf("seqlist.size expect 0,actual %lu\n", seqlist.size);
}

void TestPushBack()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');
	SeqListPrintfChar(&seqlist, "β������4��Ԫ��");
}

void TestPopBack()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListInit(&seqlist);
	SeqListPrintfChar(&seqlist, "�Կ�˳������βɾ");
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');
	SeqListPopBack(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrintfChar(&seqlist, "βɾ����Ԫ��");
}

void TestPushFront()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);

	SeqListPushFront(&seqlist, 'a');
	SeqListPushFront(&seqlist, 'b');
	SeqListPushFront(&seqlist, 'c');
	SeqListPushFront(&seqlist, 'd');

	SeqListPrintfChar(&seqlist, "ͷ��4��Ԫ��");
}

void TestPopFront()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrintfChar(&seqlist, "�Կ�˳���ͷɾ");

	SeqListPushFront(&seqlist, 'a');
	SeqListPushFront(&seqlist, 'b');
	SeqListPushFront(&seqlist, 'c');
	SeqListPushFront(&seqlist, 'd');
	SeqListPopFront(&seqlist);
	SeqListPopFront(&seqlist);

	SeqListPrintfChar(&seqlist, "ͷɾ2��Ԫ��");
}

void TestInsert()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);

	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListInsert(&seqlist, 0, 'z');
	SeqListPrintfChar(&seqlist, "��0λ�ò���z");
	SeqListInsert(&seqlist, 1, 'x');
	SeqListPrintfChar(&seqlist, "��1λ�ò���x");
}

//void TestErase()
//{
//	TEST_HEADER;
//	SeqList seqlist;
//	SeqListInit(&seqlist);
//	SeqListPopBack(&seqlist);
//	SeqListInit(&seqlist);
//	SeqListPrintfChar(&seqlist, "�Կ�˳������βɾ");
//	SeqListErase(&seqlist,);
//	SeqListErase(&seqlist,);
//	SeqListErase(&seqlist,);
//	SeqListErase(&seqlist,);
//	
//	SeqListPrintfChar(&seqlist, "");
//}

void TestGet()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);

	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListType value;
	int ret = SeqListGet(&seqlist, 0, &value);
	printf("value expected a, actual %c\n", value);
	printf("retexpected 1,actual %d\n", ret);

}

void TestSet()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);

	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListSet(&seqlist, 1, 'x');

	SeqListType value;
	int ret = SeqListGet(&seqlist, 1, &value);

	printf("ret expected 1,actual %d\n", ret);
	printf("value expected x, actual %c\n", value);
}

void TestFind()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);

	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	size_t pos = SeqListFind(&seqlist, 'x');
	printf("pos expected -1,actual %ld\n", (int64_t)pos);
	pos = SeqListFind(&seqlist, 'b');
	printf("pos expected 1,actual %ld\n", (int64_t)pos);
}

void TestBubbleSort()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'd');
	SeqListBubbleSort(&seqlist);
	SeqListPrintfChar(&seqlist, "ð������");
}


void TestBubbleSortEX()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'd');
	SeqListBubbleSortEX(&seqlist,Greater);
	SeqListPrintfChar(&seqlist, "ð������EX");

}

//int main()
//{
//	TestInit();
//	TestPushBack();
//	TestPopBack();
//	TestPushFront();
//	TestPopFront();
//	TestInsert();
//	TestGet();
//	TestSet();
//	TestFind();
//	TestBubbleSort();
//	TestBubbleSortEX();
//	system("pause");
//	return 0;
//}