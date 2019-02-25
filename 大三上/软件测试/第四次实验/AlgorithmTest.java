package Test;

import static org.junit.Assert.*;

import java.util.Date;

import org.junit.Test;

public class AlgorithmTest {
	private static Algorithm algorithm = new Algorithm();
	
	@Test
	public void testCheck() {
		int[] num = new int[] {12,13,1,3,4};
		assertFalse(algorithm.check(num));
	}

	@Test
	public void testQsort() {
		int left = 0;
		int right = 4;
		int[] num = new int[] {5,4,3,2,1};
		int[] after_num = new int[] {1,2,3,4,5};
		algorithm.qsort(num, left, right);
		for(int i=0;i<num.length;i++) {
			assertEquals(after_num[i],num[i]);
		}
	}

	@Test
	public void testPartition() {
		int left = 0;
		int right = 3;
		int[] num = new int[] {4,3,2,1};
		assertEquals(3,algorithm.partition(num, left, right));
	}

	@Test
	public void testSwap() {
		int[] num = new int[] {0,1,2};
		int m = 1;
		int n = 2;
		int[] swap_num = {0,2,1};
		algorithm.swap(num, m, n);
		for(int i=0;i<2;i++) {
			assertEquals(num[i],swap_num[i]);
		}
	}

}
