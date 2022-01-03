/*
	Searching and Sorting
	Accept elements from user and cheak whether given number is present or not.(Binary Search)
	using Basic java
	29/11/21
*/
	
import java.util.*;

class Searching
{
	public boolean BinarySearch(int Arr[], int no)
	{
		int start, end, mid;
		start = 0;
		end = Arr.length - 1;
		mid = (start + end) / 2;

		while(start <= end)
		{
			if(Arr[mid] == no)
			{
				break;
			}
			else if(no > Arr[mid])
			{
				start = mid + 1;
			}
			else if(no < Arr[mid])
			{
				end = mid - 1;
			}
			mid = (start + end) / 2;
		}
		
		if(Arr[mid] == no)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

class Program255
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
		boolean bret = obj.BinarySearch(Arr,val);

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