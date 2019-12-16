/*
     * 思路
     * 1.将keyword 存储到list 中
     * 2.按行读取到input中的数据每一行进行list匹配
     *
     *  这题通过abc查找的bc的时候，没有更好的优化思路 求解
     *
     * */
    public static void main(String[] args) {
        printResult("./input.txt" , "./keyword.conf");
    }

    public static void printResult(String inputPath, String keyword) {
        Set<String> conf = getKeyword(keyword);
        printResult(inputPath, conf);
    }

    /*
     * 匹配并输出打印输出
     * */
    private static void printResult(String inputFilePath, Set<String> keys) {
        try (FileInputStream inputStream = new FileInputStream(inputFilePath);
             BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream))) {
            String str;
            while ((str = bufferedReader.readLine()) != null) {
                //与每行的数据与keyword 进行匹配 求解更优的算法
                for (String key : keys) {
                    if (str.split(" ")[0].contains(key)) {
                        System.out.println(str);
                        break;
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /*
     * 存储keyword
     * */
    private static Set<String> getKeyword(String filePath) {
        Set<String> set = new HashSet<>();
        try (FileInputStream inputStream = new FileInputStream(filePath);
             BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream))) {
            String str;
            while ((str = bufferedReader.readLine()) != null)
                set.add(str);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return set;
    }