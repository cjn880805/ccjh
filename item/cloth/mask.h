//mask.h

//Sample for ITEM 面具
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CImask);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "面具");	//set item name
	
	set_weight(3000);
	set("unit", "个");
	set("long", "这似乎是一个由人皮制成的面具。");
	set("value", 300);
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "pretend") == 0)
		return do_pretend(me, arg);

	return 0;
}

int do_pretend(CChar *me, char * arg)
{
	CChar * who;
	char msg[255];

	if (! strlen(arg))
		return notify_fail("你想假装谁？");

	if (strcmp(arg, "none") == 0 || strcmp(arg, "cancel") == 0)
	{
		me->delete_temp("apply/name");
		me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");
		message_vision("$N从脸上取下了一个人皮面具。", me);
		return 1;
	}

	if( ! (who = (CChar *)((me->environment())->PresentName(arg, IS_CHAR)) ) 
		|| ! who->Query(IS_LIVING) )
		return notify_fail("你想假装谁？");

	tell_object(me, snprintf(msg, 255, "你开使假装%s", who->name()));
	//	message_vision("$N戴上了一个精功制成的人皮面具。\n", this_player());
	me->set_temp("apply/name", who->name());
	me->set_temp("apply/id", arg);
	me->set_temp("apply/short", who->Query_Short());
	me->set_temp("apply/long", who->querystr("long"));
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/***********************************
// mask.c
//

inherit ITEM;

virtual void create()
{
        set_name("面具", ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "这似乎是一个由人皮制成的面具。\n");
		set("no_drop", "这样东西不能离开你。\n");
        }
        setup();
}

void init()
{
	add_action("do_pretend", "pretend");
}

int do_pretend(string arg)
{
	object who;
	if (!arg)
		return notify_fail("你想假装谁？\n");
	if (arg == "none" || arg == "cancel") {
		this_player()->delete_temp("apply/name");
		this_player()->delete_temp("apply/id");
		this_player()->delete_temp("apply/short");
		this_player()->delete_temp("apply/long");
		message_vision("$N从脸上取下了一个人皮面具。\n", this_player());
		return 1;
	}
	if(!objectp(who = present(arg, environment(this_player()))) || 
		!living(who))
		return notify_fail("你想假装谁？\n");
	write("你开使假装" + who->name() + "。\n");
//	message_vision("$N戴上了一个精功制成的人皮面具。\n", this_player());
	this_player()->set_temp("apply/name", ({who->name()}));
	this_player()->delete_temp("apply/id");
	this_player()->set_temp("apply/short", ({who->short()}));
	this_player()->set_temp("apply/long", ({who->long()}));
	return 1;
}
*************************/