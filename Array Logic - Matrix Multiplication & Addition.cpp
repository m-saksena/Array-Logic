//
//  main.cpp
//  matrix multiplication
//
//  Created by Malika Saksena on 14/06/2016.
//  Copyright © 2016 Malika Saksena. All rights reserved.
//

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------

//our matrix class should use a matrix() constructor to initialize our two matrices with the element numbers, if the user does not wish to enter his/her own values.

class matrix
{
    //member variables
    int rows1, cols1, rows2, cols2, element;
    int array1[10][10], array2[10][10], result[10][10];
    
//    void display(array, int rows, int cols)
//    {
//        for(int r=0; r<rows; r++)
//        {
//            for(int c=0; c<cols; c++)
//            {
//                cout<<array[r][c];
//            }
//        }
//    }
    
public:
    
    //function to get input matrices dimensions
    matrix()
    {
        cout<<"\nProgram to perform operations on two matrices.";
        cout<<"\nEnter the number of rows for matrix 1: ";
        cin>>rows1;
        cout<<"\nEnter the number of columns for matrix 1: ";
        cin>>cols1;
        
        cout<<"\nEnter the number of rows for matrix 2: ";
        cin>>rows2;
        cout<<"\nEnter the number of columns for matrix 2: ";
        cin>>cols2;
        
        
        //displays the sample matrices
        {
            cout<<"\n--------Matrix 1 Template---------";
            element=1;
            cout<<endl;
            while(element <=(rows1*cols1))
            {
                for (int r=0; r<rows1; r++)
                {
                    for (int c=0; c<cols1; c++)
                    {
                        array1[r][c]=element;
                        cout<<array1[r][c]<<"\t \t";
                        element ++;
                    }
                    cout<<endl;
                }
            }
            
            cout<<"\n--------Matrix 2 Template---------";
            element=1;
            cout<<endl;
            while(element <=(rows2*cols2))
            {
                for (int r=0; r<rows2; r++)
                {
                    for (int c=0; c<cols2; c++)
                    {
                        array2[r][c]=element;
                        cout<<array2[r][c]<<"\t \t";
                        element ++;
                    }
                    cout<<endl;
                }
            }
            
        }

    }
 
    
    //function to ask the user to input the values of the matrices 1 & 2
    //these entered values will write over the preset values [1 2 3; 4 5 6] etc
    //users have the option of skipping this step.
    
    void input()
    {
      
        cout<<"\n \n";
        cout<<"Follwing the template, enter the values for the matrices. Separate elements with spaces, and rows with 'enter'.";
        
        //inputting matrix 1, dimensions (rows1 x cols1)
            cout<<"\n--------Matrix 1---------";
            element=1;
            cout<<endl;
            while(element <=(rows1*cols1))
            {
                for (int r=0; r<rows1; r++)
                {
                    for (int c=0; c<cols1; c++)
                    {
                        int input;
                        cin>>input;
                        cout<<"\t";
                        array1[r][c]=input;
                        element ++;
                    }
                    cout<<endl;
                }
            }
           
            

            
            //inputting matrix 2, dimensions (rows2 x cols2)
        cout<<"\n--------Matrix 2---------";
        element=1;
        cout<<endl;
        while(element <=(rows2*cols2))
        {
            for (int r=0; r<rows2; r++)
            {
                for (int c=0; c<cols2; c++)
                {
                    int input;
                    cin>>input;
                    cout<<"\t";
                    array2[r][c]=input;
                    element ++;
                }
                cout<<endl;
            }
        }
 

        
        
    }
    
    
    void multiply()
    {
        if (cols1 != rows2)
        {
            cout<<"\nThese matrices are not compatible for multiplication.";
        }

        cout<<"\n-------Result-------\n";
        for(int r=0; r<rows1;r++)
        {
            
            for(int c2=0; c2<cols2; c2++)
            {
                
                for(int c=0; c<cols1; c++)
                {
                        result[r][c2] = result[r][c2] + (array1[r][c])*array2[c][c2];
                }
                cout<<result[r][c2]<<"\t \t";
            }
            cout<<endl;
        }
        
    }
    
    void add()
    {
        cout<<"\n-------Result-------\n";
        int res_rows, res_cols;
        
        res_rows = max(rows1, rows2);
        res_cols = max(cols1, cols2);
        
        for(int r=0; r<res_rows; r++)
        {
            for(int c=0; c<res_cols; c++)
            {
                result[r][c] = array1[r][c] + array2[r][c];
                cout<<result[r][c]<<"\t\t";
            }
            cout<<endl;
        }
        }
        
     void print()
        {
            cout<<"\n---------Matrix 1-------------\n";
            for(int r = 0; r<rows1; r++)
            {
                for(int c = 0; c<cols1; c++)
                {
                 cout<<array1[r][c]<<"\t";
                }
                cout<<endl;
            }
            
            
            cout<<"\n---------Matrix 2-------------\n";
            for(int r = 0; r<rows2; r++)
            {
                for(int c = 0; c<cols2; c++)
                {
                    cout<<array2[r][c]<<"\t";
                }
                cout<<endl;
            }

        }
        
        
    
    
    
};

//---------------------------------------------------------------------------------------------------------------




//creating a 'menu' function, which outputs an integer choice
int menu()
{
    int choice;
    
    cout<<"\n";
    cout<<"\n1. Input the matrices.";
    cout<<"\n2. Multiply the matrices. ";
    cout<<"\n3. Add the matrices.";
    cout<<"\n4. Print the input matrices.";
    cout<<"\n0. Exit program.";
    cout<<"\n \n Enter your choice: ";
    cin>>choice;
    
    return choice;
    
};







int main(int argc, const char * argv[])
{
    matrix m;
    

    int choice = -1;
    
    
    while(choice != 0)
    {
        choice = menu();
    

        if(choice == 1)
        {
            m.input();
            continue;
        }
        
        if(choice == 2)
        {
            m.multiply();
            continue;
        }
        
        if(choice == 3)
        {
            m.add();
            continue;
        }
        
        if(choice == 4)
        {
            m.print();
            continue;
        }
        
        else
        {
            cout<<"\nInvalid choice.";
            continue;
        }
        
        
//        cout<<"\nDo you wish to continue? Press 1 to continue and 0 to exit.";
//        int cont;
//        
//        if (cont == 1)
//            goto <#label#>
        
        
    }
    


    
    return 0;
}

