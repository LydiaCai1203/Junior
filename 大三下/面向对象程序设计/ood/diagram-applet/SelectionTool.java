/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 *
 * FILE:     SelectionTool.java
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

public class SelectionTool extends Tool
{
  final static int Locating = 0 ;
  final static int Moving   = 1 ;
  final static int Resizing = 2 ;
  final static int Error    = 3 ;
  int state ;

  Point lastPoint ;

  Vector selected = new Vector(16) ;
  Element resizing ;
  
  SelectionTool(Diagram d) {
    super(d) ;
    state = Locating ;
  }

  void draw( Graphics g )
  {
    Enumeration enum = selected.elements() ;
    while (enum.hasMoreElements()) {
      Element e = (Element) enum.nextElement() ;
      e.highlight(g) ;
    }
  }

  void delete()
  {
    switch (state) {
      case Locating:
        Enumeration enum = selected.elements() ;
        while (enum.hasMoreElements()) {
          Element e = (Element) enum.nextElement() ;
	  // The following line is suggested by the sequence diagram.
          // However, use of "removeElement" in an iteration corrupts
	  // the vector "selected", so it's replaced by a call to 
	  // removeAllElements() after the iteration is complete.
          // unselect(e) ;
          diagram.remove(e) ;
        }
        selected.removeAllElements() ; // see comment above
        break ;
      case Moving:
        break ;
      case Resizing:
        break ;
      case Error:
        break ;
    }
  }
  
  void move( Point p )
  {
    current = p ;
    switch (state) {
      case Locating:
        break ;
      case Moving:
        Enumeration enum = selected.elements() ;
        while (enum.hasMoreElements()) {
          Element e = (Element) enum.nextElement() ;
          e.move(current.x-lastPoint.x, current.y-lastPoint.y) ;
        }
        break ;
      case Resizing:
        resizing.moveControl(current.x-lastPoint.x, current.y-lastPoint.y) ;
        break ;
      case Error:
        break ;
    }
    lastPoint = current ;
  }

  void press()
  {
    switch (state) {
      case Locating:
        Enumeration enum = selected.elements() ;
        while (enum.hasMoreElements()) {
          Element el = (Element) enum.nextElement() ;
          if (el.findControl(current)) {
            resizing = el ;
            break ;
          }
        }
        if (resizing != null) {
          state = Resizing ;
        } else {
          Element el = diagram.find(current) ;
          if (el != null) {
            select(el) ;
            state = Moving ;
          } else {
            state = Error ;
          }
        }
      case Moving:
        break ;
      case Resizing:
        break ;
      case Error:
        break ;
    }
  }

  void select(Element e)
  {
    if (!selected.contains(e)) {
      selected.addElement(e) ;
    }
  }

  void unselect(Element e)
  {
    selected.removeElement(e) ;
  }

  void release()
  {
    switch (state) {
      case Locating:
        break ;
      case Moving:
        state = Locating ;
        break ;
      case Resizing:
        resizing = null ;
        state = Locating ;
        break ;
      case Error:
        state = Locating ;
        break ;
    }
  }
}
