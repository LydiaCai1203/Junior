/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     Element.java
 *
 * JDK:      Compatible with JDK 1.0
 *
 * AUTHOR:   Mark Priestley
 * 
 * HISTORY:  Version 1.0 (March 1997)
 *
 * CHANGES:  Made public class in own file.  (November 1998)
 */

import java.awt.* ;

public abstract class Element
{
  // This implementation assumes that all elements have four
  // control points.  Certain operations must be overridden for
  // elements with fewer, such as lines.

  static final Color highlightColor = Color.red ;
  Rectangle bbox ;
  int drag ;
  
  public Element(Point p, Point q)
  {
    resize(p, q) ;
  }

  public void move(int x, int y)
  {
    bbox.x += x ;
    bbox.y += y ;
  }

  public void resize(Point p, Point q)
  {
    bbox = new Rectangle(Math.min(p.x,q.x), Math.min(p.y,q.y),
                         Math.abs(p.x-q.x), Math.abs(p.y-q.y)) ;
  }

  public void moveControl(int x, int y)
  {
    switch (drag) {
      case 0:
        bbox.x += x ;
        bbox.y += y ;
        bbox.width -= x ;
        bbox.height -= y ;
        break ;
      case 1:
        bbox.y += y ;
        bbox.width += x ;
        bbox.height -= y ;
        break ;
      case 2:
        bbox.width += x ;
        bbox.height += y ;
        break ;
      case 3:
        bbox.x += x ;
        bbox.width -= x ;
        bbox.height += y ;
        break ;
    }
    if (bbox.width < 0) {
      bbox.x += bbox.width ;
      bbox.width = -bbox.width ;
      drag += drag%2 == 0 ? 1 : -1 ;
    }
    if (bbox.height < 0) {
      bbox.y += bbox.height ;
      bbox.height = -bbox.height ;
      drag = 3-drag ;
    }
  }

  public boolean findControl( Point p )
  {
    drag = -1 ;
    if (nearEnough(p, new Point(bbox.x, bbox.y))) {
      drag = 0 ;
    } else if (nearEnough(p, new Point(bbox.x+bbox.width, bbox.y))) {
      drag = 1 ;
    } else if (nearEnough(p, new Point(bbox.x+bbox.width, bbox.y+bbox.height))) {
      drag = 2 ;
    } else if (nearEnough(p, new Point(bbox.x, bbox.y+bbox.height))) {
      drag = 3 ;
    }
    return drag != -1 ;
  }

  public void highlight(Graphics g)
  {
    drawHighlight(g, bbox.x, bbox.y, highlightColor) ;
    drawHighlight(g, bbox.x+bbox.width, bbox.y, highlightColor) ;
    drawHighlight(g, bbox.x, bbox.y+bbox.height, highlightColor) ;
    drawHighlight(g, bbox.x+bbox.width, bbox.y+bbox.height, highlightColor) ;
  }

  Rectangle bounds()
  {
    return bbox ;
  }

  public boolean contains( Point p )
  {
    return bounds().inside(p.x, p.y) ;
  }

  void drawHighlight(Graphics g, int x, int y, Color c)
  {
    Color oldColor = g.getColor() ;
    g.setColor(c) ;
    g.drawRect(x-1, y-1, 3, 3) ;
    g.setColor(oldColor) ;
  }

  abstract void draw(Graphics g) ;
  
  boolean nearEnough( Point p0, Point p1 )
  {
    return Math.abs(p0.x - p1.x) <= 3 && Math.abs(p0.y - p1.y) <= 3 ;
  }
}
