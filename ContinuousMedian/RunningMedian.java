import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class RunningMedian {
	public static void addNumber(int number, PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers) {
		// add number based on whether it higher than lowers root
		// or lower than highers root
		
		// if lowers is empty
		// peek(): fetch the first element of the Queue
		if(lowers.size() == 0 || number < lowers.peek())
		{
			lowers.add(number);
		}
		else
		{
			highers.add(number);
		}
	}

	// want heaps close to same size as possible
	// shift elements from bigger sized heap into smaller one
	public static void rebalance(PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers) {
		PriorityQueue<Integer> biggerHeap = lowers.size() > highers.size() ? lowers : highers;
		PriorityQueue<Integer> smallerHeap = lowers.size() > highers.size() ? highers : lowers;

		// compare size of the two heaps
		if(biggerHeap.size() - smallerHeap.size() >= 2) {
			// take the top element from bigger heap and add to the smaller heap
			// adding lower's max or higher's min
			smallerHeap.add(biggerHeap.poll()); // poll: pulls off top element (removes and returns)
		}
	}

	// looks at the two heap sizes
	// if different, take top element from larger heap
	// if same, average their tops
	public static double getMedian(PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers) {
		PriorityQueue<Integer> biggerHeap = lowers.size() > highers.size() ? lowers : highers;
		PriorityQueue<Integer> smallerHeap = lowers.size() > highers.size() ? highers : lowers;

		if(biggerHeap.size() == smallerHeap.size())
		{
			return ((double)(biggerHeap.peek() + smallerHeap.peek())) / 2;
		}
		else
		{
			return biggerHeap.peek(); // returning top element in bigger heap
		}
	}

	public static double[] getMedians(int[] array) {
		// heap for lower portion of numbers
		// maxheap
		PriorityQueue<Integer> lowers = new PriorityQueue<Integer> ( new Comparator<Integer> () {
			// custom comparator, store biggest value at top
			public int compare(Integer a, Integer b)
			{
				return -1 * a.compareTo(b);
			}
		});

		// for higher half of numbers
		// minheap
		PriorityQueue<Integer> highers = new PriorityQueue<Integer>();

		// array of medians
		double[] medians = new double[array.length];

		// iterate through all values in the array
		for(int i = 0; i < array.length; i++)
		{
			int number = array[i];
			// add number to heap
			addNumber(number, lowers, highers);
			// rebalance heap so that each heap differs in size by at most 1
			rebalance(lowers, highers);
			medians[i] = getMedian(lowers, highers);
		}

		return medians;
	}

	public static void main(String[] args) {

		System.out.println("Running Median");

		int[] array = {1,2,3,4,5};

		double[] medians = getMedians(array);

		for(int i = 0; i < medians.length; i++)
		{
			System.out.println(medians[i]);
		}
    }
}