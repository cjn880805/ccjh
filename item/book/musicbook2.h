//musicbook2.h
//《笑傲江湖曲》下册
//lanwood 2001-04-05

/*
学习笑傲江湖曲相当之难。
一本乐谱 学习音乐到100级，才能开始练琴。
一本琴谱 要求music 大于 100 必须用琴 只能学到100级
一本箫谱 要求music 大于 150 必须用箫 一旦改箫，就不能再用琴。只能学到100级 set("marks/xiaoao", 1);
一本琴箫合奏谱 要求 笑傲江湖曲 大于 100 add("marks/xiaoao", 2);  0 : 琴 1: 箫　2: 琴合奏 3:箫合奏
*/

ITEM_BEGIN(CImusicbook2);

void create(int nFlag = 0)
{
	set_weight(600);

	set("unit", "本");
	set("long", "这就是《笑傲江湖曲》，相传红泪妹妹为蓝笑哥哥所作。 ");
	set("value", 25000);
	set("material", "paper");

	char book_name[4][20] = {
		"箫谱",
		"箫谱",
		"琴谱",
		"琴箫合奏",
	};
	
	int lvl;

	if(nFlag)
		lvl = nFlag;
	else
	{
		if(! random(3))
		{
			lvl = 2;
		}
		else
		{
			lvl = 1;
		}
	
		if(! random(20))
		{
			lvl = 3;
		}
	}
	
	set("music_type", book_name[lvl]);
	set("book_type", lvl);
	set("index", lvl);
		
	char msg[80];
	set_name(snprintf(msg, 80, "《笑傲江湖曲》之%s", querystr("music_type")), "music book");

	set("no_drop", "这样东西不能离开你。");
	set("no_give", "这样东西不能离开你。");
	set("no_sell", 1);
};

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	say("你翻开《笑傲江湖曲》，上面画了两个女子，正在抚琴弄箫，情色悠然。", me);
	AddMenuItem("阅读《笑傲江湖曲》", "$9read $1", me); 
	SendMenu(me);

    return 1; 
}


virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "read") == 0)
		return do_study(me);
	
	return 0;
}

