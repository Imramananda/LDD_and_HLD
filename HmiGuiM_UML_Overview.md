---
title: UANativeUI UML Overview Diagram
---

flowchart TD
    VCS[Visual Core Service]
    QtRH[Qt Rendering Host]
    RTPU[Rendering Template Processing Unit]
    IMT[Intermediate Tree]
    RenTplController
    DFQuickItem
    DrawContextFactory
    DrawContext
    EventHandler

    VCS -->|Provides data| QtRH
    QtRH -->|Requests parsing| RTPU
    RTPU -->|Returns IMT| QtRH
    QtRH -->|Initializes| RenTplController
    RenTplController -->|Passes IMT| DFQuickItem
    DFQuickItem -->|Requests| DrawContextFactory
    DrawContextFactory -->|Creates| DrawContext
    DFQuickItem -->|Uses| DrawContext
    DFQuickItem -->|Uses| EventHandler