# Faceplate & ScreenWindow Low-Level Design Document (LDD)

## 1. Class Responsibilities
- *ScreenWindowQItem*: Manages visual representation and logic for ScreenWindow/Faceplate/Popup.
- *ScreenWindowProxy*: Handles property updates, event forwarding, and acts as a bridge between VCS and QML.
- *FaceplateContainerProxy*: Manages embedded faceplate screens, inherits all logic from ScreenWindowProxy.
- *ScreenWindowQItemBuilder*: Constructs QuickItems for both ScreenWindow and FaceplateContainer.
- *TopLevelScreenWindow*: Directs calls from Desktop to ScreenWindowMgr.

## 2. Sequence Flows
- *Screen/Faceplate Load*: Desktop → TopLevelScreenWindow → ScreenWindowProxy/FaceplateContainerProxy → ScreenWindowQItemBuilder → ScreenWindowQItem
- *Property Update*: VCS → Proxy → QML/QuickItem
- *Unload*: Reverse of load, with cleanup in proxies and QItems.

## 3. Data Structures
- *ScreenWindowQItem*: Contains references to frame, embedded screens, and handles events.
- *Proxy Classes*: Store references to VCS objects and QML items.

## 4. Design Patterns
- Proxy: ScreenWindowProxy, FaceplateContainerProxy
- Builder: ScreenWindowQItemBuilder
- Singleton: Factories and managers
- Template: Rendering templates for look and feel