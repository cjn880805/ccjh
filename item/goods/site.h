//site.h

//Sample for ITEM 魔法传送帖
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIsite);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	where_map.set("yz", "扬州城");
	where_map.set("sl", "少林寺");
	where_map.set("bt", "白驼山");
	where_map.set("bj", "北京");
	where_map.set("hmy", "黑木崖");
	where_map.set("hs", "华山");
	where_map.set("wd", "武当");
	where_map.set("ts", "泰山");
	where_map.set("xy", "逍遥派");
	where_map.set("xx", "星宿海");
	where_map.set("xs", "雪山寺");
	where_map.set("shl", "神龙教");
	where_map.set("qz", "泉州");
	where_map.set("lj", "灵鹫宫");

	set_name( "魔法传送帖");	//set item name
	
	set_weight(100); 
	set("no_drop", "这样东西不能离开你。");
	//set("long","一张魔法传送帖，以它的魔力现在所能到达(trans)的地方如下。\n扬州城(yz)\n少林寺(sl)\n白驼山(bt)\n北京(bj)\n黑木崖(hmy)\n华山(hs)\n武当山(wd)\n泰山(ts)\n逍遥派(xy)\n星宿海(xx)\n雪山寺(xs)\n神龙教(shl)\n泉州(qz)\n灵鹫宫(lj)");
	//set("unit","张");
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
		return notify_fail("你要去哪里？");

	if (! me->environment()->query("outdoors"))
		return notify_fail("在这房间里无法使用魔法传送。");

	if (me->is_fighting())
		return notify_fail("战斗中无法使用魔法传送！");

	CRoom * r = load_room(str);

	if(! r)
		return notify_fail("没有这个地方。");

	char msg[255];

	strncpy(msg, me->querystr("env/msg_mout"), 255);
	if(msg[0])   
		message_vision(msg, me); 
	else    
		message_vision("只见一阵烟雾过後，$N的身影已经不见了。", me);

	me->move(r);
	strncpy(msg, me->querystr("env/msg_min"), 255);
	if(msg[0])
		message_vision(msg, me);
	else 
		message_vision("$N的身影突然出现在一阵烟雾之中。", me);   
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
	set_name("魔法传送帖",({"trans site","site"}));
	set_weight(100); 
	set_max_encumbrance(8000);
	set("no_drop", "这样东西不能离开你。\n");
    if( clonep() )   
		set_default_object(__FILE__);
	else
	{ 
		 set("long",              "一张魔法传送帖，以它的魔力现在所能到达(trans)的地方如下。\n
				\t中央广场(gc)    少林寺(sl)  白驼山(bt)  天安门(tam) \n
				\t黑木崖(hmy)     华山(hs)    武当山(wd)  泰山(ts)    \n
				\t逍遥派(xy)      星宿海(xx)  雪山寺(xs)  神龙教(shl) \n
				\t泉州(qz)        灵鹫宫(lj)\n");
		set("unit","张");
	}
}
int do_trans(string arg)
{
        object me,obj;
		string msg,str;
		str=where_map[arg];
        if( !arg||!stringp(str)) 
			return notify_fail("你要去哪里？\n");
		me=this_player();
        if (! environment(me)->query("outdoors"))
			return notify_fail("在这房间里无法使用魔法传送。\n");
		if (me->is_fighting())
			return notify_fail("战斗中无法使用魔法传送！");
		str+=".c";
        if(file_size(str)<0) 
			return notify_fail("没有这个地方。\n");
		if( stringp(msg = me->query("env/msg_mout")) )   
		{	if (msg!="") message_vision(msg+"\n", me);} 
		else    
			message_vision("只见一阵烟雾过後，$N的身影已经不见了。\n", me);
		me->move(str);
		if( stringp(msg = me->query("env/msg_min")) )
		{	if (msg!="") message_vision(msg+"\n", me);}
        else 
			message_vision("$N的身影突然出现在一阵烟雾之中。\n", me);   
		return 1;
}
*****************************************************/