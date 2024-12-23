//shen.h 逍遥任务特殊道具
ITEM_BEGIN(CIzhutong)

virtual void create(int nFlag = 0)		
{
	set_name("竹筒", "zhu tong");
	set("long",	"这是一节从竹子上截下来的竹筒，可以用来装水。");
	set("unit", "根");
	set_weight(1000);
	set("value", 1);
};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->is_fighting() || me->is_busy())
		return notify_fail("你正在忙着呢。");
	
	CContainer * env=me->environment();
	if(env->query_temp("thing"))
	{
		if(env->query("index")==1)
		{
			tell_object(me, "\n$HIC你顾不上雨水哗哗的淋落在你的身上，掏出竹筒，欣喜的举了起来。不一会儿，竹筒就盛了大半筒雨水。");
			tell_object(me, "$HIR你得到了「无根水」。\n");
			load_item("wugenshuei")->move(me);
			destruct(this);
		}
		else if(env->query("index")==2)
		{
			tell_object(me, "\n$HIC轻盈的雪花朵朵飘坠，你一边欣赏着雪花漫天的美景，一边掏出竹筒，举在空中。");
			tell_object(me, "$HIR你得到了「雪水」。\n");
			load_item("xueshuei")->move(me);
			destruct(this);
		}
	}
	else if (env->PresentName("mei shu",IS_ITEM))
	{
		time_t t;	
		struct tm * newtime;
		time(&t);
		newtime = localtime(&t);

		if(newtime->tm_hour < 7 && newtime->tm_hour >6) //每天早上6点至7点前可以取得露水
		{
			tell_object(me, "\n$HIC你欣喜的发现树上已开满了鲜红的梅花，清晨的露珠在花瓣上跃动，闪烁着晶莹的光茫。");
			tell_object(me, "$HIC你拿出竹筒，小心翼翼的将露珠接了进来。");
			tell_object(me, "$HIR你得到了「露水」。\n");
			load_item("lushuei")->move(me);
			destruct(this);
		}
		else
		{
			tell_object(me, "\n$HIC你看着满园绽开的梅花，不禁为之而陶醉。");
		}
	}
	else
		return notify_fail("你拿出竹筒看了看，发现好象没什么用处。");
    return 1; 
}

ITEM_END;




