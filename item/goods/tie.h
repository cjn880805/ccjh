//tie.h

//Sample for ITEM ʱ�մ�����
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CItie);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ʱ�մ�����");	//set item name
	
	set_weight(100); 

	set("unit","��");
	set("no_get",1);
 	set("long","һ��ʱ�մ�������������ħ���������ܴ���(goto)�ĵط����¡�\n����㳡(gc)    ������(sl)    �찲��(tam)   t�䵱ɽ(wd)      ��ң��(xy)    Ȫ��(qz)  ");
	set("value", 50000);

};
/*
virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "goto") == 0)
		return do_goto(me);
	return 0;
}

int do_goto(CChar *me)
{
	string msg,str;
	str=where_map[arg];
    if (! me->environment()->query("outdoors"))
		return notify_fail("���ⷿ�����޷�ʹ��ħ�����͡�");
	
	if (me->is_fighting())
		return notify_fail("ս�����޷�ʹ��ħ�����ͣ�");
	
	str+=".h";
    if(file_size(str)<0) 
		return notify_fail("û������ط���");
	
    if( stringp(msg = me->query("env/msg_mout")) )  
	{
		if (msg!="") message_vision(msg+"\n", me);
	} 
	else  
		message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�", me);
	me->move(str);
	if( stringp(msg = me->query("env/msg_min")) )
	{
		if (msg!="") message_vision(msg+"\n", me);
	}
    else             
		message_vision("$N����ӰͻȻ������һ������֮�С�", me);      
	return 1;
}
*/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/*************************************
// tie.c   change by zhm
inherit ITEM;
mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"tam":"/d/city2/tian_anm",
"wd":"/d/wudang/chaotian",
"xy":"/d/xiaoyao/qingcaop",
"qz":"/d/quanzhou/zhongxin",
]);
void init()
{
	add_action("do_goto","goto");
}
virtual void create()
{
	set_name("ʱ�մ�����",({"tie"}));
	set("no_get",1);
	set_weight(100); 
	set_max_encumbrance(8000);
    if( clonep() )  
	     set_default_object(__FILE__);
	else 
	{     
	set("long",              "һ��ʱ�մ�������������ħ���������ܴ���(goto)�ĵط����¡�\n
		\t����㳡(gc)    ������(sl)    �찲��(tam)   \n  
		\t�䵱ɽ(wd)      ��ң��(xy)    Ȫ��(qz)  \n");
	set("value", 50000);
	set("unit","��");
	}
}

int do_goto(string arg)
{
    object me,obj;string msg,str;str=where_map[arg];
    if( !arg||!stringp(str)) return notify_fail("��Ҫȥ���\n");
	me=this_player();
    if (! environment(me)->query("outdoors"))
		return notify_fail("���ⷿ�����޷�ʹ��ħ�����͡�\n");
	if (me->is_fighting())
		return notify_fail("ս�����޷�ʹ��ħ�����ͣ�");
	str+=".c";
    if(file_size(str)<0) 
		return notify_fail("û������ط���\n");
    if( stringp(msg = me->query("env/msg_mout")) )  
	{
		if (msg!="") message_vision(msg+"\n", me);
	} 
	else  
	message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n", me);
	me->move(str);
	if( stringp(msg = me->query("env/msg_min")) )
	{
		if (msg!="") message_vision(msg+"\n", me);
	}
    else             
		message_vision("$N����ӰͻȻ������һ������֮�С�\n", me);      
	return 1;
}
******************************************************/