#include <iostream>
#include <ctime>
using namespace std;

void playGame();
void computerPlays();
void insertionSort(int arr[], int n);
void displayData(int arr[], int n);
void displayStats(int arr[], int n);
int getStandardDeviation(float arr[], int n, int mean);

int main() {
	computerPlays();
	return 0;
}

void playGame() {
	cout << "Welcome to the number guessing game!" << endl << "Please guess a number between 1 and 100 to begin." << endl;

	//Randomizes so that we get a new random number each time
	srand(time(NULL));

	//Generates a random number
	int secretNumber = rand() % 100 + 1;
	int guess;
	int numGuesses = 1;	//Keeps track of the number of guesses
	
	cin >> guess;

	//While the guess is wrong
	while (guess != secretNumber) {
		numGuesses++;
		
		//Let them know if the guess was higher or lower
		if (guess < secretNumber)
			cout << "The secret number is higher." << endl;
		else 
			cout << "The secret number is lower." << endl;

		//Get a new guess
		cin >> guess;
	}

	cout << "You guessed the secret number of " << secretNumber << " in " << numGuesses << " guesses!" << endl;
}

void computerPlays() {
	srand(time(NULL));
	int nums[50000];
	
	int size = sizeof(nums) / sizeof(*nums);

	for (int i = 0; i < size; i++) {
		int secretNum = rand() % 100 + 1;

		int guess = rand() % 100 + 1;
		int numGuesses = 1;

		while (guess != secretNum) {
			guess = rand() % 100 + 1;
			numGuesses++;
		}

		nums[i] = numGuesses;
	}

	insertionSort(nums, size);

	displayStats(nums, size);
}

void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void displayData(int arr[], int n) {
	int num = arr[0];
	string display = "|";

	for (int i = 1; i < n; i++) {	
		if (arr[i] == num) {
			display = display + "|";
		}
		else {
			cout << display << endl;
			num = arr[i];
			display = "|";
		}
	}

	cout << display << endl;
}

void displayStats(int arr[], int n) {
	float mean, median, sd;
	int sum = 0;
	float data[n];

	for (int i = 0; i < n; i++) {
		data[i] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		sum = sum + data[i];
	}

	mean = sum / n;
	median = arr[n/2];
	sd = getStandardDeviation(data, n, mean);

	cout << "Mean: " << mean << endl << "Median: " << median << endl;
}

int getStandardDeviation(float arr[], int n, float mean) {
	for (int i = 0; i < n; i++) {
		arr[i] = (arr[i] - mean) * (arr[i] - mean);
	}

	float sum = 0;

	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}

	float sd = sum / n;

	return sd;
}
