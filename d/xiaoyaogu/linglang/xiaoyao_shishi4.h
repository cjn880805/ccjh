//xiaoyao_shishi4.h 琅擐福地石室4
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_shishi4);

virtual void create()
{
	set_name( "石室4");
	set("no_autosave",1);
	set("long","这是座圆形石室，四壁岩石打磨得甚是光滑，石壁上刻满了无数径长尺许的圆圈，每个圈中都刻了各种各样的图形。。");

	add_door("琅擐福地", "逍遥谷琅擐福地", "逍遥谷琅擐福地石室4");
	set("index",4);
	add_item("shiguei");

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->query_temp("xy/renwu6_4") && me->query("xy/renwu6") && !me->query("xy/renwu6_1"))
	{
		say("你发现除了墙上有文字外，地板上更印满了凌乱的脚印，想是用来练习一种很高深的步法。", me);
		if(me->query_skill("lingboweibu",1)>200)
			AddMenuItem("练习步法", "$0lianxi $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(!me->query_temp("xy/renwu6_4") || !me->query("xy/renwu6") || me->query("xy/renwu6_1"))
		return 0;
	if(!strcmp(comm, "lianxi") && me->query_skill("lingboweibu",1)>200)
		return do_lianxi(me, arg);
	return 0;
}


int do_lianxi(CChar *me, char * arg)
{
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。");
	
   	tell_object(me, "\n$HIR你仔细琢磨着地下的步法，不右看得如痴如醉，情不自禁的按照脚印走了起来。。。");
	me->set_temp("block_msg/all",1);
	me->disable_player("练习中");
	me->call_out(wakeup, random(5)+1);
	return 1;
}

static void wakeup(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	char msg[255];
	if(!me) return;

	me->delete_temp("block_msg/all");
	me->enable_player();

	while( (me->environment())->is_character() )
		me->move((me->environment())->environment());
	
	LONG need_points =  me->skill_need_points("lingboweibu");
	LONG need_exp = 4*(need_points / me->learn_bonus() + 1);
	if(need_exp<3000)need_exp=3000+random(1500);
	
	if(me->query_valid_exp() < need_exp)
	{
		tell_object(me, "\n$HIR猛然间，你觉得浑身热气越来越盛，从丹田中不断涌将上来，身上有无数气流奔突窜跃，难过之极。");
		tell_object(me, snprintf(msg, 255, "$HIR你明白到是自己的江湖阅历不够，无法再去练习地上高深的步法，不由的叹了口气（学习%s还需%ld点经验）。\n", me->querystr_temp("lj/skill_id"), need_exp));
	}
	else if(me->query("pro/skill/lingbo_weibu")>me->query("xkd/xy"))//已经学会了
	{
		tell_object(me, "\n$HIR猛然间，你只觉得一阵头昏脑胀，无法定下心来去练习地上高深的步法。");
		tell_object(me, "$HIR你明白到是自己的武功修行已经暂时无法突破上限了，不由的叹了口气。");
	}
	else
	{
		tell_object(me,"$HIR\n地下步法甚怪，你一路演练下去，有时走了上一步后，无法接到下一步，直至想到须得凭空转一个身，这才极巧妙自然的接上了。");
		tell_object(me,"$HIR有时则须跃前纵后、左窜右闪，步法左歪右斜，没一步笔直进退。");
		tell_object(me,"$HIR细想之后，一得悟解，乐趣之大，实是难以言宣。\n");
		if(me->query_temp("xy/lingbo_weibu")<1000)	
		{
			tell_object(me, snprintf(msg, 255,"$HIR你凭借你丰富的江湖经验(-%d)，对凌波微步的领悟又深了一层。\n",need_exp));	
			me->add_temp("xy/lingbo_weibu",15+2*random(me->query_int()));
		}
		else
		{
			tell_object(me, "$HIC你脚下步法越走越快，如洛神凌波般轻盈灵动，又如彩蝶戏花般飘忽不定。\n突然你心领神会，整个人豁然顿悟，领悟出$HIW「凌波微步」$HIC的精要所在，习得$HIW「凌波微步」$HIC之$HIW「洛神凌波」$HIC。");
			me->set("pro/skill/lingbo_weibu",1);
			me->delete_temp("xy/lingbo_weibu");
			me->set("xy/renwu6_1",1); //练习领悟凌波微步之洛神凌波
		}
		me->add("combat_exp",-need_exp);
	}
	me->FlushMySkill(me);
	me->UpdateMe();
}

XiaoYao_END;
