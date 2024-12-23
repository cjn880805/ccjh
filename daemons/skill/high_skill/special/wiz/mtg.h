// mtg.h 魔法风云术 NPC专用
// Teapot
// 2001-03-09

FORCE_BEGIN(CSmtg);

virtual void create()
{
	CForce::create();

	set_name( "魔法风云术");

	Magic_t * magic;

	magic = add_magic("blindinglight", do_blindinglight);
	magic->name = "眩光一闪";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("dismantlingblow", do_dismantlingblow);
	magic->name = "击散";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("globalruin", do_globalruin);
	magic->name = "世界崩坏";
	magic->mp = 100;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("disenchant", do_disenchant);
	magic->name = "消除魔障";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("spiritwave", do_spiritwave);
	magic->name = "织灵术";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("skywave", do_skywave);
	magic->name = "织天术";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("hatewave", do_hatewave);
	magic->name = "织恨术";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("ragewave", do_ragewave);
	magic->name = "织怒术";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("mightwave", do_mightwave);
	magic->name = "织力术";
	magic->mp = 50;
	magic->target = CAST_TO_NONE;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("sunscape", do_sunscape);
	magic->name = "阳景院秘术";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("stormscape", do_stormscape);
	magic->name = "岚景院秘术";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("nightscape", do_nightscape);
	magic->name = "夜景院秘术";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("thunderscape", do_thunderscape);
	magic->name = "雷景院秘术";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("thornscape", do_thornscape);
	magic->name = "荆景院秘术";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("manalock", do_manalock);
	magic->name = "法术力缠结";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("manarecover", do_manarecover);
	magic->name = "回光";
	magic->mp = 50;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("dominariajudgment", do_dominariajudgment);
	magic->name = "多明纳里亚大审判";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("lobotomy", do_lobotomy);
	magic->name = "脑叶切除";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("washout", do_washout);
	magic->name = "冲刷殆尽";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;

	magic = add_magic("repulse", do_repulse);
	magic->name = "逐退";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;

	magic = add_magic("parallaxtide", do_parallaxtide);
	magic->name = "时空震浪潮";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_BOTH;


}

int valid_enable(string usage) { return usage == "force"; }

virtual int valid_learn(CChar * me)
{
	return 0;
}

virtual int practice_skill(CChar * me)
{
	return notify_fail("法术只能用学的来增加熟练度。");
}

static int do_parallaxtide(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * obj;
	obj=me->environment();


	if( me->query("mp") <= 50 || obj->querystr("name")=="嘉兴南湖" || !target)
		return notify_fail("Parallax Tide无法使用。");

	snprintf(msg ,255,"$N集结起法术力，弹出一道蓝色的光芒击向%s，只见%s在空中溶解掉了！",target->name(),target->name());
	message_vision(msg, me);

	target->move(load_room("嘉兴南湖"));

	message_vision("空气突然一阵震动，$N的身形自虚空之中浮现出来。", target);
	target->start_busy(2);

	me->add("mp", -50);

	return 1;
}



static int do_repulse(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || target==me)	// User cannot be the target of this spell.
		return notify_fail("Repulse无法使用。");
	
	if( me->query("mp") <= 50 )
		return notify_fail("Repulse无法使用。");
	

	snprintf(msg ,255,"$N集结起法术力，念道：你这不请自来的家伙！只见一道蓝色的光芒击向%s，%s被震到十丈开外！",target->name(),target->name());
	message_vision(msg, me);

	CContainer * obj;
	obj=me->environment();
	CContainer * obj2;
	obj2=obj->environment();
	target->move(obj2);

	message_vision("$N被从战斗中震了出来。", target);
	target->start_busy(2);

	me->add("mp", -50);

	return 1;
}


static int do_washout(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || userp(target) )	// User cannot be the target of this spell.
		return notify_fail("Wash out无法使用。");
	
	if( me->query("mp") <= 50 )
		return notify_fail("你的法术力不够！");
	
	DTItemList * list = target->Get_ItemList();
	CContainer * item;
	POSITION pos;
	
	snprintf(msg ,255,"$N集结起法术力，凝成一道蓝色的光芒击向%s，只见%s轻轻一晃！",target->name(),target->name());
	message_vision(msg, me);
	
	if(list->GetCount())
	{
		
		
		pos = list->GetHeadPosition();
		while(pos)
		{
			item = list->GetNext(pos);
			target->command(snprintf(msg, 255, "drop %ld", item->object_id()));
		}
	}
	
	message_vision("$N离开游戏。", target);
	destruct(target);
	
	me->add("mp", -50);

	return 1;
}




