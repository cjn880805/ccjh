//kuihua.h

//Sample for ITEM: 葵花宝典
//coded by Fisho
//data: 2000-11-14

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIkuihua);

//under, we will custom our item

void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "《葵花宝典》简体中文版");	//set item name

	set_weight(600);		//set item weight

	set("unit", "本");
	set("long", "这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。 ");
	set("value", 250000);
	set("material", "paper");

	set("no_drop", "这样东西不能离开你。");
	set("no_get", "这样东西不能离开那儿。");
};

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	say("这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。旺财为了方便大家阅读，把他翻译成了简体中文版。", me);
	AddMenuItem("阅读《葵花宝典》简体中文版", "$9read $1", me); 
//	AddMenuItem("添上几笔。", "$2write $1 $2", me);
//	AddMenuItem("当掉系统", "$0crash $1", me); 
	AddMenuItem("合起《葵花宝典》简体中文版", "", me); 
	SendMenu(me);

    return 1; 
}


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "read") == 0)
		return do_study(me);
	if(strcmp(comm, "join") == 0)
		return do_join(me);

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
        return notify_fail("《葵花宝典》简体中文版的第一页写着：欲练神功，必先自宫。");
           
    if( !me->query_skill("literate", 1) )
        return notify_fail("你是个文盲，先学点文化(literate)吧。");

	set("book_verb", "read");

	if (random(2))
	{
    tell_object(me,"《葵花宝典》简体中文版的第一页写着：欲练神功，必先自宫。", "study");
    tell_object(me,"你不由暗自庆幸：不错不错！", "study");
    tell_object(me,"《葵花宝典》简体中文版的第二页写着：不必自宫，也能练功。", "study");
    tell_object(me,"《葵花宝典》简体中文版的第三页写着：即使自宫，未必成功。", "study");
    tell_object(me,"《葵花宝典》简体中文版的第三页写着：若要成功，不要自宫。", "study");
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

    if ( me->query_skill("pixie_jian", 1) > 84) 
		neili_lost = 15;
	else
		if ( me->query_skill("pixie_jian", 1) > 74) 
			neili_lost = 10;
	else 
		neili_lost = 5;


    if( me->query("mp") < neili_lost) 
	{
		return notify_fail("你内力不够，无法钻研这么高深的武功。");        
    }

    pxlevel = me->query_skill("pixie_jian", 1);
    if( CChar::level2skill(me->query("level")) < pxlevel ) 
	{
        return notify_fail("你的等级不够，再怎么读也没用。");        
    }

    if( me->query_skill("pixie_jian", 1) > 9)
        if ((!(ob = me->PresentName("goldring", IS_ITEM)) ) ||
               (! ob->query("equipped") )) 
		{
            return notify_fail("你没戴戒指，感到很难理解阴柔的指法。");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 19)
        if ((!(ob = me->PresentName("shoes", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没穿绣花鞋，感到很难理解阴柔的步法。");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 29)
        if ((!(ob = me->PresentName("xiuhua", IS_ITEM)) ) ||	//modify by lanwood 2001-03-18 原来是zhen,改为xiuhua
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没用绣花针，感到无法理解这种阴柔灵活的武功。");            
        }

    if( me->query_skill("pixie_jian", 1) > 39)
        if ((!(ob = me->PresentName("pink_cloth", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没穿女人的衣衫，感到很难理解阴柔的身法。");            
        }
        
	if( me->query_skill("pixie_jian", 1) > 49)
		if ((!(ob = me->PresentName("necklace", IS_ITEM)) ) ||
               (!ob->query("equipped") )) 
		{
            return notify_fail("你没戴项链，觉得练这种阴柔的功夫缺乏自信。");
        }

    if( me->query_skill("pixie_jian", 1) > 59)
        if( DIFFERSTR(me->querystr("rank_info/respect"), "公公")) 
		{
			say("你现在需要正式加入东厂才能继续深造辟邪剑法。这将不影响你的师承，而且大家都将尊称你为公公。", me);
			AddMenuItem("加入东厂", "$0join $1", me);
			AddMenuItem("不加入", "", me);
			SendMenu(me);
			me->set_temp("pending/join", 1);
            return 1;
        }

    if( me->query_skill("pixie_jian", 1) > 199)
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

int do_join(CChar * me)
{
    if( me->querystr("rank_info/respect") == "公公") 
		return notify_fail("你已经加入东厂了，不需要重新加入。");

	if( ! me->query_temp("pending/join"))
		return 0;

	me->set("rank_info/respect", "公公");
	me->set("rank_info/rude","阉贼");
	me->set("class","eneuch");
    tell_object(me, "恭喜你成为朝廷最重要的机关东厂的一员！");
	me->delete_temp("pending/join");
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp