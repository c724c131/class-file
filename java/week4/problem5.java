public class problem5 {
    public static void main(String[] args){
        int r = (int) (Math.random() * 45) + 1; //첫값은 범위 +는 시작값
        int[] array = new int[] {0,0,0,0,0,0};
        array[0] = r;
        for(int i = 1; i < 6; i++) {
            int a = (int) (Math.random() * 45) + 1;
            while ( a == array[0] ||
                    a == array[1] ||
                    a == array[2] ||
                    a == array[3] ||
                    a == array[4] ||
                    a == array[5]) {
                a = (int) (Math.random() * 45) + 1;
            }
            array[i] = a;
        }
        for(Integer obj : array)
            System.out.print(obj + " ");
    }
}

//교수님의 로직 : dub = false 변수를 만들어서 만약 if문에 걸리면 dub = true 그 숫자를 추가하지 않음 idx를 올리지도 않음
