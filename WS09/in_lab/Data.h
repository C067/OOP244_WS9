//Callum Dodge 
//100229178
//July 27,2018

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T* data, int n) {

		//Get the first element in the data array.
		T temp = data[0];

		//For loop, looping through the values of the data array
		for (int cnt = 0; cnt < n; cnt++) {

			//Compare to see if the temp value is less than the next element
			//in the array.
			if (temp < data[cnt]) {
				//If it is, replace the value with the current element in the array.
				temp = data[cnt];
			}
		}

		//Return the temp holding the min value in the array
		return temp;
	}

	// min returns the smallest item in data
	//
	template<typename T>
	T min(const T* data, int n) {

		//Get the first element in the data array.
		T temp = data[0];

		//For loop, looping through the values of the data array
		for (int cnt = 0; cnt < n; cnt++) {

			//Compare to see if the temp value is greater than the next element
			//in the array.
			if (temp > data[cnt]) {
				//If it is, replace the value with the current element in the array.
				temp = data[cnt];
			}
		}

		//Return the temp holding the min value in the array
		return temp;
	}

	// sum returns the sum of n items in data
	//    
	template<typename T>
	T sum(const T* data, int n) {
		int total = 0;

		//For loop, looping through the values of the data array
		for (int cnt = 0; cnt < n; cnt++) {
			
			//Take the current data element and add it towards the array.
			total += data[cnt];
		}

		//Return the complete total of the array
		return total;
	}
   
	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n) {
		//Call the function Sum, as Sum loops through an Array and returns the Total 
		//value of elements.
		double totalSum = sum(data, n);

		//Calculate the average of the total by dividing it by the number of elements
		double average = totalSum / n;

		//Return the average
		return average;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(std::istream& input, T* data, int n) {
		bool result = true;	

		//For loop, looping through the values of the data array
		for (int cnt = 0; cnt < n; cnt++) {

			//Compare to see if the input contains any bad data from the file.
			if (!input.bad()) {

				//If it doesn't, ignore/remove any comma's or space in the line. 
				input.ignore(2000, ',');
				//Then, input the value within the input to each element in the data array. 
				input >> data[cnt];
				//Set the bool flag to true as the data was not bad. 
				result = true;
			}
			//Else, Set the bool flag to false as the input contains bad data. 
			else {
				result = false;
			}
		}

		return result;
	}


	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* name, const T* data, int n) {

		//Set the width of the output
		cout.width(20);

		//Set the position to print the name from right to left
		cout << right << name;

		//For loop, looping through the elements in the data array
		for (int cnt = 0; cnt < n; cnt++) {

			//Set the width of the output
			cout.width(15);
			//Set the position to print the data of each element from right to left
			cout << right << data[cnt];
		}

		//End the line.
		cout << endl;
	}

	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	template<typename T>
	bool readRow(std::istream& input, const char* name, T& data, int n){
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

