#include<iostream>
#include<stdio.h>

using namespace std;
const int s=50;

class array{
	int arr[s];
	int flag=0;
	public:
		void updateFlag(int);
		int checkFlag(void);
		void setArray(int len);
		void getArray(int len);
		void sumArray(int len);
		void largestArray(int len);
		void smallestArray(int len);
		void reverseArray(int len);
		void oddArray(int len);
		void evenArray(int len);
		void updateArray(int len);
};
void array::updateFlag(int f){
	flag=f;
}
int array::checkFlag(){
	int f=flag;
	return f;
}
void array::setArray(int len){
	int i;
	for(i=0;i<len;i++){
		cout<<"Enter Number :";
		cin>>arr[i];
	}updateFlag(1);
	cout<<"Array Values Updated"<<endl;
}
void array::getArray(int len){
	int i;
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	cout<<"\nArray:";	
	for(i=0;i<len;i++){
		cout<<arr[i]<<"\t";
	}cout<<endl;
}
void array::sumArray(int len){
	int sum=0;
	int i;
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	for(i=0;i<len;i++){
		sum+=arr[i];
	}cout<<"Sum ="<<sum<<endl;
}
void array::largestArray(int len){
	int i,check=arr[0];
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	for(i=0;i<len;i++){
		if(arr[i]>check)
			check=arr[i];
	}cout<<"Largest Integer of the Array:"<<check<<endl;
}
void array::smallestArray(int len){
	int i,check=arr[0];
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	for(i=0;i<len;i++){
		if(arr[i]<check)
			check=arr[i];
	}cout<<"Smallest Integer of the Array:"<<check<<endl;
}
void array::reverseArray(int len){
	int i;
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	cout<<"Reversed Array:";
	for(i=0;i<len;i++){
		cout<<arr[len-1-i]<<"\t";
	}cout<<endl;
}
void array::oddArray(int len){	
	int i;
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	cout<<"odd numbers in the array:";
	for(i=0;i<len;i++){
		if(arr[i]%2!=0)
			cout<<arr[i]<<"\t";
	}cout<<endl;
}
void array::evenArray(int len){
	int i;
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	cout<<"Even Numbers int the list: ";
	for(i=0;i<len;i++){
		if(arr[i]%2==0)
			cout<<arr[i]<<"\t";
	}cout<<endl;
}
void array::updateArray(int len){
	array Arr;
	int pos,value;
	if(!checkFlag()){
		cout<<"ENTER OPTION 1 FIRST TO FILL ARRAY FIELDS...";
		return;
	}
	else{
		cout<<"enter the position to update";
		cin>>pos;
		cout<<"Enter new value:";
		cin>>value;
			if(pos>=0 && pos<=len){
				arr[pos]=value;
				printf("Value updated at position %d as %d",pos,value);//<stdio.h> usage
			}else{
				cout<<"Enter Correct position/index"<<endl;
			}
	}
}
int menu(){
	cout<<endl;
	cout<<"============================================"<<endl;
	cout<<"Enter 1 to Enter the array"<<endl;
	cout<<"Enter 2 to Show the array"<<endl;
	cout<<"Enter 3 to show the sum of the elements of the array"<<endl;
	cout<<"Enter 4 to show the Largest integer of the array"<<endl;
	cout<<"Enter 5 to show the smallest integer of the array"<<endl;
	cout<<"Enter 6 to show reverse array"<<endl;
	cout<<"Enter 7 to show odd numbers of the Array"<<endl;
	cout<<"Enter 8 to show even numbers of the Array"<<endl;
	cout<<"Enter 9 to update the array"<<endl;
	cout<<"Enter 10 to EXIT"<<endl;
	cout<<"============================================";
	cout<<endl;
	return 0;
}

int main() {
    int length, choice;
    array Arr;

    do {
        cout << "Enter Length of the Array (1 to 50): ";
        cin >> length;
        if (length <= 0 || length > 50) {
            cout << "Invalid length. Try again.\n";
        }
    } while (length <= 0 || length > 50);

    while(true){
        menu();
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        switch (choice) {
            case 1:
				Arr.setArray(length);
                break;
            case 2:
                Arr.getArray(length);
                break;
            case 3:
                Arr.sumArray(length);
                break;
            case 4:
                Arr.largestArray(length);
                break;
            case 5:
                Arr.smallestArray(length);
                break;
            case 6:
                Arr.reverseArray(length);
                break;
            case 7:
                Arr.oddArray(length);
                break;
            case 8:
                Arr.evenArray(length);
                break;
            case 9:
                Arr.updateArray(length);
                break;
            case 10:
                cout << "Program terminated.\n";
                return 0;
            default:
                cout << "Enter a valid option.\n";
        }
    }

    return 0;
}