static int do_lobotomy(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target /*|| !me->is_fighting(target)*/ )
		return notify_fail("Lobotomy无法使用。");
	
	if( me->query("mp") <= 50 )
		return notify_fail("你的法术力不够！");
	
	
	
	
	DTItemList * list = target->Get_ItemList();
	CContainer * item;
	POSITION pos;
	
	if(list->GetCount())
	{
		
		snprintf(msg ,255,"$N集结起法术力，凝成一道蓝色的光芒击向%s，%s一阵恍惚，只觉得心中空荡荡的，什么也不记得！",target->name(),target->name());
		message_vision(msg, me);
		
		pos = list->GetHeadPosition();
		while(pos)
		{
			item = list->GetNext(pos);
			target->command(snprintf(msg, 255, "drop %ld", item->object_id()));
		}
	}
	else
		return notify_fail("没有Lobotomy可以指定的合法目标！");
	
	
	me->add("mp", -50);
	
	return 1;
}



static int do_dominariajudgment(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("Dominaria's Judgment无法使用。");
	
	if( me->query("mp") < 250 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"一轮苍白之月自南方升起，多明纳里亚五色的光辉照耀着$N，$N精神一振，发动全力一击！");
	message_vision(msg, me);

	int i;
	i=me->query("mp");
	me->set("mp_factor",i);

	i=me->query("level");
	me->set("level",300);
	me->add_temp("apply/attack",30000000);

	g_Combatd.Do_Attack(me,target,CCombatd::TYPE_REGULAR);
	
	me->add_temp("apply/attack",-30000000);
	me->set("level",i);
	me->set("mp_factor",0l);
//	me->set("mp",0);

//	me->add("mp", -250);

	return 1;
}

static int do_sunscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("阳景院秘术无法使用。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"突然$N额头上的铭印爆出白光，只听$N大喝道：所有人都须同心协力，否则胜利永远不会降临！");
	message_vision(msg, me);
	snprintf(msg ,255,"$N似乎受到了极大的震动！");
	message_vision(msg, target);
	int i;
	i=target->query("repute");
	i=me->query("repute")-i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_stormscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("岚景院秘术无法使用。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"突然$N额头上的铭印爆出蓝光，只听$N大喝道：安息吧！你没赢也没输，但战争对你而言，依旧是结束了！");
	message_vision(msg, me);
	snprintf(msg ,255,"$N似乎受到了极大的震动！");
	message_vision(msg, target);
	int i;
	i=target->query("mp");
	i=me->query("mp")-i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",1,me);
	target->add("mp",-i);
	target->receive_damage("hp",1,me);
	me->add("mp", -50);
	return 1;
}

static int do_nightscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("夜景院秘术无法使用。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"突然$N额头上的铭印爆出黑芒，只听$N大喝道：他们的到来，意味着你的把戏结束了！");
	message_vision(msg, me);
	snprintf(msg ,255,"$N似乎受到了极大的震动！");
	message_vision(msg, target);
	int i;
	i=target->query("repute");
	i=me->query("repute")+i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_thunderscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("雷景院秘术无法使用。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"突然$N额头上的铭印爆出赤芒，只听$N大喝道：火焰是举世共通的语言！");
	message_vision(msg, me);
	snprintf(msg ,255,"$N似乎受到了极大的震动！");
	message_vision(msg, target);
	int i;
	i=target->query("hp");
	i=me->query("hp")-i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_thornscape(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("荆景院秘术无法使用。");
	
	if( me->query("mp") < 50 )
		return notify_fail("你的法术力不够！");
	
	snprintf(msg ,255,"突然$N额头上的铭印爆出青华，只听$N大喝道：除了梦想，你能夺走我的一切，但仅留存梦想便已足够！");
	message_vision(msg, me);
	snprintf(msg ,255,"$N似乎受到了极大的震动！");
	message_vision(msg, target);
	int i;
	i=target->query("mp");
	i=me->query("mp")+i;
	if (i<0)
		i=-i;
	target->receive_damage("hp",i,me);
	me->add("mp", -50);
	return 1;
}

static int do_mightwave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N轻轻道：让我的力量坚定你的决心……", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/str",20);
		target->call_out(do_removegreenspelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removegreenspelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/str",-20);
	message_vision("$N身上绿光消散，所中的织力术的效果消退了。", me);
	return ;
}


static int do_ragewave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N轻轻道：让我的热情激励你的胜利……", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/dex",20);
		target->call_out(do_removeredspelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removeredspelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/dex",-20);
	message_vision("$N身上红光消散，所中的织怒术的效果消退了。", me);
	return ;
}


static int do_hatewave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N轻轻道：让我的仇恨增强你的愤怒……", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/damage",300);
		target->call_out(do_removeblackspelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removeblackspelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/damage",-300);
	message_vision("$N身上黑光消散，所中的织恨术的效果消退了。", me);
	return ;
}







