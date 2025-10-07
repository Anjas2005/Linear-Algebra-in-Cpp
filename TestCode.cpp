
#include <iostream>
#include <string>
#include <math.h>

#include "qbMatrix.h"

using namespace std;

// A simple function to print a matrix to stdout.

template <class T>
void PrintMatrix(qbMatrix2<T> matrix)
{
    int nRows = matrix.GetNumRows();
    int nCols = matrix.GetNumCols();
    for (int row=0; row<nRows ; ++row)
    {
        for (int col=0; col<nCols; ++col)
        {
            cout<< matrix.GetElement(row,col)<<" ";
        }
    cout << endl;
    }
}

int main()
{
    cout<< "Code to test qbMatrix2" <<endl;

    // Create a matrix and its instance
    double simpleData[12] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0};
    qbMatrix2<double> testMatrix(3,4, simpleData);

    // Extract and print the elements of test Matrix.
    cout<< endl << "********************************"<<endl;
    cout<< "3 x 4 matrix test (testMatrix)." <<endl;
    PrintMatrix(testMatrix);

    // Test Element Retrival.
    cout<< endl << "********************************"<<endl;
    cout<< "Test element retrival." <<endl;
    cout<< "Element (0,0) = " << testMatrix.GetElement(0,0) <<endl;
    cout<< "Element (1,0) = " << testMatrix.GetElement(1,0) <<endl;
    cout<< "Element (2,0) = " << testMatrix.GetElement(2,0) <<endl;
    cout<< "Element (0,1) = " << testMatrix.GetElement(0,1) <<endl;
    cout<< "Element (1,1) = " << testMatrix.GetElement(1,1) <<endl;
    cout<< "Element (2,1) = " << testMatrix.GetElement(2,1) <<endl;
    cout<< "Element (5,5) = " << testMatrix.GetElement(5,5) <<endl;


    // Test Matrix Multiplication
    cout<< endl <<"**********************" <<endl;
    cout<< "Test matrix multiplication." <<endl;
    double simpleData2[12]= {1.0,2.0,3.0,1.0,2.0,3.0,1.0,2.0,3.0,1.0,2.0,3.0};
    qbMatrix2<double> testMatrix2(4,3,simpleData2);
    cout<< "4 x 3 matrix (testMatrix2)" <<endl;
    PrintMatrix(testMatrix2);
    cout<< "Multiplication (testMatrix * testMatrix2) result:" <<endl;
    qbMatrix2<double> multTest1 = testMatrix * testMatrix2;
    PrintMatrix(multTest1);

    cout<< endl <<"**********************" <<endl;
    cout<< "testMatrix2 * testMatrix: "<<endl;
    qbMatrix2<double> multTest2= testMatrix2 * testMatrix;
    PrintMatrix(multTest2);
    cout<< endl <<"**********************" <<endl;
    

    cout<<  "Test multiplication of column vector by matrix."<<endl;
    double columnData[3] = {1.5,2.5,3.5};
    double squareData[9] = {1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0};
    qbMatrix2<double> testColumn(3,1 ,columnData);
    qbMatrix2<double> squareMatrix(3,3,squareData);
    cout<< "Column Vector = " <<endl;
    PrintMatrix(testColumn);
    cout<< "Square Matrix = " <<endl;
    PrintMatrix(squareMatrix);
    cout<< "Column Vector * Square Matrix= " <<endl;
    PrintMatrix(testColumn * squareMatrix);
    cout<< "Square Matrix * Column Vector = " <<endl;
    PrintMatrix(squareMatrix*testColumn);
    cout<< "Square Matrix + 1.0 = " <<endl;
    qbMatrix2<double> squareMatrix2 = squareMatrix + 1.0;
    PrintMatrix(squareMatrix2);
    cout<< "(square Matrix + 1.0) * column Vector = "<<endl;
    PrintMatrix((squareMatrix+1.0) * testColumn);

    // ************************************************************************************************************************************************
    // Test Equality Operator
    // ************************************************************************************************************************************************

    cout<<endl<<"**********************" <<endl;
    cout<<"Test Equality Operator"<<endl;
    cout<<"testMatrix == testMatrix2:"<<(testMatrix == testMatrix2) <<endl;
    cout<<"testMatrix2 == testMatrix: "<<(testMatrix2 == testMatrix)<<endl;
    cout<<"(Let testMatrix3 = testMatrix)" <<endl;
    qbMatrix2<double> testMatrix3 = testMatrix;
    cout<<"testMatrix == testMatrix3:"<<(testMatrix == testMatrix3) <<endl;
    cout<<"testMatrix3 == testMatrix: "<<(testMatrix3 == testMatrix)<<endl;

    // ************************************************************************************************************************************************
    // Test Matrix Additon By Scalar
    // ************************************************************************************************************************************************

    cout<< endl <<"**********************" <<endl;
    cout<< "Test addition by scalar"<<endl;
    cout<< "testMatrix + 2.0" <<endl;
    PrintMatrix(testMatrix+2.0);
    cout<<endl;
    cout<< "2.0+ testMatrix = "<<endl;
    PrintMatrix(2.0+testMatrix);

    // ************************************************************************************************************************************************
    // Test Matrix Subtraction By Scalar
    // ************************************************************************************************************************************************

    cout<< endl <<"**********************" <<endl;
    cout<< "Test Subtraction by scalar"<<endl;
    cout<< "testMatrix - 2.0" <<endl;
    PrintMatrix(testMatrix-2.0);
    cout<<endl;
    cout<< "2.0- testMatrix = "<<endl;
    PrintMatrix(2.0-testMatrix);

    // ************************************************************************************************************************************************
    // Test Matrix Multiplication By Scalar
    // ************************************************************************************************************************************************

    cout<< endl <<"**********************" <<endl;
    cout<< "Test Multiplication by scalar"<<endl;
    cout<< "testMatrix * 2.0" <<endl;
    PrintMatrix(testMatrix*2.0);
    cout<<endl;
    cout<< "2.0* testMatrix = "<<endl;
    PrintMatrix(2.0*testMatrix);

    return 0;

}