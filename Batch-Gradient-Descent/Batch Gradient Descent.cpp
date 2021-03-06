#include <stdio.h>
int main(int argc, char *argv[])
{
	float matrix[4][2] = {{1,4},{2,5},{5,1},{4,2}};
	float result[4]={19,26,19,20};
	float theta[2]={2,5}; 
	float learning_rate = 0.01;
	float loss = 1000.0; 
	for(int i=0; i<100&&loss>0.001; i++)
	{
		float offsetSumI0 = 0.0;
		float offsetSumI1 = 0.0;
		for(int j=0; j<4; j++)
		{
			float sumCurrentI = 0.0;
			for(int k=0; k<2; k++)
			{
				sumCurrentI += matrix[j][k] * theta[k];
			}
			offsetSumI0 += (sumCurrentI - result[j]) * matrix[j][0];
			offsetSumI1 += (sumCurrentI - result[j]) * matrix[j][1];
		}
		theta[0] -= learning_rate * offsetSumI0/4;
		theta[1] -= learning_rate * offsetSumI1/4;

		printf("*************************************\n");
		printf("theta now: %f,%f\n",theta[0],theta[1]);
		loss = 0.0;
		for(int j=0; j<4; j++)
		{
			float sumCurrentAll = 0.0;
			for(int k=0; k<2; k++)
			{
				sumCurrentAll += matrix[j][k] * theta[k];
			}
			loss += (sumCurrentAll - result[j]) * (sumCurrentAll - result[j]) * 1 / 2;
		}
		printf("loss now: %f\n", loss);
	}
	return 0;
}