package pack1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class djkstraj_ava{
	private static int n,m,u;
	private static ArrayList<ArrayList<Pair>> ds;
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t-->0) {
			n=in.nextInt();m=in.nextInt();u=in.nextInt();
			ds=new ArrayList<>();
			for(int i=0;i<=n;i++) ds.add(new ArrayList<Pair>());
			for(int i=0;i<m;i++) {
				int a=in.nextInt(),b=in.nextInt(),c=in.nextInt();
				Pair tp=new Pair(a,c);
				Pair tp2=new Pair(b,c);
				ds.get(a).add(tp2);ds.get(b).add(tp);
			}
			djkstra();
		}
	}
	public static void djkstra() {
		int d[]=new int[n+1];
		Arrays.fill(d, 1000);
		for(int i=0;i<ds.get(u).size();i++) {
			Pair tp=ds.get(u).get(i);
			d[tp.point]=tp.c;
			//System.out.print(tp.point+" ");
		}
		int[] ok=new int[n+1];
		ok[u]=1;d[u]=0;
//		for(int i=0;i<ds.size();i++) {
//			for(int j=0;j<ds.get(i).size();j++) {
//				System.out.print(ds.get(i).get(j).point+" ");
//			}
//			System.out.println("");
//		}
		while(true) {
			int min=10000,kt=-1;
			for(int i=1;i<=n;i++) {
				if(ok[i]==0&&min>d[i]) {
					min=d[i];kt=i;
				}
			}
			//System.out.println(kt+" "+min);
			if(kt==-1) break;
			ok[kt]=1;
			for(int i=0;i<ds.get(kt).size();i++) {
				Pair tp=ds.get(kt).get(i);
				if(d[tp.point]>min+tp.c) {
					d[tp.point]=min+tp.c;
				}
				
			}
		}
		for(int i=1;i<=n;i++) System.out.print(d[i]+" ");
		System.out.println("");
	}
}
class Pair{
	public int point,c;
	public Pair(int point,int c) {
		this.point=point;this.c=c;
	}
}
