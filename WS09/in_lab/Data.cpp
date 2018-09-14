//Callum Dodge 
//100229178
//July 27,2018

#include "Data.h"
#include <iomanip>
#include <cstring>

using namespace std;

namespace sict {

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		//Declare a variable called popChange; its purpose is to take the last value
		//and the first value in the array and subtract them from each other. Then 
		//convert it into specific format. 
		double popChange = static_cast<double>(population[n - 1] - population[0]) / 1000000;

		//Display the Population Change from 2000 to 2004
		cout << "Population change from 2000 to 2004 is " << setprecision(2) << fixed << popChange << " million" << endl;



		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		char trend[20];						//Holds the type of trend
		int temp = violentCrime[0];			//Temp value holding the first element in the Array.
		int trendCountUp = 0;				//Trend Counter
		int trendCountDown = 0;				//Trend Counter

		//For loop looping through the Violent Crime data.
		for (int cnt = 0; cnt < n; cnt++) {\

			//If the temp value is greater than the next value then the
			//trend has gone down.
			if (temp > violentCrime[cnt]) {
				//Apply the new value to the temp. 
				temp = violentCrime[cnt];
				trendCountDown += 1;
			}
			//Else, the trend is increased. 
			else {
				trendCountUp += 1;
			}
		}

		//Compare the value of the trend and see if the trend of the
		//current data is being increased or decreased. 
		if (trendCountUp > trendCountDown) {
			//Apply the trend
			strcpy(trend, "up");
		}
		else {
			//Apply the trend
			strcpy(trend, "down");
		}

		//Display the type of trend.
		cout << "Violent Crime trend is " << trend << endl;



		// Q3 print the GTA number accurate to 0 decimal places

		//Declare a variable to calculate the total average of the GTA crimes in the list of data. 
		double avgTotalAuto = static_cast<double>((average(grandTheftAuto, n)) / 1000000);
		
		//Display the average of the total GTA crimes
		cout << "There are " << setprecision(2) << fixed << avgTotalAuto << " million Grand Theft Auto incidents on average a year" << endl;



		// Q4. Print the min and max violentCrime rates

		//Calculate the minimum value of the Violent Crime Rate by sending it over to 
		//a helper function, min. Min calculates the minimum value.
		int minVioletCrime = static_cast<int>(min(violentCrimeRate, n));
		//Calculate the maximum value of the Violent Crime Rate by sending it over to 
		//a helper function, max. Max calculates the maximum value.
		int maxViolentCrime = static_cast<int>(max(violentCrimeRate, n));

		//Display the values. 
		cout << "The Minimum Violent Crime rate was " << minVioletCrime << endl;
		cout << "The Maximum Violent Crime rate was " << maxViolentCrime << endl;
	}
}
