package Java_Code;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) 
    {
        Reader read = new Reader(true);
        Writer write = new Writer(true);

        String str = read.next();
        write.println(str);

        write.close();
    }
}

class Reader 
{
    private BufferedReader br;
    private StringTokenizer st;

    public Reader(boolean readFromFile)
    {
        if(readFromFile)
        {
            try
            {
                br = new BufferedReader(new FileReader("input.txt"));
            }
            catch(FileNotFoundException e)
            {

            }
            
        }
        else 
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
    }

    public String next()
    {
        while (st == null || !st.hasMoreElements()) 
        {
            try 
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e) 
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt() { return Integer.parseInt(next()); }

    public long nextLong() { return Long.parseLong(next()); }

    public double nextDouble()
    {
        return Double.parseDouble(next());
    }

    public String nextLine()
    {
        String str = "";
        try 
        {
            str = br.readLine();
        }
        catch (IOException e) 
        {
            e.printStackTrace();
        }
        return str;
    }
}

class Writer
{
    private PrintWriter pw;

    public Writer(boolean writeToFile)
    {
        if(writeToFile)
        {
            try
            {
                pw = new PrintWriter("output.txt");
            }
            catch(FileNotFoundException e)
            {

            }
        }
        else 
        {
            new PrintWriter(System.out);
        }
    }

    public void print(Object obj)
    {
        pw.print(obj);
    }

    public void println(Object obj)
    {
        pw.println(obj);
    }

    public void close()
    {
        pw.close();
    }
}