/*
 * File: main.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 10-Oct-2024 07:17:29
 */

 /*************************************************************************/
 /* This automatically generated example C main file shows how to call    */
 /* entry-point functions that MATLAB Coder generated. You must customize */
 /* this file for your application. Do not modify this file directly.     */
 /* Instead, make a copy of this file, modify it, and integrate it into   */
 /* your development environment.                                         */
 /*                                                                       */
 /* This file initializes entry-point function arguments to a default     */
 /* size and value before calling the entry-point functions. It does      */
 /* not store or use any values returned from the entry-point functions.  */
 /* If necessary, it does pre-allocate memory for returned values.        */
 /* You can use this file as a starting point for a main function that    */
 /* you can deploy in your application.                                   */
 /*                                                                       */
 /* After you copy the file, and before you deploy it, you must make the  */
 /* following changes:                                                    */
 /* * For variable-size function arguments, change the example sizes to   */
 /* the sizes that your application requires.                             */
 /* * Change the example values of function arguments to the values that  */
 /* your application requires.                                            */
 /* * If the entry-point functions return values, store these values or   */
 /* otherwise use them as required by your application.                   */
 /*                                                                       */
 /*************************************************************************/

 /* Include Files */
#include <direct.h> // _getcwd
#include <stdlib.h> // free, perror
#include <stdio.h>  // printf
#include <string.h> // strlen
#include "main.h"
#include "rt_nonfinite.h"
#include "solve_odeF.h"
#include "solve_odeF_terminate.h"

//extern "C" { // наша функци¤ содержитс¤ в статической библиотеке
	// (фактически объектном файле) и будет подключена на этапе линковки
	// extern "C" говорит линковщику, что следует играть по правилам 
	// ¤зыка C (которые будут попроще, чем у C++ Ч например, в C нельз¤
	// оверлоадить функции и т.д.)
	// компил¤тор ifort умеет делать совместимые с C статические библиотеки,
	// ну а мы программируем на C++, так чтоЕ extern "C"
	// подробнее тут: http://stackoverflow.com/questions/1041866/in-c-source-what-is-the-effect-of-extern-c	

extern void namelistRead(double* TEND, double* ZEX, int* NE, int* NZ, double* Q1, double* Q2, double* Q3,
	double* I1, double* I2, double* TH1, double* TH2, double* A1, double* A2, double* DR1, double* DR2,
	double* DTR1, double* DTR2, double* R1, double* R2, double* F10, double* F20, double* F30, double* P10,
	double* P20, double* P30, double* DT, double* DZ, int *INHER);


static void argInit_1xd260_char_T(char result_data[], int result_size[2])
{
	int idx1;
	char* buffer;

	if ((buffer = _getcwd(NULL, 0)) == NULL)
		perror("_getcwd error");
	else
	{
		result_size[0] = 1;
		result_size[1] = (int)strlen(buffer);
	}

	for (idx1 = 0; idx1 < result_size[1]; idx1++) {
		result_data[idx1] = buffer[idx1];
	}

	free(buffer);
}

int main(int argc, char** argv)
{
	main_solve_odeF();
	solve_odeF_terminate();
	return 0;
}

void main_solve_odeF(void)
{
	int path_size[2];
	char path_data[260] = { 0 };
	char buffer[260];

	int NE, NZ, INHER, INHARM = 2;
	double TEND, ZEX, Q1, Q2, Q3, I1, I2, TH1, TH2, A1, A2, DR1, DR2,
		DTR1, DTR2, R1, R2, F10, F20, F30, P10, P20, P30, DT, DZ;

	namelistRead(&TEND, &ZEX, &NE, &NZ, &Q1, &Q2, &Q3, &I1, &I2, &TH1, &TH2, &A1, &A2, &DR1, &DR2,
		&DTR1, &DTR2, &R1, &R2, &F10, &F20, &F30, &P10, &P20, &P30, &DT, &DZ, &INHER);

	/*int	NE = 32;
	double TEND = 10;
	double ZEX = 9.6638;
	double Q1 = 3127.5553;
	double Q2 = 3127.5553;
	double Q3 = 40000;
	double I1 = 0;
	double I2 = 0;
	double TH1 = 0;
	double TH2 = 0;
	double A1 = 4;
	double A2 = 4;
	double DR1 = 0.0002;
	double DR2 = 0.0002;
	double R1 = 0.05;
	double R2 = 0.05;
	double F10 = 0.05;
	double F20 = 0.05;
	double F30 = 0.2;
	double P10 = 0;
	double P20 = 0;
	double P30 = 0;
	double DT = 0.01;
	double DZ = 0.02;
	double INHARM = 2;
	double DTR1 = 0.274;
	double DTR2 = 0.001;
	double INHER = 0;
	double NZ = 4500;*/

	argInit_1xd260_char_T(path_data, path_size);


	sprintf_s(buffer, 50, "\\%5.3f", DTR1);
	printf("%s\n", buffer);

	strcat_s(path_data, 50, buffer);

	printf("%s \nLength: %zu\n", path_data, strlen(path_data));

	path_size[1] = (int)strlen(path_data);

	if (_mkdir(path_data) == 0)
	{
		printf("Directory was successfully created\n");		
	}
	else
		printf("Problem creating output directory\n");

	/* Call the entry-point 'solve_odeF'. */
	solve_odeF(TEND, ZEX, NE, NZ, Q1, Q2, Q3, I1, I2, TH1, TH2, A1, A2, DR1, DR2,
		DTR1, DTR2, R1, R2, F10, F20, F30, P10, P20, P30, DT, DZ, INHARM, path_data, path_size);

	solve_odeF_terminate();
	return 0;
}