static int do_skywave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N轻轻道：让我的智慧赐与你羽翼……", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/dodge",1000);
		target->call_out(do_removebluespelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removebluespelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/dodge",-1000);
	message_vision("$N身上蓝光消散，所中的织天术的效果消退了。", me);
	return ;
}



static int do_spiritwave(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N轻轻道：让我的希望成为你的盾……", me);

	DTItemList search;
	CopyList(&search, (me->environment())->Get_ItemList());
	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(target==me) continue;
		if(target->is_fighting(me)) continue;
		target->add_temp("apply/armor",1000);
		target->call_out(do_removewhitespelleffect, 15, target->object_id(), 1);	// REMOVE EFFECT
		
	}

	return 1;
}
static void do_removewhitespelleffect(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	ob1->add_temp("apply/armor",-1000);
	message_vision("$N身上白光消散，所中的织灵术的效果消退了。", me);
	return ;
}


static int do_disenchant(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target /*|| !me->is_fighting(target)*/ )
		return notify_fail("Disenchant无法使用。");
	
	if( me->query("mp") <= 50 )
		return notify_fail("你的法术力不够！");
	

		DTItemList * list = target->Get_ItemList();
		CContainer * item;
		POSITION pos;
		int flag;
	
		if(list->GetCount())
		{
									
		pos = list->GetHeadPosition();
			while(pos)
			{
				item = list->GetNext(pos);
				if (item->query("equipped") && item->query("apply/damage"))
				{
					flag=1;
					break;
				}	
			}
			if (!flag)
				return notify_fail("没有Disenchant可以指定的合法目标！");
		}
		else
				return notify_fail("没有Disenchant可以指定的合法目标！");
		if (!item->query("equipped") || !item->query("apply/damage"))
				return notify_fail("没有Disenchant可以指定的合法目标！");

	snprintf(msg ,255,"$N集结起法术力，凝成一道白色的光芒，击向%s！只听一声脆响，%s手中的武器已经散裂！",target->name(),target->name());
	message_vision(msg, me);
	item->set("no_sell",1);
	item->del("apply");
	item->set_name( snprintf(msg, 255, "被Disenchant打坏的%s", item->name()));	
	item->move(me->environment());
	
	me->add("mp", -50);

	return 1;
}


static int do_globalruin(CChar * me, CContainer * ob)
{
	CContainer * obj;
	obj=me->environment();
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");
	if (!obj->query("room_locked"))
		return notify_fail("Global Ruin无法指定有效目标！");

	me->add("mp", -100);
	message_vision("$N口中念念有词道：大地摇撼，天降火雨，世界毀灭！", me);
	message_vision("只听一声轰然大震，仿佛什么开裂了一般！", me);
	obj->set("room_locked",0l);

	return 1;

}

static int do_dismantlingblow(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target /*|| !me->is_fighting(target)*/ )
		return notify_fail("Dismantling Blow无法使用。");
	
	if( me->query("mp") <= 50 )
		return notify_fail("你的法术力不够！");
	

		DTItemList * list = target->Get_ItemList();
		CContainer * item;
		POSITION pos;
		int flag;
	
		if(list->GetCount())
		{
									
		pos = list->GetHeadPosition();
			while(pos)
			{
				item = list->GetNext(pos);
				if (item->query("equipped") && item->query("apply/armor"))
				{
					flag=1;
					break;
				}	
			}
			if (!flag)
				return notify_fail("没有Dismantling Blow可以指定的合法目标！");
		}
		else
				return notify_fail("没有Dismantling Blow可以指定的合法目标！");
		if (!item->query("equipped") || !item->query("apply/armor"))
				return notify_fail("没有Dismantling Blow可以指定的合法目标！");

	snprintf(msg ,255,"$N集结起法术力，凝成一道白色的光芒，击向%s！只听一声脆响，%s身上的穿着已经散裂！",target->name(),target->name());
	message_vision(msg, me);
	
	item->del("apply");
	item->set("no_sell",1);
	item->set_name( snprintf(msg, 255, "被Dismantling Blow打坏的%s", item->name()));	
	item->move(me->environment());
	
	me->add("mp", -50);

	return 1;
}

