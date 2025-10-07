#ifndef QBMATRIX2_H
#define QBMATRIX2_H


// so we are using a single array and will use it to make matrix also we are only working on 2*2 matirx
template <class T>
class qbMatrix2
{
    public:
    // Define the various constructors
    qbMatrix2(); // Default Constructor No input parameters accepted
    qbMatrix2(int nRows,int nCols); // Accepts 2 integers of rows and cols
    qbMatrix2(int nRows,int nCols,const T *inputData);// Accepts rows and cols but also there data type
    qbMatrix2(const qbMatrix2<T>& inputMatrix);// Copy Constructor accepts another qbMatrix instance

    //And the destructor.
    ~qbMatrix2();

    //Configuration methods.
    bool resize(int numRows,int numCols);// This is a method use to resize the Matrix

    //Element Access Methods
    T GetElement(int row,int col);
    bool SetElement(int row, int col, T elementValue);
    int GetNumRows();
    int GetNumCols();

    //Operator Overload
    bool operator== (const qbMatrix2<T>& rhs);
    
    // Overload +,- and * operators(friends).
    template <class U> friend qbMatrix2<U> operator+ (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs); // adds two matrics
    template <class U> friend qbMatrix2<U> operator+ (const U& lhs,const qbMatrix2<U>& rhs);             // adds a scaler and matrix
    template <class U> friend qbMatrix2<U> operator+ (const qbMatrix2<U>& lhs, const U& rhs);            // adds a matrix and scalar

    // Overload +,- and * operators(friends).
    template <class U> friend qbMatrix2<U> operator- (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs); // sub two matrics
    template <class U> friend qbMatrix2<U> operator- (const U& lhs,const qbMatrix2<U>& rhs);             // sub a scaler and matrix
    template <class U> friend qbMatrix2<U> operator- (const qbMatrix2<U>& lhs, const U& rhs);            // sub a matrix and scalar
    
    template <class U> friend qbMatrix2<U> operator* (const qbMatrix2<U>& lhs, const qbMatrix2<U>& rhs); // mul two matrics
    template <class U> friend qbMatrix2<U> operator* (const U& lhs,const qbMatrix2<U>& rhs);             // mul a scaler and matrix
    template <class U> friend qbMatrix2<U> operator* (const qbMatrix2<U>& lhs, const U& rhs);            // mul a matrix and scalar

    private:
        int Sub2Ind(int row,int col); // Takes the row and column values and returns the appropriate linear index for that
    
    private:
        T *m_matrixData; //ptr to array of matrix data of type t
        int m_nRows, m_nCols, m_nElements;
};

// ************************************************************************************************************************************************
// Constructor/Destructor Functions
// ************************************************************************************************************************************************

template <class T>
qbMatrix2<T>::qbMatrix2()
{
    m_nRows = 1;
    m_nCols = 1;
    m_nElements =1;
    m_matrixData = new T[m_nElements];
    m_matrixData[0]=0.0;
}

// Construct Empty Matrix (All Elements 0)
template <class T>
qbMatrix2<T>::qbMatrix2(int nRows,int nCols)
{
    m_nRows =nRows;
    m_nCols =nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i=0; i<m_nElements; i++)
        m_matrixData[i] =0.0;
}

// Construct from const linear array.
template <class T>
qbMatrix2<T>::qbMatrix2(int nRows,int nCols, const T*inputData)
{
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i=0;i<m_nElements;i++)
        m_matrixData[i] = inputData[i];
}

// Copy constructor
template <class T>
qbMatrix2<T>::qbMatrix2(const qbMatrix2<T>& inputMatrix)
{
    m_nRows = inputMatrix.m_nRows;
    m_nCols = inputMatrix.m_nCols;
    m_nElements = inputMatrix.m_nElements;
    m_matrixData = new T[m_nElements];
    for (int i=0;i<m_nElements; i++)
        m_matrixData[i] = inputMatrix.m_matrixData[i];
}

//Destructor
template<class T>
qbMatrix2<T>::~qbMatrix2()
{
    if(m_matrixData != nullptr)
        delete[] m_matrixData;
}




