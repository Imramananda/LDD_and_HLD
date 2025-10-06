
title: Faceplate & ScreenWindow Sequence Diagram
---

sequenceDiagram:

    participant Desktop
    participant TopLevelScreenWindow
    participant ScreenWindowProxy
    participant FaceplateContainerProxy
    participant ScreenWindowQItemBuilder
    participant ScreenWindowQItem

    Desktop->>TopLevelScreenWindow: Request to load screen/faceplate
    TopLevelScreenWindow->>ScreenWindowProxy: Forward load request
    ScreenWindowProxy->>ScreenWindowQItemBuilder: Create QuickItem
    ScreenWindowQItemBuilder->>ScreenWindowQItem: Instantiate and initialize
    ScreenWindowProxy->>ScreenWindowQItem: Set properties, connect events
    Note over ScreenWindowProxy,ScreenWindowQItem: For Faceplate, FaceplateContainerProxy is used
    FaceplateContainerProxy->>ScreenWindowQItemBuilder: Create QuickItem (Faceplate)
    FaceplateContainerProxy->>ScreenWindowQItem: Set up embedded screen
    ScreenWindowQItem->>ScreenWindowFrameQuickItem: (If needed) Create frame item
    ScreenWindowQItem-->>Desktop: Notify load complete


title: Faceplate & ScreenWindow UML Overview Diagram
---

flowchart TD
    Desktop[Desktop]
    TopLevelScreenWindow[TopLevelScreenWindow]
    ScreenWindowProxy[ScreenWindowProxy]
    FaceplateContainerProxy[FaceplateContainerProxy]
    ScreenWindowQItemBuilder[ScreenWindowQItemBuilder]
    ScreenWindowQItem[ScreenWindowQItem]
    ScreenWindowFrameQuickItem[ScreenWindowFrameQuickItem]

    Desktop --> TopLevelScreenWindow
    TopLevelScreenWindow --> ScreenWindowProxy
    ScreenWindowProxy --> ScreenWindowQItemBuilder
    ScreenWindowQItemBuilder --> ScreenWindowQItem
    ScreenWindowProxy --> ScreenWindowQItem
    FaceplateContainerProxy --> ScreenWindowQItemBuilder
    FaceplateContainerProxy --> ScreenWindowQItem
    ScreenWindowQItem --> ScreenWindowFrameQuickItem