#include<stdio.h>
#include<limits.h>
void merge( int A[], int left, int mid, int right ){
	int len = right - left + 1;
	int *temp = new int[len]; //�������� 
	int index = 0;
	int i = left;				//ǰһ�������ʼԪ�� 
	int j = mid + 1;			//��һ�������ʼԪ�� 
	while( i <= mid && j <= right ){
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
	}
	while( i <= mid ){			//����һ����ʣ�µ����е�Ԫ��ֱ�Ӹ��Ƶ��ϲ����ж�β 
		temp[index++] = A[i++];
	}
	while( j <= right ){		//����һ����ʣ�µ����е�Ԫ��ֱ�Ӹ��Ƶ��ϲ����ж�β
		temp[index++] = A[j++];
	}
	for( int k = 0; k < len; k++ ){	//����������ת�Ƶ�ԭʼ���� 
		A[left++] = temp[k];
	}
}

//�ݹ�ʵ�ֵĹ鲢���� 
void mergeSortRecursion( int A[], int left, int right ){
	if (left == right) return ;
	int mid = (left + right) / 2;
	mergeSortRecursion( A, left, mid );
	mergeSortRecursion( A, mid+1, right );
	merge( A,left, mid, right );
} 

//����ʵ�ֵĹ鲢���� 
void mergeSort( int A[], int n ){
	int left, mid ,right;
	for( int i = 1; i < n; i*=2 ){
		left = 0;
		while( left + i < n ){
			mid = left + i - 1;
			right = mid + i < n ? mid + i : n - 1;
			merge(A,left,mid,right);
			left = right + 1;
		}
	}
}

int main(){
	int A[] = {16,34,3,6,5,1,8,7,2,4};
	int n = sizeof(A) / sizeof(int);
	mergeSortRecursion(A,0,n-1);
	printf("�鲢��������");
	for(int i = 0; i < n; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	mergeSort(A,n);
	printf("�鲢��������");
	for(int i = 0; i < n; i++){
		printf("%d ",A[i]);
	}
	return 0;
}

