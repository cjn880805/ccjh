//site.h

//Sample for ITEM ħ��������
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIsite);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	where_map.set("yz", "���ݳ�");
	where_map.set("sl", "������");
	where_map.set("bt", "����ɽ");
	where_map.set("bj", "����");
	where_map.set("hmy", "��ľ��");
	where_map.set("hs", "��ɽ");
	where_map.set("wd", "�䵱");
	where_map.set("ts", "̩ɽ");
	where_map.set("xy", "��ң��");
	where_map.set("xx", "���޺�");
	where_map.set("xs", "ѩɽ��");
	where_map.set("shl", "������");
	where_map.set("qz", "Ȫ��");
	where_map.set("lj", "���չ�");

	set_name( "ħ��������");	//set item name
	
	set_weight(100); 
	set("no_drop", "�������������뿪�㡣");
	//set("long","һ��ħ����������������ħ���������ܵ���(trans)�ĵط����¡�\n���ݳ�(yz)\n������(sl)\n����ɽ(bt)\n����(bj)\n��ľ��(hmy)\n��ɽ(hs)\n�䵱ɽ(wd)\n̩ɽ(ts)\n��ң��(xy)\n���޺�(xx)\nѩɽ��(xs)\n������(shl)\nȪ��(qz)\n���չ�(lj)");
	//set("unit","��");
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_trans(me, arg);
	return 0;
}

protected:
	CMapping where_map;

int do_trans(CChar *me, char * arg)
{
	const char * str = where_map.querystr(arg);

	if(! str[0]) 
		return notify_fail("��Ҫȥ���");

	if (! me->environment()->query("outdoors"))
		return notify_fail("���ⷿ�����޷�ʹ��ħ�����͡�");

	if (me->is_fighting())
		return notify_fail("ս�����޷�ʹ��ħ�����ͣ�");

	CRoom * r = load_room(str);

	if(! r)
		return notify_fail("û������ط���");

	char msg[255];

	strncpy(msg, me->querystr("env/msg_mout"), 255);
	if(msg[0])   
		message_vision(msg, me); 
	else    
		message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�", me);

	me->move(r);
	strncpy(msg, me->querystr("env/msg_min"), 255);
	if(msg[0])
		message_vision(msg, me);
	else 
		message_vision("$N����ӰͻȻ������һ������֮�С�", me);   
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/********************************
// transite.c   write by fan
inherit ITEM;
mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"bt":"/d/baituo/dating",
"tam":"/d/city2/tian_anm",
"hmy":"/d/heimuya/up1",
"hs":"/d/huashan/zhenyue",
"wd":"/d/wudang/chaotian",
"ts":"/d/taishan/nantian",
"xy":"/d/xiaoyao/qingcaop",
"xx":"/d/xingxiu/xxh1",
"xs":"/d/xueshan/dadian",
"shl":"/d/shenlong/dating",
"qz":"/d/quanzhou/zhongxin",
"lj":"/d/lingjiu/dating",
]);
void init()
{
	add_action("do_trans","trans");
}
virtual void create()
{
	set_name("ħ��������",({"trans site","site"}));
	set_weight(100); 
	set_max_encumbrance(8000);
	set("no_drop", "�������������뿪�㡣\n");
    if( clonep() )   
		set_default_object(__FILE__);
	else
	{ 
		 set("long",              "һ��ħ����������������ħ���������ܵ���(trans)�ĵط����¡�\n
				\t����㳡(gc)    ������(sl)  ����ɽ(bt)  �찲��(tam) \n
				\t��ľ��(hmy)     ��ɽ(hs)    �䵱ɽ(wd)  ̩ɽ(ts)    \n
				\t��ң��(xy)      ���޺�(xx)  ѩɽ��(xs)  ������(shl) \n
				\tȪ��(qz)        ���չ�(lj)\n");
		set("unit","��");
	}
}
int do_trans(string arg)
{
        object me,obj;
		string msg,str;
		str=where_map[arg];
        if( !arg||!stringp(str)) 
			return notify_fail("��Ҫȥ���\n");
		me=this_player();
        if (! environment(me)->query("outdoors"))
			return notify_fail("���ⷿ�����޷�ʹ��ħ�����͡�\n");
		if (me->is_fighting())
			return notify_fail("ս�����޷�ʹ��ħ�����ͣ�");
		str+=".c";
        if(file_size(str)<0) 
			return notify_fail("û������ط���\n");
		if( stringp(msg = me->query("env/msg_mout")) )   
		{	if (msg!="") message_vision(msg+"\n", me);} 
		else    
			message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n", me);
		me->move(str);
		if( stringp(msg = me->query("env/msg_min")) )
		{	if (msg!="") message_vision(msg+"\n", me);}
        else 
			message_vision("$N����ӰͻȻ������һ������֮�С�\n", me);   
		return 1;
}
*****************************************************/