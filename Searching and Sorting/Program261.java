/*
	Searching and Sorting
	Selection Sort
	1/12/21
*/
	
import java.util.*;

class Sorting
{
	public void SelectionSort(int Arr[])
	{
		int i = 0, j = 0, minindx = 0, temp = 0;
		int size = Arr.length;

		for(i = 0; i < size; i++)
		{
			minindx = i;
			for(j = i; j < size; j++)
			{
				if(Arr[minindx] > Arr[j])
				{
					minindx = j;
				}
			}
			temp = Arr[i];
			Arr[i] = Arr[minindx];
			Arr[minindx] = temp;
		}
		
	}
}

class Program261
{
	public static void main(String args[]) 
	{
		Scanner sobj = new Scanner(System.in);

		System.out.println("Enter size of array : ");
		int size = sobj.nextInt();	

		int Arr[] = new int[size];

		System.out.println("Enter the elements :");
		for(int i = 0; i < Arr.length; i++)
		{
			Arr[i] = sobj.nextInt();
		}

		Sorting obj = new Sorting();
		obj.SelectionSort(Arr);

		System.out.println("Data after Sorting :");
		for(int i = 0; i < Arr.length ; i++)
		{
			System.out.println(Arr[i]);
		}
	}
}


