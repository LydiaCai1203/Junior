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
 * CONTENTS: Definition of class "DiagramEditorControls"
 *
 * AUTHOR:   Mark Priestley
 * 
 * HISTORY:  Version 1.0 (September 1999)
 */ 

import java.awt.* ;
import java.applet.* ;
 
class DiagramEditorControls extends Panel
{
  DiagramEditor diagramEditor ;

  Button deleteButton      = new Button("Delete elements") ;
  Button nextDiagramButton = new Button("Next diagram") ;
  Button newDiagramButton  = new Button("New diagram") ;
  Choice toolChoice        = new Choice() ;

  public DiagramEditorControls( DiagramEditor e )
  {
    diagramEditor = e ;
    diagramEditor.setControls(this) ;
    
    for (int i = 0; i < diagramEditor.toolNames.length; i++) {
      toolChoice.addItem(diagramEditor.toolNames[i]) ;
    }

    add(newDiagramButton) ;
    add(nextDiagramButton) ;
    add(new Label("Tool:" )) ;
    add(toolChoice) ;
    add(deleteButton) ;
  }
  
  public boolean action( Event e, Object arg )
  {
    if (e.target == deleteButton) {
      diagramEditor.deleteElements() ;
    } else if (e.target == nextDiagramButton) {
      diagramEditor.nextDiagram() ;
    } else if (e.target == newDiagramButton) {
      diagramEditor.newDiagram() ;
    } else if ( e.target == toolChoice ) {
      int toolIndex = ((Choice) e.target).getSelectedIndex() ;
      diagramEditor.setTool(toolIndex) ;
    }
    return true ;
  }
}

