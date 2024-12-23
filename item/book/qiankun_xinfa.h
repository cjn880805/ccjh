//qiankun_xinfa.h

//Sample for ITEM: 乾坤大挪移心法
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqiankun_xinfa);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "羊皮");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "张");
 	set("long", "这是一张羊皮，一面有毛，一面光滑。第一行是“明教圣火心法，乾坤大挪移”十一个字。原来这就是武林第一秘籍《乾坤大挪移》心法，相传来自西域山中老人所作。想修这门绝世武功，就好好研读(du)这本书吧。");
	set("value",  10000 );
	set("material", "paper");

	set("destruct_msg", "羊皮一块块脱落，化成一堆灰飞散了。");
};

void init()
{
	CContainer * env = environment();

	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		return;
	}

	if(DIFFERSTR(querystr("owner"), env->querystr("id")) )
	{
		call_out(destruct_me, 1);
	}	
}

int do_look(CChar * me)
{
	CItem::do_look(me);
	AddMenuItem("研读", "$9du $1", me);	
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "du") == 0)
		return do_du(me);
	
	return 0;
}

int do_du(CChar *me)
{
	CContainer * where = me->environment();
	char msg[255];
	int qklevel, lvl;
	int neili_lost;

	if (where->query("pigging"))             
		return notify_fail("你还是专心拱猪吧！");  
    
	if (me->is_busy())            
		return notify_fail("你现在正忙着呢。");  
	
	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！");

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。");

	if( !me->query_skill("jiuyang_shengong", 1) )
		return notify_fail("你没有九阳神功做根坻，不能读乾坤大挪移。");

	if( me->query("hp") < 15 )
		return notify_fail("你现在过于疲倦，无法专心下来研读新知。");

	if( me->query("mp") < 1000 )
	{
		tell_object( me,"忽然，你觉得内息一乱，知道不好！");
		me->unconcious();
		return 1;
	}

	set("book_verb", "du");

	qklevel = me->query_skill("qiankun_danuoyi", 1);
	neili_lost = qklevel/10;
	if( neili_lost < 5) neili_lost = 5;
	lvl = qklevel/20;
	if( lvl < 1) lvl = 1;

	message_channel("study", snprintf(msg, 255, "$N专心研读乾坤大挪移，脸色忽青忽红，连变%ld次。", lvl), me);

	if ( EQUALSTR(me->querystr("gender"), "无性") && qklevel > 99)
		return notify_fail("你先天不足，再学下去难免走火入魔。");

	if (me->query_skill("force", 1) < 100)
		return notify_fail("就这么点基本内功还想学乾坤大挪移？");

	if (me->query("max_mp") < 1500)
		return notify_fail("就这么点内力还想学乾坤大挪移？");

	if (me->query_skill("force", 1) < lvl)
		return notify_fail("你的基本内功火候还不够，小心走火入魔！");

	if ((me->query("max_mp")/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！");

	if( CChar::level2skill(me->query("level")) < qklevel )
		return notify_fail("你的实战经验不足，再怎么读也没用。");

	if( me->query_skill("qiankun_danuoyi", 1) > 400)
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。");

	if (DIFFERSTR(me->querystr("family/family_name"), "明教") && me->query_skill("qiankun_danuoyi", 1) > 239)
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。");

	me->receive_damage("hp", (40 - me->query("int")));
	me->set("mp",me->query("mp")-neili_lost);
	if( !me->query_skill("qiankun_danuoyi", 1) )
		me->set_skill("qiankun_danuoyi", 1);
	me->improve_skill("qiankun_danuoyi", me->query_skill("literate", 1)/3+1);
	tell_object(me,"你研读《乾坤大挪移》，颇有心得。", "study");
	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp