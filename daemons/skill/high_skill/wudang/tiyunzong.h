// tiyunzong.c 梯云纵

FORCE_BEGIN(CStiyunzong);

virtual void create()
{
	set_name( "梯云纵");
	
	Magic_t * magic;

	magic = add_magic("zong", do_zong);
	magic->name = "梯云纵";
	magic->mp = 350;
	magic->target = CAST_TO_ME;
	magic->valid_cast = CAST_IN_BOTH;

}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
			{"只见$n一招「白鹤冲天」，身体向上笔直地纵起丈余，躲过了$N这一招。"},
			{"$n一个「鹞子翻身」，向后纵出数丈之远，避开了$N的凌厉攻势。"},
			{"$n使出「大鹏展翅」，向一旁飘然纵出，轻轻着地。"}
	};

	return action[random(3)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me)
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练梯云纵。");
	me->receive_damage("hp", 30);
	return 1;
}

static int do_zong(CChar * me, CContainer * ob)
{
	if(!me->is_fighting() )
		return notify_fail("\n「梯云纵」只能在战斗中使用。");
	
	if(me->query_skill("tiyunzong",1) < 200 )
		return notify_fail("\n你的梯云纵不够娴熟，不会使用「梯云纵」！");
	
	if(me->query_skill("taiji_shengong",1) < 120 )
		return notify_fail("\n你的太极神功等级不够，不能使用「梯云纵」！");  
	
	if(me->query_dex() < 28 )
		return notify_fail("\n你的身法太低，不能使用「梯云纵」！");
	
	if(me->query_skill("dodge",1) < 200 )
        return notify_fail("\n你的基本轻功太差，身体笨拙，不能使用「梯云纵」！");
	
	if(me->query("mp") < 400 )
		return notify_fail("\n你的内力太少了，无法使用出「梯云纵」！");   
	
	if (DIFFERSTR(me->query_skill_mapped("dodge"), "tiyunzong"))
		return notify_fail("\n你现在激发的轻功无法使用「梯云纵」绝技。");  
	
	if( me->query_temp("zong"))
		return notify_fail("\n你正在使用梯云纵的特殊防御「梯云纵」！");

	if(DIFFERSTR(me->querystr("family/family_name"), "武当派") )
		return notify_fail("\n你虽然曾经会过「梯云纵」这一招，可是却早在叛离武当的时候给废除了。\n");
	
	message_vision( "\n$HIW$N突然深吸一口气，一抬腿猛的拔高数丈，升势刚尽，双腿连续踢出，身体又上升丈许，才有如大鸟般盘旋落下！", me); 

	int improve =me->query("dex") * 5;
	me->add_temp("apply/dodge", improve);
	me->set_temp("zong",1);  
	me->add("mp", -(350-me->query_skill("tiyunzong",1)/10));
	me->UpdateMe();

	me->call_out(remove_effect, me->query_skill("tiyunzong") * 2/3,improve);

	return 1;
}

static void remove_effect(CContainer * ob, LONG param1, LONG param2)
{
    char msg[255];
	CChar * me = (CChar *)ob;  
	int improve=(int)param1;
	me->add_temp("apply/dodge", - improve);
	me->UpdateMe();
	me->delete_temp("zong");
	tell_object(me, "\n$HIR你散去丹田凝聚的内力，混身经脉真气流动，气定神闲，精神弈弈。\n");
	tell_room(me->environment(), snprintf(msg, 255,"\n$HIW%s全身骨头一阵轻响，散去了混身的功力。\n" ,me->name()));
}

SKILL_END;
