// 一、打印
// 1、打印List
	private static void printList(List<Integer> list){
		for(Integer e: list)
			System.out.print(e + " ");
		System.out.println();
	}
// 打印Array
	private static void printArray(int[] nums){
        for(Integer e: nums)
            System.out.print(e + " ");
        System.out.println();
    }

// 2、元素交换
//由于java中的参数传递都是采用值传递的传递方式，因此不能使用引用符号。
//可以使用重新赋值的方法
private void swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
	
// 3、迭代器
List<String> list = new ArrayList<>();
Iterator<String> it = list. iterator();
while(it. hasNext()){
  String obj = it. next();
  System. out. println(obj);
}

















