FOOD_BEGIN(CIyaopin_4);

void create(int nFlag = 0)
{
	char msg[255];

	static struct{
		char name[20], id[20];
		int type;				//类别
		LONG weight;			//重量
		LONG val;				//价值	
	}yao[11] = {
		{"七叶一枝","guiyuan dan",1,1200, 4000, },        {"紫花景天","huishen gao",2,1500, 4000, },        {"石南藤", "buqi wan",3,2000, 4000,},
		{"翻天印","baihua gao",4,2000, 4000, },
		{"五子连环草","huixue gao",5,2000, 6400, },	    {"灯心","jiegu san",6,	1000, 6400, },        {"七结","tianxian yulu",7,3000, 8000, },        {"一叶","jiuzhuan dan",8,3500, 10000, },
		{"丹枫", "tianxiang gao",9,1000, 10000, },
		{"石苇", "dahuan dan",10,	2500, 16000, },
		{"九命","gongting mifang",11,1000, 16000, },
	};

	int lvl = random(11);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);

		set("type", yao[lvl].type);
		set_weight(yao[lvl].weight);
	if (random(40))
	{
		set_name(yao[lvl].name, yao[lvl].id);
		set("value", yao[lvl].val);
	}
	else
	{
		set("flash",1);
		snprintf(msg,255,"闪%s",yao[lvl].name);
		set_name(msg, yao[lvl].id);
		set("value", yao[lvl].val*6);
	}

//		set("eat_msg", "$N服下一支$n。");

//		set("food_remaining", 1);
//	set_amount(1);
}


int do_use(CChar * me, CContainer * target)
{

//	message_vision("$n服下一支$N。",this,me);
	int i;
	int n;
	n=query("flash");

	switch (query("type"))
	{
	case 1:
		if (n)
			me->set("eff_hp",me->query("max_hp"));
		me->set("hp",me->query("eff_hp"));
		message_vision("$N的脸上突然现出一阵雾气，又迅速消退下去。",me);
		tell_object(me,"你只觉得浑身舒畅无比！");
		break;
	case 2:
		me->add_temp("apply/per",1);
		if (n)
		{
			if(me->query("per")<38)
			{
				me->add("per",1);
				message_vision("$N的脸上突然现出一阵红潮，又迅速消退下去。",me);
				tell_object(me,"你的容貌提高了！");
			}
			else
			{
				message_vision("$N的脸上突然现出一阵红潮，久久不能消退下去。",me);
				tell_object(me,"你的容貌没有办法再提升了！");
			}
		}
		else
		{
			message_vision("$N的脸上突然现出一阵红潮，又迅速消退下去。",me);
			tell_object(me,"你的容貌提高了！");
		}
		break;
	case 3:
		i=me->query("mp");
		if (n || i*2<me->query("max_mp")*4 )
			me->add("mp",i);
		message_vision("$N的脸上突然现出一阵杀气，又迅速消退下去。",me);
		tell_object(me,"你只觉得真气充实无比！");
		break;
	case 4:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/con",i);
		message_vision("$N的脸上突然现出一阵灰气，又迅速消退下去。",me);
		tell_object(me,"你的体质提高了！");
		break;
	case 5:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/str",i);
		message_vision("$N的脸上突然现出一阵紫气，又迅速消退下去。",me);
		tell_object(me,"你的力量提高了！");
		break;
	case 6:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/int",i);
		message_vision("$N的脸上突然现出一阵白气，又迅速消退下去。",me);
		tell_object(me,"你的智慧提高了！");
		break;
	case 7:
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/dex",i);
		message_vision("$N的脸上突然现出一阵黄气，又迅速消退下去。",me);
		tell_object(me,"你的敏捷提高了！");
		break;
	case 8:
		//i=me->query_skill("parry");
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/parry",i);
		message_vision("$N的脸上突然现出一阵黑气，又迅速消退下去。",me);
		tell_object(me,"你的有效招架等级提高了！");
		break;
	case 9:
		//i=me->query_skill("force");
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/force",i);
		message_vision("$N的脸上突然现出一阵蓝气，又迅速消退下去。",me);
		tell_object(me,"你的有效内功等级提高了！");
		break;
	case 10:
		//i=me->query_skill("dodge");
		i=2;
		if (!n)
			i=1;
		me->add_temp("apply/dodge",i);
		message_vision("$N的脸上突然现出一阵青气，又迅速消退下去。",me);
		tell_object(me,"你的有效轻功等级提高了！");
		break;
	case 11:
		i=me->query("eff_hp") / 20;
		if (!n)
			i=i/2;
		me->add("eff_hp",i);
		message_vision("$N的脸上突然现出一阵血色，又迅速消退下去。",me);
		tell_object(me,"你的ＨＰ上限提高了！");
		break;
	}

	me->start_busy(1);

	destruct(this);
    return 1; 
}

int Can_Use()
{
	return 1;
}





FOOD_END;
