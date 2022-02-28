package com.example;

import java.util.*;
/**
 * Hello world!
 */
public final class App {
    private App() {
    }

    /**
     * Brings your name to the world.
     * @param args The arguments of the program.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("What's your name?");
        String name = scanner.next();
        System.out.println("Hello, " + name);
    }
}
