import java.util.Scanner;

enum Condition 
{
    bad, good, excellent
}

enum Movement 
{
    impressionism, expressionism, naturalism
}

enum Technique
{
    oil, aquarelle, tempera
}

enum Material
{
    iron, stone, wood;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class artifacts
{
    private final int index;
    private final int year;
    private final String creator;

    public artifacts(int i, int y, String n)
    {
        index = i;
        year = y;
        creator = n;
        System.out.print("Creating an instance of artifact!\n"); 
    }

    public void getInfo()
    {
        System.out.println("   The creator is: " + creator);
        System.out.println("   The year is: " + year);
    }

    public void getIndex()
    {
        System.out.println("   Index is: " + index);
    }

};

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class masterpiece extends artifacts
{
    protected Condition condition;
    protected final Movement movement;

    public masterpiece(int i, int y, String c, Movement mov, Condition con)
    {
        super(i, y, c);
        movement = mov;
        condition = con;
        System.out.print("Creating an instance of masterpiece!\n"); 
    }

    public void set_condition(Condition c)
    {
        condition = c;
    }

    public void getInfo()
    {
        super.getInfo();
        System.out.println("   The condition is: " + condition);
        System.out.println("   The movement is: " + movement);
    }
};

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class paintings extends masterpiece
{
    private final double length;
    private final double width;
    private final Technique technique;

    public paintings(int i, int y, String c, Movement mov, Condition con, double len, double wid, Technique tech)
    {
        super(i, y, c, mov, con);
        length = len;
        width = wid;
        technique = tech;
        System.out.print("Creating an instance of painting!\n"); 
    }

    public void getInfo()
    {
        super.getInfo();
        System.out.println("   The length is: " + length);
        System.out.println("   The width is: " + width);
        System.out.println("   The technique is: " + technique);
        System.out.print("   The surface is: ");
        System.out.println(String.format("%.3f", width*length));
    }

    public void evaluate(Movement m, Condition c)
    {
        if(condition == c && movement == m)
        {
            System.out.print("   The painting is acceptable!\n");
        }

        else if(condition == Condition.excellent)
            System.out.print("   The painting is acceptable!\n");

        else 
            System.out.print("   The painting is not acceptable!\n");
    }

    public void evaluate(Movement m)
    {
        evaluate(m, Condition.good);
    }
};

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class sculptures extends masterpiece
{
    private double volume;
    private Material material;

    public sculptures(int i, int y, String c, Movement mov, Condition con, double v, Material m)
    {
        super(i, y, c, mov, con);
        volume = v;
        material = m;
        System.out.print("Creating an instance of sculpture!\n"); 
    }

    public void getInfo()
    {
        super.getInfo();
        System.out.println("   The volume is: " + volume);
        System.out.println("   The material is: " + material);
    }

    public void evaluate(Movement m, Condition c)
    {
        if(condition == c && movement == m)
        {
            System.out.print("   The sculpture is acceptable!\n");
        }

        else if(condition == Condition.excellent && c == Condition.good)
            System.out.print("   The sculpture is not acceptable!\n");

        else 
            System.out.print("   The sculpture is not acceptable!\n");
    }

    public void evaluate(Movement m)
    {
        evaluate(m, Condition.excellent);
    }
};

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

class MAIN
{   
    public static void auction(artifacts[] Artifacts, Movement mov, Condition con)
    {
        System.out.print("\n\n");
        for(int i = 0; i < Artifacts.length; i++)
        {
            System.out.println("For artifact number: " + (i + 1));
            Artifacts[i].getIndex();
            Artifacts[i].getInfo();

            if (Artifacts[i] instanceof paintings)
                ((paintings) Artifacts[i]).evaluate(mov, con);
            else if (Artifacts[i] instanceof sculptures)
                ((sculptures) Artifacts[i]).evaluate(mov, con);

            System.out.print("\n\n");
        }
    }

    public static void main(String[] args) 
    { 
        String[] ar_ch = {"Creator1", "Creator2", "Creator3", "Creator4", "Creator5", "Creator6", "Creator7", "Creator8", "Creator9", "Creator10", "Creator11", "Creator12", "Creator13", "Creator14", "Creator15", "Creator16", "Creator17", "Creator18", "Creator19", "Creator20", "Creator21", "Creator22", "Creator23", "Creator24", "Creator25", "Creator26"};
        int[] ar_in = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
        int[] ar_year = {2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 1984, 1932, 1923, 1945, 1978};
        double[] ar_d = {1.2, 3.3, 4.1, 5.2, 6.2, 1.5, 2.9, 2.0, 3.5, 4.2, 1.7, 3.6, 9.4, 7.2, 6.4, 5.2, 8.4, 9.3, 5.8, 6.8, 7.3, 7.4, 2.7, 1.8, 3.9, 6.1, 9.0};

    ///////////////////////////////////////////////////////////////////////////////

        int N = 0;
        Scanner in = new Scanner(System.in);
        System.out.print("Give N < 26: ");
        N = in.nextInt();

        while(N >= 26)
        {
            System.out.print("Give N again, it should be < 26: ");
            N = in.nextInt();
        }
    
    /////////////////////////////////////////////////////////////////////////////

        System.out.print("Give movement: ");
        in.nextLine();
        Movement movement = Movement.valueOf(in.nextLine());

        System.out.print("Give condition: ");
        String con = in.nextLine();

        in.close();
        System.out.print("\n");

        Condition condition = Condition.valueOf(con);

    ///////////////////////////////////////////////////////////////////////////////

        Technique technique = Technique.oil;
        Material material = Material.iron;
        artifacts[] array = new artifacts[N];

        for(int i = 0; i < N / 2; i++) 
        {
            array[i] = new paintings(ar_in[i], ar_year[i], ar_ch[i], Movement.expressionism, Condition.bad, ar_d[i], ar_d[i] + 2, technique);
        }
        
        for(int i = N / 2; i < N; i++) 
        {
            array[i] = new sculptures(ar_in[i], ar_year[i], ar_ch[i], Movement.impressionism, Condition.excellent, ar_d[i], material);
        }

        auction(array, movement, condition);
    } 
};