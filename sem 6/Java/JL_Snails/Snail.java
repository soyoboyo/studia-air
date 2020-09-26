import java.util.Random;

public class Snail extends Thread{
	
	int[][] meadow;
	boolean[][] slimaki;
	 
	public void run()
	{
		
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
			{
				if(meadow[i][j]<9)
				meadow[i][j]++;
				if(slimaki[i][j]){
					if(meadow[i][j]>=3){
					meadow[i][j]-=3;
					}
					else
					{
						meadow[i][j] = 0;
						slimakMove(i,j);						
					}
					System.out.print("@ ");
				}
				else System.out.print(meadow[i][j]+" ");
			}	    
			System.out.println();
		}
	}
	
	public Snail()
	{
		meadow = new int[10][10];
		slimaki = new boolean[10][10];
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			{
				meadow[i][j] = 9;
				slimaki[i][j] = false;
			}
	}
	
	public void slimakMove(int xx, int yy)
	{
		
		int i=0,j=0;
		int x=xx,y=yy;
		Random r = new Random();
		while(slimaki[x+i][y+j]){		
		i = r.nextInt(3)-1;
		j = r.nextInt(3)-1;
		if(x+i>9)i=-9;		
		else if(x+i<0)i=9;		
		if(y+j>9)j=-9;
		else if(y+j<0)j=9;
		}
		slimaki[xx][yy]   = false;
		slimaki[x+i][y+j] = true;		
	}
	
	public void slimak()
	{
		
		while(true){
			run();
			try{
			Thread.sleep(1000);
			}catch(Exception e){e.printStackTrace();}
			try{
				for(int i=0;i<20;i++)System.out.println();
			}catch(Exception e){e.printStackTrace();}
			}
	}
	
	public static void main(String[] args)
	{
		Snail s = new Snail();
		Random r = new Random();
		
		//wpisanie slimakow w pola
		for(int i=0;i<6;i++)
		{
			int x = r.nextInt(10);
			int y = r.nextInt(10);
			while(s.slimaki[x][y])
			{
				 x = r.nextInt(10);
				 y = r.nextInt(10);
			}
			s.slimaki[x][y]=true;
		}
		s.slimak();
	
	}
	
	
}
