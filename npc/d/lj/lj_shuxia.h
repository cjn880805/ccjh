//lj_shuxia.h	灵鹫宫属下
//秦波 2002、6、1

NPC_BEGIN(CNlj_shuxia);

void create()
{
	if(random(2))
		set_name("岛主","dao zhu");
	else
		set_name("洞主","dong zhu");

	set("title", "灵鹫宫属下");
	if(random(2))
	{
		set("gender", "男性");
	}
	else
	{
		set("gender", "女性");
	}
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",random(53));
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);
	set("no_kill",1);
	set("chat_chance", 80);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");

	call_out(do_die, 1800);
	set("no_kill",1);
	
};



void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("lj/renwu7") && query("lj/sha")) 
	{
		tell_object(me, "$HIR众人齐声大喝：“大胆狂徒,敢来万仙大会捣乱，给我将女娃娃留下！”");
		((CUser *)me)->Ready_PK();
		((CUser *)this)->Ready_PK();
		this->kill_ob(me);	
		me->kill_ob(this);
	}
	else
	{
		CContainer * env = me->environment();
		if (!me->query("lj/renwu5")&& !me->query("lj/renwu6")) 
		{
			tell_object(me, "\n$HIC猛然见，你只见前方露出一点灯火，灯火发出绿油油的光芒，迥不同寻常灯火的色作暗红或昏黄。");
			tell_object(me, "$HIC顿时你心里不禁一惊，暗道：“邪魔外道，在此聚会，我还是少惹为妙”");
			if(DIFFERSTR(env->querystr("name"), "捻金峰"))
				me->move(load_room("武陵春帘儿谷"));
			else
				me->move(load_room("武陵春铺翠谷"));
		}
		else if(env->query("lj/wanxuanhuei")==1||(me->query("lj/renwu6")&&env->query("lj/wanxuanhuei")==atoi(me->id(1))))
		{
			if(!me->query("lj/renwu6"))
			{
				tell_object(me, "\n$HIC猛然见，你只见前方露出一点灯火，灯火发出绿油油的光芒，迥不同寻常灯火的色作暗红或昏黄。");
				tell_object(me, "\n$HIR顿时你心里不禁一惊，暗道：“邪魔外道，在此聚会!”霎时间心痒难搔，跃跃欲试。\n");
				env = load_room("武陵春捻金峰");
				env->set("lj/wanxuanhuei",atoi(me->id(1)));
				env = load_room("武陵春雪鬓峰");
				env->set("lj/wanxuanhuei",atoi(me->id(1)));
				me->set("lj/renwu6",1);
				me->del("lj/renwu5");
			}
		}
		else if(env->query("lj/wanxuanhuei")>1)
		{
			tell_object(me, "\n$HIC猛然见，你只见前方露出一点灯火，灯火发出绿油油的光芒，迥不同寻常灯火的色作暗红或昏黄。");
			tell_object(me, "$HIC顿时你心里不禁一惊，暗道：“邪魔外道，在此聚会!”霎时间你心痒难搔，跃跃欲试。");
			tell_object(me, "$HIC便在此时，左首高坡上有个声音飘了过来：“何方高人，到万仙大会来捣乱？当真将三十六洞洞主、七十二岛岛主，都不放在眼内吗？”");
			tell_object(me, "$HIC你权衡了一下，忍住好奇，掉头走了出去。");
			if(DIFFERSTR(env->querystr("name"), "捻金峰"))
				me->move(load_room("武陵春帘儿谷"));
			else
				me->move(load_room("武陵春铺翠谷"));
		}
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env;
	env = load_room("武陵春捻金峰");
	if(env->query("lj/wanxuanhuei"))
	{
		env->del("lj/wanxuanhuei");
		env = load_room("武陵春雪鬓峰");
		env->del("lj/wanxuanhuei");
		tell_room(me->environment(), "\n$BLK万仙大会插血盟誓后，大伙杀上灵鹫宫夺取解药去呀！。\n");
	}
	env = load_room("武陵春济楚谷");
	if(env->querymap("lj"))
		env->del("lj");
	destruct(me);
}

char * chat_msg()
{
	CContainer * env= load_room("武陵春济楚谷");
	if(env->query("lj/lost"))
	{
		env->del("lj/taolun");
		call_out(do_die, 5);
	}
	else if(env->query("lj/win"))
	{
		set("lj/sha",1);
		call_out(do_die, 5);
	}

	if(!random(50))
	{
		switch(random(12))
		{
		case 0:
			tell_room(environment(), "张洞主大声喝道：大家听着，今日集会之事切切不可让其他人知道。");
			break;
		case 1:
			tell_room(environment(), "李岛主偷偷的对陶寨主私语道：若是被那人的手下知道了，你我大家都免不了杀身之祸！");
			break;
		case 2:
			tell_room(environment(), "田岛主大声高叫道：每年要受那些小娘皮的折磨，老子我可受够了！");
			break;
		case 3:
			tell_room(environment(), "贾洞主低声嘀咕着：就怕是那老怪物还在山上……");
			break;
		case 4:
			tell_room(environment(), "周岛主对旁边的人说道：在下更怕此去是一个陷阱，要是真如此，那我们就惨了。");
			break;
		case 5:
			tell_room(environment(), "宋洞主将手一摆喝道：嘘！小声点！前面似乎有动静。");
			break;
		case 6:
			tell_room(environment(), "王岛主站在大石上指挥道：大伙谨守山隘要道，密林中不可走进一个外人。");
			break;
		case 7:
			tell_room(environment(), "刘洞主叹道：死得干脆，那也罢了。可大伙也都是江湖上顶天立地的汉子，却要受那生不如死的折磨！");
			break;
		case 8:
			tell_room(environment(), "鲁岛主咬牙喝道：今次如果大伙杀上缥缈峰，我倒要那些小娘皮尝尝老子的厉害！嘿嘿……");
			break;
		case 9:
			tell_room(environment(), "卫洞主对旁边的诸人说：那人威震缥缈峰已逾五十年，不知这次是不是已经过世了……");
			break;
		case 10:
			tell_room(environment(), "韩岛主低首自喃：以那人的自傲，是不会用这等手段来故意测试我们忠诚的吧？");
			break;
		case 11:
			tell_room(environment(), "若干洞主岛主聚在一起，不知谁叹了一句：哎，不知道今年什么时候生死符会发作。");
			break;
		}
	}
	return "";
}

virtual void die()
{
	tell_room(environment(), "\n$HIR我们是不会放过你们的！\n");
	destruct(this);
}

NPC_END;