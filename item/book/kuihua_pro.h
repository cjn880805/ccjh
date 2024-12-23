//kuihua_pro.h
//Sample for ITEM: 葵花宝典
ITEM_BEGIN(CIkuihua_pro);


void create(int nFlag = 0)		
{
	set_name( "《葵花宝典》进阶版");	

	set_weight(1);

	set("unit", "本");
	set("long", "这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。 ");
	set("value", 0l);
	set("material", "paper");

	set("no_drop", "这样东西不能离开你。");
	set("no_get", "这样东西不能离开那儿。");
	set("no_beg", "这样东西不能离开那儿。");
	
	call_out(selfdest, 3600);	
};

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	say("这就是武林第一秘籍《葵花宝典》，相传原是一位宫中太监所作。后世高人将自身不断修炼而超越原本的心得，撰写而成此进阶版。", me);
	AddMenuItem("阅读《葵花宝典》进阶版", "$9read $1", me); 
	AddMenuItem("合起《葵花宝典》进阶版", "", me); 
	SendMenu(me);

    return 1; 
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(querystr("owner")[0] && EQUALSTR(querystr("owner"), me->id(1)) )
	{
		if(strcmp(comm, "read") == 0)
			return do_study(me);
	}
	else
	{
		tell_object(me, "你将那《葵花宝典》放在双掌中一搓，功力到处，一本原已十分陈旧的册页登时化作碎片。");
		destruct(this);
	}
	return 0;
}

int do_study(CChar * me)
{
	CContainer * ob = me->environment();
	char msg[255];
	int neili_lost, pxlevel;

//	tell_object(me,"还可以用 join 命令");
	
	if (ob->query("pigging"))
		return notify_fail("你还是专心拱猪吧！");
        
    if (me->is_busy()) 
        return notify_fail("你现在正忙着呢。");
               
    if( me->is_fighting() ) 
	    return notify_fail("你无法在战斗中专心下来研读新知！");
    
    if (EQUALSTR(me->querystr("gender"), "女性") )
		return notify_fail("自古没有女性可以读《葵花宝典》的。");
               
    if (EQUALSTR(me->querystr("gender"), "男性") ) 
        return notify_fail("《葵花宝典》进阶版的第一页写着：欲练神功，还须自宫。");
           
    if( !me->query_skill("literate", 1) )
        return notify_fail("你是个文盲，先学点文化(literate)吧。");

	if( me->query_skill("pixie_jian", 1)<600 )
        return notify_fail("你的辟邪剑法修为还不够，无法领悟出《葵花宝典》进阶版中的武学精要。");

	set("book_verb", "read");

	if (random(2))
	{
    tell_object(me,"《葵花宝典》进阶版的第一页写着：欲练神功，还须自宫。", "study");
    tell_object(me,"你不由暗自庆幸：不错不错！", "study");
    tell_object(me,"《葵花宝典》进阶版的第二页写着：若不自宫，也能练功。", "study");
    tell_object(me,"《葵花宝典》进阶版的第三页写着：即使自宫，未必成功。", "study");
    tell_object(me,"《葵花宝典》进阶版的第三页写着：若要成功，不要自宫。", "study");
	}
           
    switch(random(3)) 
	{
		case 0:
			tell_room(me->environment(), snprintf(msg, 255, "%s偷偷摸摸翻出一本书在读。", me->name()), me, "study");
            break;
        case 1:
			tell_room(me->environment(), snprintf(msg, 255, "%s边读书边骚首弄姿，好象在模仿女人。", me->name()), me, "study");
            break;
        case 2:
			tell_room(me->environment(), snprintf(msg, 255, "%s边读书边把腰身扭来扭去。", me->name()), me, "study");
            break;
    }
     
	if( me->query("hp") < 15 ) 
	{
        return notify_fail("你现在过于疲倦，无法专心下来研读新知。");        
    }

    if ( me->query_skill("pixie_jian", 1) > 801) 
		neili_lost = 50;
	else
		if ( me->query_skill("pixie_jian", 1) > 701) 
			neili_lost = 30;
	else 
		neili_lost = 20;


    if( me->query("mp") < neili_lost) 
	{
		return notify_fail("你内力不够，无法钻研这么高深的武功。");        
    }

    pxlevel = me->query_skill("pixie_jian", 1);
    //if( CChar::level2skill(me->query("level")) < pxlevel ) 
	if( pxlevel>801 ) 
	{
        return notify_fail("你的等级不够，再怎么读也没用。");        
    }

    if( me->query_skill("pixie_jian", 1) > 601)
        if ((!(ob = me->PresentName("fengyizhen", IS_ITEM)) ) ||
               (! ob->query("equipped") )) 
		{
            return notify_fail("你没戴缝衣顶针，感到很难理解阴柔的指法。");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 621)
        if ((!(ob = me->PresentName("jinlianxie", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没穿八寸金莲鞋，感到很难理解阴柔的步法。");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 651)
        if ((!(ob = me->PresentName("btzheng", IS_ITEM)) ) ||	//modify by lanwood 2001-03-18 原来是zhen,改为xiuhua
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没用BT绣花针，感到无法理解这种阴柔灵活的武功。");            
        }

    if( me->query_skill("pixie_jian", 1) > 681)
        if ((!(ob = me->PresentName("yanshuhua", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没戴艳俗大红花，觉得练这种阴柔的功夫缺乏自信。");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 701)
		if ((!(ob = me->PresentName("poliquan", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没戴玻璃项链，觉得练这种阴柔的功夫缺乏自信。");
        }

    if( me->query_skill("pixie_jian", 1) > 751)
        if ((!(ob = me->PresentName("diaojiandai", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
           return notify_fail("你没穿小可爱吊肩带，觉得练这种阴柔的功夫缺乏自信。");
        }

	if( me->query_skill("pixie_jian", 1) > 751)
        if ((!(ob = me->PresentName("kuihuaao", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
           return notify_fail("你没穿葵花小袄，感到很难理解阴柔的身法。");
        }

    if( me->query_skill("pixie_jian", 1) > 801)
	{
         return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。");         
    }

    me->receive_damage("hp", 15);
	me->add("mp", - neili_lost);
    
	if( ! me->query_skill("pixie_jian", 1) ) 
		me->set_skill("pixie_jian", 0);

    me->improve_skill("pixie_jian", me->query_skill("literate", 1) / 3 + 1);
    tell_object(me, "你研读《葵花宝典》，颇有心得。", "study");
    return 1;
}

static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();
	if(userp(me))
		tell_object((CChar *)me, "你将那《葵花宝典》放在双掌中一搓，功力到处，一本原已十分陈旧的册页登时化作碎片。");
	else
		tell_room(me, "突然一阵风吹过，《葵花宝典》进阶版在风中化为寸寸碎纸，若蝴蝶般顺风飞去了。");
	
	destruct(ob);
	return;
}
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp