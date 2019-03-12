/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     CreationTool.java
 *
 * JDK:      Compatible with JDK 1.0
 *
 * AUTHOR:   Mark Priestley
 * 
 * HISTORY:  Written September 1999
 */

import java.awt.* ;

public abstract class CreationTool extends Tool
{
  final static int LocatingStart = 0;
  final static int LocatingStop = 1 ;
  int state ;

  Point start ;

  CreationTool(Diagram d)
  {
    super(d) ;
    state = LocatingStart ;
  }

  void draw( Graphics g )
  {
    switch (state) {
      case LocatingStart:
        break ;
      case LocatingStop:
        g.setColor(Color.pink) ;
        drawElement(g) ;
        break ;
    }
  }

  void move( Point p )
  {
    current = p ;
    switch (state) {
      case LocatingStart:
        break ;
      case LocatingStop:
        // Draw action implemented in draw() method.
        break ;
    }
  }
  
  void press()
  {
    switch (state) {
      case LocatingStart:
        start = current ;
        state = LocatingStop ;
        break ;
      case LocatingStop:
        break ;
    }
  }

  void release()
  {
    switch (state) {
      case LocatingStart:
        break ;
      case LocatingStop:
        Element e = newElement(start, current) ;
        diagram.add(e) ;
        state = LocatingStart ;
        break ;
    }
  }

  abstract Element newElement(Point start, Point stop) ;
  abstract void    drawElement(Graphics g) ;
}
