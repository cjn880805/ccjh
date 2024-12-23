//wanbaolou.h 万宝楼

ROOM_BEGIN(CRBeiJing_wanbaolou);

virtual void create()
{
	set_name( "万宝楼");

	add_npc("pub_jianning");//建宁公主
	add_npc("pub_shiwei1");//建宁公主贴身侍卫
	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");
	add_npc("pub_shiwei1");

	set("no_fight",1);
	set("no_cast",1);
	
	add_door("北京东北", "北京东北", "北京万宝楼");

	set("long", "楼里堆满奇珍异宝,中间放着把整体贴金并镶嵌若干红、绿宝石的金椅，其扶手和靠背均由金凤缠绕面而成。座后为金漆屏风，屏风正中钤镌刻着“春帐穹庐小醉 宝影不知觅处 归梦隔狼河 又被河声搅碎 ........。”" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !me->query("wei/renwu2"))
	{
		if(me->query("wei/renwu1") && !me->query_temp("wei/renwu2_1"))
		{
			tell_object(me, "\n$YEL建宇公主怒喝道：“大胆刁民，见了本公主为何不下跪！左右，还不快与我拿下！”");
			tell_object(me, "$YEL一群贴身护卫一涌而上，将你按倒在地，像捆粽子般用绳子捆了个结实！\n");
			me->disable_player("捆缚中");
			me->call_out(do_tanhua, 1);
		}
		else if(me->query("wei/renwu1") && me->query_temp("wei/renwu2_1") && me->query_temp("wei/renwu2_2"))
		{
			if(!me->query_temp("wei/renwu2_4"))
			{
				tell_object(me, "\n$YEL众贴身侍卫大声惊呼：“原来是装死！”");
				//四名贴身侍卫攻击该玩家。战斗结束后，如打赢，则任务继续，否则任务失败。
				CFightRoom * obj;
				CContainer * env = me->environment();
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name("万宝楼的战斗", "fight_room");		
				obj->move(env);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				
				for(int i=0;i<4;i++)
				{
					CContainer * wei=env->present("Shi Wei");
					if(!wei)
					{
						CChar * robber = load_npc("pub_shiwei1");
						robber->set("owner",me->id(1));
						robber->move(obj);
						obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);
					}
					else
					{
						wei->set("owner",me->id(1));
						wei->move(obj);
						obj->Join_Team((CChar * )wei, CFightRoom::FIGHT_TEAM_A);
					}
				}
				obj->Begin_Fight(0);
			}
			else
			{
				tell_object(me, "\n$YEL只见建宇公主缩在屋角，一付惊慌的模样。\n");
			}
		}
	}
}

static void do_tanhua(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	int damage;
	if(me->query("pks")<10)
	{
		switch(me->query_temp("wei/tanhuan"))
		{
		case 0:
			tell_object(me, "\n建宇公主对着你嘿嘿地歼笑了几声！");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 1:
			tell_object(me, "建宇公主拿出一把精致的小匕首，用块白毛巾拭了拭，又把刀子浸入盐水里泡了一会儿，然后割开你的上衣，用匕首在你的背上画起画来！");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 2:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主用匕首在你的背上斜斜地划了一道。");
			tell_object(me, snprintf(msg, 255,"$HIR你疼得惨叫了一声，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 3:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主用匕首在你的背上划了一条直线。");
			tell_object(me, snprintf(msg, 255,"$HIR你疼得惨叫了一声，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 4:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主用匕首在你的背上快速地画了一个竖条。");
			tell_object(me, snprintf(msg, 255,"$HIR你疼得惨叫了一声，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 5:
			damage=50+random(100)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主用匕首在你的背上戳了几下！");
			tell_object(me, snprintf(msg, 255,"$HIR你疼得惨叫了一声，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 6:
			tell_object(me, "\n你终于忍受不了盐水加创伤的疼痛，两眼一黑，晕了过去。\n");
			me->delete_temp("wei/tanhuan");
			me->enable_player();
			me->set_temp("wei/renwu2_1",1);//已经受过建宇公主的折磨
			me->unconcious();
			me->move(load_room("北京万宝楼水牢"));
			break;
		}
	}
	else if(me->query("pks")<100)
	{
		switch(me->query_temp("wei/tanhuan"))
		{
		case 0:
			tell_object(me, "\n建宇公主对你冷笑了一声。");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 1:
			damage=500+random(500)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主手持一把钢刀，拎起你的左耳，一刀割了下来。");
			tell_object(me, snprintf(msg, 255,"$HIR你痛得厉声惨叫，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 2:
			damage=500+random(500)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主手持一把钢刀，拎起你的右耳，一刀割了下来。");
			tell_object(me, snprintf(msg, 255,"$HIR你痛得厉声惨叫，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 3:
			damage=500+random(500)-me->query("con");
			if(damage>me->query("hp"))
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
			}
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主手持一把钢刀，捏起你的鼻子，一刀割了下来。");
			tell_object(me, snprintf(msg, 255,"$HIR你痛得厉声惨叫，结果造成了%d点的伤害。",damage));
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 4:
			tell_object(me, "\n贴身护卫抬来一面镜子放到了你的跟前，你看到镜子里自己的古怪模样，吓得晕了过去。\n");
			me->delete_temp("wei/tanhuan");
			me->enable_player();
			me->set_temp("wei/renwu2_1",1);//已经受过建宇公主的折磨
			me->unconcious();
			me->move(load_room("北京万宝楼水牢"));
			break;
		}
	}
	else
	{
		switch(me->query_temp("wei/tanhuan"))
		{
		case 0:
			tell_object(me, "\n建宇公主哼了一声。");
			me->add_temp("wei/tanhuan",1);
			me->call_out(do_tanhua, 1);	
			break;
		case 1:
			if(me->query("hp")<4444)
			{
				damage=me->query("hp")-1;
				me->add("apply/per",-1);
				me->add("apply/con",-1);
				me->add("apply/str",-1);
				me->add("apply/dex",-1);
			}
			else
				damage=4444;
			me->add("hp",-damage);
			tell_object(me, "\n建宇公主举起一把大风刀，手起刀落，几下就把你身上能砍的地方全砍了下来。");
			tell_object(me, snprintf(msg, 255,"$HIR你还没来得及出声，就已经失去了知觉，结果造成了%d点的伤害。\n",damage));
			me->delete_temp("wei/tanhuan");
			me->enable_player();
			me->set_temp("wei/renwu2_1",1);//已经受过建宇公主的折磨
			me->unconcious();
			me->move(load_room("北京万宝楼水牢"));
			break;
		}
	}
}
ROOM_END;
