/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     Tool.java
 *
 * JDK:      Compatible with JDK 1.0
 *
 * AUTHOR:   Mark Priestley
 * 
 * HISTORY:  Version 1.0 (March 1997)
 *
 * CHANGES:  Made public class in own file (November 1998)
 */

import java.awt.* ;

public abstract class Tool
{
  Point current ;
  Diagram diagram ;

  Tool(Diagram d) {
    diagram = d ;
  }
  
  void draw(Graphics g) {}

  void delete() {}

  abstract void move( Point p ) ;
  abstract void press() ;
  abstract void release() ;
}
