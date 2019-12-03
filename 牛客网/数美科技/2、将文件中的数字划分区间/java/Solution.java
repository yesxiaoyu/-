/*
     * 思路
     *
     * 创建一个大小为1000 int数组
     * 其中 int[0] 代表 0—99
     * 其中 int[1] 代表 100—199
     * 其中 int[2] 代表 200—299
     * ……
     * 依次类推
     * 时间复杂为 O(n)
     * */
    public static void main(String[] args) {
        printResult("./input.txt");
    }

    private static void printResult(String filePath) {
        int n = 100000;
        int m = 100;
        int[] memo = new int[n / m];
        storageResult(memo, filePath);
        int temp;
        for (int i = 0; i < memo.length; i++) {
            temp = i * 100;
            System.out.println(temp + "—" + (temp + 99) + " " + memo[i]);
        }
    }

    private static void storageResult(int[] memo, String inputFilePath) {
        try (FileInputStream inputStream = new FileInputStream(inputFilePath);
             BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream))) {
            String str;
            while ((str = bufferedReader.readLine()) != null) {
                memo[Integer.parseInt(str) / 100]++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }