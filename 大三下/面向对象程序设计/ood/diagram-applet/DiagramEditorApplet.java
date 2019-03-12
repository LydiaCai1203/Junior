/*
 * Diagram Editor Application
 * --------------------------
 *
 * *** Java version ***
 * 
 * FILE:     Diaged.java
 *
 * JDK:      Compatible with JDK 1.0
 *
 * CONTENTS: Definition of class "DiagramEditor"
 *           and component classes "Controls" and "DrawCanvas"
 *
 * AUTHOR:   Mark Priestley
 * 
 * HISTORY:  Version 1.0 (March 1997)
 */ 

import java.awt.* ;
import java.applet.* ;

public class DiagramEditorApplet extends Applet
{
  public void init()
  {
    setLayout( new BorderLayout() ) ;
    DiagramEditor dc = new DiagramEditor() ;
    add( "Center", dc ) ;
    add( "North", new DiagramEditorControls(dc) ) ;
  }
}

