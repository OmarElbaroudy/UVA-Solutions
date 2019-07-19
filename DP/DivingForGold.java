import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class UVA {
    static scanner scanner = new scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    static int t,w,n,d[],cost[],memo[][],c;
    static StringBuilder sb;
    public static void main(String[] args) throws Exception {
        scanner.waitForInput();
        while (scanner.ready()) {
            //==================================================//
            //answer here:
            t=scanner.nextInt(); w=scanner.nextInt();
            n=scanner.nextInt();
            memo=new int[n+1][t+1];
            sb=new StringBuilder();
            d=new int[n]; cost=new int[n];
            for (int i = 0; i <n ; i++) {
                d[i]=scanner.nextInt();
                cost[i]=scanner.nextInt();
            }
            //bottom-up approach for getting max:
            for (int i=n-1; i>=0; i--){
                for (int remt=0; remt<=t; remt++){
                    if (remt-(d[i]*w*3)>=0) memo[i][remt]=Math.max(memo[i+1][remt],memo[i+1][remt-(d[i]*w*3)]+cost[i]);
                    else memo[i][remt]=memo[i+1][remt];
                }
            }
            out.println(memo[0][t]);
            c=trace(0,t);
            out.println(c);
            out.println(sb);
            //==================================================//
            out.flush();
        }
          out.close();
    }
    static int trace(int idx,int time){
        if (idx==n) return 0;
        if (memo[idx+1][time]==memo[idx][time]) return trace(idx+1,time);
        else{
            sb.append(d[idx]+" "+cost[idx]+'\n');
            return 1+trace(idx+1,time-(3*w*d[idx]));
        }
    }
}


class Pair implements Comparable<Pair> {
    public int node;
    public int value;

    public Pair(int n,int v) {
        this.node=n;
        this.value=v;
    }

    @Override
    public int compareTo(Pair o) {
        return (o.value!=value)?o.value-value:node-o.node;
    }

    public String toString(){
        return this.node+" "+this.value;
    }

}
class scanner {
    StringTokenizer st;
    BufferedReader br;

    public scanner(InputStream system) {
        br = new BufferedReader(new InputStreamReader(system));
    }

    public scanner(String file) throws Exception {
        br = new BufferedReader(new FileReader(file));
    }

    public String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public char nextChar() throws IOException {
        return next().charAt(0);
    }

    public Long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public boolean ready() throws IOException {
        return br.ready();
    }

    public void waitForInput() throws InterruptedException {
        Thread.sleep(3000);
    }

    int[] readArray(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    long[] readLongArray(int n) throws IOException {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    }
}



