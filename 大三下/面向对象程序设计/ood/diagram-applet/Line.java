/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     Line.java
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
import java.util.* ;

public class Line extends Element
{
  Point p0, p1 ;

  public Line(Point p, Point q)
  {
    super(p, q) ;
  }

  public void move(int x, int y)
  {
    p0.translate(x, y) ;
    p1.translate(x, y) ;
  }

  public void resize(Point p, Point q)
  {
    p0 = new Point(p.x, p.y) ;
    p1 = new Point(q.x, q.y) ;
  }

  public void moveControl(int x, int y)
  {
    switch (drag) {
      case 0:
        p0.translate(x, y) ;
        break ;
      case 1:
        p1.translate(x, y) ;
        break ;
    }
  }

  public boolean findControl( Point p )
  {
    drag = -1 ;
    if (nearEnough(p, p0)) {
      drag = 0 ;
    } else if (nearEnough(p, p1)) {
      drag = 1 ;
    }
    return drag != -1 ;
  }

  Rectangle bounds()
  {
    return new Rectangle(Math.min(p0.x,p1.x), Math.min(p0.y,p1.y),
                         Math.abs(p0.x-p1.x), Math.abs(p0.y-p1.y)) ;
  }

  public void highlight(Graphics g)
  {
    drawHighlight(g, p0.x, p0.y, highlightColor) ;
    drawHighlight(g, p1.x, p1.y, highlightColor) ;
  }
  
  void draw(Graphics g)
  {
    g.drawLine( p0.x, p0.y, p1.x, p1.y ) ;
  }
}
