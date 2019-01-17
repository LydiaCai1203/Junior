package Test;

//从扑克牌抽5张牌，0可以为任意数，判断是否是顺子 


public class Algorithm{
	public boolean check(int[] num){ 
	    //0-13 
	    int[] pai = new int[14]; 
	    for(int n : num){ 
	        pai[n]+=1; 
	    } 
	    qsort(num,0,num.length-1); 
	    int count = pai[0]; 
	    int start = 0; 
	    if(num[0]==0){ 
	        start=num[1]; 
	    } 
	    else{ 
	        start=num[0]; 
	    } 
	    for(int i = start;i<=start+5;i++){ 
	        if(pai[i]>1)return false; 
	        count += pai[i]; 
	    } 
	    if(count == 5)return true; 
	    else return false; 
	    
	} 

	public void qsort(int[] num,int left,int right){ 
	    if(left<right){ 
	        int partition = partition(num,left,right); 
	        qsort(num,left,partition-1); 
	        qsort(num,partition+1,right); 
	    } 
	} 

	public int partition(int[] num,int left,int right){ 
	    int partition = num[left]; 
	    while(left<right){ 
	        while(left<right && num[right]>=partition){ 
	            right--; 
	        } 
	        swap(num,left,right); 
	        while(left<right && num[left]<=partition){ 
	            left++; 
	        } 
	        swap(num,left,right); 
	    } 
	    
	    return left;        
	} 

	public void swap(int[] num,int m,int n){ 
	    int temp = num[m]; 
	    num[m]=num[n]; 
	    num[n]=temp; 
	}
}