//C program to implement Matrix multiplication
 #include <stdio.h>
 #include <conio.h>
 
		void enterData(int Matrix1[][10], int Matrix2[][10], int row1, int column1, int row2, int column2);
		void multiplyMatrices(int Matrix1[][10], int Matrix2[][10], int mult[][10], int row1, int column1, int row2, int column2);
		void display(int mult[][10], int row1, int column2);

		int main()
		{
			int Matrix1[10][10], Matrix2[10][10], mult[10][10], row1, column1, row2, column2, i, j, k;

	          printf("Enter rows and column for first matrix: ");
				scanf("%d %d", &row1, &column1);

			printf("Enter rows and column for second matrix: ");
				scanf("%d %d", &row2, &column2);

	      // If column of first matrix in not equal to row of second matrix, ask user to enter the size of matrix again.
	      
				while (column1 != row2)
				{
					printf("Error! column of first matrix not equal to row of second.\n");
					printf("Enter rows and column for first matrix: ");
						scanf("%d%d", &row1, &column1);
					printf("Enter rows and column for second matrix: ");
						scanf("%d%d", &row2, &column2);
				}

  				// Function that takes matrices data
  				
       			 enterData(Matrix1, Matrix2, row1, column1, row2, column2);

       			 // Function to multiply two matrices.
       			 
       			 multiplyMatrices(Matrix1, Matrix2, mult, row1, column1, row2, column2);

       			 // Function to display resultant matrix after multiplication
       			 
       			 display(mult, row1, column2);

	   return 0;
    }

       //function to fill elements in the matrix

		void enterData(int Matrix1[][10], int Matrix2[][10], int row1, int column1, int row2, int column2)
		{
			int i, j;
				printf("\nEnter elements of matrix 1:\n");
					for(i = 0; i < row1; ++i)
					{
						for(j = 0; j < column1; ++j)
						{
							printf("Enter elements a%d%d: ", i + 1, j + 1);
									scanf("%d", &Matrix1[i][j]);
					}
					}

					printf("\nEnter elements of matrix 2:\n");
						for(i = 0; i < row2; ++i)
							{
							for(j = 0; j < column2; ++j)
							{
								printf("Enter elements b%d%d: ", i + 1, j + 1);
									scanf("%d", &Matrix2[i][j]);
							}
						}
  					}

		void multiplyMatrices(int Matrix1[][10], int Matrix2[][10], int mult[][10], int row1, int column1, int row2, int column2)
		{
			int i, j, k;

			// Initializing elements of matrix mult to 0.
			
				for(i = 0; i < row1; ++i)
	            {
	         		for(j = 0; j < column2; ++j)
	         		{
						mult[i][j] = 0;
					}
				}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	
			for(i = 0; i < row1; ++i)
			{
				for(j = 0; j < column2; ++j)
				{
					for(k=0; k<column1; ++k)
					{
						mult[i][j] += Matrix1[i][k] * Matrix2[k][j];
					}
				}
				}
             }

     //function to display matrix

		void display(int mult[][10], int row1, int column2)
		{
			int i, j;
			printf("\nOutput Matrix:\n");
				for(i = 0; i < row1; ++i)
				{
					for(j = 0; j < column2; ++j)
		           {
		 				printf("%d  ", mult[i][j]);
							if(j == column2 - 1)
						printf("\n\n");
		}
	}
  }
  