static int do_blindinglight(CChar * me, CContainer * ob)
{
	if(me->query("mp") < 100) 
		return notify_fail("你的法力不足！");

	me->add("mp", -100);

	message_vision("$N口中念念有词道：天使的利剑只能穿过身体，但我的正直却能透达內心！", me);


	//眩光一闪攻击敌、我全体！
	DTItemList search;

	CopyList(&search, (me->environment())->Get_ItemList());

	POSITION p;
	p = search.GetHeadPosition();
	while(p)
	{
//		char msg[255];
		CContainer * obj = search.GetNext(p);
		CChar * target;
		
		if(! obj->is_character()) continue;
		target = (CChar *)obj;

//		if(! target->is_fighting(me)) continue;
		if(target==me) continue;
		
		target->start_busy(5);
		target->SendState();

//		msg="只见眩光一闪，$N的眼前一片白芒！";
		message_vision("只见眩光一闪，$N的眼前一片白芒！", target);
	}

//	me->start_busy(1+random(2));	// Cose 2W.
	return 1;
}

static int do_manalock(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
//	CContainer * weapon;
	char msg[255];

	if(ob && ob->is_character())
		target = (CChar *)ob;

 	if( !target || !me->is_fighting(target) )
		return notify_fail("法术力缠结无法使用。");
	
//	if (! (weapon = me->query_weapon())
//		||  weapon->querystr("skill_type") != "sword")
//		return notify_fail("连山绝鼗无法使用。");
	
	if( me->query("mp") <= 1500 )
	{
		me->set("mp",0l);
		return notify_fail("你的法术力不够！");
	}
	
	snprintf(msg ,255,"$N集结起法术力，凝成淡蓝色的光芒环绕在%s周围，困住了%s！",target->name(),target->name());
	message_vision(msg, me);
	
	
	me->add("mp", -1500);
	me->start_busy(2);
	target->start_busy(2);

	me->call_out(do_kml, 1, target->object_id(), 1);	// Keep Manalock

	
	return 1;
	
}

static void do_kml(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
	CChar * target = (CChar *)(me->environment())->Present(param1);
//	CContainer * weapon;
	char msg[255];


	if( !target || !me->is_fighting(target) )
		return ;
	
	if(! living(me))
		return ;

	if( me->query("mp") < 1500 )
	{
		tell_object(me,"你的法力衰竭了。");
		snprintf(msg ,255,"淡蓝色的光芒渐渐消失不见了。");
		target->start_busy(1);
		me->start_busy(3);
		me->set("mp",0l);
		message_vision(msg, me);
		return ;
	}

	me->add("mp",-1500);

	snprintf(msg ,255,"一阵淡蓝色的光芒在$N周身跳动。");
	message_vision(msg, target);

	me->start_busy(2);
	target->start_busy(2);

	me->call_out(do_kml, 1, target->object_id(), 1);	// Keep Manalock



}




static int do_manarecover(CChar * me, CContainer * ob)
{
	char msg[255];

	if(ob !=me)
		return notify_fail("你只能对自己施展回光。");

	if( me->query("hp") <= 2000 )
		return notify_fail("你的生命不够！");
	
	snprintf(msg ,255,"$N集结起所有生气，凝成淡白色的光芒环绕在自己周围！");
	message_vision(msg, me);
	
	me->add("hp", -2000);
	me->add("mp", 1500);

	me->call_out(do_kmr, 1, me->object_id(), 1);	// Keep Manalock
	return 1;
}

static void do_kmr(CContainer *ob1, LONG  param1, LONG amount1)
{
	CChar * me = (CChar *)ob1;
//	CChar * target = (CChar *)(me->environment())->Present(param1);
//	CContainer * weapon;
	char msg[255];


//	if( !target || !me->is_fighting(target) )
//		return ;
	
	if(! living(me))
		return ;

	if( me->query("hp") <= 2000 )
	{
		tell_object(me,"你的生命衰竭了。");
		snprintf(msg ,255,"淡白色的光芒渐渐消失不见了，$N晃了两下，摔倒在地上。");
		me->set("hp",0l);
		message_vision(msg, me);
		me->unconcious();
		return ;
	}

	me->add("hp",-2000);
	me->add("mp",1500);

	snprintf(msg ,255,"一阵淡白色的光芒在$N周身跳动。");
	message_vision(msg, me);

	me->call_out(do_kmr, 1, 1, 1);	// Keep Manalock
}

FORCE_END;
