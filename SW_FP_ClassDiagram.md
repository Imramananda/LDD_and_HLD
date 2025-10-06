---
title: Faceplate & ScreenWindow Class Diagram
---

classDiagram
    class ScreenWindowQItem {
        +refreshDrawing()
        +compComplete()
        +setScreenWindowFrameQI()
        +getScreenWindowFrameQI()
        +setWindowFrameProperties()
    }
    class ScreenWindowFrameQuickItem {
        +getImtPtr()
        +refreshDrawing()
        +compComplete()
        +deInit()
        -paint()
    }
    class ScreenWindowProxy {
        +propertyUpdate()
        +eventForwarding()
    }
    class FaceplateContainerProxy {
        +createFaceplateScreen()
        +initialize()
    }
    class ScreenWindowQItemBuilder {
        +createQuickItem()
        +initializeCommonProps()
    }
    class TopLevelScreenWindow {
        +loadScreen()
        +unloadScreen()
    }
    ScreenWindowQItem *-- ScreenWindowFrameQuickItem
    ScreenWindowProxy <|-- FaceplateContainerProxy
    ScreenWindowQItemBuilder --> ScreenWindowQItem
    TopLevelScreenWindow --> ScreenWindowProxy
    ScreenWindowProxy --> ScreenWindowQItem