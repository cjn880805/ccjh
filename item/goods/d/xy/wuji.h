//wuji.h 逍遥任务特殊道具
NPC_BEGIN(CNwuji)

virtual void create()
{
	set_name("乌鸡", "wu ji");
	set("long",	"这是一只全身白毛的乌鸡，可作食用药材。");
	
	set("icon", tiger);
	
	set("race", "野兽");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	
	CVector v;
	
	v.append("bite");
	v.append("claw");
	v.append("knock");
	set("verbs", v);
	
	set("max_hp",15000);
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 250);
	set_temp("apply/armor", 200);
	set_temp("apply/damage", 400);
	set_temp("apply/dodge", 200);
	set_temp("apply/parry", 200);

	set("no_get","乌鸡拍了拍翅膀飞到了一边，挑战似的冲你叫了起来：“咯咯咯咯....蛋”。");

	call_out(do_xiadan, 900);
};

virtual int do_look(CChar * me)
{
	say("这是一只全身白毛的乌鸡，可作食用药材。", me);
	if (me->PresentName("shen",IS_ITEM))
		AddMenuItem("捕捉","$0bu $1 0",me);
	SendMenu(me);
	
	return 1;
}

static void do_xiadan(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	if(EQUALSTR(env->querystr("area"),"house"))
	{
		message_vision("\n$HIR乌鸡忽然静静的趴在地下一动不动，过了些许时间，“咯咯咯咯....蛋”的鸡鸣声传入你的耳边。\n你定睛一看，不由一乐，原来乌鸡下了一个蛋出来。",me); 
		load_item("jidan")->move(env);
	}
	me->call_out(do_xiadan, 900);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if (strcmp(comm,"bu") == 0)
	{
		if (me->is_busy())
		{
			switch(random(5))
			{
			case 0:
			case 1:
				return notify_fail("我在忙着呢，你少给我乱发指令……。");
				break;
			case 3:
				return notify_fail("我都快累死了，你有完没完？");
				break;
			default:
				return notify_fail("太累了，让我先歇会吧……");
				break;
			}
		}

		if (me->query("hp") < 60)
			return notify_fail("你的体力太低了，还是先睡一觉吧。");
		
		if (!me->PresentName("shen",IS_ITEM))	//如果玩家身上没有带绳子
			return notify_fail("以你现在的身手，还是去找根绳子来吧！");
		
		me->add("hp",-50);
		message_vision("\n$HIC$N悄悄的拿出一个绳子结成一个套圈，蹑手蹑脚的走到乌鸡后面，猛的一扔，向它套可过去。", me);
		int lvl=me->query_skill("dodge",1);
		int jump;
		if(lvl>=300)
			jump=1;
		else if(lvl>=200 )
		{
			if(random(100)>20)	jump=1;
		}
		else if(lvl>=100 )
		{
			if(random(100)>30)	jump=1;
		}
		else if(lvl>=50 )
		{
			if(random(100)>50)	jump=1;
		}
		if(jump==1)
		{
			message_vision("\n$HIR$N成功的捆住了乌鸡。",me); 
			disable_player("捆绑");
			del("no_get");
			CContainer * shen=me->present("shen");
			if(shen)
				destruct(shen);
		}
		else
		{
			message_vision("\n$HIR乌鸡拍了拍翅膀飞到了一边，挑战似的冲$N叫了起来：“咯咯咯咯....蛋”。",me); 
			message_vision("$HIR$N大感汗颜！\n",me); 
		}
		return 1;
	}
	else if (strcmp(comm,"kill") == 0 || strcmp(comm,"fight") == 0 
		||strcmp(comm,"cast") == 0 ||strcmp(comm,"get") == 0 )
	{
		message_vision("\n$HIR乌鸡拍了拍翅膀飞到了一边，挑战似的冲$N叫了起来：“咯咯咯咯....蛋”。",me); 
		message_vision("$HIR$N大感汗颜！\n",me); 
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}
NPC_END;




