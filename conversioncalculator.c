#include <stdio.h>

/*
  Program:     Conversion Calculator
  Author:      Geniesa Hargrove
  Date:        11/3/24
  Time spent:  6 hours 45 minutes
  Purpose:	   The purpose of this program is to allow users to choose conveting either length or weight.
				After selecting what to convert the user can choose to convert from metric to customary
				or vice versa.
 */


 //Length and Weight Conversion Function
void convert_length(void);
void convert_weight(void);
void clear_input(void);

//Converto to metric or us functions
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);

// us to metric
void get_us_numbers(int* p_feet, double* p_inches);
void convert(int feet, double inches, int* p_meters, double* p_centimeters);
void display_conversion_metric(int meters, double centimeters);

//metric to us length
void get_metric_numbers(int* p_meters, double* p_centimeters);
void convert_to_us(int meters, double centimeters, int* feet, double* inches);
void display_conversion_us(int feet, double inches);

//weight to metric
void get_us_weight(int* p_pounds, double* p_ounces);
void convert_weight_to_metric(int pounds, double ounces, int* p_kilograms, double* p_grams);
void display_weight_metric(int kilograms, double grams);

//weight to us
void get_weight_metric(int* p_kilograms, double* p_grams);
void convert_weight_to_us(int kilograms, double grams, int* p_pounds, double* p_ounces);
void display_weight_to_us(pounds, ounces);





int main(int argc, char* argv[])
{
	//int input = 1;
	//run while true or not 0

	while (1)

	{
		int input;
		printf("0 :end\n");
		printf("1 :convert length\n");
		printf("2: convert weight\n");
		printf("Please enter 0, 1, or 2: ");
		scanf("%d", &input);

		//locks user into valid input
		while (input > 2 || input < 0)
		{
			printf("Invalid Input. Please enter 0, 1, or 2: ");
			scanf("%d", &input);

			clear_input();
		}

		// when 0 return to main
		if (input == 0)
		{
			return;
		}
		else if (input == 1)
		{
			convert_length();
		}

		else if (input == 2)
		{
			convert_weight();
		}
	}
	return 0;
}


//Converting Length to metric or us sysyem
void convert_length(void)
{
	printf("\nYou chose to convert length\n");
	int length_choice;

	//Converting values menue

	printf("\n0 :back\n");
	printf("1 :Convert from Feet/Inches to Meters/Centimeters\n");
	printf("2 :Convert from Meters/Centimeters to Feet/Inches\n");
	scanf("%d", &length_choice);

	clear_input();

	//trap user into correct input
	while (length_choice < 0 || length_choice > 2)

	{
		printf("Invalid Input.Please enter 0, 1, or 2: ");
		scanf("%d", &length_choice);

		clear_input();
	}

	if (length_choice == 0)

	{
		//input of 0 will end program
		return;
	}

	else if (length_choice == 1)

	{
		//input of 1 will convert to metric system
		length_to_metric();
	}
	else
	{
		//input of 2 will conver to customary system
		length_to_us();
	}
}


//converting weight to metric or us system
void convert_weight(void)
{
	int weight_choice;

	printf("\nYou chose to convert weight\n");
	//converting values menue

	printf("\n0 :back\n");
	printf("1 :Convert from Pounds/Ounces to Kilograms/Grams\n");
	printf("2 :Convert from Kilograms/Grams to Pounds/Ounces\n");

	scanf("%d", &weight_choice);

	clear_input();

	while (weight_choice < 0 || weight_choice > 2)
	{
		printf("Invalid Input.Please enter 0, 1, or 2: ");
		scanf("%d", &weight_choice);

		clear_input();
	}
	if (weight_choice == 1)
	{
		weight_to_metric();
	}
	else if (weight_choice == 2)
	{
		weight_to_us();
	}
	return;
}


//functions that convert to metric or us.
void length_to_metric(void)
{
	int feet;
	double inches;
	int meters;
	double centimeters;
	// (Note:  there are 0.3048 meters in a foot, 12 inches in a foot, and 
	//100 centimeters in a meter.

	printf("\nyou chose to convert to mentric system.\n");

	get_us_numbers(&feet, &inches);
	convert(feet, inches, &meters, &centimeters);
	display_conversion_metric(meters, centimeters);

}

void length_to_us(void)
{
	int meters;
	double centimeters;
	int feet;
	double inches;

	printf("\nyou chose to convert to us stystem\n");
	get_metric_numbers(&meters, &centimeters);
	convert_to_us(meters, centimeters, &feet, &inches);
	display_conversion_us(feet, inches);
}


void weight_to_metric(void)
{
	int pounds;
	double ounces;
	int kilograms;
	double grams;

	printf("\nyou chose to convert weight metric system\n\n");
	get_us_weight(&pounds, &ounces);
	convert_weight_to_metric(pounds, ounces, &kilograms, &grams);
	display_weight_metric(kilograms, grams);
}

void get_us_weight(int* p_pounds, double* p_ounces)
{
	//create pointers for the user input pounds and ounces 
	printf("Input pounds: ");
	scanf("%d", p_pounds);

	printf("Input ounces: ");
	scanf("%lf", p_ounces);

	printf("\nYou chose %d pounds and %lf ounces\n", *p_pounds, *p_ounces);
}

