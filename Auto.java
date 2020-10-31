import java.util.*;
class Automorph
{
    public static void main()
    {
        Scanner in=new Scanner(System.in);
        int i,l,h,sq,x,c;
        System.out.println("Input Range:");
        l=in.nextInt();
        h=in.nextInt();
        System.out.println("Automorphic No.\t Square");
        for(i=l;i<=h;i++)
        {
            sq=i*i;
            x=i;
            c=1;
            while(x>0)
            {
                c=c*10;
                x=x/10;
            }
            if(sq%c==i)
            {
            System.out.println(i+"\t|\t"+sq);
        }
    }
}
}
