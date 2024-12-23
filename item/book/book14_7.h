//book14_7.h

//Sample for ITEM 四十二章经七
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbook14_7);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "四十二章经七");	//set item name
	
	set_weight(1000);
	set("long", "一本镶白旗的经书,封皮(binding)很精致。");
	set("unit", "本");
	set("material", "paper");
	
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
		return do_study(me);
	if(strcmp(comm, "tear") == 0)
		return do_tear(me, arg);
	return 0;
}

int do_study(CChar *me)
{
	tell_object(me,"可以用 tear <arg>。如：tear 或 tear binding。");
	return 0;
}

int do_tear(CChar * me, string dir)
{
	if( dir=="binding" ) 
	{
		if(query("hasgot"))
			message_vision("$N将封皮撕开,发现羊皮已经被取走了。", me);
		else
		{
			message_vision("$N将封皮撕开，几块羊皮掉了下来。", me);
			message_vision("$N先将羊皮上的地图记了下来，然后把它们烧掉了。", me);
			me->set("huanggong/haspi7", 1);
            set("hasgot",1);  
		}
	}
    else
	{
		message_vision("$N一下把经书撕得粉碎。", me);
		destruct(this);
	}
	
	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/********************************

inherit ITEM;
int do_tear(string arg);

void init()
{
        add_action("do_tear", "tear");
}

virtual void create()
{
        set_name("四十二章经七", ({"book7"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n一本镶白旗的经书,封皮(binding)很精致。\n");
                set("unit", "本");
                set("material", "paper");
        }
        setup();
}

int do_tear(string arg)
{
	object me;
	string dir;
	me = this_player();

        if( !arg || arg=="" ) return 0;

	if(arg=="book7")
	{
	message_vision("$N一下把经书撕得粉碎。\n", this_player());
	destruct(this_object());
	return 1;
	}

	if( sscanf(arg, "book7 %s", dir)==1 ) {
	if( dir=="binding" ) {
		if(this_object()->query("hasgot"))
		message_vision("$N将封皮撕开,发现羊皮已经被取走了。\n", this_player());
		else
		{
		message_vision("$N将封皮撕开，几块羊皮掉了下来。\n", this_player());
		message_vision("$N先将羊皮上的地图记了下来，然后把它们烧掉了。\n", this_player());
	        me->set("huanggong\haspi7", 1);
                this_object()->set("hasgot",1);  
        	}
	}
        else
	{
	message_vision("$N一下把经书撕得粉碎。\n", this_player());
	destruct(this_object());
	}
	return 1;
        }	
}
**********************/