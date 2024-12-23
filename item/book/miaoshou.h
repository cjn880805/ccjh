//妙手空空 miaoshou.h
//Lanwood 2001-02-10
//学习妙手空空之术

ITEM_BEGIN(CImiaoshou);

virtual void create(int nFlag = 0)
{
	set_name( "妙手空空入门秘籍");

 	set_weight(200);		

	set("unit", "本");
 	set("long", "这是一册旧书。");
	set("value",  1500 );
	set("material", "paper");
	set("skill/name","stealing");	// name of the skill
	set("skill/exp_required",  1000);
	set("skill/jing_cost",   20+random(20));
	set("skill/difficulty", 20 );
	set("skill/max_skill",  20);
	set("skill/min_skill", 0l);
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
	{
		//非惯窃用缺省研读
		if(! me->query("thief")) return 0;

		if(me->query("hp") < 50)
		{
			tell_object(me, "你感到头晕眼花，什么也看不清。");
			return 1;
		}

		tell_object(me, "你偷偷摸摸的掏出一本破旧的《妙手空空入门》，迅速翻了几页，似乎有所心得。");

		me->add_temp("hp", -50);
		me->add_temp("mark/miaoshou", random(me->query_skill("stealing", 1)) + 1);
		me->start_busy(2);

		if( random(me->query_temp("mark/miaoshou")) > 20)
		{
			tell_object(me, "$YEL你似乎理解了偷窃的真谛，然后迅速将书撕掉。");
			me->delete_temp("mark/miaoshou");
			me->add("thief", -1);
			destruct(this);
			return 1;
		}

		return 1;
	}

	return 0;
}

ITEM_END;
