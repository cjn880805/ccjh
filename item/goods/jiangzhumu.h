ITEM_BEGIN(CIjiangzhumu);

virtual void create(int nFlag = 0)		
{
	set_name( "绛珠玉木");	
	set("long","一株高丈余的小树，通体透明，有若流了血的水晶珊瑚，红得煞是好看");
	set("no_get", "你不忍心去攀折这株奇树。。。");
	set_weight(1);
	set("no_clean_up", 1);
	call_out(do_zhuguo, 600);	
};

static void do_zhuguo(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(env->query("zhuguo"))
	{
	case 0:
		tell_room(env, "\n\n$HIR只见一块奇形古怪似若拐杖巨石，石上面生着一株高丈余的小树，通体透明，有若流了血的水晶珊瑚，红得煞是好看。枝间翠叶涟涟，还结着几朵粉白的花苞。\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 1:
		tell_room(env, "\n\n$HIR仔细看时，只见小树上的几朵蓓蕾，都如拇指般大，白得宛如无瑕白玉，都被花瓣紧紧包着。\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 2:
		tell_room(env, "\n\n$HIR一阵风过，忽闻奇香扑鼻，精神顿爽。小树上蓓蕾在微风中将花瓣慢慢舒展开来，露出品红的花蕊。\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 3:
		tell_room(env, "\n\n$HIR香气益发浓郁起来，小树上的花朵竟似中了魔咒般，越开越盛。\n只一瞬已变得有如茶盏般大小，红白相映 ，娇艳欲滴。\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 4:
		tell_room(env, "\n\n$HIR花瓣渐枯，微风吹过，片片如雪般飘落，只见蕊中已结出嫩红的小果。\n\n");
		env->add("zhuguo",1);
		me->call_out(do_zhuguo, 300);	
		break;
	case 5:
		tell_room(env, "\n\n$HIR小果渐渐长大，只见其珠红似珍珠，圆润光洁。\n待朱果长成，小树便有如被吸干了精元般，渐渐萎缩，最终没入巨石，消失不见。\n\n");
		env->del("zhuguo");
		load_item("zuguo")->move(env);
		destruct(me);
		break;
	}
}


ITEM_END;

