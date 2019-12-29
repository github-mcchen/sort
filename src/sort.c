#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
* @brief 直接插入排序
* @param data
* @param length
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int insert_sort(RecordType data[], int length)
{
	RecordType tmp;
	int i, j;
	
	if (NULL == data)
	{
		return E_ERROR;
	}
	
	tmp = data[i];
	for (i = 1; i < length; i++)
	{
		tmp = data[i];
		j = i-1;
		while ( (j >= 0) && (tmp < data[j]) )
		{
			data[j+1] = data[j];
			j --;
		}
		data[j+1] = tmp;
	}
	
	return E_OK;
}

/**
* @brief 冒泡排序
* @param data
* @param length
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int bubble_sort(RecordType data[], int length)
{
	RecordType tmp;
	int i, j;
	bool change = E_TRUE;
	
	if (NULL == data)
	{
		return E_ERROR;
	}
	
	for (i = 0; i < length-1 && change; i++)
	{
		change = E_FALSE;
		for (j = 0; j < length-i-1; j++)
		{
			if (data[j] > data[j+1])
			{
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
				change = E_TRUE;
			}
		}
	}
	return E_OK;
}
int main(void)
{
	int i;
	RecordType data[10] = {12,11,10,9,8,7,6,5,4,3};
	
	printf("before to sort...\n");
	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		printf("data[%d] = %d\n", i, data[i]);
	}
	
	//insert_sort(data, sizeof(data)/sizeof(data[0]));
	bubble_sort(data, sizeof(data)/sizeof(data[0]));
	printf("after to sort...\n");
	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		printf("data[%d] = %d\n", i, data[i]);
	}
}