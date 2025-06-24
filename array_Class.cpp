#include <iostream>
#include <iomanip>

using namespace std;

class Array {
private:
	static const int MAX_SIZE = 50;
	int arr[MAX_SIZE];
	bool isInitialized;
	int size;

public:
	// Constructor
	Array() : isInitialized(false), size(0) {}
	
	// Public methods
	void setArray(int len);
	void displayArray() const;
	void calculateSum() const;
	void findLargest() const;
	void findSmallest() const;
	void displayReverse() const;
	void displayOddNumbers() const;
	void displayEvenNumbers() const;
	void updateElement();
	
private:
	// Helper method to check if array is initialized
	bool checkInitialized() const;
};

bool Array::checkInitialized() const {
	if (!isInitialized) {
		cout << "\n*** ERROR: Please enter array elements first (Option 1) ***\n";
		return false;
	}
	return true;
}

void Array::setArray(int len) {
	size = len;
	cout << "\nEnter " << len << " elements:\n";
	for (int i = 0; i < len; i++) {
		cout << "Element " << (i + 1) << ": ";
		cin >> arr[i];
	}
	isInitialized = true;
	cout << "\n✓ Array values updated successfully!\n";
}

void Array::displayArray() const {
	if (!checkInitialized()) return;
	
	cout << "\nArray Elements: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i];
		if (i < size - 1) cout << ", ";
	}
	cout << endl;
}

void Array::calculateSum() const {
	if (!checkInitialized()) return;
	
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	cout << "\nSum of all elements: " << sum << endl;
}

void Array::findLargest() const {
	if (!checkInitialized()) return;
	
	int largest = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > largest) {
			largest = arr[i];
		}
	}
	cout << "\nLargest element: " << largest << endl;
}

void Array::findSmallest() const {
	if (!checkInitialized()) return;
	
	int smallest = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
		}
	}
	cout << "\nSmallest element: " << smallest << endl;
}

void Array::displayReverse() const {
	if (!checkInitialized()) return;
	
	cout << "\nArray in reverse order: ";
	for (int i = size - 1; i >= 0; i--) {
		cout << arr[i];
		if (i > 0) cout << ", ";
	}
	cout << endl;
}

void Array::displayOddNumbers() const {
	if (!checkInitialized()) return;
	
	cout << "\nOdd numbers in the array: ";
	bool foundOdd = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			if (foundOdd) cout << ", ";
			cout << arr[i];
			foundOdd = true;
		}
	}
	if (!foundOdd) {
		cout << "None found";
	}
	cout << endl;
}

void Array::displayEvenNumbers() const {
	if (!checkInitialized()) return;
	
	cout << "\nEven numbers in the array: ";
	bool foundEven = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			if (foundEven) cout << ", ";
			cout << arr[i];
			foundEven = true;
		}
	}
	if (!foundEven) {
		cout << "None found";
	}
	cout << endl;
}

void Array::updateElement() {
	if (!checkInitialized()) return;
	
	int position, newValue;
	
	cout << "\nCurrent array: ";
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "]=" << arr[i];
		if (i < size - 1) cout << ", ";
	}
	cout << endl;
	
	cout << "Enter position to update (0 to " << (size - 1) << "): ";
	cin >> position;
	
	if (position < 0 || position >= size) {
		cout << "\n*** ERROR: Invalid position! Please enter a value between 0 and " 
			 << (size - 1) << " ***\n";
		return;
	}
	
	cout << "Current value at position " << position << ": " << arr[position] << endl;
	cout << "Enter new value: ";
	cin >> newValue;
	
	arr[position] = newValue;
	cout << "\n✓ Value at position " << position << " updated to " << newValue << endl;
}

void displayMenu() {
	cout << "\n" << string(50, '=') << endl;
	cout << "           ARRAY OPERATIONS MENU" << endl;
	cout << string(50, '=') << endl;
	cout << "1.  Enter array elements" << endl;
	cout << "2.  Display array" << endl;
	cout << "3.  Calculate sum of elements" << endl;
	cout << "4.  Find largest element" << endl;
	cout << "5.  Find smallest element" << endl;
	cout << "6.  Display array in reverse" << endl;
	cout << "7.  Display odd numbers" << endl;
	cout << "8.  Display even numbers" << endl;
	cout << "9.  Update an element" << endl;
	cout << "10. Exit program" << endl;
	cout << string(50, '=') << endl;
}

int getValidChoice() {
	int choice;
	cout << "Enter your choice (1-10): ";
	cin >> choice;
	
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		return -1;
	}
	
	return choice;
}

int getArraySize() {
	int length;
	do {
		cout << "Enter the size of the array (1 to 50): ";
		cin >> length;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "*** ERROR: Please enter a valid number ***\n";
			continue;
		}
		
		if (length <= 0 || length > 50) {
			cout << "*** ERROR: Size must be between 1 and 50 ***\n";
		}
	} while (length <= 0 || length > 50);
	
	return length;
}

int main() {
	cout << "Welcome to Array Operations Program!\n";
	
	int arraySize = getArraySize();
	Array myArray;
	
	while (true) {
		displayMenu();
		int choice = getValidChoice();
		
		switch (choice) {
			case 1:
				myArray.setArray(arraySize);
				break;
			case 2:
				myArray.displayArray();
				break;
			case 3:
				myArray.calculateSum();
				break;
			case 4:
				myArray.findLargest();
				break;
			case 5:
				myArray.findSmallest();
				break;
			case 6:
				myArray.displayReverse();
				break;
			case 7:
				myArray.displayOddNumbers();
				break;
			case 8:
				myArray.displayEvenNumbers();
				break;
			case 9:
				myArray.updateElement();
				break;
			case 10:
				cout << "\nThank you for using Array Operations Program!\n";
				cout << "Program terminated successfully.\n";
				return 0;
			default:
				cout << "\n*** ERROR: Invalid choice! Please enter a number between 1 and 10 ***\n";
		}
		
		cout << "\nPress Enter to continue...";
		cin.ignore();
		cin.get();
	}
	
	return 0;
}
