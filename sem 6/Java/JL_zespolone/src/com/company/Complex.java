package com.company;

import java.util.Random;

public class Complex {
	private Double re;
	private Double im;

	public Double module() {
		return Math.sqrt(re * re + im * im);
	}

	public void conjugate() {
		Double newIm = -im;
		if (newIm < 0) {
			System.out.println(re + " " + newIm + "i");
		} else {
			System.out.println(re + " + " + newIm + "i");
		}
	}

	public Complex add(Complex z) {
		return new Complex(re + z.re, im + z.im);
	}

	public Complex sub(Complex z) {
		return new Complex((re - z.re), (im - z.im));
	}

	public Complex mul(Complex z) {
		return new Complex(re * z.re - im * z.im, re * z.im + im * z.re);
	}

	public Complex div(Complex z) {
		Double div = z.re * z.re + z.im * z.im;
		return new Complex(((re * z.re + im * z.im) / div), ((im * z.re - re * z.im) / div));
	}

	public void display() {
		if (im < 0) {
			System.out.println(re + " " + im + "i");
		} else {
			System.out.println(re + " + " + im + "i");
		}
	}

	public static void display(Complex z) {
		if (z.im < 0) {
			System.out.println(z.re + " " + z.im + "i");
		} else {
			System.out.println(z.re + " + " + z.im + "i");
		}
	}

	public Double getRe() {
		return re;
	}

	public void setRe(Double re) {
		this.re = re;
	}

	public Double getIm() {
		return im;
	}

	public void setIm(Double im) {
		this.im = im;
	}

	public Complex(Double re, Double im) {
		this.re = re;
		this.im = im;
	}

	public Complex() {
		Random rnd = new Random();
		this.re = rnd.nextDouble();
		this.im = rnd.nextDouble();
	}
}
