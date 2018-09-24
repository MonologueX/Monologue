#pragma once
#include <malloc.h>
#include <stdlib.h>

#define INIT_CAPCITY (3)

typedef int SeqListType;
typedef struct DSeqList
{
	SeqListType* parray;
	size_t capcity;
	size_t size;//32位 4个字节 64位
}DSeqList;

void DSeqListInit(DSeqList* seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	seqlist->capcity = INIT_CAPCITY;
	seqlist->parray = (SeqListType *)malloc(sizeof(SeqListType)* seqlist->capcity);
	seqlist->size = 0;
}

void DSeqListDestory(DSeqList* seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	free(seqlist->parray);
	seqlist->capcity = 0;

	seqlist->size = 0;
}

static void ExpandIfReqquired(DSeqList* seqlist)
{
	size_t i = 0;
	if (seqlist->size < seqlist->capcity)
	{
		return;
	}
	seqlist->capcity *= 2;
	SeqListType* NewParray = (SeqListType *)malloc(sizeof(SeqListType)* seqlist->capcity);
	for (; i < seqlist->size; i++)
	{
		NewParray[i] = seqlist->parray[i];
	}
	
	free(seqlist->parray);
	seqlist->parray = NewParray;
}


void DSeqListPushBack(DSeqList* seqlist, SeqListType value)
{
	if (seqlist == NULL)
	{
		//非法输入
		return;
	}
	ExpandIfReqquired(seqlist);
	seqlist->parray[seqlist->size] = value;
	++seqlist->size;
	return;
}

void TestDslist()
{
	DSeqList sld;
	DSeqListInit(&sld);
	DSeqListPushBack(&sld, 1);
	DSeqListPushBack(&sld, 2);
	DSeqListPushBack(&sld, 3);
	DSeqListPushBack(&sld, 4);
	DSeqListPushBack(&sld, 5);
}