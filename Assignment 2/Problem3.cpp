#include <vector> 

using namespace std;

void MaxIncSeq (int *nums, int len);

void MaxIncSeq (int *nums, int len){
//

	int i,j,k;
	int temp, sum=0;
	int op_ele[3];
	
	for (i=0; i<(len-2); i++){
		for (j=i+1; j<(len-1); j++){
			if(*(nums+i)< *(nums+j)){
				for (k=j+1; k<len; k++){
					if(*(nums+j)< *(nums+k)){
						temp=*(nums+i)+*(nums+j)+*(nums+k);
						if(temp> sum){
							sum=temp;
							op_ele[0]=*(nums+i);
							op_ele[1]=*(nums+j);
							op_ele[2]=*(nums+k);
						}
					}
				}
			}
		}
	}
	
	for(int i=0; i<3; i++)
		cout << op_ele[i] << " ";
	cout << "\n";
}