// ************************************************************************************************************************************************
// Configuration Functions
// ************************************************************************************************************************************************

template <class T>
bool qbMatrix2<T>::resize(int numRows,int numCols)
{
    m_nRows = numRows;
    m_nCols = numCols;
    m_nElements = (m_nRows * m_nCols);
    delete[] m_matrixData;
    m_matrixData = new T[m_nElements];
    if (m_matrixData != nullptr)
    {
        for (int i=0; i<m_nElements; i++)
            m_matrixData[i] =0.0;
            return true;
    }
    else
    {
        return false;
    }
}

// ************************************************************************************************************************************************
// Element Functions
// ************************************************************************************************************************************************


template <class T>
T qbMatrix2<T>::GetElement(int row, int col)
{
    int linearIndex = Sub2Ind(row,col);
    if(linearIndex >= 0)
        return m_matrixData[linearIndex];
    else
        return 0.0;
}

template <class T>
bool qbMatrix2<T>::SetElement(int row,int col, T elementValue)
{
    int linearIndex = Sub2Ind(row,col);
    if(linearIndex >= 0)
    {
        m_matrixData[linearIndex] = elementValue;
        return true;
    }
    else
    {
        return false;
    }
}


template <class T>
int qbMatrix2<T>::GetNumRows()
{
    return m_nRows;
}

template <class T>
int qbMatrix2<T>::GetNumCols()
{
    return m_nCols;
}


// ************************************************************************************************************************************************
// Overloaded Operator Functions
// ************************************************************************************************************************************************

// ************************************************************************************************************************************************
// The + OPERATOR 
// ************************************************************************************************************************************************

// matrix + matrix
template<class T>
qbMatrix2<T> operator+ (const qbMatrix2<T>& lhs, const qbMatrix2<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;
    T *tempResult = new T[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i]= lhs.m_matrixData[i] + rhs.m_matrixData[i];
    
    qbMatrix2<T> result(numRows,numCols,tempResult);
    delete[] tempResult;
    return result;
}

// Scalar + matrix
template <class T>
qbMatrix2<T> operator+ (const T& lhs, const qbMatrix2<T>& rhs)
{
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElements = numRows * numCols;
    T*tempResult = new T[numElements];
    for (int i=0; i<numElements; ++i)
        tempResult[i] = lhs + rhs.m_matrixData[i];
    
    qbMatrix2<T> result(numRows, numCols,tempResult);
    delete[] tempResult;
    return result;
} 

// matrix + Scalar

template <class T>
qbMatrix2<T> operator+ (const qbMatrix2<T>& lhs, const T& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;
    T *tempResult = new T[numElements];
    for (int i=0; i<numElements; ++i)
        tempResult[i] = lhs.m_matrixData[i] + rhs;

    qbMatrix2<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}

// ************************************************************************************************************************************************
// The - OPERATOR 
// ************************************************************************************************************************************************

// matrix - matrix
template<class T>
qbMatrix2<T> operator- (const qbMatrix2<T>& lhs, const qbMatrix2<T>& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;
    T *tempResult = new T[numElements];
    for (int i=0; i<numElements; i++)
        tempResult[i]= lhs.m_matrixData[i] - rhs.m_matrixData[i];
    
    qbMatrix2<T> result(numRows,numCols,tempResult);
    delete[] tempResult;
    return result;
}

// Scalar - matrix
template <class T>
qbMatrix2<T> operator- (const T& lhs, const qbMatrix2<T>& rhs)
{
    int numRows = rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElements = numRows * numCols;
    T*tempResult = new T[numElements];
    for (int i=0; i<numElements; ++i)
        tempResult[i] = lhs - rhs.m_matrixData[i];
    
    qbMatrix2<T> result(numRows, numCols,tempResult);
    delete[] tempResult;
    return result;
} 

// matrix - Scalar

template <class T>
qbMatrix2<T> operator- (const qbMatrix2<T>& lhs, const T& rhs)
{
    int numRows = lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;
    T *tempResult = new T[numElements];
    for (int i=0; i<numElements; ++i)
        tempResult[i] = lhs.m_matrixData[i] - rhs;

    qbMatrix2<T> result(numRows, numCols, tempResult);
    delete[] tempResult;
    return result;
}



// ************************************************************************************************************************************************
// The * OPERATOR 
// ************************************************************************************************************************************************


// Scalar * Matrix

template <class T>
qbMatrix2<T> operator* (const T& lhs, const qbMatrix2<T>& rhs)
{
    int numRows= rhs.m_nRows;
    int numCols = rhs.m_nCols;
    int numElements = numRows * numCols;
    T *tempResult = new T[numElements];
    for(int i=0;i< numElements; ++i)
        tempResult[i] = lhs * rhs.m_matrixData[i];
    qbMatrix2<T> result(numRows, numCols,tempResult);
    delete[] tempResult;
    return result;
}

// Matrix * Scalar

template <class T>
qbMatrix2<T> operator* (const qbMatrix2<T>& lhs, const T& rhs)
{
    int numRows= lhs.m_nRows;
    int numCols = lhs.m_nCols;
    int numElements = numRows * numCols;
    T *tempResult = new T[numElements];
    for(int i=0;i< numElements; ++i)
        tempResult[i] = lhs.m_matrixData[i] * rhs;
    qbMatrix2<T> result(numRows, numCols,tempResult);
    delete[] tempResult;
    return result;
}

// matrix * matrix
template <class T>
qbMatrix2<T> operator* (const qbMatrix2<T>& lhs,const qbMatrix2<T>& rhs)
{
    int r_numRows = rhs.m_nRows;
    int r_numCols = rhs.m_nCols;
    int l_numRows = lhs.m_nRows;
    int l_numCols = lhs.m_nCols;

    if(l_numCols == r_numRows)
    {
        T *tempResult = new T[lhs.m_nRows * rhs.m_nCols];
        // Loop thorugh each row of the LHS.
        for (int lhsRow=0; lhsRow<l_numRows; lhsRow++)
        {
            // Loop Through each column on the RHS.
            for(int rhsCol=0; rhsCol<r_numCols; rhsCol++)
            {
                T elementResult=0.0;
                // Loop thorugh each element of this LHS row.
                for (int lhsCol=0; lhsCol<l_numCols; lhsCol++)
                {
                    // Compute the LHS linear index.
                    int lhsLinearIndex =(lhsRow * l_numCols) + lhsCol;

                    // Compute the RHS Linear Index
                    // RHS Row Number must be equal to lhs column no.
                    int rhsLinearIndex =(lhsCol * r_numCols) + rhsCol;

                    // Perform the Calculation on these elements.
                    elementResult += (lhs.m_matrixData[lhsLinearIndex] * rhs.m_matrixData[rhsLinearIndex]   );  
                }

                // Store the Result
                int resultLinearIndex=(lhsRow * r_numCols) + rhsCol;
                tempResult[resultLinearIndex]=elementResult;
            }
        }
        qbMatrix2<T> result(l_numRows, r_numCols, tempResult);
        delete[] tempResult;
        return result;
    }
    else
    {
        qbMatrix2<T> result(1,1);
        return result;
    }
}

// ************************************************************************************************************************************************
// The == Operator
// ************************************************************************************************************************************************

template <class T>
bool qbMatrix2<T>::operator==(const qbMatrix2<T>& rhs)
{
    // Check if the matrices are the same size, if not return false.
    if ((this-> m_nRows != rhs.m_nRows) && (this-> m_nCols != rhs.m_nCols))
        return false;
    
    // Check if the elements are equal.
    bool flag = true;
    for(int i=0;i<this->m_nElements; ++i)
    {
        if(this-> m_matrixData[i] != rhs.m_matrixData[i])
        flag= false;
    }
    return flag;
}




// ************************************************************************************************************************************************
// Private Functions
// ************************************************************************************************************************************************

template <class T>
int qbMatrix2<T>::Sub2Ind(int row,int col)
{
    if((row < m_nRows) && (row >= 0) && (col < m_nCols) && (col >= 0))
        return (row * m_nCols) + col;
    else
        return -1;
}



#endif