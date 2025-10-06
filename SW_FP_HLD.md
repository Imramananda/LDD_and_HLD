# Faceplate & ScreenWindow High-Level Design Document (HDD)

## 1. Overview
- Faceplate and ScreenWindow are core UI container concepts in UANativeUI, supporting embedded screens, popups, and reusable UI groups.
- Both use a common architecture for creation, rendering, and event handling, maximizing code reuse and maintainability.

## 2. Main Components
- *ScreenWindowQItem*: Common QuickItem for ScreenWindow, Faceplate, and Popup. Inherits from ScreenContainer.
- *ScreenWindowProxy*: Proxy between VCS and QML for rendering template-based items. Used for both ScreenWindow and Faceplate.
- *FaceplateContainerProxy*: Specialized proxy for Faceplate containers, inherits from ScreenWindowProxy.
- *ScreenWindowQItemBuilder*: Builder for creating QuickItems for both ScreenWindow and FaceplateContainer.
- *TopLevelScreenWindow*: Proxy between Desktop and ScreenWindowMgr for screen loading/unloading.

## 3. Key Flows
- Desktop triggers screen/faceplate loading via proxies and builders.
- Common code in ScreenWindowQItem, ScreenWindowProxy, and builder classes ensures consistent behavior.

## 4. Design Patterns
- Proxy, Builder, Singleton, Template, and common base classes for shared logic.