ITEM_BEGIN(CIjieyuling)

void create(int nFlag = 0)		
{
	set_name("刀剑劫余令", "jieyu ling");
    set_weight(1);
    set("unit", "块");
    set("long", "这是一块紫黑色的灵牌，上面刻着一刀一剑。");
	set("material", "steal");
	set("no_drop",1);
	set("no_sell",1);
};

//设置主人
void init()
{
	CContainer * env = environment();

	if(! querystr("owner")[0] && userp(env) )
	{
		set("owner", env->querystr("id"));
		return;
	}
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if(! target || target == me)
		return notify_fail("你要对谁使用？");

	if (me->is_fighting())
		return notify_fail("现在无法使用刀剑劫余令！");

	if (me->query_temp("fool/finish"))
		return notify_fail("你已经完成任务，还不快回去复命，磨蹭什么！");

	if( me->is_busy())
		return notify_fail("你现在很忙。");

	char msg[255];	
	int flag=0;

	tell_object(me, snprintf(msg, 255, "$HIG你用锐利的眼神盯着%s。",target->name()));

	if (target->object_id() == me->query_temp("fool/doing") && random(me->query_int()) > 20)
	{
		switch(random(5)) 
		{
		case 0:
			snprintf(msg, 255, "$WHT你发现%s忽然把头一低，似乎想避开你的目光。",target->name());
            break;
		case 1:
			snprintf(msg, 255, "$WHT你发现%s忽然打了个哆嗦，面如土色。",target->name());
			break;
		case 2:
			snprintf(msg, 255, "$WHT你发现%s太阳穴高高坟起，似乎是个练武的人。",target->name());
			break;
		case 3:
			snprintf(msg, 255, "$WHT你发现%s腰间鼓鼓囊囊的，样子象是一件兵刃",target->name());
			break;
		case 4:
			snprintf(msg, 255, "$WHT你发现%s的眼中精光一闪，马上又变的一脸茫然。",target->name());
			break;
		}

		flag=1;
	}  
	else
	{
		switch(random(11)) 
		{
		case 0:
			snprintf(msg, 255, "$HIG只见%s正挤眉弄眼，色迷迷的东张西望。",target->name());
			break;
			
		case 1:
			snprintf(msg, 255, "$HIG只见%s饿得面黄肌瘦，骨瘦如柴。",target->name());
			break;
			
		case 2:
			snprintf(msg, 255, "$HIG只见%s面颊微红，一脸娇羞的模样。",target->name());
                     break;
		case 3:
			snprintf(msg, 255, "$HIG只见%s满脸横肉，嘴脸凶顽。",target->name());
			break;
			
		case 4:
			snprintf(msg, 255, "$HIG只见%s悲痛欲绝，哭的象个泪人似的。",target->name());
			break;

		case 5:
			snprintf(msg, 255, "$HIG只见%s手足僵硬，浑身散发着金属光泽。",target->name());
			break;

		case 6:
			snprintf(msg, 255, "$HIG只见%s面无表情，呆若木鸡。",target->name());
			break;
			
		case 7:
			snprintf(msg, 255, "$HIG只见%s长得尖嘴猴腮，目光狡诈。",target->name());
			break;
         
		case 8:
			snprintf(msg, 255, "$HIG只见%s干笑几声，脸上挤出一丝媚笑。",target->name());
			break;
                
		case 9:
        	snprintf(msg, 255, "$HIG只见%s挺胸叠肚，一脸傲慢的神色。",target->name());
	        break;
                
		case 10:
			snprintf(msg, 255, "$HIG只见%s长得明眸皓齿，一脸天真的神色。",target->name());
			break;
		}
	}
	
	tell_object(me,msg);
	me->start_busy(2);

	if (! flag) return 1;
	
	//成功的找到了。

	message_vision("$HIW$N对着$n冷笑一声道：阁下的案子发了，老老实实跟我走一趟。",me,target);
	message_vision("$HIY$N长笑一声，道：可没这么容易！",target);
	destruct(target);

	flag = 11 + me->query("fool/diff");	//难度系数
	
	//创建一个怪物。
	CNnpcmirror * monster = (CNnpcmirror *)load_npc("monster_jieyu");
	monster->make_mirror(me, flag);
	monster->set_name( me->querystr_temp("fool/name"));
	monster->set("foolid", me->query_temp("fool/doing"));
	monster->set_weight(50000000);
	monster->move(me->environment());
	monster->kill_ob(me);

	monster->call_out(do_die, 400+random(100));	

	return 1;
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

ITEM_END;