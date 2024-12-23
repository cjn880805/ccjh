//ziqitai.h

//Sample for room: 紫气台
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_ziqitai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "紫气台");
	
	add_npc("pub_compere");
	add_door("华山朝阳峰小路2", "华山朝阳峰小路2", "华山紫气台");

	set("long", "紫气台终年云遮雾掩，迷蒙不见天日，更为怪异的是：没逢下雨天，山谷之中就隐隐有紫气出现。");  
	set("biwu",1);
	set("sleep_room",1);
    
 };

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if(me->query_temp("jy/no_say"))
		{
			tell_object(me, "由于你的一些行为扰乱了游戏的秩序，这里已经不再欢迎你了！");
			me->move(load_room("佛山北帝庙"));
			return 1;
		}
		else 
		{
			CContainer * obj = Present(atol(target));
			if(!strcmp(comm, "look")||!strcmp(comm, "fight")||!strcmp(comm, "cast"))
			{
				tell_object(me, "未经申请，闲杂人等不得在此乱来。");
				return 1;
			}
			else if(!strcmp(comm, "kill"))
			{
				if(!me->query_temp("比武") )
				{
					tell_object(me, "未经申请，闲杂人等不得在此乱来。");
					return 1;
				}
				else if(!userp(obj))
				{
					return 1;
				}
				else if(!(CChar *)obj->query_temp("比武"))
				{
					tell_object(me, "你的对手尚未申请切磋资格，请换一个对手或等他申请资格后再切磋。");
					return 1;
				}
				else
				{
					me->set_temp("biwu/go",1);
					obj->set_temp("biwu/go",1);
					me->delete_temp("比武");
					obj->delete_temp("比武");
					return 0;
				}
			}
		}
		return 0;
	}

	if(strcmp(comm, "chblk") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("请选中当前房间目标.");
		obj->set_temp("jy/no_say", 1);
		message_vision("$N丢出一块胶布，啪的一声贴在$n嘴上。", me, obj); 
		return 1;
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}
ROOM_END;
