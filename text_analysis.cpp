#include <iostream>
#include<string>
#include <vector>
#include<fstream>
#include<cstdlib>
#include<iomanip>

using namespace std;
//range words according to ascII

void Merge(string* array, int left, int mid, int right)
{
	string* temp = new string[right - left + 1];
	int i = left, j = mid + 1, m = 0;
	while (i <= mid && j <= right)
	{
		if (array[i] < array[j])
		{
			temp[m++] = array[i++];
		}
		else
		{
			temp[m++] = array[j++];
		}
	}
	while (i <= mid)
	{
		temp[m++] = array[i++];
	}
	while (j <= right)
	{
		temp[m++] = array[j++];

	}
	for (int n = left, m = 0; n <= right; n++, m++)
	{
		array[n] = temp[m];
	}
	//delete temp;
}

void MergeSort(string* array,int left, int right)
{
if (left < right)
{
int mid = (left + right) / 2;
MergeSort(array,left, mid);
MergeSort(array,mid + 1, right);
Merge(array, left, mid, right);
}
}

//merge the same word
int merge(string* array, int* num, int size){
	int i,n=2;
	for (i = 1; i < size-1; i++){
		if (array[i] == array[i + 1]){
			num[n]++;
		}
		else{
			array[n] = array[i + 1];
			n++;
		}
			
		}
	return n;

	}


void main(){
	ifstream ifile("trump\\twittext.txt");//read words from tweets.txt
	if (!ifile){
		cout << "fail to open file " << endl;
		exit(0);
	}
	string data[500];
	int size=500, i;
	for (i = 0; i < 501; i++){
		if (!ifile.eof()){
			ifile >> data[i];
		}
		else{
			ifile.close();
			size = i;
			break;
		}
	}
	if (i == 500) ifile.close();

	int *pnum = (int*)malloc(size*sizeof(int));
	for (i = 0; i < size; i++) pnum[i] = 1;
	string ts;
	int t;

	MergeSort(data,1, size);
	int n = merge(data, pnum, size);
	
	
	ofstream ofile;//save the result in ft1.txt
	ofile.open("trump\\ft2.txt");
	ofile << "words tweeted"<<endl;
	for (i = 0; i < n; i++){
		ofile << setw(25) << data[i] <<pnum[i]<<endl;
	}
	ofile.close();
	
	system("pause");
}
