---
title: UANativeUI Class Diagram
---

classDiagram
    class RenTplController {
        +render()
        +handleEvent()
        +IMT : IntermediateTree
    }
    class DFQuickItem {
        +paint()
        +imtIterator
        +drawContext
    }
    class RenTplProxy {
        +initController()
        +handlePropertyUpdate()
    }
    class DrawContextFactory {
        +getInstance()
        +createDrawContext()
        -cache
    }
    class EventHandler {
        +storeEventInfo()
        +findEvent()
        +eventInfoVector
    }
    class IDrawContext {
        <<interface>>
        +draw()
    }
    class DrawContext {
        +saveState()
        +restoreState()
        +draw()
    }
    RenTplController --> DFQuickItem : uses
    RenTplProxy --> RenTplController : creates
    DFQuickItem --> DrawContextFactory : uses
    DrawContextFactory --> IDrawContext : creates
    DrawContextFactory --> DrawContext : creates
    DFQuickItem --> EventHandler : uses
    DrawContext --> IDrawContext : implements