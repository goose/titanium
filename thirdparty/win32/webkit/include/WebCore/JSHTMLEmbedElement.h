/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSHTMLEmbedElement_h
#define JSHTMLEmbedElement_h

#include "JSHTMLElement.h"
#include <runtime/CallData.h>

namespace WebCore {

class HTMLEmbedElement;

class JSHTMLEmbedElement : public JSHTMLElement {
    typedef JSHTMLElement Base;
public:
    JSHTMLEmbedElement(PassRefPtr<JSC::Structure>, PassRefPtr<HTMLEmbedElement>);
    static JSC::JSObject* createPrototype(JSC::ExecState*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    bool customGetOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue*, JSC::PutPropertySlot&);
    bool customPut(JSC::ExecState*, const JSC::Identifier&, JSC::JSValue*, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue* prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType));
    }

    virtual JSC::CallType getCallData(JSC::CallData&);

    static JSC::JSValue* getConstructor(JSC::ExecState*);
private:
    static bool canGetItemsForName(JSC::ExecState*, HTMLEmbedElement*, const JSC::Identifier&);
    static JSC::JSValue* nameGetter(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
};


class JSHTMLEmbedElementPrototype : public JSC::JSObject {
public:
    static JSC::JSObject* self(JSC::ExecState*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue* prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType));
    }
    JSHTMLEmbedElementPrototype(PassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
};

// Functions

JSC::JSValue* jsHTMLEmbedElementPrototypeFunctionGetSVGDocument(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*, const JSC::ArgList&);
// Attributes

JSC::JSValue* jsHTMLEmbedElementAlign(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLEmbedElementAlign(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLEmbedElementHeight(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLEmbedElementHeight(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLEmbedElementName(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLEmbedElementName(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLEmbedElementSrc(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLEmbedElementSrc(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLEmbedElementType(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLEmbedElementType(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLEmbedElementWidth(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSHTMLEmbedElementWidth(JSC::ExecState*, JSC::JSObject*, JSC::JSValue*);
JSC::JSValue* jsHTMLEmbedElementConstructor(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);

} // namespace WebCore

#endif