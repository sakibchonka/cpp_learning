import jdk.javadoc.internal.doclets.formats.html.resources.standard;

class Main{
    public static boolean fun(int[] a,int sum){
        int curr_sum = a[0],s=0;
        for(int e=1;e<a.length;e++){
            while(curr_sum>sum && s<e-1){
                curr_sum-=a[s];
                s++;
            }
            if(curr_sum==sum)return true;
            if(e<a.length) curr_sum+=a[e];
        }
        return curr_sum==sum;
    }
    public static void main(String[] args) {
        int[] a = new int[]{1,4,20,3,10,5};
        System.out.println(fun(a,25));
    }
}