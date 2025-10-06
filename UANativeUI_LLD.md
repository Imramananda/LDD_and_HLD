# UANativeUI Low-Level Design Document (LDD)

## 1. Class Responsibilities
- *RenTplController*: Manages rendering for template-based items, event handling.
- *DFQuickItem*: QQuickPaintedItem, renders using IMT and DrawContext.
- *RenTplProxy*: Proxy between VCS and rendering items.
- *DrawContextFactory*: Singleton, creates and caches draw contexts.
- *EventHandler*: Stores and processes event info, maps UI events to IMT elements.

## 2. Sequence Flows
- *Initialization*: Factories create controllers/items, set up services.
- *Rendering*: IMT traversed, rendered via DrawContext.
- *Event Handling*: Events captured, mapped, processed, IMT updated.

## 3. Data Structures
- *IMT (Intermediate Tree)*: Binary tree for rendering templates.
- *EventInfoVector*: Stores event mappings for UI elements.

## 4. Design Patterns (with code references)
- *Singleton*: DrawContextFactory (see source/HmiGui/src/GfxQtRH/QuickItemBuilders/)
- *Factory*: ScreenItemProxyFactory, DrawContextFactory
- *Proxy*: RenTplProxy
- *Builder*: RenTplQuickItemBuilder, PopupQuickItemBuilder
- *Observer*: EventHandler, property change notifications
- *Template*: Rendering templates, IMT traversal
- *Abstract Factory*: DrawContext creation