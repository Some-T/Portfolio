#include <iostream>		//Only one library is relevant to this code
//#include <cstdlib>
using namespace std;	//Global namespace std.


int main() {	//Int main() contains the entirety of the program code inbetween { }

//The six below 'float' type variables all relate to parcel weight in kg, therefore kilograms are usually represented to two decimal places e.g. 80.37 kg
	
	float fParcelWeight = 0;
	float fMaxParcel = 120;
	float fPayload = 0;
	float fCapacity = 750;
	float fHeaviestVan = 0;
	float fHeavyParcel = 0;

	int iNumberOfVans = 0; //This variable defines the total number of vans to be outputted at the end of the day/program.

	bool bBeltFull = false; //This variable defines whether the belt is full or not using boolean logic

	char beltFullChar; //This variable stores the string based answer to whether the belt is full or not and then converts it to boolean logic using an if statement.

	//The two below statements asks the user for string based Input in order to evaluate in the further below using an 'if' statement.2

	cout << "Is the belt full? [Y/N]" << endl << endl;
	cin >> beltFullChar;

	if (beltFullChar == 'y' || beltFullChar == 'Y') {
		bBeltFull = true;
	}
	else {
		bBeltFull = false;
	}

	/*The below while loop asks the user for the next parcel weight on the belt 
	and also automatically adds any parcels that went over the last payload limit per van*/

	while (bBeltFull) {
		fPayload = 0;
		while (fPayload <= fCapacity) {
			if (fHeavyParcel > 0) {
				fParcelWeight = fHeavyParcel;
				fHeavyParcel = 0;
			}
			else {
				cout << endl;
				cout << "What is the weight in kg of the next parcel?" << endl << endl;
				cin >> fParcelWeight;
			} 

			/*The below if statement checks whether the current parcel on the belt that has been
			  inputted by the user, exceeds the maximum parcel weight of 120 kg or not if it does 
			  it does not add it to the van and sends it back to the sender*/

			if (fParcelWeight <= fMaxParcel) {
				fPayload = fPayload + fParcelWeight;
				cout << endl;
				cout << "Total Payload so far (Maximum of 750 kg): " << fPayload << " kg" << endl << endl;
			}
			else {
				cout << endl;
				cout << "Parcel weighs more than 120 kg! This will be taken off the belt and sent back to the sender of the parcel." << endl << endl;
				fParcelWeight = 0;
			}
		}

		/*The below checks whether the parcel exceeeds the payload amount in order to add it back to the 'next' van and 
		its payload at the beginning, it also reports a van has been dispatched upon the payload exceeding the maximum along
		with its payload and total vans dispatched so far, it also prints out the current heaviest payload. Then upon the user
		entering whether the belt is full or not, if it is full it starts the program from the beginning again or if the user 
		says the belt is empty the day/program ends and it prints as report out of the total number of vans loaded with parcels, 
		the heaviest van and whether there was any parcels left over for the following day.*/

		if (fPayload >= fCapacity) {
			cout << "The last parcel you entered with the amount " << fParcelWeight << " kg " << "exceeds the maximum payload of 750 kg, this will be assigned to the next payload of the next van automatically, unless the day ends." << endl << endl;
			fPayload = fPayload - fParcelWeight;
			fHeavyParcel = fParcelWeight;
			fParcelWeight = 0;
		}
		if (fPayload > fHeaviestVan) {
			fHeaviestVan = fPayload;
		}
		iNumberOfVans = iNumberOfVans + 1;
		cout << "+1 van has been dispatched." << endl << endl;
		cout << "Payload of this dispatched van is: " << fPayload << " kg" << endl << endl;
		cout << iNumberOfVans << " van(s) have been dispatched so far." << endl << endl;
		cout << fHeaviestVan << " kg" << " is currently the heaviest payload that has been sent out." << endl << endl;
		fPayload = 0;
		cout << "Is the belt full? [Y/N]" << endl << endl;
		cin >> beltFullChar;
		if (beltFullChar == 'y' || beltFullChar == 'Y') {
			bBeltFull = true;
		}
		else {
			bBeltFull = false;
		}
	}
	cout << endl;
	cout << "The total number of vans sent out for this day was: " << iNumberOfVans << endl << endl;
	cout << "The heaviest payload sent out for this day was: " << fHeaviestVan << " kg" << endl << endl;
	cout << "One parcel was left over which was to heavy and will be sent out tomorrow, this weighed: " << fHeavyParcel << " kg" << endl << endl;

	//The below stops the program from exiting automatically.
	system("pause");
	return 0;
}