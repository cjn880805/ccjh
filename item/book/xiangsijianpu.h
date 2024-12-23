// xiangsijianpu.h 青梅素笺
//Lanwood 2001-02-10


ITEM_BEGIN(CIxiangsijianpu);

virtual void create(int nFlag = 0)
{
	set_name( "青梅素笺");

 	set_weight(200);		

	set("unit", "本");
 	set("long", "一枝终南青梅，上面以细细的缎带扎着微黄的素笺。这便是王重阳随身携带数十年之物，触手之处还能略微感到阵阵余温。");
//	set("value",  1500 );
	set("material", "paper");
	set("skill/name","vivien_sword");	// name of the skill
	set("skill/exp_required",  1000);
	set("skill/jing_cost",   20+random(20));
	set("skill/difficulty", 20 );
//	set("skill/max_skill",  300);
//	set("skill/min_skill", 0l);
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "study") == 0)
	{
		if(me->query("hp") < 50)
		{
			tell_object(me, "你感到头晕眼花，什么也看不清。");
			return 1;
		}
		if(EQUALSTR(querystr("owner1"),me->id(1)) )
		{
			if(!query("skill/max_skill"))
			{
				if(me->query_skill("vivien_sword",1)<340)
				{
					set("skill/max_skill",me->query_skill("vivien_sword",1)+10);
					set("skill/min_skill",me->query_skill("vivien_sword",1));
				}
				else
				{
					set("skill/max_skill",  350);
					set("skill/min_skill",  340);
				}
			}
			if(me->query_skill("vivien_sword",1)>=this->query("skill/min_skill") && me->query("gumu/jq")==me->query("age") 
				&& me->query_temp("gumu/read"))
			{
				tell_object(me, "你仔细解开缎带，发现素笺上娟秀的字体竟然写的是一种绝世剑法。");
				me->improve_skill("vivien_sword", random(me->query_skill("literate", 1) / 2 + 1) + 1);
				me->add("hp", -50);
				me->start_busy(2);
			}
			else
				tell_object(me, "你仔细解开缎带，发现素笺上娟秀的字体正是祖师婆婆的笔迹。");

			if( me->query_skill("vivien_sword",1) >= this->query("skill/max_skill"))
			{
				tell_object(me, "$YEL你看着看着，眼中不禁落下泪来。惊慌之中，笺上的墨迹已被你的泪水化开，模糊一片。");
				me->delete_temp("gumu/read");
				destruct(this);
				return 1;
			}
		}
		else
		{
			tell_object(me, "$YEL你看着看着，眼中不禁落下泪来。惊慌之中，笺上的墨迹已被你的泪水化开，模糊一片。");
			destruct(this);
			return 1;
		}
		return 1;
	}

	return 0;
}

ITEM_END;




