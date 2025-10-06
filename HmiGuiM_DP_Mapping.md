# Design Pattern Mapping in UANativeUI

## Singleton
- *Purpose:* Ensure a class has only one instance and provide a global point of access.
- *References:*
  - source/HmiGui/src/GfxQtRH/Core/SingletonFactory.cpp/.h: SingletonFactory manages singleton instances for various types.
  - Usage: SingletonFactory::getInstance<T>(name) returns a singleton instance.
  - Example: ScreenObjectQItemBuilderFactory is accessed as a singleton.

## Factory & Abstract Factory
- *Purpose:* Create objects without specifying the exact class; abstract factory creates families of related objects.
- *References:*
  - source/HmiGui/src/GfxQtRH/Core/BuilderRegistry.h: BuilderRegistry and ScreenObjectQItemBuilderFactory register and create builder objects for UI items. Macro REGISTER_BUILDER automates builder registration.
  - source/HmiGui/src/GfxQtRH/Core/ScreenItemProxyFactory.h: ScreenItemProxyFactory creates proxies for different screen items.

## Proxy
- *Purpose:* Provide a surrogate or placeholder for another object to control access.
- *References:*
  - source/HmiGui/src/GfxQtRH/ScreenItemProxies/: Classes like RenTplProxy, SubTreeBasedRenTplProxy, and GroupObjectProxy act as proxies between the rendering host and the underlying data or logic.
  - documentation/HmiGui/2_Detailed_Design/GroupObject/src/GroupObjectProxy_SequenceDiagram.wsd: Sequence diagram shows proxy creation and usage.

## Builder
- *Purpose:* Construct complex objects step by step.
- *References:*
  - source/HmiGui/src/GfxQtRH/QuickItemBuilders/: Classes like RenTplQuickItemBuilder, PopupQuickItemBuilder, ScreenQuickItemBuilder build complex QML/Quick items.
  - BuilderRegistry manages registration and lookup of builders.

## Observer
- *Purpose:* Notify multiple objects about state changes.
- *References:*
  - source/Perfetto/sdk/perfetto.cc: TrackEventSessionObserverRegistry manages observers for event tracking.
  - Event handling in RenderingTemplate framework (see EventHandler class and sequence diagrams in documentation).

## Template
- *Purpose:* Define the skeleton of an algorithm, deferring some steps to subclasses.
- *References:*
  - Rendering templates and IMT traversal in RenderingTemplateFramework.md.
  - Classes like DFQuickItem and ImtInterpreter use template methods for rendering.

## Object Pool
- *Purpose:* Reuse objects that are expensive to create.
- *References:*
  - Not explicitly found, but caching in factories (e.g., DrawContextFactory) may act as a simple object pool.

## Adapter
- *Purpose:* Allow the interface of an existing class to be used as another interface.
- *References:*
  - Likely used in interfacing Qt/QML with internal data structures (not directly referenced in the search).

## Registry
- *Purpose:* Maintain a central registry of objects or types.
- *References:*
  - BuilderRegistry, ProxyRegistry manage mappings of types to creators.