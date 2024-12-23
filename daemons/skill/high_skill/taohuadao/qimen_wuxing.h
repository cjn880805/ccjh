//qimen_wuxing.h 奇门五行
//Code by Teapot
//2001.02.15


SKILL_BEGIN(CSqimen_wuxing);

virtual void create()
{
	set_name( "奇门五行");

	set("special", 1);

	Magic_t * magic;

	magic = add_magic("escape", do_escape);
	magic->name = "奇门遁甲";
	magic->mp = 400;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;
	
	magic = add_magic("mizheng", do_mizheng);
	magic->name = "八卦迷阵";
	magic->mp = 150;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("qimen_wuxing", 1) > 5*me->query("int"))//先天限制。
		return notify_fail("奇门五行你只能修习到这里。");

	return 1;
}

static int do_escape(CChar * me, CContainer * ob)
{
	int i;
	CContainer * troom;
	troom=me->environment();
	
	i=me->query_skill("qimen_wuxing",1);
	if( i < 100)
		return notify_fail("你对奇门五行的领悟不足！");	// 天赋２０以上的人方能施展。

	if( me->query("mp") < 400)
		return notify_fail("你的法力不足！");
	me->add("mp", -400);

	me->start_busy(6);	// Busy.

	i=i/10;	// 每次进入游戏的最大施展次数。	一般玩家上限为１５０－１００／１０＝５。

	message_vision("只见$N捻了一个响指，刹那间爆出一股青烟，$N的身形隐入不见。",me);

	if (me->query_temp("teapot/escape")>i || me->query_temp("no_fei")|| me->query_temp("no_fei_1"))		//Fail.
	{
		message_vision("可是突然一阵风吹过，青烟消散，但见$N手足无措的站在其中。",me);
		return 1;
	}

	if (!random(i+1))	// Fail:等级越高，成功率越大。
	{
		message_vision("可是突然一阵风吹过，青烟消散，但见$N手足无措的站在其中。",me);
		return 1;
	}

	me->add_temp("teapot/escape",1);

	message_vision("待到青烟消散，$N已然无影无综。",me);

	troom = load_room("桃花岛桃花轩");
	me->move(troom);
	message_vision("一阵风吹过，你发觉身边仿佛突然多了个人影，但又好象已经在这里站了很久了。",me);

	if (!random(i+1))
	{
		tell_object(me,"你逃出生天，觉得仿佛全身的精力都消散了一般……");
		me->unconcious();
	}

	return 1;
}

//奇门八卦迷阵
static int do_mizheng(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( !target || !me->is_fighting(target) )
		return notify_fail("八卦迷阵只能对战斗中的对手使用。");
	
	if(  me->query_skill("qimen_wuxing", 1) < 120 )
		return notify_fail("你对奇门五行的领悟不足！");
	
	if (me->query_temp("thd/mazed")) 
		return notify_fail("你正在陷入别人布的迷阵中。");

	if(me->query("mp") <150 ) 
		return notify_fail("你的内力不足以布一个迷阵。");

	if(me->query_temp("thd/maze") ) 
		return notify_fail("你已经布了一个迷阵了。");

	if(DIFFERSTR(me->querystr("family/family_name"), "桃花岛") )
		return notify_fail("你虽然听说过「八卦迷阵」这一招，可是却未获传授。\n");
	
	if(random(me->query_int()) > target->query_int()/2 ||
		 random(me->query_skill("qimen_wuxing", 1))> target->query_skill("qimen_wuxing", 1)/2)
	{
		msg ="\n$HIY$N一边作战，一边利用周围的石块、树枝等布了一个简单的阵，$n登时手足无措。\n"  ;
		
		int skill = me->query_skill("qimen_wuxing", 1);

		me->add_temp("apply/defense", skill/5);
		me->set_temp("thd/maze", 1);
		me->set_temp("thd/maze_id", target->object_id());
		me->UpdateMe();

		target->add_temp("apply/dodge",-(skill/10));
		target->set_temp("thd/mazed", 1);
		target->set_temp("thd/mazed_id", me->object_id());
		target->UpdateMe();

		me->call_out(remove_effect, 1, target->object_id(),skill/2);
	}
	else
	{
		msg ="\n$HIY$N一边作战，一边利用周围的石块、树枝等布了一个简单的阵，试图困住$n。\n$n沉思片刻，微然一笑，身形一闪，招架之间左一脚，右一脚，顿将你布下的迷阵尽数破去。"  ;
		me->start_busy(2);
	}
	message_vision(msg.c_str(), me, target);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG count)
{
	CChar * me = (CChar *)ob;
	CChar * target = (CChar *)(me->environment())->Present(param1);
	int skill = me->query_skill("qimen_wuxing", 1);
	if(me) 
	{
		if (!target) //如果有人离开了战斗，则将恢复双方的状态
		{
			target=(CChar *)find_object(me->query_temp("thd/maze_id"), 1);
			if(target)
			{
				target->add_temp("apply/dodge",skill/10);
				target->delete_temp("thd/mazed");
				target->delete_temp("thd/mazed_id");
				target->UpdateMe();
				tell_object(target, "\n$HIY你陷入的迷阵已经失效了。\n");
			}
			me->delete_temp("thd/maze");
			me->delete_temp("thd/maze_id");
			me->add_temp("apply/defense", - (skill/5));
			me->UpdateMe();
			tell_object(me, "\n$HIY你布的迷阵已经失效了。\n");
			return;
		}
		if (count>0 && me->is_fighting(target))
		{
			me->call_out(remove_effect, 1, target->object_id(),count-1);
			return;
		}
		me->delete_temp("thd/maze");
		me->delete_temp("thd/maze_id");
		me->add_temp("apply/defense", - (skill/5));
		me->UpdateMe();

		target->add_temp("apply/dodge",skill/10);
		target->delete_temp("thd/mazed");
		target->delete_temp("thd/mazed_id");
		target->UpdateMe();

		char msg[255];
        if (target && me->is_fighting(target))
		{
			tell_object(me, snprintf(msg, 255, "\n$HIY你布的迷阵已经被%s破坏了。\n",target->name(1)));
			if (userp(target) && living(target))
				tell_object(target,snprintf(msg, 255, "\n$HIY%s对你布的迷阵已经被你识破了。\n",me->name(1)));
		}
		else 
		{
			tell_object(me, "\n$HIY你布的迷阵已经失效了。\n");
		}
	}
}

SKILL_END;

