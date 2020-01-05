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
	int q = 1;
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
			printf("第%d次排序\n", q++);
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

/**
* @brief 简单选择排序
* @param data
* @param length
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int select_sort(RecordType data[], int length)
{
	RecordType tmp;
	int i, j, k;
	
	if (NULL == data)
	{
		return E_ERROR;
	}
	
	for (i = 0; i < length-1; i++)
	{
		k = i;
		for (j = i + 1; j < length; j++)
		{
			if (data[j] < data[k])
			{
				k = j;
			}
			if (k != i)
			{
				tmp = data[i];
				data[i] = data[k];
				data[k] = tmp;
			}
		}
	}
	return E_OK;
}

/**
* @brief 快速排序
* @param data
* @param low
* @param high
* @return 成功 = 基准记录位置  其它 = E_ERROR 
*/
int quick_pass(RecordType data[], int low, int high)
{
	RecordType tmp;
	
	if (NULL == data || low > high)
	{
		return E_ERROR;
	}
	
	tmp = data[low];
	while (low < high)
	{
		/*high从右往左寻找小于基准记录的记录*/
		while (low < high && data[high] >= tmp)
		{
			high --;
		}
		/*找到小于基准记录的记录，则插入到空单元data[low]*/
		if (low < high)
		{
			data[low] = data[high];
			low ++;
		}
		/*low从左往右寻找大于基准记录的记录*/
		while (low < high && data[low] < tmp)
		{
			low ++;
		}
		/*找到大于基准记录的记录，则插入到空单元data[high]*/
		if (low < high)
		{
			data[high] = data[low];
			high --;
		}
	}
	/*将基准记录保存到low=high的位置,并且返回基准记录的位置*/
	data[low] = tmp;
	
	return low;
}

/**
* @brief 递归的快速排序
* @param data
* @param low
* @param high
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int quick_sort(RecordType data[], int low, int high)
{
	int pos;
	
	if (NULL == data || low > high)
	{
		return E_ERROR;
	}
	
	if (low < high)
	{
		pos = quick_pass(data, low, high);
		if (E_ERROR != pos)
		{
			quick_sort(data, low, pos-1);
			quick_sort(data, pos+1, high);
		}
		else
		{
			return E_ERROR;
		}
	}
	return E_OK;
}


int main(void)
{
	int i;
	RecordType data[] = {10,9,8,7,6,5,4};
	
	printf("before to sort...\n");
	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		printf("data[%d] = %d\n", i, data[i]);
	}
	
	//insert_sort(data, sizeof(data)/sizeof(data[0]));
	//bubble_sort(data, sizeof(data)/sizeof(data[0]));
	//select_sort(data, sizeof(data)/sizeof(data[0]));
	quick_sort(data, 0, sizeof(data)/sizeof(data[0])-1);
	printf("after to sort...\n");
	for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
	{
		printf("data[%d] = %d\n", i, data[i]);
	}
	return E_OK;
}