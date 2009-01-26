
/**
 * Appcelerator Kroll - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2009 Appcelerator, Inc. All Rights Reserved.
 */
#include <kroll/kroll.h>
#include "menu_item.h"

namespace ti
{

	MenuItem::MenuItem() : StaticBoundList()
	{

		// query methods
		this->SetMethod("isSeparator", &MenuItem::_IsSeparator);
		this->SetMethod("isItem", &MenuItem::_IsItem);
		this->SetMethod("isSubMenu", &MenuItem::_IsSubMenu);

		// mutators
		this->SetMethod("makeSeparator", &MenuItem::_MakeSeparator);
		this->SetMethod("makeItem", &MenuItem::_MakeItem);
		this->SetMethod("makeSubMenu", &MenuItem::_MakeSubMenu);

		// submenu methods
		this->SetMethod("addSeparator", &MenuItem::_AddSeparator);
		this->SetMethod("addItem", &MenuItem::_AddItem);
		this->SetMethod("addSubMenu", &MenuItem::_AddSubMenu);

	}

	MenuItem::~MenuItem()
	{
		printf("destroying: %x\n", (int) this);
	}

	void MenuItem::SetMethod(const char *name, void (MenuItem::*method)(const ValueList&, SharedValue))
	{
		MethodCallback* callback = NewCallback<MenuItem, const ValueList&, SharedValue>(static_cast<MenuItem*>(this), method);
		SharedBoundMethod bound_method = new StaticBoundMethod(callback);
		SharedValue method_value = Value::NewMethod(bound_method);
		this->Set(name, method_value);
	}

	bool MenuItem::IsSeparator()
	{
		SharedValue type = this->Get("type");
		return (type->IsInt() && type->ToInt() == SEP);
	}

	bool MenuItem::IsItem()
	{
		SharedValue type = this->Get("type");
		return (type->IsInt() && type->ToInt() == ITEM);
	}

	bool MenuItem::IsSubMenu()
	{
		SharedValue type = this->Get("type");
		return (type->IsInt() && type->ToInt() == SUBMENU);
	}

	void MenuItem::_IsSeparator(const ValueList& args, SharedValue result)
	{
		result->SetBool(this->IsSeparator());
	}

	void MenuItem::_IsItem(const ValueList& args, SharedValue result)
	{
		result->SetBool(this->IsItem());
	}

	void MenuItem::_IsSubMenu(const ValueList& args, SharedValue result)
	{
		result->SetBool(this->IsSubMenu());
	}

	void MenuItem::MakeSeparator()
	{
		this->Set("type", Value::NewInt(SEP));
		this->Set("iconURL", Value::Undefined);
		this->Set("label", Value::Undefined);
	}

	void MenuItem::MakeItem(SharedValue label,
	                       SharedValue callback,
	                       SharedValue icon_url)
	{
		this->Set("type", Value::NewInt(ITEM));
		this->Set("label", label);
		this->Set("callback", callback);
		this->Set("iconURL", icon_url);
	}

	void MenuItem::MakeSubMenu(SharedValue label,
	                          SharedValue icon_url)
	{
		this->Set("type", Value::NewInt(SUBMENU));
		this->Set("label", label);
		this->Set("iconURL", icon_url);
		this->Set("callback", Value::Undefined);
	}

	void MenuItem::_MakeSeparator(const ValueList& args, SharedValue result)
	{
		this->MakeSeparator();
	}

	void MenuItem::_MakeItem(const ValueList& args, SharedValue result)
	{
		SharedValue label = Value::Undefined;
		SharedValue icon_url = Value::Undefined;
		SharedValue callback = Value::Undefined;

		if (args.size() > 0 && args.at(0)->IsString())
			label = args.at(0);

		if (args.size() > 1 && args.at(1)->IsMethod())
			callback = args.at(1);

		if (args.size() > 2 && args.at(2)->IsString())
			icon_url = args.at(2);

		this->MakeItem(label, callback, icon_url);
	}

	void MenuItem::_MakeSubMenu(const ValueList& args, SharedValue result)
	{
		SharedValue label = Value::Undefined;
		SharedValue icon_url = Value::Undefined;

		if (args.size() > 0 && args.at(0)->IsString())
			label = args.at(0);

		if (args.size() > 1 && args.at(1)->IsString())
			icon_url = args.at(1);

		this->MakeSubMenu(label, icon_url);
	}

	SharedValue MenuItem::AddSeparator()
	{
		MenuItem* item = new MenuItem();
		item->MakeSeparator();

		SharedBoundObject so = SharedBoundObject(item);
		SharedValue v = Value::NewObject(so);
		this->Append(v);
		return v;
	}

	SharedValue MenuItem::AddItem(SharedValue label,
	                              SharedValue callback,
	                              SharedValue icon_url)
	{
		MenuItem* item = new MenuItem();
		item->MakeItem(label, callback, icon_url);

		SharedBoundObject so = SharedBoundObject(item);
		SharedValue v = Value::NewObject(so);
		this->Append(v);
		return v;
	}

	SharedValue MenuItem::AddSubMenu(SharedValue label,
	                                 SharedValue icon_url)
	{
		MenuItem* item = new MenuItem();
		item->MakeSubMenu(label, icon_url);

		SharedBoundObject so = SharedBoundObject(item);
		SharedValue v = Value::NewObject(so);
		this->Append(v);
		return v;
	}

	void MenuItem::_AddSeparator(const ValueList& args, SharedValue result)
	{
		SharedValue new_item = this->AddSeparator();
		result->SetValue(new_item);
	}

	void MenuItem::_AddItem(const ValueList& args, SharedValue result)
	{
		SharedValue label = Value::Undefined;
		SharedValue icon_url = Value::Undefined;
		SharedValue callback = Value::Undefined;

		if (args.size() > 0 && args.at(0)->IsString())
			label = args.at(0);

		if (args.size() > 1 && args.at(1)->IsMethod())
			callback = args.at(1);

		if (args.size() > 2 && args.at(2)->IsString())
			icon_url = args.at(2);

		SharedValue new_item = this->AddItem(label, callback, icon_url);
		result->SetValue(new_item);
	}

	void MenuItem::_AddSubMenu(const ValueList& args, SharedValue result)
	{
		SharedValue label = Value::Undefined;
		SharedValue icon_url = Value::Undefined;

		if (args.size() > 0 && args.at(0)->IsString())
			label = args.at(0);

		if (args.size() > 1 && args.at(1)->IsString())
			icon_url = args.at(1);

		SharedValue new_item = this->AddSubMenu(label, icon_url);
		result->SetValue(new_item);
	}

	const char* MenuItem::GetLabel()
	{
		SharedValue label_value = this->Get("label");
		if (label_value->IsString())
			return label_value->ToString();
		else
			return NULL;
	}

	const char* MenuItem::GetIconURL()
	{
		SharedValue label_value = this->Get("iconURL");
		if (label_value->IsString())
			return label_value->ToString();
		else
			return NULL;
	}

}