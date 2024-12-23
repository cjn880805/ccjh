//book14_7.h

//Sample for ITEM ��ʮ���¾���
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbook14_7);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ʮ���¾���");	//set item name
	
	set_weight(1000);
	set("long", "һ�������ľ���,��Ƥ(binding)�ܾ��¡�");
	set("unit", "��");
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
	tell_object(me,"������ tear <arg>���磺tear �� tear binding��");
	return 0;
}

int do_tear(CChar * me, string dir)
{
	if( dir=="binding" ) 
	{
		if(query("hasgot"))
			message_vision("$N����Ƥ˺��,������Ƥ�Ѿ���ȡ���ˡ�", me);
		else
		{
			message_vision("$N����Ƥ˺����������Ƥ����������", me);
			message_vision("$N�Ƚ���Ƥ�ϵĵ�ͼ����������Ȼ��������յ��ˡ�", me);
			me->set("huanggong/haspi7", 1);
            set("hasgot",1);  
		}
	}
    else
	{
		message_vision("$Nһ�°Ѿ���˺�÷��顣", me);
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
        set_name("��ʮ���¾���", ({"book7"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\nһ�������ľ���,��Ƥ(binding)�ܾ��¡�\n");
                set("unit", "��");
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
	message_vision("$Nһ�°Ѿ���˺�÷��顣\n", this_player());
	destruct(this_object());
	return 1;
	}

	if( sscanf(arg, "book7 %s", dir)==1 ) {
	if( dir=="binding" ) {
		if(this_object()->query("hasgot"))
		message_vision("$N����Ƥ˺��,������Ƥ�Ѿ���ȡ���ˡ�\n", this_player());
		else
		{
		message_vision("$N����Ƥ˺����������Ƥ����������\n", this_player());
		message_vision("$N�Ƚ���Ƥ�ϵĵ�ͼ����������Ȼ��������յ��ˡ�\n", this_player());
	        me->set("huanggong\haspi7", 1);
                this_object()->set("hasgot",1);  
        	}
	}
        else
	{
	message_vision("$Nһ�°Ѿ���˺�÷��顣\n", this_player());
	destruct(this_object());
	}
	return 1;
        }	
}
**********************/