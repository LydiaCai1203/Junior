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
import java.util.Vector ;
import java.util.Enumeration ;

public class DiagramEditor extends Canvas
{
  private Vector diagrams = new Vector(16) ;
  Diagram currentDiagram ;
  DiagramEditorControls controls ;

  Tool tool ;
  Image offscreen ;

  public final static int RECTANGLE = 0 ;
  public final static int LINE      = 1 ;
  public final static int ELLIPSE   = 2 ;
  public final static int SELECTION = 3 ;

  public String toolNames[] = {"Rectangle", "Line", "Ellipse", "Selection"} ;

  public DiagramEditor()
  {
    setBackground( Color.white ) ;
    newDiagram() ;
  }

  public void setControls( DiagramEditorControls c )
  {
    controls = c ;
  }

  public void setTool( int t )
  {
   switch (t) {
      case RECTANGLE:
        tool = new WrectangleTool(currentDiagram) ;
        break ;
      case LINE:
        tool = new LineTool(currentDiagram) ;
        break ;
      case ELLIPSE:
        tool = new EllipseTool(currentDiagram) ;
        break ;
      case SELECTION:
        tool = new SelectionTool(currentDiagram) ;
        break ;
    }
    repaint() ;
    if (controls != null) {
      controls.toolChoice.select(t) ;
    }
  }

  public void paint(Graphics g)
  {
    update(g) ;
  }

  public void update(Graphics g)
  {
    Dimension canvasSize = size() ;
    if (offscreen == null) {
      offscreen = this.createImage(canvasSize.width, canvasSize.height) ;
    }
    Graphics og = offscreen.getGraphics() ;
    og.setColor(getBackground()) ;
    og.fillRect(0, 0, canvasSize.width, canvasSize.height) ;
    og.setColor(Color.black) ;
    og.drawRect(0, 0, canvasSize.width-1, canvasSize.height-1) ;
    og.setColor(Color.blue) ;
    currentDiagram.draw(og) ;
    tool.draw(og) ;
    g.drawImage(offscreen, 0, 0, this) ;
  }

  public void deleteElements()
  {
    tool.delete() ;
    repaint() ;
  }

  public void nextDiagram()
  {
    if ( currentDiagram == diagrams.lastElement() ) {
      currentDiagram = (Diagram) diagrams.firstElement() ;
    }
    else {
      int diagramIndex = diagrams.indexOf(currentDiagram) ;
      currentDiagram = (Diagram) diagrams.elementAt(diagramIndex + 1) ;
    }
    setTool(RECTANGLE) ;
  }

  public void newDiagram()
  {
    currentDiagram = new Diagram() ;
    diagrams.addElement(currentDiagram) ;
    setTool(RECTANGLE) ;
  }

  public boolean mouseDown( Event e, int x, int y )
  {
    tool.press() ;
    repaint() ;
    return true ;
  }
  
  public boolean mouseDrag( Event e, int x, int y )
  {
    tool.move( new Point(x,y) ) ;
    repaint() ;
    return true ;
  }

  public boolean mouseMove( Event e, int x, int y )
  {
    tool.move( new Point(x,y) ) ;
    repaint() ;
    return true ;
  }

  public boolean mouseUp( Event e, int x, int y )
  {
    tool.release() ;
    repaint() ;
    return true ;
  }
}
