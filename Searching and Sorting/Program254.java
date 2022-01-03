/*
	Searching and Sorting
	Accept elements from user and cheak whether given number is present or not.(Linear Search)
	using Basic java
	29/11/21
*/
	
import java.util.*;

class Searching
{
	public boolean LinearSearch(int Arr[], int no)
	{
		int i = 0;
		for(i = 0; i < Arr.length; i++)
		{
			if(Arr[i] == no)
			{
				break;
			}
		}
		if(i == Arr.length)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

class Program254
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

		System.out.println("Entered data is :");
		for(int i = 0; i < Arr.length; i++)
		{
			System.out.println(Arr[i]);
		}

		System.out.println("Enter element to search :");
		int val = sobj.nextInt();

		Searching obj = new Searching();
		boolean bret = obj.LinearSearch(Arr,val);

		if(bret == true)
		{
			System.out.println("Element Found!");
		}
		else
		{
			System.out.println("Element Not Found!");
		}
	}
}