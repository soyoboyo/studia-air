package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

		Complex x = new Complex(10.0, 100.0);
		List<Complex> numbers = new ArrayList<Complex>();
		numbers.add(new Complex(1.0, 2.0));
		numbers.add(new Complex(3.0, 4.0));
		numbers.add(new Complex(5.0, 6.0));

		x.display();
		System.out.println("module= " + x.module());
		x.conjugate();
		x.display();
		System.out.println("add");
		Complex.display(x.add(numbers.get(0)));
		System.out.println("sub");
		Complex.display(x.sub(numbers.get(1)));
		System.out.println("mul");
		Complex.display(x.mul(numbers.get(2)));
    }
}
