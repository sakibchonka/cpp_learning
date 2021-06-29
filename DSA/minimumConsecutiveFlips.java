class HelloWorld{

     public static void print(int[] a){
        int n = a.length;
        for(int i=1;i<a.length;i++){
            if(a[i]!=a[i-1]){
                if(a[i]!=a[0]){
                    System.out.print("From "+i+" to ");
                }
                else
                    System.out.println(i-1);
            }
        }
        if(a[n-1]!=a[0])
            System.out.println(n-1);
     }
     
     public static void main(String []args){
        int[] arr = new int[]{0,0,1,1,0,0,1,1,0,1};
        print(arr);
     }
}