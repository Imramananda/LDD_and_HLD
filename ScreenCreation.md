title: UANativeUI Screen Creation Sequence Diagram
---

sequenceDiagram
    participant VCS as Visual Core Service
    participant QtRH as Qt Rendering Host
    participant RTPU as Rendering Template Processing Unit
    participant RenTplController
    participant DFQuickItem
    participant DrawContextFactory
    participant DrawContext

    VCS->>QtRH: Provide screen data
    QtRH->>RTPU: Request template parsing
    RTPU-->>QtRH: Return IMT (Intermediate Tree)
    QtRH->>RenTplController: Create and initialize
    RenTplController->>DFQuickItem: Pass IMT and resources
    DFQuickItem->>DrawContextFactory: Request draw context
    DrawContextFactory-->>DFQuickItem: Return DrawContext
    DFQuickItem->>DrawContext: Render using IMT