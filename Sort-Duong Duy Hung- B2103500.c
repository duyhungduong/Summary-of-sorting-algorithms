#include <stdio.h>

typedef long int keytype;
typedef double othertype;
typedef struct  {
	keytype key;
	othertype otherfields;
}recordtype;

void Swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void SelectionSort(recordtype a[], int n){
	int i,j, lowindex;
	keytype lowkey;
	for(i=0; i<=n-2; i++){
	lowkey = a[i].key;
	lowindex = i;
	for(j=i+1; j<=n-1; j++)
		if(a[j].key < lowkey) {
			lowkey = a[j].key;
			lowindex = j;
		}
	Swap(&a[i],&a[lowindex]);
}
}
void InsertionSort(recordtype a[], int n){
	int i,j;
	for (i=1; i<=n-1;i++){
		j=i;
		while ((j>0)&&(a[j].key<a[j-1].key)) {
			Swap(&a[j], &a[j-1]);
			j--;
		}
	}
}

void BubbleSort(recordtype a[], int n){
	int i,j;
	for (i=0;i<=n-2;i++)
		for (j=n-1; j>=i+1; j--)
			if (a[j].key < a[j-1].key)
				Swap(&a[j], &a[j-1]);
}

int FindPivot(recordtype a[], int i, int j){
	keytype firstkey;
	int k;
	k= i+1;
	firstkey = a[i].key;
	while ((k<=j) && (a[k].key == firstkey)) k++;
	if (k>j) return -1 ;
	else 
		{
			if (a[k].key > firstkey) return k;
			else return i;
		}
}

int Partition(recordtype a[], int i, int j, keytype pivot){
		int L, R;
		L= i;
		R = j;
		while (L<=R){
			while (a[L].key < pivot) L++;
			while (a[R].key >= pivot) R--;
			if (L<R) Swap(&a[L], &a[R]);
		}
return L;
}

void QuickSort(recordtype a[], int i, int j){
	keytype pivot ;
	int pivotindex, k;
	pivotindex = FindPivot(a,i,j);
	if (pivotindex != -1){
		pivot = a[pivotindex].key;
		k = Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}
void PushDown(recordtype a[], int first,int last){
	int r= first;
	while (r <= (last-1)/2)
		if (last == 2*r+1) {
			if (a[r].key > a[last].key)
				Swap(&a[r],&a[last]);
				r = last;
			} 
		else if ((a[r].key>a[2*r+1].key) && (a[2*r+1].key<=a[2*r+2].key)){
			Swap(&a[r],&a[2*r+1]);
			r = 2*r+1 ;
		}
		else if ((a[r].key>a[2*r+2].key) && (a[2*r+2].key<a[2*r+1].key)){
			Swap(&a[r],&a[2*r+2]);
			r = 2*r+2 ;
		}
		else
			r = last;
}

void HeapSort(recordtype a[], int n){
	int i;
	// Tao Heap
	for (i=(n-2)/2; i>=0;i--){
		PushDown(a,i,n-1);
	}
	//Sort
	for (i=n-1; i>=2; i--){
		Swap(&a[0], &a[i]);
		PushDown(a, 0 , i-1);
	}
	Swap(&a[0], &a[1]);
}
void read_data (recordtype a[], long int *n){
	FILE *f;
	f = fopen("DataforSort.txt", "r");
	long int i=0;
	if (f!=NULL){
		while (!feof(f)){
			fscanf(f,"%ld%lf", &a[i].key, &a[i].otherfields); 
			i++;
		}
	}else printf("Loi");
	fclose(f);
	*n=i;
}

void print_data(recordtype a[], int n){
	long int i;
	for (i=0;i<n;i++)
		printf("%ld	%ld	%.2lf\n", i+1, a[i].key, a[i].otherfields);
}

int main(){
	recordtype a[100004];
	long int n;
	read_data(a, &n);
//HeapSort(a,n); //6.5s? // Xem lai KQ
	QuickSort(a, 0, n-1); //7s
//	SelectionSort(a, n); //21s
//	InsertionSort(a,n);	//40s
//	BubbleSort(a,n); //67s

	print_data(a, n);
	printf("---------------------");
	printf("\n\n1	%ld 	%.2lf ", a[0].key , a[0].otherfields);
}

