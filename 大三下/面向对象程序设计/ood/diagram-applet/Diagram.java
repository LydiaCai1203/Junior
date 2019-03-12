/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 * 
 * FILE:     Drawing.java
 *
 * JDK:      Compatible with JDK 1.0
 *
 * CONTENTS: Definition of class "Drawing"
 *
 * AUTHOR:   Mark Priestley
 * 
 * HISTORY:  Written September 1999
 */

import java.awt.* ;
import java.util.* ;

public class Diagram
{
  private Vector elements = new Vector(16) ;

  public void add( Element e )
  {
    elements.addElement(e) ;
  }

  public void remove( Element e )
  {
    elements.removeElement(e) ;
  }

  public Element find( Point p )
  {
    Enumeration enum = elements.elements() ;
    while (enum.hasMoreElements()) {
      Element e = (Element) enum.nextElement() ;
      if (e.contains(p)) {
        return e ;
      }
    }
    return null ;
  }

  public void draw( Graphics g )
  {
    Enumeration enum = elements.elements() ;
    while (enum.hasMoreElements()) {
      Element e = (Element) enum.nextElement() ;
      e.draw(g) ;
    }
  }
}

