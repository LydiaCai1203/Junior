/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     WrectangleTool.java
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

public class WrectangleTool extends CreationTool
{
  WrectangleTool(Diagram d)
  {
    super(d) ;
  }
  
  Element newElement(Point start, Point stop)
  {
    return new Wrectangle(start, stop) ;
  }

  void drawElement(Graphics g)
  {
    g.drawRect( Math.min(start.x,current.x),
                Math.min(start.y,current.y),
                Math.abs(start.x-current.x),
                Math.abs(start.y-current.y)) ;
  }
}
