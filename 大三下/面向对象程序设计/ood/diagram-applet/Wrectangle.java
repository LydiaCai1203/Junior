/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     Wrectangle.java
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

public class Wrectangle extends Element
{
  public Wrectangle(Point p, Point q)
  {
    super(p, q) ;
  }

  void draw(Graphics g)
  {
    g.drawRect( bbox.x, bbox.y, bbox.width, bbox.height ) ;
  }
}
