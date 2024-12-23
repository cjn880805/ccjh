//wangyougu.h

//Sample for room:  血刀门忘忧谷
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_wangyougu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门忘忧谷");

	add_npc("pub_yangzong");
	
	add_door("血刀门大雪山山谷9", "血刀门大雪山山谷9", "血刀门忘忧谷");
	add_door("血刀门大雪山山谷8", "血刀门大雪山山谷8", "血刀门忘忧谷");

};


virtual int do_look(CChar * me)
{
	char msg[255];
	CContainer * weapon;
	weapon = me->query_weapon();

	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if (me->query("xy/renwu8_2") && EQUALSTR(weapon->querystr("base_name"),"yao chu"))
	{
		AddMenuItem("挖", "$0wa $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	CContainer * weapon;
	weapon = me->query_weapon();

	if(!strcmp(comm, "wa") && me->query("xy/renwu8_2") && EQUALSTR(weapon->querystr("base_name"),"yao chu"))
		return do_wa(me, arg);
	return 0;
}

int do_wa(CChar *me, char * arg)
{
	CContainer * weapon;
	weapon = me->query_weapon();
	char msg[255];
	if (! weapon)
	{
		tell_object(me,"\n$HIR手无寸铁，从何说起？");
	}
	else
	{
		if(EQUALSTR(weapon->querystr("base_name"),"yao chu"))
		{
			if (me->is_busy())
			{
				switch(random(0))
				{
				case 0:
				case 1:
					return notify_fail("我在忙着呢，你少给我乱发指令……。");
					break;
					
				case 3:
					return notify_fail("我都快累死了，你有完没完？");
					break;
				case 7:
				case 8:
					return notify_fail("太累了，让我先歇会吧……");
					break;
					
				default:
					return notify_fail("唉呀，先等等，我的锄头已经挥不动了……");
					break;
				}
			}
			if (me->query("hp") < 60)
				return notify_fail("你的体力太低了，还是先睡一觉吧。");
			
			if (!me->PresentName("yao chu",IS_ITEM))	//如果玩家身上没有带锄头
				return notify_fail("你没有锄头怎么挖呢？该不是想用宝刀宝剑来掘吧？");
			
			me->add("hp",-5);
			message_vision("\n$HIC$N看了看眼前的这片生机盎然的草地，缓缓的挥起锄头挖了起来。", me);
			if(!random(10))
			{
				load_item("baihe")->move(me);
				tell_object(me,"$HIC只见一株“$HIR百合$HIC”显露在你面前，你一阵欣喜，小心翼翼的松开锄头，用手轻轻的将它拔起揣入怀中");
			}
			me->start_busy(3);
			return 1;
		}
		else
		{
			tell_object(me,snprintf(msg, 255,"\n$HIR你的%s似乎并不适合用来挖掘。",weapon->name(1)));
		}
	}
	return 1;
}

ROOM_END;