void convert_weight_to_metric(int pounds, double ounces, int* p_kilograms, double* p_grams)
{
	int user_pounds = pounds;
	double user_ounces = ounces;

	// (Note:  there are 2.2046 pounds in a kilogram, 1000 grams in a kilogram, and 16 ounces in a pound.
	//convert pounds to grams.
	double total_grams = ((user_pounds / 2.2046) * 1000);
	// create placeholder to add the ounces to grams conversion
	double grams_placeholder = total_grams;
	//convert ounces to grams and add to total grams
	total_grams = grams_placeholder + (((user_ounces / 16) / 2.2046) * 1000);

	//convert to kilograms and store in kilograms.
	*p_kilograms = total_grams / 1000;
	//get remaining grams and store in grams.
	*p_grams = total_grams - (*p_kilograms * 1000);
}

void display_weight_metric(int kilograms, double grams)
{
	printf("\nThe conversion is %d kilograms and %.2lf grams.\n", kilograms, grams);
}

void weight_to_us(void)
{
	int pounds;
	double ounces;
	int kilograms;
	double grams;

	printf("\nyou chose to convert weight us system\n\n");
	get_weight_metric(&kilograms, &grams);
	convert_weight_to_us(kilograms, grams, &pounds, &ounces);
	display_weight_to_us(pounds, ounces);
}

void get_weight_metric(int* p_kilograms, double* p_grams)
{
	//create and store pointers for kilograms and grams 
	printf("Input Kilograms: ");
	scanf("%d", p_kilograms);
	printf("Input Grams: ");
	scanf("%lf", p_grams);

	printf("You chose %d kilograms and %lf grams\n", *p_kilograms, *p_grams);
}

void convert_weight_to_us(int kilograms, double grams, int* p_pounds, double* p_ounces)
{
	int user_kilograms = kilograms;
	double user_grams = grams;
	// (Note:  there are 2.2046 pounds in a kilogram, 1000 grams in a kilogram, and 16 ounces in a pound.
	//convert to ounces
	double total_ounces = (user_kilograms * 2.2046 * 16) + (((user_grams / 1000) * 2.2046) * 16);

	*p_pounds = total_ounces / 16;
	//seperatres remaining ounces from pounds
	*p_ounces = total_ounces - (*p_pounds * 16);
}

void display_weight_to_us(int pounds, double ounces)
{
	printf("\nThe conversion is %d pounds and %.2lf ounces\n", pounds, ounces);
}

void get_us_numbers(int* p_feet, double* p_inches)
{
	//pass by reference the values entered by user
	printf("input feet: ");
	scanf("%d", p_feet);

	printf("input inches: ");
	scanf("%lf", p_inches);
	clear_input();

	printf("\nyou chose %d feet and %lf inches\n", *p_feet, *p_inches);
}

void convert(int feet, double inches, int* p_meters, double* p_centimeters)
{
	//variables in scope of function
	// creates pointers to the converted meters/centimeters
	int user_feet = feet;
	double user_inches = inches;
	int converted_meters;
	int converted_centimeters;

	//user feet * 0.3048 meters in a foot * 100 centimeters in a meter. 
	// plus user inches / 12 inches in a foot * 0.3048 meters in a foot * 100 centimeters in a meter
	double total_centimeters = (user_feet * 30.48) + (user_inches * 2.54);

	//turns total centimeters into meters. converted centimeters is total centimeters - converted meters * 100 centimeters in a meter
	converted_meters = total_centimeters / 100;
	converted_centimeters = (total_centimeters - (converted_meters * 100));

	//stores complete conversions as pointers
	*p_centimeters = converted_centimeters;
	*p_meters = converted_meters;
}

void display_conversion_metric(int meters, double centimeters)
{
	printf("\nThe conversion is %d meters and %lf centimeters\n", meters, centimeters);
}



void get_metric_numbers(int* p_meters, double* p_centimeters)
{
	//create and store pointers for meters and centimeters
	printf("\nInput meters: ");
	scanf("%d", p_meters);
	printf("Input centimeters: ");
	scanf("%lf", p_centimeters);

	printf("\n You chose %d meters and %lf centimeters\n", *p_meters, *p_centimeters);
}

void convert_to_us(int meters, double centimeters, int* p_feet, double* p_inches)
{
	int user_meters = meters;
	double user_centimeters = centimeters;
	double converted_feet;

	//convert all to meters. user meters plus user centimeters * 100cm in a meter
	double total_meters = user_meters + (user_centimeters / 100);

	// total meters to feet
	converted_feet = total_meters / 0.3048;

	*p_feet = converted_feet;
	*p_inches = (converted_feet - *p_feet) * 12;
}

void display_conversion_us(int feet, double inches)
{
	printf("\nThe conversion is %d feet and %.2lf inches\n", feet, inches);
}

//clear input
void clear_input(void)
{
	char garbage;

	do

	{
		scanf("%c", &garbage);
	} while (garbage = !"\n");
}