# UANativeUI High-Level Design Document (HDD)

## 1. System Context
- *Qt Rendering Host (QtRH)*: Core rendering engine for UI, decoupled from direct data services.
- *Visual Core Service (VCS)*: Provides screen data, properties, and runtime values.
- *Rendering Template Processing Unit (RTPU)*: Parses templates, generates Intermediate Tree (IMT).

## 2. Main Modules
- *RenderingTemplate Framework*: Template parsing, IMT generation, rendering.
- *Event Handling*: Captures UI events, updates IMT, triggers redraws.
- *Controls, Faceplates, Flashing, SubTree, etc.*: Specialized frameworks for UI elements.

## 3. Key Flows
- *Screen Creation*: VCS provides data → QtRH uses RTPU → IMT generated → Rendered by QtRH.
- *Event Handling*: UI event → EventHandler → IMT update → Redraw.

## 4. Main Classes (see LDD for details)
- RenTplController, DFQuickItem, RenTplProxy, DrawContextFactory, EventHandler, etc.

## 5. Design Patterns Used
- Singleton, Factory, Abstract Factory, Proxy, Builder, Observer, Template, etc.

## 6. Diagrams
- See diagrams in /documentation/HmiGui/2_Detailed_Design/Frameworks/RenderingTemplate/images/ and generated Mermaid/PlantUML files.