int do_study(CChar * me)
{   
    if (me->is_busy()) 
        return notify_fail("你现在正忙着呢。");
               
    if( me->is_fighting() ) 
	    return notify_fail("你无法在战斗中专心下来研读新知！");
    
    if (EQUALSTR(me->querystr("gender"), "无性") )
		return notify_fail("你无根无性，无法理解其中的玄妙。");
    
    int skill = me->query_skill("music", 1);
	
	if( skill < 30)
		return notify_fail("你对乐理的研究太浅，无法理解其中的玄妙。");

	CContainer * qin = me->query_weapon();

	if(! qin || DIFFERSTR(qin->querystr("skill_type"), "music"))
		return notify_fail("你得先找把乐器来练习！");

	int type = query("book_type");
	int music_user = me->query("marks/xiaoao");
	int myskill = me->query_skill("xiaoaojianghu", 1);

	//1, 判断能否学习
	if(type == 3)	//合奏曲
	{
		if(myskill < 100)
		{
			if(type & 1 )
				return notify_fail("你的箫练得不熟，没办法与琴合。");
			else
				return notify_fail("你的琴练得不熟，没办法与箫合");
		}

		if(! (music_user & 2))
			me->set("marks/xiaoao", music_user & 2);

	}else if(type == 2)	//箫谱
	{
		if(! myskill )	//第一次用箫，从此使箫。
		{
			music_user = 1;
			me->set("marks/xiaoao", 1);
		}
		else if(! (music_user & 1) )	//否则判断是否已经用箫
			return notify_fail("你用琴已经很纯熟了，再改箫怕是不好吧。");

		if(myskill > 100)
			return notify_fail("你用箫的技巧已经相当娴熟，这本箫谱对你没什么用了。");
	}
	else			//琴谱
	{
		//判断是否已经用箫
		if( music_user & 1 )
			return notify_fail("你已经改用箫了，再学琴怕是不好吧。");
		
		if(myskill > 100)
			return notify_fail("你用琴的技巧已经相当娴熟，这本琴谱对你没什么用了。");
	}


	//2, 判断乐器类型
	if(music_user & 1 && DIFFERSTR(qin->querystr("music_type"), "xiao"))
		return notify_fail("你必须先找支箫来练习《笑傲江湖曲》。");
	if(! (music_user & 1) && DIFFERSTR(qin->querystr("music_type"), "qin"))
		return notify_fail("你必须先找把琴来练习《笑傲江湖曲》。");

	//3，开始练习
	if(music_user & 1)	//箫
	{
		if(skill < 50)
			message_vision("\n$HIY$N转身抽出一支$n$HIY，轻轻放在唇边，有板有眼的对着《笑傲江湖曲》吹奏起来。\n", me, qin);
		else if(skill < 100)
			message_vision("\n$HIY$N神态怡然的竖起$n$HIY，轻轻吐气，乐曲如流水般飘过……\n", me, qin);
		else 
			message_vision("\n$HIY$N在$n$HIY上轻轻上一吹，立时，如仙曲般的箫声荡漾在每个人的心间。\n", me, qin);
	}
	else		//琴
	{
		if(skill < 50)
			message_vision("\n$MAG$N摆出一把$n$MAG，款款坐下，有板有眼的对着《笑傲江湖曲》弹奏起来。\n", me, qin);
		else if(skill < 100)
			message_vision("\n$MAG$N摆出一把$n$MAG，纤指一拨，乐曲如流水般飘过……\n", me, qin);
		else 
			message_vision("\n$MAG$N在$n$MAG上轻轻上一拨，立时，如仙曲般的琴声荡漾在每个人的心间。\n", me, qin);
	}
	
	me->start_busy(5);
	me->set_temp("pending/xiaoao", 1);
	me->start_busy(do_lianxi, halt_lianxi);
	return 1;
}

static int do_lianxi(CChar * me)
{	
	int lose = me->query_skill("music");
	int skill = me->query_skill("xiaoaojianghu");

	CContainer * weapon = me->query_weapon();

	if(me->query("hp") < lose || me->query("mp") < 30 || ! weapon)
	{
		me->set_temp("pending/xiaoao", 0l);
		message_channel("study", "$HIC$N轻轻一笑，收起了《笑傲江湖曲》。", me);
		tell_object(me, "你的体力或真气不足，需要休息一下了。", "study");
		me->SendState(me);		
		return 0;
	}
	if( skill  >= CChar::level2skill(me->query("level")) )
		return notify_fail("你的等级不够，练得再多也没用。");
	//练功
	if(! random(5))
	{
		if( me->query("marks/xiaoao") & 1)	//箫
			message_channel("study", "$HIC$N神色怡然的吹奏$HIC$n，乐曲入行云搬飘过……", me, weapon);
		else
			message_channel("study", "$HIC$N手指在$n$HIC上轻抚，乐曲如流水般行走……", me, weapon);
	}
	
	me->add("hp", -lose);
	me->add("mp", -30);

	me->improve_skill("xiaoaojianghu", me->query_skill("music", 1) / 3 + 1);
	return 1;
}

static int halt_lianxi(CChar * me, CChar * who, char * how)
{
	me->set_temp("pending/xiaoao", 0l);

	CContainer * weapon = me->query_weapon();
	if(! weapon) return 0;

	//显示中止原因信息
	if( me->query("marks/xiaoao") & 1)	//箫
		message_vision("$HIY突然将$n$HIY收回袖口，神色凛然的起身站起。", me, weapon);
	else
		message_vision("$MAG只听「铮」的一响，$n$MAG断了一弦，$N轻叹口气，指上留下一道殷殷血痕！", me, weapon);
	
	me->SendState(me);
	return 1;
}


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp