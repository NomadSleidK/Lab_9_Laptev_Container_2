#include <iostream>
#include <vector>
#include <math.h>
#include <string>

 
using namespace std;

class NoTargetIndex{};

class Array
{
private:
    string name;
    vector <int> array;
    int firstPoint = 0;
    int lastPoint = 0;
    
public:
    
    Array(int size, int startPosition, int lastPositions, string arrayName)
    {
        try {
            for(int i = 0; i < size; i++)
            {
                array.push_back(0);
            }
            
            firstPoint = startPosition;
            lastPoint = lastPositions;
            name = arrayName;
            
        } catch(bad_alloc) {
            cout << "Error!!!" << endl;;
        }
    }
    
    vector <int> GetArray()
    {
        return array;
    }
    
    string GetName()
    {
        return name;
    }
    
    int GetElement(int index)
    {
        int position = 0;
        
        if (index > 0)
        {
            position = index + abs(firstPoint);
        }
        else if (index < 0)
        {
            position = index + abs(firstPoint);
        }
        else
        {
            position = index;
        }
        if(position > abs(firstPoint) + abs(lastPoint) || position < 0)
        {
            throw NoTargetIndex();
        }
        return array[position];
    }
    
    void ArrayInput()
    {
        for(int i = 0; i < array.size(); i++)
        {
            cin >> array[i];
        }
    }
    
    void DispleyArray()
    {
        cout << name << "= ";
        for(int i = 0; i < array.size(); i++)
        {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

    void Sum(int Constant)
    {
        vector <int> resultArray(array);
        int size = int(array.size());
        
        for(int i = 0; i < size; i++)
        {
            resultArray[i] += Constant;
        }
        
        cout << name << '+' << "const=" << ' ';
        
        for(int i = 0; i < size; i++)
        {
            cout << resultArray[i] << ' ';
        }
        cout << endl;
        
        resultArray.clear();
    }
    
    void Diff(int Constant)
    {
        vector <int> resultArray(array);
        int size = int(array.size());
        
        for(int i = 0; i < size; i++)
        {
            resultArray[i] -= Constant;
        }
        
        cout << name << '-' << "const=" << ' ';
        
        for(int i = 0; i < size; i++)
        {
            cout << resultArray[i] << ' ';
        }
        cout << endl;
        
        resultArray.clear();
    }
    
    void Prod(int Constant)
    {
        vector <int> resultArray(array);
        int size = int(array.size());
        
        for(int i = 0; i < size; i++)
        {
            resultArray[i] *= Constant;
        }
        
        cout << name << '*' << "const=" << ' ';
        
        for(int i = 0; i < size; i++)
        {
            cout << resultArray[i] << ' ';
        }
        cout << endl;
        
        resultArray.clear();
        resultArray.shrink_to_fit();
    }
    
    void SortUp(vector <int>& sortArray, int index)
    {
        int boofer = 0;
        
        boofer = sortArray[index-1];
        sortArray[index-1] = sortArray[index];
        sortArray[index] = boofer;
    }
    
    void SortDown(vector <int>& sortArray, int index)
    {
        int boofer = 0;
        
        boofer = sortArray[index-1];
        sortArray[index-1] = sortArray[index];
        sortArray[index] = boofer;
    }
    
    void Sort(bool flag)
    {
        vector <int> sortArray(array);
        int size = int(array.size());
        
        for(int i = 0; i < size; i++)
        {
            for(int index = 1; index < size; index++)
            {
                if(flag == true && (sortArray[index-1] > sortArray[index]))
                {
                    SortUp(sortArray, index);
                }
                else if(flag == false && (sortArray[index-1] < sortArray[index]))
                {
                    SortDown(sortArray, index);
                }
            }
        }
        
        if (flag == true)
        {
            cout << "sort up " << name << "= ";
        }
        else
        {
            cout << "sort down " << name << "= ";
        }

        for(int i = 0; i < size; i++)
        {
            cout << sortArray[i] << ' ';
        }
        cout << endl;
        
        sortArray.clear();
    }
};

void ArrayOperations(Array Object1, Array Object2, int code)
{
    vector <int> aVector (Object1.GetArray());
    vector <int> bVector (Object2.GetArray());
    int size = int(aVector.size());
    int* result = new int[size];
    bool flag = false;
    
    switch (code) {
        case 0:
            for(int i = 0; i < size; i++)
            {
                result[i] = aVector[i] + bVector[i];
            }
            cout << "summa= ";
            break;
            
        case 1:
            for(int i = 0; i < size; i++)
            {
                result[i] = aVector[i] - bVector[i];
            }
            cout << "raznost= ";
            break;
        case 2:
            for(int i = 0; i < size; i++)
            {
                result[i] = aVector[i] * bVector[i];
            }
            cout << "proizv= ";
            break;
        case 3:
            for(int i = 0; i < size; i++)
            {
                if(bVector[i] != 0)
                {
                    result[i] = int(aVector[i] / bVector[i]);
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                cout << "delenie= ";
            }
            break;
    }
    if(flag)
    {
        cout << "delenie na 0";
    }
    else
    {
        
        for(int i = 0; i < size; i++)
        {
            cout << result[i] << ' ';
        }
    }
    cout << endl;
    
    aVector.clear();
    bVector.clear();
    delete [] result;
}

void DispleyIndexElement(Array Obj, int index)
{
    int element = 0;
    
    try
    {
        element = Obj.GetElement(index);
        cout << Obj.GetName() << '[' << index << "]= " << element << endl;
    }
    catch(NoTargetIndex)
    {
        cout << Obj.GetName() << " wrong index " << index << endl;
    }
}

void Control(Array Object1, Array Object2, int Constanta)
{
    int command = 0;
    int index = 0;
    
    ArrayOperations(Object1, Object2, 0);
    ArrayOperations(Object1, Object2, 1);
    ArrayOperations(Object1, Object2, 2);
    ArrayOperations(Object1, Object2, 3);
    
    do{
        cin >> command;
        switch (command) {
            case 1:
                cin >> index;
                DispleyIndexElement(Object1, index);
                break;
            case 2:
                cin >> index;
                DispleyIndexElement(Object2, index);
                break;
        }
    }
    while(command != 0);
}

int main()
{
    int startPosition = 0, lastPosition = 0;
    int size = 0;
    int Constanta = 0;
    
    cin >> startPosition >> lastPosition;
    size = abs(startPosition) + abs(lastPosition) + 1;
    
    Array Object1(size, startPosition, lastPosition, "Array1");
    Array Object2(size, startPosition, lastPosition, "Array2");
    
    Object1.ArrayInput();
    Object2.ArrayInput();
    
    cin >> Constanta;
    
    Object1.DispleyArray();
    
    Object1.Sum(Constanta);
    Object1.Diff(Constanta);
    Object1.Prod(Constanta);
    Object1.Sort(true);
    Object1.Sort(false);
    
    Object2.DispleyArray();
    
    Object2.Sum(Constanta);
    Object2.Diff(Constanta);
    Object2.Prod(Constanta);
    Object2.Sort(true);
    Object2.Sort(false);
    
    Control(Object1, Object2, Constanta);
    return 0;
}

