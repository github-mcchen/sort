#ifndef _SORT_H_
#define _SORT_H_

#define E_OK 		0
#define E_ERROR 	-1
#define E_TRUE 		1
#define E_FALSE 	0

#define  RecordType int


/**
* @brief 直接插入排序
* @param data
* @param length
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int insert_sort(RecordType data[], int length);

/**
* @brief 冒泡排序
* @param data
* @param length
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int bubble_sort(RecordType data[], int length);

/**
* @brief 简单选择排序
* @param data
* @param length
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int select_sort(RecordType data[], int length);

/**
* @brief 快速排序
* @param data
* @param low
* @param high
* @return 成功 = 基准记录位置  其它 = E_ERROR 
*/
int quick_pass(RecordType data[], int low, int high);

/**
* @brief 递归的快速排序
* @param data
* @param low
* @param high
* @return 成功 = E_OK  其它 = E_ERROR 
*/
int quick_sort(RecordType data[], int low, int high);
#endif