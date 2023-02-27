#pragma once
#include <cocos2d.h>

USING_NS_CC;

#ifdef CINNAMON_EXPORTING
#define CINNAMON_API __declspec(dllexport)
#else
#define CINNAMON_API __declspec(dllimport)
#endif

// not a macro but whatever, move later

template <class T = CCNode>
static T* getChild(CCNode* x, int i) {
    if (i < 0) i = x->getChildrenCount() + i;
    if (i < 0) return nullptr;
    if (static_cast<int>(x->getChildrenCount()) <= i) return nullptr;
    return static_cast<T*>(x->getChildren()->objectAtIndex(i));
}