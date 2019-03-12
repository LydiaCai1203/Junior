/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     LineTool.java
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

public class LineTool extends CreationTool
{
  LineTool(Diagram d)
  {
    super(d) ;
  }

  Element newElement(Point start, Point stop)
  {
    return new Line(start, stop) ;
  }

  void drawElement(Graphics g)
  {
    g.drawLine( start.x, start.y, current.x, current.y ) ;
  }
}
